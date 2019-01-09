N,K=gets.chomp.split.map(&:to_i)
h=gets.chomp.split.map(&:to_i)

dp = Array.new(N)
dp[0] = 0
1.upto(N-1) do |i|
  arr = []
  1.upto(K) do |j|
    break if i-j < 0
    arr << dp[i-j] + (h[i] - h[i-j]).abs
  end
  dp[i] = arr.min
end

puts dp[N-1]