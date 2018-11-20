str = gets.chomp

str.split("").each_with_index {|c, i| print c if i % 2 == 0 }
print "\n"