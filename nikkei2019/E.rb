N=gets.to_i
1.upto(N) do |i|
  ans=[]
  2.upto(6) do |j|
    ans << ('a'.ord+j-2).chr if i % j == 0
  end
  if ans.size==0
    puts i
  else
    puts ans.join
  end
end