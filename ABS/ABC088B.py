n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
alice,bob=0,0


for i, x in enumerate(a):
  if i % 2 == 0:
    alice += x
  else:
    bob += x

print(alice - bob)
