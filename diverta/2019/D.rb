N=gets.to_i
ans = 0
1.upto(Math.sqrt(N)) do |i|
  next if N%i != 0
  if i>1 && N % (i-1) == N / (i-1)
    ans += i-1
  end
  j = N/i
  if j > 1 && N % (j-1) == N / (j-1)
    ans += j-1
  end
end
puts ans