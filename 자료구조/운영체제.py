cur_time = 0
idle_time = 0
process = []

with open('multi.inp', 'r') as file:
    for line in file.readlines()[1:]:
        process_data = list(map(int, line.split()))[:-1]
        process.append({'q': process_data, 'io_fin_at': 0})
print(process)

# 프로세스 목록에서 처리할 작업(`q`)이 남아있는 프로세스가 있는 동안 계속 실행
while any(len(p['q']) > 0 for p in process):
    idx = next((i for i, p in enumerate(process) if len(p['q']) > 0 and p['io_fin_at'] <= cur_time), -1)

    if idx == -1:
        next_times = [p['io_fin_at'] for p in process if len(p['q']) > 0]
        if next_times:
            move_to = min(next_times)
            idle_time += move_to - cur_time
            cur_time = move_to
    else:
        # 이 부분이 `if idx == -1`의 else가 아니라, while 루프 내에 직접 위치해야 합니다.
        p = process[idx]
        cur_time += p['q'].pop(0)
        if p['q']:
            p['io_fin_at'] = cur_time + p['q'].pop(0)

# 모든 프로세스가 완료된 후 현재 시간 업데이트
if any(p['io_fin_at'] > cur_time for p in process):
    cur_time = max(p['io_fin_at'] for p in process)

print(idle_time, cur_time)
