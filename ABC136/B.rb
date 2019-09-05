n=gets.to_i
if n < 10
  puts n
elsif n < 100
  puts 9
elsif n < 1000
  puts 9 + n-99
elsif n < 10000
  puts 9 + 900 
elsif n < 100000
  puts 9 + 900 + n - 9999
else
  puts 9 + 900 + 90000
end
