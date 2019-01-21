N,K=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i)

dp=Array.new(N+1).map{Array.new(K+1,0)}

MOD=1000000007

dp[0][0] = 1

csum = Array.new(K+1)
1.upto(N) do |i|
  csum[0] = dp[i-1][0]
  1.upto(K) {|j| csum[j] = (csum[j-1]+dp[i-1][j]) % MOD }
  0.upto(K) do |j|
    if j-a[i-1]-1 >= 0
      dp[i][j] = csum[j] - csum[j-a[i-1]-1]   
    else
      dp[i][j] = csum[j]
    end
    dp[i][j] %= MOD
  end
end

puts dp[N][K]

