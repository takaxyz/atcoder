N=gets.to_i
sum=0
1.upto(N) do |i|
  sum+=i
  if sum >= N
    1.upto(i) do |j|
      puts j if j != sum - N
    end
    exit
  end
end