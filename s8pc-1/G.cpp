#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

const int MAXN = 16;

int n,m;
ll dp[(1<<MAXN)][MAXN];
int cnt[(1<<MAXN)][MAXN];

struct eg{
  ll t;
  ll d;
  ll time;
};

vector<vector<eg>> edge;

int dfs(int S, int v){
  printf("dfs %d %d\n", S, v);
  //if(dp[S][v]>=0)return dp[S][v];

  if(S==((1<<n)-1) && v == 0)return dp[S][v] = 0;

  int tmp = INF;
  for(auto &p : edge[v]){
    if(p.time < dp[S][v] + p.d)continue;

    int i = p.t;
    printf("%d %d\n",v,i);

    if(!((S>>i) & 1)){
      int next = S | (1<<i);
      if(dp[next][i] > dp[S][i] + p.d){
        cnt[next][i] = cnt[S][v]; 
        dp[next][i] = dp[S][i] + p.d;
        printf("aa %d %d %d\n", next, i, dp[next][i]);
      }else if(dp[next][i] == dp[S][i] + p.d){
        cnt[next][i] += cnt[S][v]; 
      }
    }

  }
//  cout << tmp << endl;
}


int main(){
  cin >> n >> m;
  edge.resize(n);

  REP(i,(1<<n))REP(j,n)dp[i][j]=INF;
  REP(i,(1<<n))REP(j,n)cnt[i][j]=0;
  cnt[0][0] = 1;
  dp[0][0] = 0;

  REP(i,m){
    ll s,t,d,time;
    cin >> s >> t >> d >> time;
    s--;t--;
    eg e = {t,d,time};
    edge[s].emplace_back(e);
    eg e2 = {s,d,time};
    edge[t].emplace_back(e2);
  }

  dfs(0,0);

  REP(i,(1<<n))REP(j,n){
    cout << i << " " << j << " " << dp[i][j] << endl;
  }

  if(dp[(1<<n)-1][0] == INF){
    cout << "IMPOSSIBLE" << endl;
  }else{
    cout << dp[(1<<n)-1][0] << " " << cnt[(1<<n)-1][0] << endl;
  }



}

