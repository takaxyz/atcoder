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
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  int sx,sy,gx,gy;
  REP(i,h)REP(j,w){
    if(s[i][j]=='S'){
      sx=i;
      sy=j;
    }else if(s[i][j]=='G'){
      gx = i;
      gy = j;
    }
  }


  vvi dx(2,vi());
  vvi dy(2,vi());

  dx[0] = {1,-1};
  dx[1] = {0,0};
  dy[0] = {0,0};
  dy[1] = {1,-1};


  int ans=INF;

  REP(di,2){
    vvi dist(h,vi(w, INF));
    queue<tuple<int,int,int>> q;
    q.emplace(sx,sy,di);
    dist[sx][sy]=0;

    while(!q.empty()){
      auto [x,y,d] = q.front();
      q.pop();
      REP(i,2){
        int nx = x + dx[d][i];
        int ny = y + dy[d][i];

        if(nx < 0 || nx >= h || ny < 0 || ny >=w)continue;

        if(s[nx][ny]=='#')continue;
        if(dist[nx][ny] <= dist[x][y]+1)continue;

        dist[nx][ny] = dist[x][y]+1;
        q.emplace(nx,ny, d ^ 1);
      }
    }

    chmin(ans,dist[gx][gy]);

  }

  cout << (ans == INF ? -1 : ans) << endl;

}

