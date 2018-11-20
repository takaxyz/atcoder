h = Hash.new
for c in 'a'..'z' do
  h[c] = 0
end

s = gets.chomp.split("")
s.each { |c| h[c] = 1}

for c in 'a'..'z' do
  if h[c] == 0 then
    puts c
    exit
  end
end

puts 'None'
