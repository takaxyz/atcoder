n,m=gets.chomp.split.map(&:to_i)
k = []
s = []
flag = [0,1,2,4,8,16,32,64,128,256,512]
m.times do
  ks = gets.chomp.split.map(&:to_i)
  k << ks[0]
  s << ks[1,ks.size-1]
end
p = gets.chomp.split.map(&:to_i)
ans = 0
0.upto(2**n-1) do |i|
  c = 0
  0.upto(m-1) do |j|
    c_on = 0
    s[j].each do |k|
      c_on += 1 if i & flag[k] == flag[k]
    end
    if c_on % 2 == p[j]
      c += 1
    else
    end
  end
  ans += 1 if c == m
end
puts ans