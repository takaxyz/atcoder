N=gets.to_i
a=gets.chomp.split.map(&:to_i)
a.unshift(-1)
b=Array.new(N+1)
N.downto(1) do |i|
  j=i*2
  t=0
  while(j<=N) do
    t+=b[j]
    j += i
  end
  t %= 2
  b[i] = (t+a[i])%2
end
ans=[]
1.upto(N) do |i|
  ans << i if b[i] == 1
end
puts ans.size
puts ans.join(' ') if ans.size > 0