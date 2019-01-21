N=gets.to_i
A,B=gets.chomp.split.map(&:to_i)
P=gets.chomp.split.map(&:to_i)
cnt = [0,0,0]
P.each do |i|
  if i <= A
    cnt[0] +=1
  elsif i <= B
    cnt[1] +=1
  else
    cnt[2] +=1
  end
end
p cnt.min
