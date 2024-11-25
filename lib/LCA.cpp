// past201912-open K

struct LCA {
  int sz;
  vi dep;
  vvi edge;
  vvi dp;

  int logN;
  LCA(int n): sz(n),dep(n), edge(n) {
    logN = 1;
    while((1 << logN) <= n)logN++;
    dp.assign(logN, vi(n,-1));
  }

  void add(int src, int dst){
    edge[src].pb(dst);
    edge[dst].pb(src);
  }

  void dfs(int v, int p, int d){
    dp[0][v] = p;
    dep[v] = d;
    for(auto x: edge[v]){
      if(x==p)continue;
      dfs(x, v, d+1);
    }
  }

  void build(int root=0){
    dfs(root,-1,0);
    REP(i,logN-1)REP(j,sz){
      if(dp[i][j] == -1)dp[i+1][j] = -1;
      else dp[i+1][j] = dp[i][dp[i][j]];
    }
  }
  int query(int u, int v){
    if(dep[u] < dep[v])swap(u,v);
    REP(i,logN){
      if((dep[u] - dep[v]) >> i & 1){
        u = dp[i][u];
      }
    }

    if(u==v)return u;
    for(int i = logN-1; i >= 0; i--){
      if(dp[i][u] != dp[i][v]){
        u = dp[i][u];
        v = dp[i][v];
      }
    }
    return dp[0][u];

  }
};
