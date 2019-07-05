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

  def f(x,y)
    return 1 if(x==0 && y==0)
    return 0 if(x < y || y < 1)

    nCk(x-1,y-1)
  end
end

MOD=10**9+7
combi = Combi.new(1000000)

N,K=gets.chomp.split.map(&:to_i)


1.upto(K) do |i|
  ans=0
  ans = combi.f(K,i) * combi.f(N-K,i-1)
  ans += combi.f(K,i) * combi.f(N-K,i) * 2
  ans += combi.f(K,i) * combi.f(N-K,i+1)
  puts ans % MOD
end