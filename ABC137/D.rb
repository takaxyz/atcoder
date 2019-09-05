n,m=gets.chomp.split.map(&:to_i)
ba=[]
n.times do
  a,b=gets.chomp.split.map(&:to_i)
  ba << [b,a]
end
ba.sort! {|a, b| (a[0] <=> b[0]).nonzero? || (a[1] <=> b[1])}
ba.reverse!
ans=0
d=0
ba.each do |b,a|
  if a+d <= m
    ans+=b
    d+=1
  end
end
puts ans