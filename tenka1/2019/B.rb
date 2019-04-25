N=gets.to_i
s=gets.chomp.split("")
K=gets.to_i
0.upto(N-1) {|i| s[i] = '*' if s[i] != s[K-1]}
puts s.join("")