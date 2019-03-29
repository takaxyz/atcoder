N,M,C=gets.chomp.split.map(&:to_i)
B=gets.chomp.split.map(&:to_i)
ans = 0
N.times do
  a=gets.chomp.split.map(&:to_i)
  t=0
  a.each_with_index do |v,i|
    t += v * B[i]
  end
  ans +=1 if t + C > 0
end
puts ans
     
