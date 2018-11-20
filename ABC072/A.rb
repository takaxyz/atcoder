X, t = gets.chomp.split(" ").map(&:to_i)
puts [0, X - t].max
