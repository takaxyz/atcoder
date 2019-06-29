N=gets.to_i
v=gets.chomp.split.map(&:to_i)
c=gets.chomp.split.map(&:to_i)
ans=0
N.times do |i|
  ans += v[i]-c[i] if v[i]-c[i] > 0
end
puts ans
