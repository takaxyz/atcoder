A,B,K=gets.chomp.split.map(&:to_i)
t=[]
1.upto(100) { |i| t << i if A%i==0 && B%i==0}
t.reverse!
puts t[K-1]
