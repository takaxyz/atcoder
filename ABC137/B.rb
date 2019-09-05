k,x=gets.chomp.split.map(&:to_i)
ans=[]
[x-k+1, -(10**6)].max.upto([x+k-1,10**6].min) do |i|
  ans << i
end
puts ans.join(" ")