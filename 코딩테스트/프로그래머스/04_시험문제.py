# answers = [1,2,3,4,5]   # [5, 0, 0]

answers = [1,3,2,4,2] # [2, 2, 2]


def solution(answers):
    persons = [
        [1,2,3,4,5],
        [2,1,2,3,2,4,2,5],
        [3,3,1,1,2,2,4,4,5,5]
    ]
    count = [0] * len(persons)
    for idx, ans in enumerate(answers):
        for person, person_ans in enumerate(persons):
            if ans == person_ans[idx%len(person_ans)]:
                count[person] += 1

    high = []
    max_score = max(count)

    for idx, point in enumerate(count):
        if point == max_score:
            high.append(idx+1)
    return high


print(solution(answers))