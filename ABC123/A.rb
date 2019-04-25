a=[]
5.times do
  a << gets.to_i
end
k=gets.to_i
puts a[4]-a[0]<=k ? "Yay!" : ":("
