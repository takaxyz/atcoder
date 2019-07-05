S=gets.chomp.split("")
ans=1
prev=S[0]
1.upto(S.size-1) do |i|
  next if prev < S[i]
  prev = S[i]
  ans+=1
end
puts ans