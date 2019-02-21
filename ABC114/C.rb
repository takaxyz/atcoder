N=gets.to_i

l = N.to_s.length
n = ['3','5','7']
m = ['3','5','7']
2.upto(l) do |i|
    tmp = []
    m.each do |j|
        n.each do |k|
            if k.length == i-1
                tmp << k + j
            end
        end
    end
    n += tmp
end

ans = 0
n.each do |v|
    if v.include?('3') && v.include?('5') && v.include?('7')
        if v.to_i <= N
            ans += 1
        end
    end
end
puts ans
