
h, w = gets.chomp.split(" ").map(&:to_i)

c = Array.new
10.times do
    c.push(gets.chomp.split(" ").map(&:to_i))
end

a = Array.new
h.times do
    a.push(gets.chomp.split(" ").map(&:to_i))
end

for k in 0..9 do
    for i in 0..9 do
        for j in 0..9 do
            c[i][j] = [c[i][j], c[i][k]+c[k][j]].min
        end
    end
end

ans = 0
for i in 0..h-1 do
    for j in 0..w-1 do
        ans += c[a[i][j]][1] if a[i][j] != -1
    end
end

puts ans