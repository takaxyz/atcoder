S=gets.chomp
N=gets.to_i
puts S[(N-1)/5] + S[(N-1)%5]
