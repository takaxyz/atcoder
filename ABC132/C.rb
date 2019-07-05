N=gets.to_i
d=gets.chomp.split.map(&:to_i).sort

puts d[N/2] - d[N/2-1]
