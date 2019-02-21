N,M=gets.chomp.split.map(&:to_i)
NUM=[0,2,5,5,4,5,6,3,7,6]
A = gets.chomp.split.map(&:to_i).sort.reverse

dp = Array.new(N+1, -Float::INFINITY)
dp[0] = 0
1.upto(N) do |i|
  A.each do |a|
    if i - NUM[a] >= 0
      if dp[i] < dp[i - NUM[a]] + 1
        dp[i] = dp[i - NUM[a]] + 1
      end
    end
  end
end

n = N
ans = []
while(n > 0)
  A.each do |a|
    next if n - NUM[a] < 0
    if dp[n - NUM[a]] == dp[n] - 1
      n -= NUM[a]
      ans << a
      break
    end
  end
end

puts ans.map(&:to_s).join