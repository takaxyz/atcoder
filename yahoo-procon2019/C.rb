k,a,b=gets.chomp.split.map(&:to_i)
ans=0
if b-a>2
  if k>=a-1
    ans = a
    k -= a-1
    ans += (b-a) * (k/2)
    ans += 1 if k.odd?
  else
    ans = 1+k
  end
else
  ans = 1+k
end
puts ans