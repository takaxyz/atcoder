N=gets.to_i
h=gets.chomp.split.map(&:to_i)
if N==1
  puts "Yes"
  exit
end

(N-1).downto(1) do |i|
  if h[i]+1 < h[i-1]
    puts "No"
    exit
  elsif h[i]+1 == h[i-1]
    h[i-1] -= 1
  end
end
puts "Yes"