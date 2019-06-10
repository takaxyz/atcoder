N=gets.to_i
v=gets.chomp.split.map(&:to_i)
c=gets.chomp.split.map(&:to_i)
t=[]
N.times do |i|
  t << v[i]-c[i]
end
t.sort!.reverse!
ans=0
t.each do |n|
 break if n <= 0
 ans+=n
end
puts ans
