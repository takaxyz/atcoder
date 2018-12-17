N = gets.to_i
a = gets.chomp.split.map(&:to_i).sort.reverse
h = Hash.new(0)
a.each do |v|
    h[v] += 1
end

b = [1]
1.upto(32){|i| b[i] = b[i-1]<<1} 
b.reverse!

ans = 0

used = Hash.new(0)

a.each do |v|
    next if h[v] == 0
    h[v] -= 1
    flag = 0
    b.each do |w|
        if h[w - v] > 0
            ans += 1
            h[w - v] -= 1
            flag = 1
            break
        end
    end
    h[v] += 1 if flag == 0
end
puts ans