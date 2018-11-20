mod = 1000000007
gets
s1 = gets.chomp.split("")
s2 = gets.chomp.split("")

if s1.size == 1 then
  puts 3
  exit
end 

if s1[0] == s2[0] then
  i = 1
  ans = 3
else
  i = 2
  ans = 6
end

while(i < s1.size) do
  if s1[i] == s2[i] then
    if s1[i-1] == s2[i-1] then
      ans = ans * 2
    end
    i += 1
  else
    if s1[i-1] == s2[i-1] then
      ans = ans * 2
    else
      ans = ans * 3      
    end
    i += 2
  end
end    

puts ans % mod

