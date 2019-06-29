s=gets.chomp
cnt=s.count('0')
puts 2*[cnt,s.size-cnt].min
