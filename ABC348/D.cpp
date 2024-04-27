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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


struct Med {
  int r,c,e;
  Med(){}
  Med(int r,int c,int e) : r(r),c(c),e(e) {}
};

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> a(h);
  REP(i,h)cin >> a[i];

  int sx=0,sy=0,tx=0,ty=0;
  REP(i,h)REP(j,w){
    if(a[i][j]=='S')sx=i,sy=j;
    if(a[i][j]=='T') tx=i,ty=j;
  }

  int n;
  cin >> n;

  vector<Med> meds;

  REP(_,n){
    int r,c,e;
    cin >> r >> c >> e;
    r--; c--;
    meds.emplace_back(r,c,e);
  }
  meds.emplace_back(tx,ty,0);
  n++;

  int sv=-1;
  REP(i,n){
    auto [r,c,e] = meds[i];
    if(r == sx && c == sy)sv=i;
  }

  if(sv==-1){
    cout << "No" << endl;
    return 0;
  }


  vvi edge(n);

  REP(v,n){
    queue<P> q;
    vvi d(h,vi(w,INF));

    auto[xx,yy,ee] = meds[v];

    q.push({xx,yy});
    d[xx][yy]=0;
    while(!q.empty()){
      auto [x,y] = q.front();
      q.pop();

      REP(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
        if(a[nx][ny]=='#')continue;
        if(d[nx][ny]!=INF)continue;

        d[nx][ny] = d[x][y]+1;

        q.push({nx,ny});
      }
    }

    REP(i,n){
      if(i!=v){
        auto[r,c,e] = meds[i];
        if(d[r][c] <= ee)edge[v].pb(i);
      }
    }
  }

  // cout << sv << endl;
  // REP(i,n){
  //   for(auto x: edge[i])cout << i << " " << x << endl;
  // }


  vi d(n,INF);

  queue<int> q;
  q.push(sv);
  d[sv]=0;

  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(auto nv: edge[v]){
      if(d[nv]!=INF)continue;

      d[nv] = d[v]+1;
      q.push(nv);
    }
  }

  cout << (d[n-1] != INF ? "Yes" : "No") << endl;


}

