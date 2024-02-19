def solution(N, stages): # 스태에지개수, 현재 멈춰 있는 스테이지 번호가 담긴 배열
    # 실패울이 높은 스테이지부터 내림차순으로 스테이지 번호가 담겨 있는 배열을 반환하라
    li = [0]*(N+2) # 스테이지 번호, 스테이지에 들어간 사람
    fail = {}

    for stage in stages:
        li[stage]+=1
    
    for idx, people in enumerate(li):
        if idx == N+1 or idx == 0:  # 스테이지번호가 성공한 사람이거나 0이면 제외
            continue
        A = people # 스테이지에 도달했으니 아직 클리어 못한 플레이어 수
        B = len([i for i in stages if i >= idx]) # 스테이지에 도달한 플레이어수
        if A == 0:
            fail[idx] = 0
        else:
            fail[idx] = A/B

    result = sorted(fail, key=fail.get, reverse=True)
    return result

if __name__ == "__main__":
    N = 5
    stages = [2,1,2,6,2,4,3,3]
    # stages = [4,4,4,4,4]
    print(solution(N, stages))