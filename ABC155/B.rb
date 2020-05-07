n=gets.to_i
a=gets.chomp.split.map(&:to_i)
a.each do |v|
  next if v.odd? 
  if v % 5 != 0 && v % 3 !=0
    puts "DENIED"
    exit
  end
end
puts "APPROVED"
     
