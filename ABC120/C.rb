l=[]
s=gets.chomp.split("")
ans=0
s.each do |c|
  if l.size == 0 || l[-1] == c
    l << c
  else
    l.pop
    ans+=2
  end
end
puts ans