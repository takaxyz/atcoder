N=gets.to_i
A=gets.chomp.split.map(&:to_i)
t=0
0.upto(N-1) do |i|
  if i.even?
    t+=A[i]
  else
    t-=A[i]
  end
end
ans = [t]
0.upto(N-2) do |i|
  ans << A[i] * 2 - ans[-1]
end
puts ans.join(" ")