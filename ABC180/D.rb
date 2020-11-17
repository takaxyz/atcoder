x,y,a,b=gets.split(" ").map(&:to_i)
s=x;
ans=0;

while (s*(a-1)<b && s*a < y) do
  s *= a;
  ans+=1;
end


ans += (y-s-1)/b;
puts ans 