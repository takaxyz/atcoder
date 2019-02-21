require 'prime'
N=gets.to_i
h = Hash.new(0)
1.upto(N) do |i|
    i.prime_division.each do |a,b|
        h[a] += b
    end
end

nn = 1
1.upto(N) do |i|
    nn *= i
end
ans = []
h.keys.permutation(3) do |a,b,c|
    tmp = a**4 * b**4 * c**2
    if nn % tmp == 0
        ans << tmp  
    end
end
h.keys.permutation(2) do |a,b|
    tmp = a**24 * b**2
    if nn % tmp == 0
        ans << tmp  
    end
    tmp = a**14 * b**4
    if nn % tmp == 0
        ans << tmp  
    end
end


h.each do |k,v|
    ans << k ** 74 if v >= 74
end

p ans.uniq.size
