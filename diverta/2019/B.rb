R,G,B,N=gets.chomp.split.map(&:to_i)
ans=0
0.upto(N/R) do |r|
  0.upto(N/G) do |g|
    next if N-r*R-g*G < 0
    if (N-r*R-g*G) % B == 0
      ans += 1
    end
  end
end
puts ans