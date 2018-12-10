N,K=gets.chomp.split.map(&:to_i)
h = []
N.times {h << gets.to_i}
h.sort!
ans = Float::INFINITY
0.upto(N-K) do |i|
    ans = h[i+K-1] - h[i] if h[i+K-1] - h[i] < ans 
end
puts ans