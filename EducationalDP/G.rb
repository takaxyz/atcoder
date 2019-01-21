N,M=gets.chomp.split.map(&:to_i)
e = Hash.new{|hash, key| hash[key] = []}
M.times do
  x,y=gets.chomp.split.map(&:to_i)
  e[x] << y
end

memo = Array.new(N+1, 0)

def depth(memo, e, node)
  if memo[node] > 0
    return memo[node]
  end

  if e[node].size == 0
    memo[node] = 1
    return 1
  end

  ret = 0
  e[node].each do |child|
    tmp = depth(memo, e, child) + 1
    ret = tmp if ret < tmp
  end
  memo[node] = ret
  return ret
end

1.upto(N) do |i|
  depth(memo, e, i)
end

p memo
puts memo.max - 1 