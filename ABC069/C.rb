N=gets.to_i
a=gets.chomp.split.map(&:to_i)
c1,c2,c4=0,0,0
a.each do |v|
  if v % 4 == 0
    c4 += 1
  elsif v % 2 == 0
    c2 += 1
  else
    c1 +=1
  end
end

if N.even?
  if c1 <= c4
    puts "Yes"
  else
    puts "No"
  end
else
  if (N/2+1==c1 && c1 == c4+1) || c1 <= c4
    puts "Yes"
  else
    puts "No"
  end
end