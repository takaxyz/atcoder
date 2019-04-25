N=gets.to_i
S=gets.chomp.split("")
b=[0]
w=[0]
0.upto(N-1) do |i|
  if S[i] == "#"
    b << b[-1]+1
  else
    b << b[-1]
  end
end
(N-1).downto(0) do |i|
  if S[i] == "."
    w << w[-1]+1
  else
    w << w[-1]
  end
end
w.reverse!
ans = 10**6
0.upto(N) do |i|
  ans = b[i] + w[i] if b[i] + w[i] < ans
end
puts ans