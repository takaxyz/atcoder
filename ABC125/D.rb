N=gets.to_i
A=gets.chomp.split.map(&:to_i)
m_cnt=0
sum=0
min=Float::INFINITY
A.each do |a|
  if a < 0
    m_cnt += 1
  end
  if min > a.abs
    min = a.abs
  end
  sum+=a.abs
end
if m_cnt.even?
  puts sum
else
  puts sum - 2 * min
end