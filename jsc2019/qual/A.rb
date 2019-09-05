m,d=gets.chomp.split.map(&:to_i)
ans=0
1.upto(m) do |i|
  22.upto(d) do |j|
    ans += 1 if i == (j%10) * (j/10) && j%10>=2
  end
end
puts ans
