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

def pow(base, exponent)
    result = 1
    while exponent > 0
      result = result*base if exponent%2 == 1
      exponent = exponent >> 1
      base = base*base
    end
    return result
end

MOD = 998244353
combi = Combi.new(200002,998244353)
n,m,k=gets.chomp.split.map(&:to_i)

ans = 0
col = m * pow(m-1, n-k-1)
k.downto(0) do |kk|
    ans += col * combi.nCk(n-1,kk)
    ans %= MOD
    col *= (m-1)
end
puts ans


