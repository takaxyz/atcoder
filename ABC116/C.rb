N=gets.to_i
h=gets.chomp.split.map(&:to_i)
ans = 0
flag = false
100.times do 
  0.upto(N-1) do |i|
    if h[i] > 0
      h[i] -= 1
      if flag == false
        flag = true
        ans += 1
      end
    else
      flag = false
    end
  end
  flag = false
end
puts ans