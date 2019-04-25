N,Q=gets.chomp.split.map(&:to_i)
s=gets.chomp.split("")
t,d=[],[]
Q.times do
  tt,dd=gets.chomp.split
  t << tt
  d << dd
end

def out_l(s,t,d,pos)
  0.upto(t.size-1) do |i|
    if t[i] == s[pos]
      if d[i] == 'L'
        pos -= 1
      else
        pos += 1
      end
    end
    if pos < 0
      return true
    elsif pos >= s.size
      return false
    end
  end
  return false
end
def out_r(s,t,d,pos)
  0.upto(t.size-1) do |i|
    if t[i] == s[pos]
      if d[i] == 'L'
        pos -= 1
      else
        pos += 1
      end
    end
    if pos < 0
      return false
    elsif pos >= s.size
      return true
    end
  end
  return false
end

l = 0
r = N-1
mid = (l+r)/2

ans = N

while(l<=r)
  if out_l(s,t,d,mid)
    l = mid + 1
  else
    r = mid - 1
  end
  mid = (l+r)/2
end

#printf("%d %d %d\n",l,r,mid)

if l>=0
  ans -= l
end

l = 0
r = N-1
mid = (l+r)/2

while(l<=r)
  if out_r(s,t,d,mid)
    r = mid - 1
  else
    l = mid + 1
  end
  mid = (l+r)/2
end

#printf("%d %d %d\n",l,r,mid)
if l < N
  ans -= (N-l)
end

puts ans

