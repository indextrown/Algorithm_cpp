def solution(N, stages): # 스태에지개수, 현재 멈춰 있는 스테이지 번호가 담긴 배열
    # 실패울이 높은 스테이지부터 내림차순으로 스테이지 번호가 담겨 있는 배열을 반환하라
    li = [0]*(N+2) # 스테이지 번호, 스테이지에 들어간 사람
    fail = {}
    remaining_player = len(stages)      # 전체 플레이어 수 = 아직 클리어 못한 플레이어수

    for stage in stages:
        li[stage]+=1
    
    for idx in range(1, N+1):
        if remaining_player == 0:
            fail[idx] = 0
        else:
            fail[idx] = li[idx]/remaining_player
        remaining_player -= li[idx]
    result = sorted(fail, key=fail.get, reverse=True)
    return result

if __name__ == "__main__":
    N = 5
    stages = [2,1,2,6,2,4,3,3]
    print(solution(N, stages))

