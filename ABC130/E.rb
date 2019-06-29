n,m=gets.chomp.split.map(&:to_i)
s=gets.chomp.split.map(&:to_i)
t=gets.chomp.split.map(&:to_i)
MOD=10**9+7

dp=Array.new(n+1).map{Array.new(m+1,0)}
sum=Array.new(n+1).map{Array.new(m+1,0)}


1.upto(n) do |i|
  1.upto(m) do |j|
    if s[i-1] == t[j-1]
      dp[i][j]=(sum[i-1][j-1] + 1)%MOD
    else
      dp[i][j]=0
    end
    sum[i][j] = (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j])%MOD
  end
end
puts (sum[n][m] + 1)%MOD
