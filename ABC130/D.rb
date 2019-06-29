n,k=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i)
r=0

sum=0
ans=0

0.upto(n-1) do |l|
  while(sum<k && r<n) do
    sum+=a[r]
    r+=1
  end

  if sum < k
    break
  else
    ans+=n-r+1
    sum-=a[l]
  end
end

puts ans