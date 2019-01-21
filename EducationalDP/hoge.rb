0.upto(3) do |i|
  0.upto(3) do |j|
    next if i + j > 3
    printf("%d %d\n", j, i + j)
  end
end