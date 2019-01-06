a,b,c=gets.chomp.split.map(&:to_i)
if c<=a
    puts c+b
elsif (c-a) <= b
    puts c+b
else
    puts 2*b+a+1    
end