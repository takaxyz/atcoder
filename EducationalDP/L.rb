N=gets.to_i
a=gets.chomp.split.map(&:to_i)
dp=Array.new(N).map{Array.new(N)}
0.upto(N-1) do |i|
  if N.even?
    dp[i][i] = -a[i]
  else
    dp[i][i] = a[i]
  end
end

0.upto(N-1) do |i|
  0.upto(N-1) do |j|
    next if i + j > N - 1

    if j == i+j
      if N.even?
        dp[j][i+j] = -a[i+j]
      else
        dp[j][i+j] = a[i+j]
      end    
    else
      if (N+j-(i+j)).odd?
        # Taro
        if i+j-1 >= 0
          dp[j][i+j] = dp[j][i+j-1] + a[i+j] if dp[j][i+j] == nil || dp[j][i+j] < dp[j][i+j-1] + a[i+j]
        end
        if j+1 < N
          dp[j][i+j] = dp[j+1][i+j] + a[j] if dp[j][i+j] == nil || dp[j][i+j] < dp[j+1][i+j] + a[j]
        end
      else
        # Jor
        if i+j-1 >= 0
          dp[j][i+j] = dp[j][i+j-1] - a[i+j] if dp[j][i+j] == nil || dp[j][i+j] > dp[j][i+j-1] - a[i+j]
        end
        if j+1 < N
          dp[j][i+j] = dp[j+1][i+j] - a[j] if dp[j][i+j] == nil || dp[j][i+j] > dp[j+1][i+j] - a[j]
        end
      end
    end
  end
end

puts dp[0][N-1]