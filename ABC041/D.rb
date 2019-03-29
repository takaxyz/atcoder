N, M=gets.chomp.split.map(&:to_i)
def hoge(n)
  ret = []
  1.upto(N) do |i|
    ret << i if (1 << i) & n == (1 << i)
  end
  ret
end

b = Array.new(N,0)
M.times do
  x,y=gets.chomp.split.map(&:to_i)
  b[x-1] |= 1<<(y-1)
end
dp = Array.new(1<<N,0)
dp[0]=1

0.upto((1<<N) - 1) do |i|
  0.upto(N-1) do |j|
    t = 1<<j
    if (i & t) == 0 and (b[j] & i) == 0
      dp[i|t] += dp[i]
    end
  end
end

puts dp[-1]