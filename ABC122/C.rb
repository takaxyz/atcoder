N,Q=gets.chomp.split.map(&:to_i)
S=gets.chomp
csum = [0,0]
0.upto(N-2) do |i|
  if S[i,2] == 'AC'
    csum[i+2] = csum[i+1] + 1
  else
    csum[i+2] = csum[i+1]    
  end
end

Q.times do
  l,r=gets.chomp.split.map(&:to_i)
  puts csum[r]-csum[l]
end