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

  vector dist(n+1, vector<ll>(n+1,LINF));
  REP(i,n+1)dist[i][i]=0;
  REP(_,m){
    int a,b,c;
    cin >> a >> b >> c;
    chmin(dist[a][b],(ll)c);
    chmin(dist[b][a],(ll)c);
  }
  int k,t;
  cin >> k >> t;
  REP(_,k){
    int d;
    cin >> d;
    dist[d][0] = t;
    dist[0][d] = 0;
  }
  REP(k,n+1)REP(i,n+1)REP(j,n+1)chmin(dist[i][j], dist[i][k] + dist[k][j]);

  // REP(i,n+1)REP(j,n+1){
  //   printf("%d %d: %lld\n",i,j,dist[i][j]);
  // }

  int q;
  cin >> q;
  REP(_,q){
    int qq;
    cin >> qq;
    if(qq == 1){
      int x,y,tt;
      cin >> x >> y >> tt;

      chmin(dist[x][y],(ll)tt);
      chmin(dist[y][x],(ll)tt);

      REP(i,n+1)REP(j,n+1){
        chmin(dist[i][j],dist[i][x] + dist[y][j] + dist[x][y]);
        chmin(dist[i][j],dist[i][y] + dist[x][j] + dist[y][x]);
      }

    }else if(qq==2){
      int x;
      cin >> x;

      dist[x][0] = t;

      REP(i,n+1)REP(j,n+1){
        chmin(dist[i][j],dist[i][x] + dist[0][j] + t);
      }

      dist[0][x] = 0;

      REP(i,n+1)REP(j,n+1){
        chmin(dist[i][j],dist[i][0] + dist[x][j]);
      }


    }else{
      ll ans=0;
      FOR(i,1,n+1)FOR(j,1,n+1)ans += (dist[i][j] == LINF ? 0 : dist[i][j]);
      cout << ans << endl;
    }
  }

}

