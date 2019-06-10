n,m=gets.chomp.split.map(&:to_i)
s=Array.new(n+2,0)
m.times do
  l,r=gets.chomp.split.map(&:to_i)
  s[l]+=1
  s[r+1]-=1
end
1.upto(n+1) do |i|
  s[i] += s[i-1]
end 
puts s.count(m)
