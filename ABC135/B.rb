N=gets.to_i
t=0
gets.chomp.split.map(&:to_i).each_with_index do |v,i|
  t += 1 if v != i+1
end
puts t<=2 ? "YES" : "NO"
