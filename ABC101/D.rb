1.upto(100) do |i|
  t = i
  s = 0
  while t>0
    s += t % 10
    t /= 10
  end
  printf("%d %d %f\n", i, s, i.to_f / s)
end