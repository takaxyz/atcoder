H=rand(1..30)
W=rand(1..30)
printf("%d %d\n",H,W)
1.upto(H) do |i|
  1.upto(W) do |j|
    print rand(0..2).even? ? "." : "#"
  end
  puts
end
