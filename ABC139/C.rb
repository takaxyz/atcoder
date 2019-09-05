N=gets.to_i
H=gets.chomp.split.map(&:to_i).reverse
ans=0
t=0
1.upto(N-1) do |i|
  if H[i-1] <= H[i]
    t+=1
  else
    ans = t if ans < t
    t = 0
  end
end
ans = t if ans < t

puts ans
