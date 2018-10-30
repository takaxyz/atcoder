n = gets.chomp.to_i
a = [2, 1]
for i in 2..n
  a[i] = a[i-1] + a[i-2]
end
p a[n]
