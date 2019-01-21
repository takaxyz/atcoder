s=gets.to_i
h = {}
h[s] = 1
2.upto(1000000) do |i|
#  puts s
  if s.odd?
    s = 3 * s + 1
  else
    s = s/2
  end
  if h.has_key?(s)
    puts i
    exit
  else
    h[s] = 1
  end
end
