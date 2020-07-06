a,r,n=gets.chomp.split.map(&:to_i)

LIM=10**9;

def mpow(x, n)
  return 1 if n == 0

  y = mpow(x, n/2);
  y *= y;

  if n%2==1 then
    y *=x
  end

  if y > LIM
    puts "large"
    exit
  end
  return y
end

ans = a * mpow(r, n-1)
if ans > LIM
  puts "large"
else
  puts ans
end