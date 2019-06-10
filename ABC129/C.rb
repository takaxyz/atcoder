n,m=gets.chomp.split.map(&:to_i)
MOD=1000000007
a=[]
m.times do
  a << gets.to_i
end
if a.size > 0 and a[0] == 1
  dp=[1,0]
  j=1
else
  dp=[1,1]
  j=0
end
2.upto(n) do |i|
  if j < a.size and a[j] == i
    dp[i] = 0
    j += 1
  else
    dp[i] = (dp[i-1] + dp[i-2]) % MOD
  end
end
p dp[n]
