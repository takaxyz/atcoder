T=gets.chomp.split("")
t = T.clone
ans=0
1.upto(t.size-1) do |i|
  if t[i-1] == '2' && t[i] == '5'
    ans+=2
  elsif t[i-1] == '2' && t[i] == '?'
    t[i] = '5'
    ans+=2
  elsif t[i-1] == '?' && t[i] == '5'
    t[i-1] = '2'
    ans+=2
  elsif t[i-1] == '?' && t[i] == '?'
    t[i-1] = '2'
    t[i] = '5'
    ans+=2
  end
end
ans1=ans
ans=0
t = T.clone
2.upto(t.size-1) do |i|
  if t[i-1] == '2' && t[i] == '5'
    ans+=2
  elsif t[i-1] == '2' && t[i] == '?'
    t[i] = '5'
    ans+=2
  elsif t[i-1] == '?' && t[i] == '5'
    t[i-1] = '2'
    ans+=2
  elsif t[i-1] == '?' && t[i] == '?'
    t[i-1] = '2'
    t[i] = '5'
    ans+=2
  end
end
#p t
puts [ans1,ans].max