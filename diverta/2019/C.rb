N=gets.to_i
ans=0
c1,c2,c3,c4=0,0,0,0
N.times do
  s=gets.chomp
  ans += s.scan(/AB/).size
  if s.match(/^B.*A$/)
    c1+=1
  elsif s.match(/A$/)
    c2+=1
  elsif s.match(/^B/)
    c3+=1
  else
    c4+=1
  end
end

if c2>0 || c3>0
  ans += [c2,c3].min + c1
elsif c1>0
  ans+=c1-1
end
puts ans
