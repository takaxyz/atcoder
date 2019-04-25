N=gets.to_i
H=gets.chomp.split.map(&:to_i)
min=0
ans=0
H.each do |h|
  if h >= min
    ans += 1
    min = h
  end
end
puts ans