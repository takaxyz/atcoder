A,B=gets.chomp.split.map(&:to_i).sort
puts A==B ? 2*B : 2*B-1
