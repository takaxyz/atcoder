a,b=gets.chomp.split.map(&:to_i)
if a<6
  puts 0
elsif a<13
  puts b/2
else
  puts b
end
