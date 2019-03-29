N,A,B=gets.chomp.split.map(&:to_i)
ans=0
N.times do
  s,d=gets.chomp.split
  d=d.to_i
  if d < A
    ans += s == "East" ? A : -A
  elsif d > B
    ans += s == "East" ? B : -B
  else
    ans += s == "East" ? d : -d
  end
end

if ans == 0
  puts 0
elsif ans > 0
  puts "East " + ans.to_s
else
  puts "West " + (-ans).to_s
end
