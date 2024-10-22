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
  int n,m,q;
  cin >> n >> m >> q;

  vector d(n,vector<ll>(n,LINF));
  REP(i,n)d[i][i]=0;

  vector<tuple<int,int,ll>> r(m);

  REP(i,m){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    d[a][b]=c;
    d[b][a]=c;
    r[i] = {a,b,c};
  }


  vector<tuple<int,int,int>> Q(q);
  REP(i,q){
    int t;
    cin >> t;
    if(t==1){
      int j;
      cin >> j;
      j--;
      Q[i] = {t, j, 0};
      auto [a,b,c] = r[j];
      d[a][b]=LINF;
      d[b][a]=LINF;
    }else{
      int x,y;
      cin >> x >> y;
      x--; y--;
      Q[i] = {t,x,y};
    }
  }
  reverse(ALL(Q));

  REP(k,n)REP(i,n)REP(j,n)chmin(d[i][j],d[i][k]+d[k][j]);

  vector<ll> ans;
  for(auto [t, x, y] : Q){
    if(t == 2){
      ans.pb(d[x][y]);
    }else{
      auto [a,b,c] = r[x];
      chmin(d[a][b],c);
      chmin(d[b][a],c);

      REP(i,n)REP(j,n){
        chmin(d[i][j],d[i][a] + c + d[b][j]);
        chmin(d[i][j],d[i][b] + c + d[a][j]);
      }

    }
  }
  reverse(ALL(ans));
  for(auto x: ans)cout << (x == LINF ? -1 : x ) << endl;
}

