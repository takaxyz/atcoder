

def solve(dp,a,left,right,turn)
  if dp[left][right] != nil
    return dp[left][right]
  end

  if left == right
    if turn.odd?
    # Tao
      return dp[left][right] = a[left]
    else
    # Jiro
      return dp[left][right] = -a[left]  
    end
  end

  if turn.odd?
    # taro
    l = solve(dp,a,left,right-1,turn+1) + a[right]
    r = solve(dp,a,left+1,right,turn+1) + a[left]
    if l < r
      dp[left][right] = r
    else
      dp[left][right] = l
    end
  else
    # jiro
    l = solve(dp,a,left,right-1,turn+1) - a[right]
    r = solve(dp,a,left+1,right,turn+1) - a[left]
    if l < r
      dp[left][right] = l
    else
      dp[left][right] = r
    end
  end

  dp[left][right]
end

N=gets.to_i
a=gets.chomp.split.map(&:to_i)
dp=Array.new(N).map{Array.new(N,nil)}

solve(dp,a,0,N-1,1)

puts dp[0][N-1]

