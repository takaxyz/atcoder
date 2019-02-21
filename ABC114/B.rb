s=gets.chomp
ans=Float::INFINITY
0.upto(s.length-3) do |i|
    ans = (s[i,3].to_i - 753).abs if ans > (s[i,3].to_i - 753).abs
end
puts ans