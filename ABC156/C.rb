n=gets.to_i
x=gets.chomp.split.map(&:to_i).sort

ans=10**10
x.min.upto(x.max) do |i|
  t=0
  x.each do |j|
    t+=(i-j)**2
  end
  ans = t if t < ans
end
puts ans