N=gets.to_i
c=[]
N.times{ c << gets.to_i }
lis=Array.new(N+1,Float::INFINITY)
c.each_with_index do |v,i|
  l=1
  r=N
  mid=(l+r)/2
  while(l<=r)
    if(v < lis[mid])
      r = mid-1
    elsif(v > lis[mid])
      l = mid+1
    else

    end
    mid=(l+r)/2
  end
  lis[l] = v
#  printf("%d %d\n",l,r)
end
ans = N
N.downto(1) do |i|
  if lis[i] != Float::INFINITY
    puts N - i
    exit
  end
end
