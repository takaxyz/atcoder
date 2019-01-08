N=gets.to_i
h=Hash.new(0)
N.times do
  s = gets.chomp
  h[s[0]] += 1 if s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H'
end

ans = 0
h.values.combination(3) do |l,m,n|
  ans += l*m*n
end
puts ans
