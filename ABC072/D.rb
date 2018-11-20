gets
p = gets.chomp.split(" ").map(&:to_i)
count  = 0

i = 0
while(i < p.size)
    if p[i] == i + 1 then
        if i < p.size - 1 && p[i+1] == i+2 then
            i += 2
        else
            i += 1
        end
        count += 1
    else
        i += 1
    end

end

puts count
