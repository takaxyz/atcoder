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

using P = pair<ll,ll>;

void solve(){
  int n;
  cin >> n;

  vector<P> vs;
  REP(_,n){
    ll x,y;
    cin >> x >> y;
    vs.emplace_back(x,y);
  }

  auto cmp = [](P const &i, P const &j) -> bool{
    auto [x,y] = i;
    auto [u,v] = j;

    int zi = (y > 0 || (y==0 && x > 0)) ? 0 : 1;
    int zj = (v > 0 || (v==0 && u > 0)) ? 0 : 1;

    if(zi != zj)return zi < zj;

    return x * v - y * u > 0;
  };

  sort(ALL(vs), cmp);
  vs.insert(vs.begin(),ALL(vs));

  int ans = 0;
  int r = 0;
  REP(l,n){
    chmax(r, l+1);

    auto [x,y] = vs[l];
    while(r < l+n){
      auto [u,v] = vs[r];
      if(x*v - y*u <= 0)break;
      r++;
    }
    chmax(ans, r - l);
  }

  //for(auto [x,y]: vs)printf("%lld %lld\n",x,y);

  cout << ans << endl;
}


int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

