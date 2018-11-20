x,a,b = gets.chomp.split(" ").map(&:to_i)
if (x-a).abs > (x-b).abs then
  puts "B"
else
  puts "A"
end
