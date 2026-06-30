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

vi f(int n, vvi& e){

  auto dfs = [&](int v, int p, vvi& e, vi& d, auto dfs) -> void{
    for(auto nv: e[v]){
      if(nv == p)continue;
      d[nv] = d[v]+1;
      dfs(nv, v, e, d, dfs);
    }
  };

  vi d1(n);
  dfs(0,-1,e,d1,dfs);
  int x = distance(d1.begin(), max_element(ALL(d1)));
  d1 = vi(n);
  dfs(x,-1,e,d1,dfs);
  int y = distance(d1.begin(), max_element(ALL(d1)));

  vi d2(n);
  dfs(y,-1,e,d2,dfs);

  vi d3(n);
  REP(i,n)d3[i]=max(d2[i],d1[i]);

  sort(ALL(d3));
  return d3;
}



int main(){
  int n1;
  cin >> n1;
  vvi e1(n1);
  REP(_,n1-1){
    int u,v;
    cin >> u >> v;
    u--;v--;
    e1[u].pb(v);
    e1[v].pb(u);
  }
  int n2;
  cin >> n2;
  vvi e2(n2);
  REP(_,n2-1){
    int u,v;
    cin >> u >> v;
    u--;v--;
    e2[u].pb(v);
    e2[v].pb(u);
  }

  vi d1 = f(n1,e1);
  vi d2 = f(n2,e2);
  int mx = max(*max_element(ALL(d1)), *max_element(ALL(d2)));

  vector<ll> s(n2+1);
  REP(i,n2)s[i+1] = s[i]+d2[i];

  // REP(i,n1)cout << d1[i] << (i==n1-1 ? "\n":" ");
  // REP(i,n2)cout << d2[i] << (i==n2-1 ? "\n":" ");
  // REP(i,n2+1)cout << s[i] << (i==n2 ? "\n":" ");
  // cout << mx << endl;
  ll ans=0;
  REP(i,n1){
    int j = lower_bound(ALL(d2), mx - d1[i]-1) - d2.begin();
    //cout << j << endl;
    ans += (ll)mx * j;
    ans += (ll)(s[n2] - s[j]) + (ll)(d1[i] + 1)*(n2-j);
  }
  cout << ans << endl;
}

