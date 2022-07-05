for(int i = 0; i < l; i++){
    for(int smaller = 0; smaller < 2; smaller++){
      for(int j = 0; j < 2; j++){
        for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
          dp[i + 1][smaller || x < n[i]][j || x == 3] += dp[i][smaller][j];          
        }
      }
    }
  }

