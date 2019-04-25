A,B=gets.chomp.split.map(&:to_i).sort
puts [2*B-1, A+B].max
