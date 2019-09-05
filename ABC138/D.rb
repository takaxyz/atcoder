N,Q=gets.chomp.split.map(&:to_i)
edge=Array.new(N+1).map{Array.new}
(N-1).times do
  a,b=gets.chomp.split.map(&:to_i)
  edge[a] << b
  edge[b] << a
end

v=Array.new(N+1,0)
Q.times do
  p,x=gets.chomp.split.map(&:to_i)
  v[p]+=x
end
stack = [[1,0]]
w=Array.new(N+1,-1)
w[0]=0

while(!stack.empty?)
  pos,parent = stack.pop
  w[pos] = v[pos] + w[parent]
  edge[pos].each do |t|
    next if w[t] != -1 
    stack.push([t,pos])
  end
end
puts w[1..N].join(" ")