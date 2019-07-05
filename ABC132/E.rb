N,M=gets.chomp.split.map(&:to_i)
e1 = Array.new(N+1).map{Array.new}
M.times do
  u,v=gets.chomp.split.map(&:to_i)
  e1[u] << v
end
s,t=gets.chomp.split.map(&:to_i)
e2 = Array.new(N*3+1).map{Array.new}
1.upto(N) do |i|
  e1[i].each do |j|
    e2[i] << N+j
    e2[N+i] << 2*N+j
    e2[2*N+i] << j
  end
end

d = Array.new(3*N+1,10**10)

def bfs(s, t, e, d, depth)
  que = []
  que.push(s)
  d[s] = depth

  while(que.size != 0)
    n = que.shift
    e[n].each do |v|
      next if d[v] <= d[n] + 1
      d[v] = d[n] + 1
      que.push(v)
    end
  end

end

bfs(s,t,e2,d,0)

if d[t] != 10**10
  puts d[t] / 3
else
  puts -1
end
