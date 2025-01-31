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

int dx[] = {1,0,-1,1,-1,0};
int dy[] = {1,1,1,0,0,-1};

const int BASE = 250;
const int MAX = 500;

int main(){
  int n,x,y;
  cin >> n >> x >> y;
  x += BASE; y += BASE;
  vvi d(MAX, vi(MAX,-1));
  REP(_,n){
    int xx,yy;
    cin >> xx >> yy;
    xx += BASE; yy += BASE;
    d[xx][yy]=INF;
  }

  queue<P> q;
  q.push({BASE,BASE});
  d[BASE][BASE]=0;
  while(!q.empty()){
    auto [xx,yy] = q.front();
    q.pop();
    REP(i,6){
      int nx = xx + dx[i];
      int ny = yy + dy[i];
      if(nx <0 || nx >= MAX || ny < 0 || ny >= MAX)continue;
      if(d[nx][ny]==INF)continue;
      if(d[nx][ny]!=-1)continue;
      d[nx][ny] = d[xx][yy]+1;
      q.push({nx,ny});
    }
  }
  cout << d[x][y] << endl;
}

