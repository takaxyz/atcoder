class Node
  attr_accessor :id, :edges, :cost, :done
  def initialize(id)
    @id = id
    @edges = []
    @cost = nil
    @done = false
  end
end

class Edge
  attr_reader :cost, :to
  def initialize(to, cost)
    @cost, @to = cost, to
  end
end

N,M,T=gets.chomp.split.map(&:to_i)

nodes1 = []
nodes2 = []
N.times {|i| nodes1 << Node.new(i+1); nodes2 << Node.new(i+1)}
A=gets.chomp.split.map(&:to_i)

M.times do
  a,b,c=gets.chomp.split.map(&:to_i)
  nodes1[a-1].edges << Edge.new(b,c)
  nodes2[b-1].edges << Edge.new(a,c)
end

nodes1[0].cost = 0
nodes2[0].cost = 0

def solve(nodes)
  loop do
    doneNode = nil
    nodes.each do |node|
      next if node.done || node.cost == nil

      if doneNode == nil || node.cost < doneNode.cost
        doneNode = node
      end
    end

    break if doneNode == nil

    doneNode.done = true

    doneNode.edges.each do |edge|
      cost = doneNode.cost + edge.cost
      if nodes[edge.to-1].cost == nil || cost < nodes[edge.to-1].cost
        nodes[edge.to-1].cost = cost
      end
    end
  end
end

solve(nodes1)
solve(nodes2)

ans = 0
1.upto(N) do |i|
  c1 = nodes1[i-1].cost
  c2 = nodes2[i-1].cost
  a = A[i-1]
  next if c1 == nil
  next if T-c1-c2 < 0
  tmp = (T-c1-c2)*a
  ans = tmp if tmp > ans
end
puts ans