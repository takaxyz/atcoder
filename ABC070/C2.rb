def gcd(a,b)
    return a if b == 0
    gcd(b,a%b)
end

def lcm(a,b)
    a * b / gcd(a,b)
end

ans = 1
n = gets.to_i
n.times do
    t = gets.to_i
    ans = lcm(ans,t)
end
puts ans