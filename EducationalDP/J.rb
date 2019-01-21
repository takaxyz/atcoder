N=gets.to_i
a=gets.chomp.split.map(&:to_i)
h=Hash.new(0)
a.each do |v|
  h[v] += 1
end
dp = Array.new(N+2).map{Array.new(N+2).map{Array.new(N+2,0.0)}}
dp[0][0][0] = 0.0;

0.upto(N) do |i|
  0.upto(N) do |j|
    0.upto(N) do |k|
      next if i + j + k == 0

      res = N
      p = 1.0

      if i > 0
        p += i.to_f * dp[i-1][j+1][k] / N
        res -= i
      end
      if j > 0
        p += j.to_f * dp[i][j-1][k+1] / N
        res -= j
      end
      if k > 0
        p += k.to_f * dp[i][j][k-1] / N
        res -= k
      end

      r = N.to_f / (N-res)

      dp[i][j][k] = r * p
    end
  end
end
p dp[h[3]][h[2]][h[1]]