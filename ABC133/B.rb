N,D=gets.chomp.split.map(&:to_i)
x=[]
N.times { x << gets.chomp.split.map(&:to_i)}
ans=0
0.upto(N-1) do |i|
  (i+1).upto(N-1) do |j|
    t = 0
    0.upto(D-1) do |k|
      t += (x[i][k] - x[j][k])**2
    end

    0.upto(Math.sqrt(t)) do |l|
      ans += 1 if t == l**2
    end
  end
end
puts ans