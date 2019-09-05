a,b=gets.chomp.split.map(&:to_i).sort
puts (b-a).even? ? (b-a)/2+a : "IMPOSSIBLE"
  
