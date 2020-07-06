0.upto(9) do |a|
  0.upto(99) do |b|
    s = sprintf("%d.%02d",a,b)
    f = (s.to_f*100).to_i
    if s.delete(".").to_i != f then
      printf("%s  %d\n",s,f)
    end 
  end
end
