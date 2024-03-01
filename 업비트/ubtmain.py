from myUpbit import *
import my_key   # 업비트 시크릿 엑세스키
import ende_key # 암호화키
import time
import pyupbit



simpleEnDecrypt = SimpleEnDecrypt(ende_key.ende_key) #ende_key.py 에 있는 키를 넣으세요
Upbit_AccessKey = simpleEnDecrypt.decrypt(my_key.upbit_access)
Upbit_SecretKey = simpleEnDecrypt.decrypt(my_key.upbit_secret)

# 100만원 가정
# 5개의 코인 구매
# 100/5 = 20 즉 한 코인당 20만원치 살거다
# 20만원치를 분할구매
# 각 코인별 할당 금액 알아야함

# upbit는 객체
upbit = pyupbit.Upbit(Upbit_AccessKey,Upbit_SecretKey)   



# 내가 매수할 총 코인 개수
MaxCoinCnt = 5.0

# 처음 매수할 비중(퍼센트)
FirstRate = 10.0

# 추가 매수할 비중(퍼샌트)
WaterRate = 5.0

# 내 잔고 데이터를 가져온다
balances = upbit.get_balances()
#총 원금
TotalMoney = GetTotalMoney(balances)
#총 평가금액
TotalRealMoney = GetTotalRealMoney(balances)

 
# 업비틔의 수익률: 매수금액에 대한 수익률
# 아래 수익률: 내가 가진 총 자산에 대한 수익률
# 내 잔고 데이터의 총 수익률 = (총원금-총평가금액)*100/총평가금액
TotalRevenue = (TotalRealMoney - TotalMoney) * 100.0/ TotalMoney

# 코인당 매수할 최대 매수금액(총자산/원하는개수)
CoinMaxMoney = TotalMoney / MaxCoinCnt
# 처음에 매수할 금액 10%
FirstEnterMoney = CoinMaxMoney / 100.0 * FirstRate
# 그 이후 매수할 금액 5%
WaterEnterMoney = CoinMaxMoney / 100.0 * WaterRate


""" print("-----------------------------------------")
print("Total Money:", GetTotalMoney(balances))
print("Total Real Money:", GetTotalRealMoney(balances))
print(f"Total Revenue: {TotalRevenue}%", )
print("-----------------------------------------")
print("one_CoinMaxMoney: ", CoinMaxMoney)
print("FirstEnterMoney: ", FirstEnterMoney)
print("WaterEnterMoney: ", WaterEnterMoney) """

print("-----------------------------------------------")
print ("총 투자 원금: ", GetTotalMoney(balances))
print ("현재 평가 금액: ", GetTotalRealMoney(balances))
print ("총 수익율: ", TotalRevenue)
print("-----------------------------------------------")
print ("코인당 최대 매수 금액 : ", CoinMaxMoney)
print ("처음 매수할 금액 : ", FirstEnterMoney)
print ("추가매수(물탈) 금액 : ", WaterEnterMoney)


 
# 거래대금이 많은 탑코인 20개의 리스트
TopCoinList = GetTopCoinList("week", 10)
print(f"Top 코인 리스트")
print("------------------------------------")
for i in TopCoinList:
    print(i)
print("------------------------------------")
# 제외 코인 리스트
OutCoinList = ["KRW-RFR","KRW-MARO","KRW-DAWN",",KRW-TSHP", "KRW-PXL","KRW-GRS","KRW-STORJ","KRW-BTC","KRW-HIFI"]
# 원하는 코인
LovelyCoinList = ["KRW-BTC", "KRW-ETH", "KRW-DOT"]

Tickers = pyupbit.get_tickers("KRW")

for ticker in Tickers:
    try: 
        # 탑코인 안에 티커가 존재한다면 매수매도 할거야 없으면 pass (그다음티커로 넘어가)
        # 거래량 많은 탑코인 리스트안의 코인이 아니라면 스킵! 탑코인에 해당하는 코인만 이후 로직을 수행
        if CheckCoinInList(TopCoinList, ticker) == False:
            continue
        # 위험한 코인 이라면 pass
        if CheckCoinInList(OutCoinList, ticker) == True:
            continue


        print("대상 코인 :",ticker)
        time.sleep(0.1)
        # 60분봉 기준으로 데이터 가져오겠다.
        df_60 = pyupbit.get_ohlcv(ticker, interval="minute60")  # 바꿔도됨 상승장이면 작게 가져가도됨 위험은 부담됨

        # 60분봉의 rsi14지표를 가져오겠다 (숫자가 줄어들면 매수 기회가 많음, 하지만 위험) -1:현재, -2: 이전
        """ rsi60_min_before = GetRSI(df_60, 14, -2)
        rsi60_min = GetRSI(df_60, 14, -1) """
        rsi60_min_before = GetRSI(df_60,14,-3)
        rsi60_min = GetRSI(df_60,14,-2)

        revenu_rate = GetRevenueRate(balances, ticker)
        print("- 최근 RSI지표 추이 :", rsi60_min_before, " -> ", rsi60_min)
        print("revenu_rate: ", revenu_rate)

        # 원화 잔고를 가져온다
        time.sleep(0.05)
        won = float(upbit.get_balance("KRW"))
        print("# 현재 남은 돈(원화) :", won)
        print("------------------------------------")
        



        # 이미 매수한 코인. 물타기!!!
        if IsHasCoin(balances, ticker) == True:

            # 현재 매수된 코인의 총 매수금액
            NowCoinTotalMoney = GetCoinNowMoney(balances, ticker)

            # 짧게 1퍼센트만 먹기
            #if revenu_rate >=1.0:
            # rsi14지표60분봉 70이상, 수익률 1.0이상
            # 60분봉 기준 RSI지표 70 이상이면서 수익권일때 분할 매도를 ㅏㄴ다
            if rsi60_min >=70.0 and revenu_rate >=1.0:
                print("!!!!!!!!!!!!!!!수익 성공 야호  분할 매도!!!!!!!!!!!!!!!!!!!!")

                # 현재 걸려있는 지정가 주문을 취소한다. 왜? 아래 매수매도 로직이 있으니깐.
                CancelCoinOrder(upbit, ticker)

                # NowCoinTotalMoney이 10000원 이하면 전부 판다. 
                # 정정. 매수금액의 25퍼센트까지는 매도하고 그 이상인 경우는 분할 매도. 즉 60분봉 기준 4번안에 다 팔린다.
                # 최대 코인매수금액 1/4보다 작다면 전체 시장가 매도
                if NowCoinTotalMoney < (CoinMaxMoney/4.0):
                    # 시장가 매도를 한다
                    balances = SellCoinMarket(upbit,ticker,upbit.get_balance(ticker))
                else:
                    # 시장가로 절반씩 판다
                    balances = SellCoinMarket(upbit,ticker,upbit.get_balance(ticker) / 2.0)
                time.sleep(2.0)
                won = float(upbit.get_balance("KRW"))




            ####손절로직
            # 내가 가진 원화가 물탈 돈보다 작다..(원금 바닥) 그런데 수익률이 -10퍼 이하다? 그럼 절반 팔아서 물탈돈을 마련하자
            # 이 로직은 없애서 존버 해도 됨
            # 최대코인매수금액의 1/4보다 크다면 절반씩 시장가 매도
            #
            if won<WaterEnterMoney and revenu_rate <= -10.0:
                print("!!!!!!!!!!!!!!!원화 바닥 해당 코인 절반 매도합니다 ㅜ.ㅜ !!!!!!!!!!!!!!!!!!!!")
                #현재 걸려있는 지정가 주문을 취소한다. 왜? 아래 매수매도 로직이 있으니깐 
                CancelCoinOrder(upbit,ticker)
                balances = SellCoinMarket(upbit,ticker,upbit.get_balance(ticker) / 2.0)


            ############################# 구입부 #############################
              
            # 할당된 최대코인매수금액 대비 매수된 코인 비율 = 현재까지 매수된 금액/한코인에 할당된 최대 금액
            Total_Rate= NowCoinTotalMoney / CoinMaxMoney * 100.0

            #60분봉 기준 RSI지표 30 이하에서 빠져나왔을 때
            if rsi60_min_before <= 30.0 and rsi60_min > 30.0:
                #할당된 최대코인매수금액 대비 매수된 코인 비중이 50%이하일때..
                if Total_Rate <= 50.0:
                    print("!!!!!!!!!!!!!!!물탈 돈으로 물을 탑니다!!!!!!!!!!!!!!!!!!!!!")
                    #현재 걸려있는 지정가 주문을 취소한다. 왜? 아래 매수매도 로직이 있으니깐 
                    CancelCoinOrder(upbit,ticker)
                    
                    balances = BuyCoinMarket(upbit,ticker,WaterEnterMoney)
                #50%를 초과하면
                else:
                    # 방어로직
                    #수익율이 마이너스 5% 이하 일때만 매수를 진행하여 원금 소진을 늦춘다.
                    print("!!!!!!!!!!!!!!! 수익율이 ",revenu_rate,"일때만 물을 탑니다 !!!!!!!!!!!!!!!!!!!!!")
                    if revenu_rate <= -5.0:
                        print("!!!!!!!!!!!!!!!물탈 돈으로 물을 탑니다!!!!!!!!!!!!!!!!!!!!!")
                        #현재 걸려있는 지정가 주문을 취소한다. 왜? 아래 매수매도 로직이 있으니깐 
                        CancelCoinOrder(upbit,ticker)

                        balances = BuyCoinMarket(upbit,ticker,WaterEnterMoney)
                        

        #아직 매수하기 전인 코인들 즉 매수 대상
        else:


            #거래량 많은 탑코인 리스트안의 코인이 아니라면 스킵! 탑코인에 해당하는 코인만 이후 로직을 수행한다.
            """ if CheckCoinInList(TopCoinList,ticker) == False:
                continue """
            #60분봉 기준 RSI지표 30 이하이면서 아직 매수한 코인이 MaxCoinCnt보다 작다면 매수 진행!
            #if rsi60_min <=30.0 and GetHasCoinCnt(balances)<MaxCoinCnt:
            # 이전 rsi지표가 30이하고, 현재rsi지표가 30 이상이면 빠져나왔으므로 매수진입 
            
            #60분봉 기준 RSI지표 30 이하에서 빠져나오면서 아직 매수한 코인이 MaxCoinCnt보다 작다면 매수 진행!
            if rsi60_min_before <=30.0 and rsi60_min>30.0 and GetHasCoinCnt(balances)<MaxCoinCnt:
                print("!!!!!!!!!!!!!!!첫 매수! 가즈아!!!!!!!!!!!!!!!!!!!!!!!!")
                time.sleep(0.05)
                # 시장가 매수를 한다
                balances = BuyCoinMarket(upbit,ticker,FirstEnterMoney)







            # 단타전략 추가    
            time.sleep(0.05)
            # 15분봉 기준으로 데이터 가져오겠다.
            df_15 = pyupbit.get_ohlcv(ticker, interval="minute15")  

            # 15분봉 기준 5일선 값을 구한다
            ma5_before_3 = GetMA(df_15, 5, -4)
            ma5_before_2 = GetMA(df_15, 5, -3)
            ma5 = GetMA(df_15, 5, -2)

            # 15분봉 기준 20일선 값을 구한다
            ma20 = GetMA(df_15, 20, -2)
            print("ma20: ", ma20)
            print("ma5:", ma5, " <- ", ma5_before_2, " <- ", ma5_before_3)
            
            if ma5 < ma20 and ma5_before_3 > ma5_before_2 and ma5_before_2 < ma5:
                print("!!!!!!!!!!!!!!!단타 첫 매수! 가즈아!!!!!!!!!!!!!!!!!!!!!!!!")
                #시장가 매수를 한다.
                balances = BuyCoinMarket(upbit,ticker,FirstEnterMoney)

                #평균매입단가와 매수개수를 구해서 1% 상승한 가격으로 지정가 매도주문을 걸어놓는다.
                avgPrice = GetAvgBuyPrice(balances, ticker)  # 평균 매입 단가
                coin_volume= upbit.get_balance(ticker)         # 개수
                
                # 평균 매입단가보다 1% 오른값
                avgPrice *=1.01
                # 지정가 매도주문
                SellCoinLimit(upbit,ticker,avgPrice,coin_volume)
            



            # 1분 기준으로 30 이하일 때 매수를 하는 로직(전체 생략가능) 
            time.sleep(0.05)
            # 15분봉 기준으로 데이터 가져오겠다.
            df_1= pyupbit.get_ohlcv(ticker, interval="minute1")  
            rsi1_min = GetRSI(df_1, 14, -1) 
            print("rsi1_min", rsi1_min )
            if rsi1_min < 30.0:
                print("!!!!!!!!!!!!!!!단타 첫 매수! 가즈아!!!!!!!!!!!!!!!!!!!!!!!!")
                balances = BuyCoinMarket(upbit,ticker,FirstEnterMoney)

                #평균매입단가와 매수개수를 구해서 1% 상승한 가격으로 지정가 매도주문을 걸어놓는다.
                avgPrice = GetAvgBuyPrice(balances, ticker)  # 평균 매입 단가
                coin_volume= upbit.get_balance(ticker)         # 개수
                
                # 평균 매입단가보다 1% 오른값
                avgPrice *=1.01
                # 지정가 매도주문
                SellCoinLimit(upbit,ticker,avgPrice,coin_volume)


    except Exception as e:
        print("error:",e)
        





