m,k=gets.chomp.split.map(&:to_i)
if m==0
  if k==0
    puts "0 0"
  else
    puts -1
  end
elsif m==1
  if k==0
    puts "0 0 1 1"
  else
    puts -1
  end
elsif 2**m <= k
  puts -1
else
  a=[]
  0.upto(2**m-1) do |i|
    next if i == k
    a << i
  end
  a.each do |v|
    printf("%d ", v)
  end
  printf("%d ", k)
  a.reverse.each do |v|
    printf("%d ", v)
  end
  printf("%d\n",k)
end 