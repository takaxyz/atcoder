n,m=gets.chomp.split.map(&:to_i)
a=gets.chomp.split.map(&:to_i).sort
bc=[]
m.times do 
  b,c=gets.chomp.split.map(&:to_i)
  bc << [c,b]
end
bc.sort!
bc.reverse!
ans=a.inject(:+)
#puts ans
i=0
bc.each do |c,b|
  break if i == n
  break if a[i] > c
  b.times do
    if a[i] < c
      ans+=c-a[i]
      i+=1
      break if i == n
    else
      break
    end
  end
end
puts ans