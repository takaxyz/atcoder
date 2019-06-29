N,L=gets.chomp.split.map(&:to_i)
m = Float::INFINITY
N.times do |i|
  m = L + i if (L + i).abs < m.abs
end
puts N*(2*L+N-1)/2-m