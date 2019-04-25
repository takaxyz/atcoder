S=gets.chomp.split("")
ans1,ans2=0,0
S.each_with_index do |s,i|
  if i.even? && s=='0' || i.odd? && s=='1'
    ans1+=1
  end
  if i.odd? && s=='0' || i.even? && s=='1'
    ans2+=1
  end
end
puts [ans1,ans2].min