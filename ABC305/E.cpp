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

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vvi edge(n);
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].pb(b);
    edge[b].pb(a);
  }
  vvi hs(n+1);
  vi d(n,-1);
  REP(i,k){
    int p, h;
    cin >> p >> h;
    p--;
    hs[h].pb(p);
    d[p] = h;
  }
  for(int i = n; i>0; i--){
    for(auto v: hs[i]){
      //cout << i << " " << v << endl;
      for(auto nv : edge[v]){
        if(d[nv] < i-1){
          d[nv]=i-1;
          hs[i-1].pb(nv);
        }
      }
    }
  }
  vi ans;
  REP(i,n)if(d[i]>=0)ans.pb(i);
  sort(ALL(ans));
  cout << ans.size() << endl;
  REP(i,ans.size())cout << ans[i]+1 << endl;
}

