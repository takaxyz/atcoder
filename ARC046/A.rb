n=gets.to_i
i = 0
v = 1
while(i < n)
  if v < 10
    i +=1
  elsif 10 <= v && v < 100 && v % 11 == 0
    i +=1
  elsif 100 <= v && v < 1000 && v % 111 == 0
    i +=1
  elsif 1000 <= v && v < 10000 && v % 1111 == 0
    i +=1
  elsif 10000 <= v && v < 100000 && v % 11111 == 0
    i +=1
  elsif 100000 <= v && v < 1000000 && v % 111111 == 0
    i +=1
  end
  v += 1
end
puts v-1
