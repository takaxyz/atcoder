  // k : 最大値
  // a[i] : i の1つ先


  int logK = 1;
  while((1ll << logK) <= k)logK++;

  vvi dp(logK+1, vi(n));
  REP(i,n)dp[0][i] = a[i];
  REP(i,logK)REP(j,n)dp[i+1][j] = dp[i][dp[i][j]];

  int now = 0;
  for(int i = logK; i >= 0; i--){
    if((k >> i) & 1)now = dp[i][now];
  }

