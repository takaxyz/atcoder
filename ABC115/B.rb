N=gets.to_i
p = []
N.times {p << gets.to_i}
p.sort!
p[-1]=p[-1]/2
puts p.inject(:+)