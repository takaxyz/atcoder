a,b=gets.chomp.split
a = a.to_i

puts a * b.delete(".").to_i / 100

