def gcd(a,b)
  return a if b == 0
  gcd(b,a%b)
end

N=gets.to_i
a=gets.chomp.split.map(&:to_i)
l=[0]
r=[0]
a.each_with_index do |v|
  l << gcd(v,l[-1])
end

a.reverse.each_with_index do |v|
  r << gcd(v,r[-1])
end

ans=0
0.upto(N) do |i|
  tmp = gcd(l[i],r[N-1-i])
  ans = tmp if ans < tmp
end
puts ans
