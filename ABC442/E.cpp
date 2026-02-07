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
//using P = pair<int,int>;
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

int main(){
  int n,q;
  cin >> n >> q;
  vector<P> p(n);
  REP(i,n)cin >> p[i].first >> p[i].second;

  vi id(n);
  iota(ALL(id),0);

  auto cross = [&](const P& x, const P& y){
    return x.first * y.second - x.second * y.first;
  };

  auto cmp = [&](const int i, const int j) -> bool{
    auto x = p[i];
    auto y = p[j];
    int x_up = ((x.second == 0 && x.first > 0) || x.second > 0);
    int y_up = ((y.second == 0 && y.first > 0) || y.second > 0);

    if(x_up != y_up)return x_up > y_up;

    return  cross(x,y) > 0;
  };

  sort(ALL(id), cmp);

  vi l(n),r(n);
  r[n-1]=n-1;
  FOR(i,1,n){
    if(!cmp(id[i-1], id[i]))l[i] = l[i-1];
    else l[i] = i;
  }
  for(int i = n-1; i > 0; i--){
    if(!cmp(id[i-1], id[i]))r[i-1] = r[i];
    else r[i-1] = i-1;
  }

  vi rev(n);
  REP(i,n)rev[id[i]]=i;

  REP(_,q){
    int a,b;
    cin >> a >> b;
    a--; b--;
    swap(a,b);
    int al = l[rev[a]];
    int br = r[rev[b]];

    if(al <= br)cout << br - al + 1 << endl;
    else cout << n + br - al + 1 << endl;

  }

  // for(auto x: id)cout << x << endl;
  // cout << endl;
  // for(auto x: l)cout << x << endl;
  // cout << endl;
  // for(auto x: r)cout << x << endl;
}

