N,M=gets.chomp.split.map(&:to_i)
r=gets.chomp.split.map(&:to_i)
lg = [0.0]

1.upto(N) do |i|
  lg << lg[-1] + Math.log10(i)
end

ans = N*Math.log10(M)
r.each do |v|
  ans += lg[v]
end

ans -= lg[N]
puts ans.ceil 