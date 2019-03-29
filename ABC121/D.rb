A,B=gets.chomp.split.map(&:to_i)

def f(n)
  case n%4
  when 0
    n
  when 1
    1 
  when 2
    n^1
  when 3
    0
  end
end

puts f(B) ^ f(A-1)