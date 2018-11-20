A, B, C, D, E, F = gets.chomp.split(" ").map(&:to_i)

limit = E.to_f / (100 + E)

tmp = 0
max_s =0
max_sw = 0
for a in 0..(F/100/A)
    for b in 0..((F-100*a*A)/100/B)
        next if a + b == 0
        for c in 0..((F-100*a*A-100*b*B)/C)
            for d in 0..((F-100*a*A-100*b*B-c*C)/D)
 #               printf "%d %d %d %d\n", a, b, c, d
                sw = c*C+d*D+a*A*100+b*A*100
                s = c*C+d*D
                n = s.to_f / sw
#                printf "%f\n", n 
                break if n > limit
                if tmp < n
                    tmp = n
                    max_s = s
                    max_sw = sw
                end
            end
        end
    end
end
if max_s > 0
    puts "#{max_sw} #{max_s}"
else
    puts "#{100*A} #{max_s}"
end