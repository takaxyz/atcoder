H,W=gets.chomp.split.map(&:to_i)
dp = Array.new(W+1,0)
MOD = 1000000007
dp[1] = 1
H.times do
  a = gets.chomp.split("")
  a.each_with_index do |c, i|
    if c == '#'
      dp[i+1] = 0
    else
      dp[i+1] += dp[i]
      dp[i+1] %= MOD
    end
  end
end
p dp[W]