S=gets.chomp

if S.match(/^keyence/)
  puts "YES"
elsif S.match(/keyence$/)
  puts "YES"
elsif S.match(/^k.*eyence$/)
  puts "YES"
elsif S.match(/^ke.*yence$/)
  puts "YES"
elsif S.match(/^key.*ence$/)
  puts "YES"
elsif S.match(/^keye.*nce$/)
  puts "YES"
elsif S.match(/^keyen.*ce$/)
  puts "YES"
elsif S.match(/^keyenc.*e$/)
  puts "YES"
else
  puts "NO"
end
