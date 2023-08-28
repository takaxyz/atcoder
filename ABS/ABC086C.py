n = int(input())

nx,ny,nt=0,0,0
for _ in range(n):
  t,x,y = map(int,input().split())
  
  d = abs(nx-x)+abs(ny-y)
  if t-nt < d or ((t-nt)%2) != (d%2):
    print("No")
    exit()
  nx,ny,nt=x,y,t

print("Yes")