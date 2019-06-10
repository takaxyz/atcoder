r,d,x=gets.chomp.split.map(&:to_i)
10.times do
  x=r*x-d
  puts x
end
