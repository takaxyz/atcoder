#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int dfs(vector<vector<int>> &a, int n, vector<int> &g, int emp, int grp){
  int ret;
  if(n < emp){
    ret=0;
    FOR(i,1,n)FOR(j,i+1,n+1){
      if(g[i]==g[j]){
        ret += a[i][j];
      }
    }
    return ret;
  }else{
    ret=-100000000;
    g[emp] = grp;
    REP(i,3){
      ret = max(ret,dfs(a,n,g,emp+1,i));
    }
  }
  return ret;
}

int main(){
  int N;
  cin >> N;
  vector<vector<int>> a(N+1,vector<int>(N+1));

  FOR(i,1,N)FOR(j,i+1,N+1)cin >> a[i][j];

  vector<int> g(N+1,0);
  int ans = dfs(a,N,g,1,0);
  cout << ans << endl;
}

