a,b,k=gets.chomp.split.map(&:to_i)
k.times do |i|
    if i % 2 == 0
        if a%2 == 1
            a -= 1
        end
        b += a/2
        a /= 2        
    else
        if b%2 == 1
            b -= 1
        end
        a += b/2
        b /= 2        
    end
end

printf("%d %d\n",a,b)