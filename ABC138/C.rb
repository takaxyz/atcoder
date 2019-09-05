N=gets.to_i
v=gets.chomp.split.map(&:to_i).sort
t=v[0].to_f
1.upto(N-1) do |i|
  t=(t+v[i])/2.0
end
puts t