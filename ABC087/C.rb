N=gets.to_i
a1=[0] + gets.chomp.split.map(&:to_i)
a2=[0] + gets.chomp.split.map(&:to_i)

csum1=[0]
csum2=[0]
1.upto(N) {|i| csum1[i] = csum1[i-1] + a1[i]}
1.upto(N) {|i| csum2[i] = csum2[i-1] + a2[i]}

ans = -1
1.upto(N) do |i|
  t = csum1[i] + csum2[N] - csum2[i-1]
  ans = t if t > ans
end
puts ans