n = gets.chomp.to_i
k = gets.chomp.to_i
x = gets.chomp.split(" ").map(&:to_i)
sum = 0
x.each do |a|
    sum += a < k - a ? a * 2 : (k - a) * 2 
end
puts sum