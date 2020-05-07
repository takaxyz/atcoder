S=gets.chomp
if S =~ /^\d{3}$/
  puts S.to_i*2
else
  puts "error"
end
