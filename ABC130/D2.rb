n,k=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i)
t=0
l,r=0,0
a.each_with_index do |v,i|
  t+=v
  if t>=k
    r=i
    break
  end
end

if r==0
  puts 0
  exit
end

ans=n-r
while(l<n) do
  t -= a[l]

  if t >=k
    ans+=n-r
  else
    while(r<n-1 && t<k) do
      r+=1
      t+=a[r]
    end

    if t<k
      puts ans
      exit  
    else
      ans += n-r
    end
  end

  l += 1
end
puts ans