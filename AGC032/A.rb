N=gets.to_i
b = gets.chomp.split.map(&:to_i)

ans = []
while(!b.empty?) do 
  flag = 0
  (b.size-1).downto(0) do |i|
    if b[i] == i+1
      ans << b[i]
      b.slice!(i)
      flag = 1
      break
    end
  end
  if flag == 0
    puts -1
    exit
  end
end
ans.reverse!
ans.each {|v| puts v}