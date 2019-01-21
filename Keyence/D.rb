N,M=gets.chomp.split.map(&:to_i)
A=gets.chomp.split.map(&:to_i).sort.reverse
B=gets.chomp.split.map(&:to_i).sort.reverse
MOD = 1000000007

if A.size != A.uniq.size || B.size != B.uniq.size
  puts 0
  exit
end

i=0
j=0
ans = 1
(N*M).downto(1) do |k|
  if A[i] == k && B[j] == k
    i += 1
    j += 1
    next
  end
  
  if A[i] == k
    ans = ans * j % MOD
    i += 1
  elsif B[j] == k
    ans = ans * i % MOD
    j += 1
  else
    ans = ans * (i * j - N*M + k) % MOD
  end
end

puts ans

