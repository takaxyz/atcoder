n, a, b = map(int, input().split())

ans=0
for i in range(1, n+1):
  s=0
  x=i
  while(x>0):
    s += x % 10
    x //= 10
  if a <= s and s <= b:
    ans+=i

print(ans)
