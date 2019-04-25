X,Y,Z,K=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i)
b=gets.chomp.split.map(&:to_i)
c=gets.chomp.split.map(&:to_i)

ab = []
a.each_with_index do |m, i|
  next if i >= K
  b.each_with_index do |n, j|
    next if j >= K
    ab << m+n
  end
end

ab.sort!.reverse!

abc = []
ab.each_with_index do |m, i|
  next if i >= K
  c.each_with_index do |n, j|
    next if j >= K
    abc << m+n
  end
end

abc.sort!.reverse!

0.upto(K-1) do |i|
  puts abc[i]
end

