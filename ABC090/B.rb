A,B = gets.chomp.split.map(&:to_i)
ans = 0
A.upto(B) do |i|
  ans+=1 if i.to_s == i.to_s.reverse
end
puts ans