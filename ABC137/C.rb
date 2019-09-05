N=gets.to_i
h=Hash.new(0)
N.times do
  s=gets.chomp.split("")
  h[s.sort.join("")]+=1
end

ans=0

h.each do |k,v|
  next if v == 1
  ans += v*(v-1)/2
end
puts ans