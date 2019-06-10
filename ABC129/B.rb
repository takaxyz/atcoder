n=gets.to_i
w=gets.chomp.split.map(&:to_i)
w1=w[0]
w2=w[1,n-1].inject(:+)
ans=(w1-w2).abs
1.upto(n-2) do |i|
  w1 += w[i]
  w2 -= w[i]
  ans=(w1-w2).abs if ans > (w1-w2).abs
end
puts ans