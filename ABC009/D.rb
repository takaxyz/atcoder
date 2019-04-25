K,M=gets.chomp.split.map(&:to_i)
A=gets.chomp.split.map(&:to_i)
c=Array.new(K,0).map{Array.new(K,0)}
c[0]=gets.chomp.split.map(&:to_i)
1.upto(K-1) {|i| c[i][i-1]=2**32-1}

def power(a,n)
  if n == 0
    b=Array.new(a.size,0).map{Array.new(a.size,0)}
    0.upto(b.size-1) {|i| b[i][i]=2**32-1}
    b
  elsif n%2==0
    b=power(a,n/2)
    mul(b,b)
  else
    b=power(a,n-1)
    mul(b,a)
  end
end

def mul(a,b)
  c=Array.new(a.size,0).map{Array.new(a.size,0)}
  0.upto(a.size-1) do |i|
    0.upto(a.size-1) do |j|
      0.upto(a.size-1) do |k|
        c[i][j] ^= a[i][k] & b[k][j]
      end
    end
  end
  c
end

if M<=K
  puts a[M-1]
  exit
end

d=power(c,M-K)
ans=0
0.upto(K-1) {|i| ans ^= d[0][i] & A[K-i-1]}
puts ans
