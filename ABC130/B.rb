n,x=gets.chomp.split.map(&:to_i)
l=gets.chomp.split.map(&:to_i)
d=0
ans=1
n.times do |i|
  d+=l[i]
  ans += 1 if d <= x
end
puts ans