N,x=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i)
m=a.index(a.min)
b=[]
m.upto(N-1) {|i| b << a[i] }
0.upto(m-1) {|i| b << a[i] }
bs = [0]
b.each do |v|
  bs << bs[-1] + v
end

1.upto(N-1) do |i|
  b[i] = b[i-1] + x if b[i] > b[i-1] + x
end
p b