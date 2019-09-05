$MOD=10**9+7

class Combi
  def initialize(max_n, mod = 10**9+7)
      @mod = mod
      @max_n = max_n

      @fac = Array.new(@max_n+1)
      @inv = Array.new(@max_n+1)
      @finv = Array.new(@max_n+1)

      @fac[0] = @fac[1] = 1
      @finv[0] = @finv[1] = 1
      @inv[1] = 1
      2.upto(@max_n) do |i|
          @fac[i] = @fac[i-1] * i % @mod
          @inv[i] = @mod - @inv[@mod%i] * (@mod/i) % @mod
          @finv[i] = @finv[i-1] * @inv[i] % @mod
      end
  end

  def nCk(n,k)
    return 0 if(n<0 || k<0 || k>n) 
    @fac[n] * @finv[n - k] * @finv[k] % @mod
  end
  def nPk(n,k)
    return 0 if(n<0 || k<0 || k>n)
    #@fac[n] * @finv[n - k] % @mod
    nCk(n,k) * @fac[k] % @mod
  end
end

$combi = Combi.new(1000000)

$n,$k=gets.chomp.split.map(&:to_i)
$edge = Array.new($n).map{Array.new()}

($n-1).times do
  a,b=gets.chomp.split.map(&:to_i)
  a -= 1
  b -= 1
  $edge[a] << b;
  $edge[b] << a;
end


$ans=1

stack = [0]
visited = [false] * $n

while(!stack.empty?)
  i = stack.pop
  visited[i] = true
  if i==0
    $ans = $combi.nPk($k,$edge[0].size+1)
  else
    $ans *= $combi.nPk($k-2,$edge[i].size-1)
  end
  $ans %= $MOD
  $edge[i].each do |v|
    next if visited[v] == true
    stack << v
  end  
end

puts $ans

