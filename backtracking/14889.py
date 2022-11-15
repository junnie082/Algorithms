import sys
N = int(sys.stdin.readline())
_map = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
visited = [False] * N
result = []
_min = 1e9

def diff():
    _start = 0
    _link = 0
    # 오름차순 비교 for문으로 시간 절약
    for i in range(N - 1):
        for j in range(i + 1, N):
            # True 인 경우 _start 팀
            if visited[i] and visited[j]:
                _start += _map[i][j]   # S(i, j)
                _start += _map[j][i]   # S(j, i)
            # False 인 경우 _link 팀
            elif not visited[i] and not visited[j]:
                _link += _map[i][j]
                _link += _map[j][i]
    return abs(_start - _link)
 
def dfs(depth, idx, N):
    global _min
    if depth == N // 2:   # 절반만 선택
        diff_result = diff()
        _min = min(_min, diff_result)
        if _min == 0:  # 0 이면 바로 출력
            print(_min)
            exit(0)
        return
    for i in range(idx, N):
        if not visited[i]:
            visited[i] = True
            dfs(depth + 1, i + 1, N)
            visited[i] = False
    return

dfs(0, 0, N)
print(_min)
