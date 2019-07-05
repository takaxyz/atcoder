pos=[0,4,6,8]
S=gets.chomp
0.upto(15) do |i|
  s = "AKIHABARA".split("")
  0.upto(3) do |j|
    if (i >> j) & 1 == 1 then
      s[pos[j]] = "" 
    end
  end

  if s.join("") == S
    puts "YES"
    exit
  end
end
puts "NO"