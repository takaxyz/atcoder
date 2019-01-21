N=gets.to_i
A=gets.chomp.split.map(&:to_i)
B=gets.chomp.split.map(&:to_i)

if A.inject(:+) < B.inject(:+)
  puts -1
  exit
end


fusoku = 0
k = []
cc = 0
0.upto(N-1) do |i|
  if A[i] < B[i]
    fusoku += B[i] - A[i]
    cc += 1
  elsif A[i] > B[i]
    k << A[i] - B[i]
  end
end

if cc == 0
  puts 0
  exit
end

k.sort!
k.reverse!

flag = false
cnt = 0
k.each do |v|
  fusoku -= v
  cnt += 1
  if fusoku <= 0
    flag = true
    break
  end
end

puts flag ? cc + cnt : -1