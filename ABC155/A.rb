a=gets.chomp.split.map(&:to_i)
h={}
a.each do |v|
  h[v]=1
end
puts h.size==2 ? "Yes" : "No"
