N=gets.to_i
A=gets.chomp.split.map(&:to_i)

def gcd(a,b)
  return a if b == 0
  gcd(b,a%b)
end


ans=A[0]
1.upto(N-1) {|i| ans = gcd(ans,A[i])}
puts ans