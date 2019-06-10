l=gets.chomp.split("").map(&:to_i)
MOD=10**9+7
dp=[1,2]
1.upto(l.size-1) do |i|
  if l[i] == 0
    dp[0] = (dp[0] * 3) % MOD
  else
    dp[0] = (dp[0] * 3 + dp[1]) % MOD
    dp[1] = (dp[1] * 2) % MOD
  end
end
puts (dp[0]+dp[1])%MOD