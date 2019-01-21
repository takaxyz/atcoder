H,W=gets.chomp.split.map(&:to_i)
s=[]
H.times {s << gets.chomp.split("")}

di = [-1, 0, 1, 0]
dj = [0, -1, 0, 1]

visited = Array.new(H).map{Array.new(W,false)}

queue = []

ans = 0
(0...H).each do |i|
  (0...W).each do |j|
    next if visited[i][j] == true
    b = 0
    w = 0

    queue << [i,j]
    visited[i][j] = true
    b += 1 if s[i][j] == '#'
    w += 1 if s[i][j] == '.'
    while(queue.size > 0) do
#      p queue
      pos = queue.pop
      (0..3).each do |ci|
        ii = pos[0]+di[ci]
        jj = pos[1]+dj[ci]
        next if ii < 0 || ii >= H
        next if jj < 0 || jj >= W
        next if visited[ii][jj]

        if s[pos[0]][pos[1]] != s[ii][jj]
#          printf("%s %s\n", s[pos[0]][pos[1]], s[ii][jj])
          queue << [ii,jj]
          visited[ii][jj] = true
          b += 1 if s[ii][jj] == '#'
          w += 1 if s[ii][jj] == '.'
        end
      end
    end
#    printf("%d %d\n", b, w)
    ans += b * w
  end
end
puts ans