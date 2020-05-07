class Node
    attr_accessor :parent, :rank

    def initialize(n)
      @parent = n
      @rank = 0
    end
  end

class UnionFindTree
  attr_accessor :count
  def initialize(n)
    @nodes = (0..n).to_a.map { |i| Node.new(i) }
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
  end

  def same?(a, b)
    find(a) == find(b)
  end

  def parents
    @nodes.map(&:parent)
  end
end

n,m,k=gets.chomp.split.map(&:to_i)

uft = UnionFindTree.new(n+1)

flist = Hash.new{|hash, key| hash[key] = []}

m.times do
  a,b=gets.chomp.split.map(&:to_i)
  uft.unite(a,b)
  flist[a] << b
  flist[b] << a
end

blist = Hash.new{|hash, key| hash[key] = []}

k.times do
  c,d=gets.chomp.split.map(&:to_i)
  blist[c] << d
  blist[d] << c
end


h = Hash.new(0)

1.upto(n) do |i|
  h[uft.find(i)] += 1
end

list = []
1.upto(n) do |i|
  ans=h[uft.find(i)]-1
  ans -= flist[i].size
  blist[i].each do |v|
    ans -= 1 if uft.same?(i,v)
  end
  list << ans
end
puts list.join(" ")
