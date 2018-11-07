h,w,k=gets.chomp.split.map(&:to_i)
dp=Array.new(h+1).map{Array.new(w)}

MOD = 1000000007

nn = [1,2,3,5,8,13,21,34]

dp[0][0] = 1
1.upto(w-1) do |i|
    dp[0][i] = 0
end

if w == 1
    puts 1
    exit
end

1.upto(h) do |i|
    0.upto(w-1) do |j|
        dp[i][j] = 0
        if(j==0)
            dp[i][j] += dp[i-1][j] * nn[w-2]
            dp[i][j] += dp[i-1][j+1] * nn[[0,w-3].max]
        elsif(j==w-1)
            dp[i][j] += dp[i-1][j] * nn[w-2]
            dp[i][j] += dp[i-1][j-1] * nn[[0,w-3].max]
        else
            n = nn[[0,j-2].max]
            n *= nn[[0,w-2-j].max]
            dp[i][j] += dp[i-1][j-1] * n

            n = nn[j-1]
            n *= nn[[0,w-2-j].max]
            dp[i][j] += dp[i-1][j] * n

            n = nn[j-1]
            n *= nn[[0,w-3-j].max]
            dp[i][j] += dp[i-1][j+1] * n
        end
        dp[i][j] = dp[i][j] % MOD
    end
end

#p dp
puts dp[h][k-1] % MOD


