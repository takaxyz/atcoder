S=gets.chomp.split("")
T=gets.chomp.split("")
ans=0
0.upto(2) do |i|
  ans += 1 if S[i] == T[i]
end
puts ans