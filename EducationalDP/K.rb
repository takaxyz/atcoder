N,K=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i)
dp=Array.new(K+1,false)

a[0].upto(K) do |i|
  a.each do |v|
    break if i - v < 0
    if dp[i - v] == false
      dp[i] = true
      break
    end
  end
end

puts dp[K] ? "First" : "Second"