gets
h = Hash.new(0)

a = gets.chomp.split(" ").map(&:to_i)
a.each { |c| h[c] += 1}

x = Array.new
h.sort.reverse.each do | key, val|
  if h[key] >= 4 then
    x.push(key)
    x.push(key)
  elsif h[key] >= 2 then
    x.push(key)
  end
  break if x.size == 2
end

if x.size >= 2 then
  puts x[0] * x[1]
else
  puts 0
end
