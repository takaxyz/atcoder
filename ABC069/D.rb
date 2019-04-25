H,W=gets.chomp.split.map(&:to_i)
N=gets.to_i
a=gets.chomp.split.map(&:to_i)
g=Array.new(H,0).map{Array.new(W,0)}
p=0
a.each_with_index do |v,i|
  while(v>0)
    g[p / W][p % W]=i+1
    v-=1
    p+=1
  end
end

g.each_with_index do |v,i|
  if i.even?
    puts v.join(" ")
  else
    puts v.reverse.join(" ")
  end
end