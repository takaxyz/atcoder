N=gets.to_i
h=Hash.new(0)
gets.chomp.split.map(&:to_i).each do |i|
  h[i]+=1
end
if h[0] == N
  puts "Yes"
elsif N%3!=0
  puts "No"
elsif h[0]==N/3 && h.size==2
  puts "Yes"
elsif h.size==3
  h.each do |k,v|
    if v==N/3
    else
      puts "No"
      exit
    end
  end
  a = h.to_a
  if (a[0][0] ^ a[1][0] ^ a[2][0]) == 0
    puts "Yes"
  else
    puts "No"
  end

else
  puts "No"
end
