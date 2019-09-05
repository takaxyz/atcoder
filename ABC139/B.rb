A,B=gets.chomp.split.map(&:to_i)
if B==1
  puts 0
else
  puts (B-2)/(A-1)+1
end
