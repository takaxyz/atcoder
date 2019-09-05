p=gets.to_i
n=1789997546303
(1000-p).times do
  if n % 2 == 0
    n = n/2
  else
    n = 3*n+1
  end
end
puts n