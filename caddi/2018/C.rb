require 'prime'

N,P=gets.chomp.split.map(&:to_i)
ans=1
Prime.prime_division(P).each do |a,b|
  next if b < N

  ans *= (a ** (b/N))
end
puts ans
