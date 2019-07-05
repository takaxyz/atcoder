s=gets.chomp.split("")
ans = 10**5
h = {}
s.each_with_index do |c, i|
  h[c] = [-1] if !h.has_key?(c)
  h[c] << i
end


ans = 10**5
h.each do |k,v|
  v << s.size
  tmp = 0
  v.each_cons(2) do |a,b|
    tmp = b-a if b-a > tmp
  end
  ans = tmp if ans > tmp
end
puts ans-1