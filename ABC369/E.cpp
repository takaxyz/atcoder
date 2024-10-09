#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
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

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int n,m;
  cin >> n >> m;
  
  vector<tuple<int,int,ll>> edge(m);
  vector d(n, vector<ll>(n,LINF));

  REP(i,m){
    int u,v;
    ll t;
    cin >> u >> v >> t;
    u--; v--;
    chmin(d[u][v], t);
    chmin(d[v][u], t);
    edge[i] = {u,v,t};
  }
  REP(i,n)d[i][i]=0;
  REP(k,n)REP(i,n)REP(j,n)chmin(d[i][j], d[i][k] + d[k][j]);

  int q;
  cin >> q;
  while(q--){
    int k;
    cin >> k;
    vi b(k);
    REP(i,k){
      cin >> b[i];
      b[i]--;
    }

    sort(ALL(b));

    ll ans = LINF; 
    do{
      REP(i, (1<<k)){
        ll dist = 0;
        vector<P> rt;
        REP(j,k){
          auto [u,v,t] = edge[b[j]];
          if((i >> j) & 1){
            rt.emplace_back(u,v);
          }else{
            rt.emplace_back(v,u);
          }
          dist += t;
        }

        REP(i,k){
          if(i == 0)dist += d[0][rt[i].first];
          else dist += d[rt[i-1].second][rt[i].first];
        }
        dist += d[rt[k-1].second][n-1]; 
        chmin(ans, dist);
      }
    }while(next_permutation(ALL(b)));
    cout << ans << endl;
  }
}

