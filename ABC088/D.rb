H,W=gets.chomp.split.map(&:to_i)
s = []
s << ['#'] * (W+2)
H.times { s << ['#'] + gets.chomp.split("") + ['#']}
s << ['#'] * (W+2)

d = Array.new(H+2).map{Array.new(W+2,Float::INFINITY)}

def dfs(s, d, i, j, c)
  return if s[i][j] == '#'
  return if d[i][j] <= c

  d[i][j] = c
  dfs(s,d,i,j+1,c+1)
  dfs(s,d,i,j-1,c+1)
  dfs(s,d,i+1,j,c+1)
  dfs(s,d,i-1,j,c+1)
end

dfs(s, d, 1, 1, 1)

if d[H][W] == Float::INFINITY
  puts -1
else
  ans = 0
  s.each {|ss| ans += ss.count('.')}
  puts ans - d[H][W]
end
