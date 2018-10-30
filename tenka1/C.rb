n=gets.to_i
a = []
n.times do
    a << gets.to_i
end
a.sort!

ans = 0
if n % 2 == 0
    (n/2+1).upto(n-1) do |i|
        ans += a[i] * 2    
    end

    ans += a[n/2]
    (0).upto(n/2-2) do |i|
        ans -= a[i] * 2    
    end
    ans -= a[n/2-1]
else
    (n/2+1).upto(n-1) do |i|
        ans += a[i] * 2    
    end

    (0).upto(n/2-2) do |i|
        ans -= a[i] * 2    
    end
    ans -= a[n/2]
    ans -= a[n/2-1]

    tmp = ans
    ans = 0

    (n/2+2).upto(n-1) do |i|
        ans += a[i] * 2    
    end
    ans += a[n/2]
    ans += a[n/2+1]

    (0).upto(n/2-1) do |i|
        ans -= a[i] * 2    
    end

    ans = tmp if tmp > ans

end
puts ans
