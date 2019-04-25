N=gets.to_i
a=[]
5.times{ a << gets.to_i}
a.sort!
puts (N-1)/a[0]+5
