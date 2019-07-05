R,C=gets.chomp.split.map(&:to_i)
ans=0
C.step(R,C) do |i|
  C.step(R,C) do |j|
    if i**2 + j**2 <= R**2
      ans += 1
    end
  end
end
puts ans*4