n=gets.to_i
a=gets.chomp.split.map(&:to_i)
t=0.0
a.each do |v|
  t += 1.0/v
end
puts 1.0/t
