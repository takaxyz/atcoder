N=gets.to_i
a,b=gets.chomp.split.map(&:to_i)
d=Array.new(N+1).map{Array.new(N+1,Float::INFINITY)}
e=Hash.new { |h,k| h[k] = [] }

MOD = 10**9+7

(1..N).each {|i| d[i][i] = 0 }

M=gets.to_i
M.times do
  x,y=gets.chomp.split.map(&:to_i)
  e[x] << y
  e[y] << x

  d[x][y] = 1
  d[y][x] = 1
end


(1..N).each do |k|
  (1..N).each do |i|
    (1..N).each do |j|
      d[i][j] = d[i][k] + d[k][j] if d[i][j] > d[i][k] + d[k][j]
    end
  end
end

def dfs(a, b, i, cnt, visited, d, e)
  return if(a==b)
  return if visited[a] == true

  visited[a] = true
  e[a].each do |c|
    if(d[c][b] == d[a][b] - 1 && visited[c] == false)
#      printf("%d %d %d %d\n",a,b,c,i)
      cnt[i] += 1
      dfs(c,b,i+1,cnt,visited,d,e)
      visited[c] = true
    end
  end

end

visited = Array.new(N+1,false)
cnt = Array.new(N+1,0)

dfs(a,b,0,cnt,visited,d,e)

ans = 1
0.upto(d[a][b]-1) do |i|
  ans *= cnt[i]
  ans %= MOD
end

puts ans
# (1..N).each do |i|
#   (1..N).each do |j|
#     printf("%d -> %d : %d\n", i, j, d[i][j])
#   end
# end
