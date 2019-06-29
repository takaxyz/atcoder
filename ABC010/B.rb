n=gets.to_i
t=[0,0,1,0,1,2,3,0,1,0]
ans=0
gets.chomp.split.map(&:to_i).each do |i|
  ans += t[i]
end
puts ans
