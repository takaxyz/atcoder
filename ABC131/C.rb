A,B,C,D=gets.chomp.split.map(&:to_i)

def gcd(a,b)
  return a if b == 0
  gcd(b,a%b)
end

def lcm(a,b)
  a * b / gcd(a,b)
end

def hoge(n,c,d)
  ret = n - n / c
  ret += n - n / d
  ret -=  n - n / lcm(c,d)
  ret
end

puts hoge(B,C,D) - hoge(A-1, C, D)