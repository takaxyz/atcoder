s=gets.chomp.split("")
b = 0
ans = 0
s.each do |c|
    if c == 'B'
        b += 1
    else
        ans += b
    end
end
puts ans