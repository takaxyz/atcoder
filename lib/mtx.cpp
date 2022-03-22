vector<vector<mint>> mtxmul(vector<vector<mint>> &x, vector<vector<mint>>& y){
  int s = x.size();
  int t = x[0].size();
  int u = y[0].size();
  vector<vector<mint>> res(s, vector<mint>(u, 0));

  REP(i,s)REP(j,u)REP(k,t){
    res[i][j] +=  x[i][k] * y[k][j];
  }

  return res;
}

vector<vector<mint>> mtxpow(vector<vector<mint>> &x, ll n){
  vector<vector<mint>> res(x.size(), vector<mint>(x.size()));

  if(n==0){
    REP(i,x.size()){
      res[i][i]=1;
    }
    return res;
  }

  res = mtxpow(x, n/2);
  res = mtxmul(res, res);
  if(n & 1){
    res = mtxmul(res, x);
  }
  return res;
}

