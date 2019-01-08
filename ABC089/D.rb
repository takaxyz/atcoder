H,W,D=gets.chomp.split.map(&:to_i)
p = Array.new(H*W+1)
H.times do |i|
  gets.chomp.split.map(&:to_i).each_with_index do |v,j|
    p[v] = [i,j]
  end
end

d = [0] * (D+1)
(D+1).upto(H*W) do |i|
  d[i] = d[i-D] + (p[i][0] - p[i-D][0]).abs + (p[i][1] - p[i-D][1]).abs
end

Q=gets.to_i
Q.times do
  l,r = gets.chomp.split.map(&:to_i)
  puts d[r] - d[l]
end
