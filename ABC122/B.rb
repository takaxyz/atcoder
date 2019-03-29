S=gets.chomp.split("")
ans = 0
tmp = 0
S.each do |c|
  if "ATGC".include?(c)
    tmp += 1
  else
    ans = [tmp,ans].max
    tmp = 0
  end
end
ans = [tmp,ans].max
puts ans