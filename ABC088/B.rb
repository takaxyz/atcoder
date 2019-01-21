gets
a=gets.chomp.split.map(&:to_i).sort.reverse
ans=0
a.each_with_index do |v, i|
  ans += i.even? ? v : -v
end
puts ans
