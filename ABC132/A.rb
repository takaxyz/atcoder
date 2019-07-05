S=gets.chomp.split("")
h = Hash.new(0)
S.each do |v|
  h[v] += 1
end
if h.size == 2 and h[S[0]] == 2
  puts "Yes"
else
  puts "No"
end
