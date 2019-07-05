N=100
h=Hash.new(0)
1.upto(Math.sqrt(N)) do |i|
  h[N/i] += 1
end
p h
p h.size