A=gets.to_i
B=gets.to_i
C=gets.to_i
X=gets.to_i

ans = 0
0.upto(X/500) do |i|
  break if i > A
  0.upto((X-i*500)/100) do |j|
    break if j > B
    0.upto((X-500*i-100*j)/50) do |k|
      break if k > C
      ans += 1 if 500*i+100*j+50*k == X
    end
  end
end
puts ans