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
  int n;
  ll x,y;
  cin >> n >> x >> y;

  vector<tuple<ll,ll,ll,ll>> vs;
  vs.pb({0,0,x-1,y-1});

  REP(_,n){
    char c;
    ll a,b;
    cin >> c >> a >> b;

    vector<tuple<ll,ll,ll,ll>> old;
    swap(old,vs);
    for(auto [x0,y0,x1,y1]: old){
      if(c == 'X'){
        if(x1 < a){
          vs.pb({x0,y0-b,x1,y1-b});
        }else if(x0 >= a){
          vs.pb({x0,y0+b,x1,y1+b});
        }else{
          vs.pb({x0,y0-b,a-1,y1-b});
          vs.pb({a,y0+b,x1,y1+b});
        }
      }else{
        if(y1 < a){
          vs.pb({x0-b,y0,x1-b,y1});
        }else if(y0 >= a){
          vs.pb({x0+b,y0,x1+b,y1});
        }else{
          vs.pb({x0-b,y0,x1-b,a-1});
          vs.pb({x0+b,a,x1+b,y1});
        }

      }
    } 
  }

  // for(auto [x0,y0,x1,y1]: vs){
  //   printf("%lld %lld %lld %lld\n",x0,y0,x1,y1);
  // }

  int sz=vs.size();
  dsu uf(sz);

  REP(i,sz)FOR(j,i+1,sz){
    auto [x0i,y0i,x1i,y1i] = vs[i];
    auto [x0j,y0j,x1j,y1j] = vs[j];

    if(x1i +1 == x0j || x1j + 1 == x0i){
      if(y0i <= y0j && y0j <= y1i)uf.merge(i,j);
      if(y0i <= y1j && y1j <= y1i)uf.merge(i,j);
      if(y0j <= y0i && y0i <= y1j)uf.merge(i,j);
      if(y0j <= y1i && y1i <= y1j)uf.merge(i,j);
    }

    if(y1i +1 == y0j || y1j +1 == y0i){
      if(x0i <= x0j && x0j <= x1i)uf.merge(i,j);
      if(x0i <= x1j && x1j <= x1i)uf.merge(i,j);
      if(x0j <= x0i && x0i <= x1j)uf.merge(i,j);
      if(x0j <= x1i && x1i <= x1j)uf.merge(i,j);
    }
  }

  auto g = uf.groups();
  // for(auto x: g){
  //   for(auto y: x){
  //     cout << y << " ";
  //   }
  //   cout << endl;
  // }

  vector<ll> ans;
  for(auto v: g){
    ll sum=0;
    for(auto x: v){
      auto [x0,y0,x1,y1] = vs[x];
      sum += (x1-x0+1) * (y1-y0+1);
    }
    ans.pb(sum);
  }
  sort(ALL(ans));
  cout << ans.size() << endl;
  for(auto x: ans)cout << x << endl;

}

