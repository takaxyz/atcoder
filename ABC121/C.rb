n,m=gets.chomp.split.map(&:to_i)
a=[]
b=Hash.new(0)
n.times do
  aa,bb=gets.chomp.split.map(&:to_i)
  a << aa
  b[aa] += bb
end
a.sort!
a.uniq!
ans = 0
a.each do |v|
  if m <= b[v]
    ans += m * v
    puts ans
    exit
  end
  ans += v * b[v]
  m -= b[v]
end
puts ans


