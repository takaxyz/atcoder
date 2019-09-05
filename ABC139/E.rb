N=gets.to_i
1.upto(N) do |i|
  list=[]
  gets.chomp.split.map(&:to_i).each do |j|
    list << i+j-3
  end

  0.upto(N-3) do |j|
    list[j] list[j+1]
  end

end