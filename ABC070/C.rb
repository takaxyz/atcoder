def lcm(a, b)
    x = a * b

    if a < b then
        tmp = a
        a = b
        b = tmp
    end

    r = a % b
    while(r != 0)
        a = b
        b = r
        r = a % b
    end
    return x / b
end

def dp(t)
    if t.size == 1 then 
        return t[0]
    elsif t.size == 2 then
        return lcm(t[0], t[1])
    else
        return lcm(dp(t.slice(0,t.size/2)), dp(t.slice(t.size/2,t.size-t.size/2)))
    end
end

t = Array.new

gets
STDIN.each_line {|line| t.push(line.to_i) }

puts dp(t)