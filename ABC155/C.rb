n=gets.to_i

h=Hash.new(0)
n.times do
  h[gets.chomp]+=1
end

prev=nil
h.to_a.sort {|a, b| (a[1] <=> b[1]).nonzero? || (b[0] <=> a[0])}.reverse.each do |a,b|
  prev = b if prev == nil

  break if b != prev

  puts a
end
 