#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;


int N, M;

vi dijkstra(int s, vvi edge){
  minPQ<P> q;

  vi dist(N,INF);

  dist[s]=0;
  q.push(P{0,s});
  while(!q.empty()){
    P v = q.top();q.pop();

    REP(i,edge[v.Se].size()){
      int n = edge[v.Se][i];
      
      if(dist[n] < v.Fi)continue;

      if(dist[n] > v.Fi + 1){
        dist[n] = v.Fi + 1;
        q.push(P{dist[n],n});
      }
    }
  }

  return(dist);
}

int dfs(int S, int v, int n, vvi &dp,vvi &edge){
 //  printf("%d %d\n", S, v);
   if(dp[S][v]>=0)return dp[S][v];

   if(S==((1<<n)-1) && v == 0)return dp[S][v] = 0;

   int tmp = INF;
   REP(i,n){
     if(edge[v][i]==INF)continue;
     if(!((S>>i) & 1)){
       chmin(tmp, dfs(S | (1<<i), i, n, dp, edge) + edge[v][i]);
     }

   }
//   cout << tmp << endl;
   return dp[S][v] = tmp;
}

int main(){
  cin >> N >> M;

  vvi edge(N, vi());
  REP(i,M){
    int u,v;
    cin >> u >> v;
    u--;v--;
    edge[u].eb(v);
    edge[v].eb(u);
  }

  vvi edge2(N);

  REP(i,N){
    edge2[i] = dijkstra(i, edge);
    // REP(j,N){
    //   cout << d[j] << (j==N-1 ? "\n":" ");
    // }
  }

  int s, K;
  cin >> s >> K;
  s--; 
  vi t(K+1);
  REP(i,K){
    int tt;
    cin >> tt; tt--;
    t[i+1] = tt;
  }
  t[0]=s;

  // K+1ノードのTSPに変換する
  K++;
  vvi dp((1<<K), vi(K, INF));

//  REP(i,K)cout << t[i] << (i==K-1?"\n":" ");
  vvi edge3(K, vi(K,INF));
  REP(i,K)REP(j,K){
    //t[i] - t[j]
    edge3[i][j] = edge2[t[i]][t[j]];
    edge3[j][i] = edge2[t[j]][t[i]];
  }

  // REP(i,K)REP(j,K){
  //   cout << edge3[i][j] << (j==K-1 ? "\n":" ");
  // }

  REP(i,(1<<K))REP(j,K)dp[i][j]=-1;
  dfs(1,0,K,dp,edge3);
  int ans=INF;
  REP(i,(1<<K))REP(j,K){
    cout << i << " " << j << " : " << dp[i][j] << endl;
  }

  PRINT(ans);
}

