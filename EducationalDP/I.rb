N=gets.to_i
p=gets.chomp.split.map(&:to_f)

dp = Array.new(N+1).map{Array.new(N+1,0.0)}
dp[0][0] = 1.0

p.each_with_index do |v, i|
  dp[i+1][0] = dp[i][0] * (1-p[i])
  1.upto(i+1) do |j|
    dp[i+1][j] = dp[i][j-1] * (p[i]) + dp[i][j] * (1-p[i])
  end
end

ans = 0.0
(N/2+1).upto(N) do |i|
  ans += dp[N][i]
end
puts ans