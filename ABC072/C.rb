gets
a = gets.chomp.split(" ").map(&:to_i)

h = Hash.new(0)
for i in a do
    h[i] += 1
end

ans = 0
h.sort.each do | key, val|
    ans = [ans, h[key-1] + h[key] + h[key+1]].max
end
puts ans