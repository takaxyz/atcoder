N,K=gets.chomp.split.map(&:to_i)
S=gets.chomp.split("")
prev=S[0]
ss = []
ss << 0 if prev=='0'

cnt = 1
1.upto(N-1) do |i|
  if prev == S[i]
    cnt += 1
  else
    ss << cnt
    prev = S[i]
    cnt = 1
  end  
end
ss << cnt
ss << 0 if S[-1] == '0'

if ss.size/2 <= K
  puts N
  exit
end

tmp = 0
0.step(2*K) do |i|
  tmp += ss[i]
end
ans = tmp
(2*K+1).step(ss.size-2,2) do |i|
  tmp = tmp + ss[i] + ss[i+1] - ss[i-2*K-1] - ss[i-2*K]
  ans = tmp if tmp > ans
end
puts ans