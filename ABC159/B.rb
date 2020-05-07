s=gets.chomp

def ck(s)
  if s.size.even?
    return s[0,s.size/2] == s[s.size/2,s.size/2].reverse
  else
    return s[0,s.size/2] == s[s.size/2+1,s.size/2].reverse
  end

end

if ck(s) && ck(s[0,(s.size-1)/2]) && ck(s[((s.size+3)/2-1)..-1])
  puts "Yes"
else
  puts "No"
end