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

combi = Combi.new(300000)

n,k=gets.chomp.split.map(&:to_i)

k.upto(n+1) do |i|
  puts combi.nCk(n+1,i)
end
