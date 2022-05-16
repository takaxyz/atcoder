#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

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

int n,m,q,k;
vvi edge;
vi a;

vi bfs(int s){
  queue<int> q;
  q.push(s);
  vi d(n,-1);
  d[s]=0;

  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto w: edge[v]){
      if(d[w]!=-1)continue;
      d[w] = d[v] + 1;
      q.push(w);
    }
  }
  return d;
}

int main(){
  cin >> n >> m >> q >> k;
  edge.reserve(n);
//  REP(i,k)d[i] = vi(n,-1);
  a.reserve(k);
  REP(i,k){
    cin >> a[i];
    a[i]--;
  }
  REP(i,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }

  vvi dd(n, vi());

  REP(i,k)dd[a[i]] = bfs(a[i]);

  // REP(i,n)REP(j,n){
  //   cout << i << " " << j << " " << d[i][j] << endl;
  // }
  REP(i,q){
    int s,t;
    cin >> s >> t;
    s--; t--;
    int ans=INF;
    REP(i,k){
      chmin(ans, dd[a[i]][s] + dd[a[i]][t]);
    }
    cout << ans << endl;
  }

}

