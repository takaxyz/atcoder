n,m=gets.chomp.split.map(&:to_i)

if n*n < m
  puts -1
  return
end

ok = n
ng = 0

while((ok-ng).abs > 1) do
  mid = (ok+ng)/2
  if(mid * n >= m)
    ok = mid    
  else
    ng = mid  
  end
end

z = ok
ok = n
ng = 0

while((ok-ng).abs > 1) do
  mid = (ok+ng)/2
  if(mid * z >= m)
    ok = mid    
  else
    ng = mid  
  end
end

puts z * ok