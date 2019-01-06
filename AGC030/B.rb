L,N=gets.chomp.split.map(&:to_i)
x = []

N.times do 
  x << gets.to_i
end

ans = x[0]

0.upto(N-2) do |i|
  puts ans

  if i.even?
    ans += x[i/2] + L - x[N-1-i/2]
  else
    ans += L - x[N-1-i/2] + x[1+i/2]
  end
end

puts ans
 
