c=[]
3.times { c<< gets.chomp.split.map(&:to_i) }
a = [0]
b = c[0]
1.upto(2) {|i| a[i] = c[i][0] - b[0]}

1.upto(2) do |i|
  1.upto(2) do |j|
    if c[i][j] != a[i] + b[j]
      puts "No"
      exit
    end
  end
end

puts "Yes"