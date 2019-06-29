N=gets.to_i
ba=[]
N.times do
  a,b = gets.chomp.split.map(&:to_i)
  ba << [b,a]
end
ba.sort!

t = 0
ba.each do |b,a|
  t += a
  if b < t
    puts "No"
    exit
  end
end
puts "Yes"