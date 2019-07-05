N=gets.to_i
p=gets.chomp.split.map(&:to_i)
ans=0
1.upto(N-2) do |i|
  if (p[i-1] < p[i] && p[i] < p[i+1]) || (p[i-1] > p[i] && p[i] > p[i+1]) then
    ans+=1
  end
end
puts ans