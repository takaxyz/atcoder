h = Hash.new(0)
3.times do
  gets.chomp.split.map(&:to_i).each { |v| h[v]+=1 }
end
h.each do |k,v|
  if v == 3
    puts "NO"
    exit
  end 
end
puts "YES"
