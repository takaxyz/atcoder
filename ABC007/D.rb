
def solve(s, i, dp)
  return dp[i-1][0] + dp[i-1][1] if(i == s.size)

  if(i==0)
    if s[i] == 9
      dp[i][0] = s[i] - 1
      dp[i][1] = 0
    elsif 4 < s[i]
      dp[i][0] = s[i] - 1
      dp[i][1] = 1
    elsif 4 == s[i] 
      dp[i][0] = 4
      dp[i][1] = 0
    else 
      dp[i][0] = s[i]
      dp[i][1] = 1
    end 
  else
    if s[i] == 9
      dp[i][0] = dp[i-1][0] * 8 + dp[i-1][1] * 8 
      dp[i][1] = dp[i-1][1] * 0
    elsif 4 < s[i]
      dp[i][0] = dp[i-1][0] * 8 + dp[i-1][1] * (s[i] - 1)
      dp[i][1] = dp[i-1][1]
    elsif 4 == s[i] 
      dp[i][0] = dp[i-1][0] * 8 + dp[i-1][1] * 4
      dp[i][1] = dp[i-1][1] * 0
    else 
      dp[i][0] = dp[i-1][0] * 8 + dp[i-1][1] * s[i]
      dp[i][1] = dp[i-1][1]
    end 
  end

  solve(s,i+1,dp)    

end

A,B=gets.chomp.split.map(&:to_i)

dp = Array.new(B.to_s.size).map{Array.new(2,0)}
b = solve(B.to_s.split("").map(&:to_i), 0, dp)

dp = Array.new((A-1).to_s.size).map{Array.new(2,0)}
a = solve((A-1).to_s.split("").map(&:to_i), 0,dp)

puts (B-A+1)-(b - a)
