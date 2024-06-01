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
// using P = pair<int,int>;
using P = pair<ll,int>;
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

  vi k(m);
  vector<P> c(m);
  vvi a(m,vi());
  REP(i,m){
    cin >> k[i];
    cin >> c[i].first;
    c[i].second = i;
    REP(j,k[i]){
      int aa;
      cin >> aa;
      aa--;
      a[i].pb(aa);
    }
  }

  sort(ALL(c));
  // for(auto [cost, i]: c)cout << cost << " " << i << endl;

  dsu uf(n);

  int cnt=0;
  ll ans=0;
  REP(i, m){
    auto [cost,idx] = c[i];

    int v = a[idx][0];

    FOR(j,1,k[idx]){
      if(!uf.same(v, a[idx][j])){
        uf.merge(v, a[idx][j]);
        ans += cost;
        cnt++;
      }

      if(cnt==n-1){
        cout << ans << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
}

