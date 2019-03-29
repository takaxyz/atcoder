class Node
  attr_accessor :parent, :rank
  
  def initialize(n)
    @parent = n
    @rank = 0
  end
end

class UnionFindTree
  attr :ans

  def initialize(n)
    @nodes = (0..n).to_a.map { |i| Node.new(i) }
    @count = [1] * (n+1)
    @ans = n * (n-1) / 2
  end
  
  def find(x)
    return x if @nodes[x].parent == x
    
    return @nodes[x].parent = find(@nodes[x].parent)
  end
  
  def unite(a, b)
    a = find(a)
    b = find(b)
    return if a == b
    
    if @nodes[a].rank < @nodes[b].rank
      @nodes[a].parent = b
    else
      @nodes[b].parent = a
      @nodes[a].rank += 1 if @nodes[a].rank == @nodes[b].rank
    end
    @ans -= @count[a] * @count[b]
    tmp = @count[a] + @count[b]
    @count[a]=tmp
    @count[b]=tmp
  end

  def same?(a, b)
    find(a) == find(b)
  end
  
  def parents
    @nodes.map(&:parent)
  end
end

N,M=gets.chomp.split.map(&:to_i)
ab = []
M.times do
  ab.unshift(gets.chomp.split.map(&:to_i))
end
tree = UnionFindTree.new(N)
ans = []
ab.each do |a, b|
  ans.unshift(tree.ans)
  tree.unite(a,b)
end
ans.each do |v|
  puts v
end