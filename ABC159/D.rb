N=gets.to_i
h=Hash.new(0)
a=gets.chomp.split.map(&:to_i)
a.each do |v|
  h[v] += 1
end

ans=0
h.each do |k,v|
  ans += v*(v-1)/2
end

a.each do |v|
  puts ans - h[v]*(h[v]-1)/2 + (h[v]-1)*(h[v]-2)/2 
end