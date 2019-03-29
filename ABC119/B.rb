BTC=380000
N=gets.to_i
ans = 0.0
N.times do
  x,u=gets.chomp.split
  ans += u == 'JPY' ? x.to_i : x.to_f * BTC
end
puts ans