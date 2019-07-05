N=gets.to_i
ab=[]
min_plan=[0,Float::INFINITY]
N.times do
  a,b= gets.chomp.split.map(&:to_i)
  ab << [a,b]
  min_plan = [a,b] if b-a < (min_plan[1] - min_plan[0]) 
end
ab.sort!

#p ab

M=gets.to_i
t_list = []
ans=[]
M.times do |i|
  t_list << [gets.to_i, i]
end

pos=0
t_list.sort.each do |t, i|
  while(pos < ab.size && ab[pos][0] < t)
    pos += 1
  end

  if(pos == ab.size)
    ans << [i, ab[-1][1] + t - ab[-1][0]]
  elsif(pos == 0)
    ans << [i, ab[0][1]]
  else
    ans << [i, [ab[pos-1][1] + t - ab[pos-1][0], ab[pos][1]].min]
  end
end

ans.sort.each do |a,b|
  puts b
end
