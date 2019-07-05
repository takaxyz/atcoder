N=gets.to_i
x=gets.chomp.split.map(&:to_i).sort

ans = 0
0.upto(N-2) do |i|
  ans += (x[i+1] - x[i]) * (i+1) * (N-1-i)
end
puts ans