N=gets.to_i
ACGT=['A','C','G','T']
MOD=10**9+7
dp = {}
ACGT.each do |c1|
  ACGT.each do |c2|
    ACGT.each do |c3|
      c = c1+c2+c3
      dp[c] = [0]*102
      if c == 'AGC' || c == 'ACG' || c == 'GAC'
      else
        dp[c][3] = 1
      end
    end
  end
end
4.upto(N) do |i|
  ACGT.each do |c1|
    ACGT.each do |c2|
      ACGT.each do |c3|
        ACGT.each do |c4|
          c = c1+c2+c3+c4
          if c.match(/AGC/) || c.match(/GAC/) || c.match(/ACG/) || c.match(/A.GC/) || c.match(/AG.C/)
          else
            dp[c2+c3+c4][i] += dp[c1+c2+c3][i-1]         
            dp[c2+c3+c4][i] %= MOD
          end
        end
      end
    end  
  end
end
ans = 0
dp.each_key do |k|
  ans += dp[k][N]
end
puts ans%MOD

