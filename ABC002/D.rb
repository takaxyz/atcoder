N,M=gets.chomp.split.map(&:to_i)
d = Array.new(N+1,0).map{ Array.new(N+1,0)}
M.times do
    xx,yy = gets.chomp.split.map(&:to_i)
    d[xx][yy] = 1
    d[yy][xx] = 1
end

ans = 1
2.upto(N) do |i|
    (1..N).to_a.combination(i) do |a|
        ans = i if a.combination(2).all? { |x,y| d[x][y]==1}
    end
end
puts ans



