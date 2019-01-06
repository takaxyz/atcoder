N,K=gets.chomp.split.map(&:to_i)
ans=0

if K==0
  puts N*N
  exit
end

(K+1).upto(N) do |b|
  ans += N/b*(b-K)
  ans += N%b-(K-1) if N%b-(K-1) > 0
end
puts ans