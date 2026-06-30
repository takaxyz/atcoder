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

int dx[] ={0,1};
int dy[] ={1,0};

int main(){
  int n,m;
  cin >> n >> m;

  vector a(n,vector<ll>(n));

  REP(i,n)REP(j,n){
    cin >> a[i][j];

    REP(_, 2*n-2-i-j){
      a[i][j] *= 10;
      a[i][j] %= m;
    }
  }

  vector<set<ll>> st(n);
  REP(i,1 << (n-1)){
    int p = __builtin_popcount(i);

    int x = 0, y = 0;
    ll score = a[x][y];
    REP(j,n-1){
      int d = (i >> j) & 1;
      x += dx[d];
      y += dy[d];
      score += a[x][y];
      score %= m;
    }
    st[p].insert(score);
  }

  vector<set<ll>> st2(n);
  REP(i,1 << (n-1)){
    int p = __builtin_popcount(i);
    int x = n - p - 1;
    int y = p;
    ll score = 0;

    REP(j,n-1){
      int d = (i >> j) & 1;
      x += dx[d];
      y += dy[d];
      score += a[x][y];
      score %= m;
    }
    st2[n-p-1].insert(score);
  }


  // REP(i,n){
  //   cout << i << ":" <<  endl;
  //   for(auto x: st[i])cout << x << endl;
  // }
  // REP(i,n){
  //   cout << i << ":"  << endl;
  //   for(auto x: st2[i])cout << x << endl;
  // }

  ll ans=-1;
  REP(i,n){
    for(auto x: st[i]){
      auto it = st2[i].lower_bound(m-x);
      if(it != st2[i].begin()){
        it--;
      }else{
        it = max_element(ALL(st2[i]));
      }
      chmax(ans,(*it + x) % m);
    }
  }
  cout << ans << endl;

}

