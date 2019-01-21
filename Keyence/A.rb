N=gets.chomp.split.map(&:to_i)
puts N.include?(1) && N.include?(9) && N.include?(7) && N.include?(4) ? "YES" : "NO"