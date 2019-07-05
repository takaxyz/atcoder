N,M=gets.chomp.split.map(&:to_i)
edge = Array.new(N+1).map{Hash.new(0)}

M.times do
  a,b,l=gets.chomp.split.map(&:to_i)
  edge[a][l]+=1
  edge[b][l]+=1
end

ans=0
1.upto(N) do |i|
  edge[i].each_key do |k|
    next if k > 1270

    if k == 1270
      ans += (edge[i][k])*(edge[i][k]-1)/2
    else
      ans += edge[i][k] * edge[i][2540-k]
    end
  end
end
puts ans