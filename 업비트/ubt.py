import pyupbit
import pandas as pd
import time



# 100만원 가정
# 5개의 코인 구매
# 100/5 = 20 즉 한 코인당 20만원치 살거다
# 20만원치를 분할구매
# 각 코인별 할당 금액 알아야함


access = "17iEMcWV2GQRJlAcmxri0cxoLxmrGjmKjbq4IhK8"          # 본인 값으로 변경
secret = "RxQApejEyEIxorrqtfEcoLCw9BGPeL46HFuGVxg2"          # 본인 값으로 변경
upbit = pyupbit.Upbit(access, secret)                        # upbit는 객체

# RSI지표 수치를 구해준다. 분봉/일봉정보, 기간, 기준 날짜
def get_balance_info(access_key, secret_key):
    # 업비트 객체 생성
    upbit = pyupbit.Upbit(access_key, secret_key)
    
    # 보유 중인 모든 암호화폐의 잔고 및 단가 정보
    my_balances = upbit.get_balances()
    print("내 잔고")
    # 보유 현금 조회
    print("현금: ", upbit.get_balance("KRW"))
    for coin_balance in my_balances:
        # 코인이름(티커)
        ticker = coin_balance['currency']
        
        # 해당하는 티커 무시
        if ticker in ["KRW", "APENFT"]:
            continue
        
        # 마켓에서 거래되고 있는 코인 현재가격
        now_price = pyupbit.get_current_price("KRW-" + ticker)
        print(ticker, "보유잔고: ", coin_balance['balance'])
        print("평균매입단가|현재마켓거래가: ", coin_balance['avg_buy_price'], "|", now_price)
        
        # 매수평균가
        avg_price = float(coin_balance['avg_buy_price'])
        
        # 수익률 = (현재가격 - 매수평균가) / 매수평균가 * 100.0 
        revenu_rate = (now_price - avg_price) / avg_price * 100.0
        print("수익률: ", revenu_rate, "%") 
        print()
        print()

# RSI지표 수치를 구해준다. 첫번째: 분봉/일봉 정보, 두번째: 기간
# 정해진 숫자기간동안에서 전일대비 상승분의 평균/(전일대비 상승분의 평균+하락분의 평균)
#아래 함수안의 내용은 참고로만 보세요! 제가 말씀드렸죠? 검증된 함수니 안의 내용 몰라도 그냥 가져다 쓰기만 하면 끝!
#RSI지표 수치를 구해준다. 첫번째: 분봉/일봉 정보, 두번째: 기간, 세번째: 기준 날짜
def GetRSI(ohlcv,period,st):
    #이 안의 내용이 어려우시죠? 넘어가셔도 되요. 우리는 이 함수가 RSI지표를 정확히 구해준다는 것만 알면 됩니다.
    ohlcv["close"] = ohlcv["close"]
    delta = ohlcv["close"].diff()
    up, down = delta.copy(), delta.copy()
    up[up < 0] = 0
    down[down > 0] = 0
    _gain = up.ewm(com=(period - 1), min_periods=period).mean()
    _loss = down.abs().ewm(com=(period - 1), min_periods=period).mean()
    RS = _gain / _loss
    return float(pd.Series(100 - (100 / (1 + RS)), name="RSI").iloc[st])

# 거래대금이 많은 순으로 리스트 얻는다. 첫번쨰: 기간(분봉)(day, week, minute15...), 두번째: 몇개까지
def GetTopCoinList(interval, top):
    # print("------------GetTopCoinList Start------------")
    # 원화 마켓 정보만 가져옴
    Tickers = pyupbit.get_tickers("KRW")
    # 거래대금 저장 딕셔너리
    dic_coin_money = dict()
    # Top 10만 저장 딕셔너리
    coin_list = list()
    # top10만 가져오겠다
    # Top 10 을 위한 카운트 변수
    cnt = 0

    # print(f"top{top} coin seaeching....")
    # 거래대금을 딕셔너리에 저장
    for ticker in Tickers:
        try:
            df = pyupbit.get_ohlcv(ticker, interval) # 모든 코인의 분봉정보 가져옴?
            # 거래대금 = volume(거래량)*그날의 종가 => 엄밀하게 거래대금은 아니지만 우리는 이 방식으로 
            # 진행중인 거래대금 + 어제의 거래대금 -> 최근에 거래량 많은거 알 수 있음
            volume_money = (df['close'][-1]* df['volume'][-1])+(df['close'][-2]* df['volume'][-2])
            
            # 거래대금 정보 저장
            dic_coin_money[ticker] = volume_money
            #print(ticker, dic_coin_money[ticker])
            #print("코인티커: ",ticker)
            time.sleep(0.1)
            
        except Exception as e:
            print("exception:", e)
    # 큰 거래대금부터 정렬 -> 결과값: 튜플 리스트
    dic_sorted_coin_money = sorted(dic_coin_money.items(), key=lambda x: x[1], reverse=True)


    # top 10만 리스트에 저장하자
    for coin_data in dic_sorted_coin_money:
        cnt +=1
        if cnt <=top:
            coin_list.append(coin_data[0])
        else:
            break

    print("------------GetTopCoinList End  ------------")
    return coin_list

# 해당되는 리스트안에 해당 코인이 있는지 여부를 리턴하는 함수
def CheckCoinInList(CoinList,Ticker):
    InCoinOk = False

    #리스트안에 해당 코인이 있는지 체크합니다.
    for coinTicker in CoinList:
        #있으면 True로!!
        if coinTicker == Ticker:
            InCoinOk = True
            break

    return InCoinOk

#티커에 해당하는 코인의 수익율을 구해서 리턴하는 함수.
def GetRevenueRate(balances,Ticker):
    revenue_rate = 0.0
    for value in balances:
        try:
            realTicker = value['unit_currency'] + "-" + value['currency']
            if Ticker == realTicker:
                time.sleep(0.05)
                
                #현재 가격을 가져옵니다.
                nowPrice = pyupbit.get_current_price(realTicker)

                #수익율을 구해서 넣어줍니다
                revenue_rate = (float(nowPrice) - float(value['avg_buy_price'])) * 100.0 / float(value['avg_buy_price'])
                break

        except Exception as e:
            print("GetRevenueRate error:", e)
    # 매수 진행하지 않은 데이터는 0.0취급
    return revenue_rate

#티커에 해당하는 코인의 총 매수금액을 리턴하는 함수
def GetCoinNowMoney(balances,Ticker):
    CoinMoney = 0.0
    for value in balances:
        realTicker = value['unit_currency'] + "-" + value['currency']
        if Ticker == realTicker:
            #해당 코인을 지정가 매도를 걸어놓으면 그 수량이 locked에 잡히게 됩니다. 
            #만약 전체 수량을 지정가 매도를 걸었다면 balance에 있던 잔고가 모두 locked로 이동하는 거죠
            #따라서 총 코인 매수 금액을 구하려면 balance + locked를 해줘야 합니다.
            CoinMoney = float(value['avg_buy_price']) * (float(value['balance']) + float(value['locked']))
            break
    return CoinMoney

#티커에 해당하는 코인이 매수된 상태면 참을 리턴하는함수
def IsHasCoin(balances,Ticker):
    HasCoin = False
    for value in balances:
        realTicker = value['unit_currency'] + "-" + value['currency']
        if Ticker == realTicker:
            HasCoin = True
    return HasCoin

#내가 매수한 (가지고 있는) 코인 개수를 리턴하는 함수
def GetHasCoinCnt(balances):
    CoinCnt = 0
    for value in balances:
        avg_buy_price = float(value['avg_buy_price'])
        if avg_buy_price != 0: #원화, 드랍받은 코인(평균매입단가가 0이다) 제외!  
            CoinCnt += 1
    return CoinCnt

#총 원금을 구한다! => 원화 + 매수한코인(잔고*평균매입단가)
def GetTotalMoney(balances):
    total = 0.0
    for value in balances:
        try:
            ticker = value['currency']
            if ticker == "KRW": #원화일 때는 평균 매입 단가가 0이므로 구분해서 총 평가금액을 구한다.
                total += (float(value['balance']) + float(value['locked']))
            else:
                avg_buy_price = float(value['avg_buy_price'])

                #매수평균가(avg_buy_price)가 있으면서 잔고가 0이 아닌 코인들의 총 매수가격을 더해줍니다.
                if avg_buy_price != 0 and (float(value['balance']) != 0 or float(value['locked']) != 0):
                    #balance(잔고 수량) + locked(지정가 매도로 걸어둔 수량) 이렇게 해야 제대로 된 값이 구해집니다.
                    #지정가 매도 주문이 없다면 balance에 코인 수량이 100% 있지만 지정가 매도 주문을 걸면 그 수량만큼이 locked로 옮겨지기 때문입니다.
                    total += (avg_buy_price * (float(value['balance']) + float(value['locked'])))
        except Exception as e:
            print("GetTotalMoney error:", e)
    return total

#총 평가금액을 구한다! 
#위 원금을 구하는 함수와 유사하지만 코인의 매수 평균가가 아니라 현재 평가가격 기준으로 총 평가 금액을 구한다.
def GetTotalRealMoney(balances):
    total = 0.0
    for value in balances:

        try:
            ticker = value['currency']
            if ticker == "KRW": #원화일 때는 평균 매입 단가가 0이므로 구분해서 총 평가금액을 구한다.
                total += (float(value['balance']) + float(value['locked']))
            else:
            
                avg_buy_price = float(value['avg_buy_price'])
                if avg_buy_price != 0 and (float(value['balance']) != 0 or float(value['locked']) != 0): #드랍받은 코인(평균매입단가가 0이다) 제외 하고 현재가격으로 평가금액을 구한다,.
                    realTicker = value['unit_currency'] + "-" + value['currency']

                    time.sleep(0.1)
                    nowPrice = pyupbit.get_current_price(realTicker)
                    total += (float(nowPrice) * (float(value['balance']) + float(value['locked'])))
        except Exception as e:
            print("GetTotalRealMoney error:", e)


    return total


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
print("-----------------------------------------------")
for i in TopCoinList:
    print(i)
print("-----------------------------------------------")

