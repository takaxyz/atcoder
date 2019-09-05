N=gets.to_i
a=gets.chomp.split.map(&:to_i)
b=gets.chomp.split.map(&:to_i)
ans=0
0.upto(N-1) do |i|
  if a[i] <= b[i]
    ans+=a[i]
    b[i]-=a[i]
    a[i]=0
    if a[i+1] <= b[i]
      ans+=a[i+1]
      b[i]-=a[i+1]
      a[i+1]=0
    else
      ans+=b[i]
      a[i+1]-=b[i]
      b[i]=0
    end
  else
    ans+=b[i]
    a[i]-=b[i]
    b[i]=0
  end
end
puts ans