N=gets.to_i
a=gets.chomp.split.map(&:to_i)
0.upto(N-1) { |i| a[i] = [a[i], i+1]}
a.sort!.reverse!
a.each {|v| puts v[1]}