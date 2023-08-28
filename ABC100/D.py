n,m = map(int, input().split())

xyz = [list(map(int, input().split())) for _ in range(n)]

ans=0
for i in range(2**3) :
  arr = [0] * n
  for j in range(n): 
    for k in range(3):
      if (i >> k) & 1 :
        arr[j] += xyz[j][k]
      else:
        arr[j] -= xyz[j][k]
  arr.sort(reverse=True)

  ans = max(ans, sum(arr[:m]))

print(ans)