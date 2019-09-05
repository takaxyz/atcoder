n,m=gets.chomp.split.map(&:to_i)
x=gets.chomp.split.map(&:to_i).sort
y=gets.chomp.split.map(&:to_i).sort

MOD=10**9+7
s=0
1.upto(n) do |i|
  s += -(n-i)*x[i-1] + (i-1) * x[i-1]
  s %= MOD
end
t=0
1.upto(m) do |i|
  t += -(m-i)*y[i-1] + (i-1) * y[i-1]
  t %= MOD
end
puts s*t%MOD
