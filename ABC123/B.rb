ans=0
min=10
5.times do
  a=gets.to_i
  ans += (a+9)/10*10
  min = a%10 if a%10!=0 && min > a%10
end
if min==10
  puts ans
else
  puts ans - 10 + min
end
