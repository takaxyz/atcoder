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
const int MOD = 1e9 + 7;


void solve(){
  int n, m;
  cin >> n >> m;
  vi c(n);
  REP(i,n)cin >> c[i];

  vvi edge(n);
  REP(i,m){
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].pb(v);
    edge[v].pb(u);
  }

  queue<P> q;
  q.push({0,n-1});
  vvi d(n, vi(n,-1));
  d[0][n-1]=0;
  while(!q.empty()){
    auto [ta, ao] = q.front();
    q.pop();

    // ta: 0, ao: 1
    REP(i,2){
      vi tto, ato;
      for(auto v: edge[ta]){
        if(c[v]==(1^i))continue;
        tto.push_back(v);
      }
      for(auto v: edge[ao]){
        if(c[v]==(0^i))continue;
        ato.push_back(v);
      }

      for(auto x: tto){
        for(auto y: ato){
          if(d[x][y]!=-1)continue;
          d[x][y] = d[ta][ao]+1;
          q.push({x,y});
        }
      }
    }
  }
  cout << d[n-1][0] << endl;

}

int main(){
  int t;
  cin >> t;

  REP(_, t)solve();
}

