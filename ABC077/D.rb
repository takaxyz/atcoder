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
      @fac[n] * @finv[n - k] * @finv[k] % @mod
  end
end

MOD=10**9+7
combi = Combi.new(1000000)

N=gets.to_i
a=gets.chomp.split.map(&:to_i)

cnt = Hash.new(0)
a.each {|v| cnt[v]+=1}

m = nil
cnt.each {|k,v| m = k if v == 2}
pos=[]
a.each_with_index do |v,i|
  pos << i if v == m
end 
puts N
2.upto(N+1) do |i|
  if N+1-(pos[1]-pos[0]+1) >= i-1
    puts (combi.nCk(N+1,i) - combi.nCk(N+1-(pos[1]-pos[0]+1), i-1)) % MOD
  else
    puts combi.nCk(N+1,i)
  end
end
