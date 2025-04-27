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

int dx[] ={1,0,-1,0};
int dy[] ={0,1,0,-1};

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  a--; b--; c--; d--;
  vvi dist(h,vi(w,INF));
  
  dist[a][b]=0;
  deque<P> q;
  q.push_front({a,b});

  while(!q.empty()){
    auto [x,y] = q.front();
    q.pop_front();
  
    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
      if(s[nx][ny]=='.'){
        if(dist[nx][ny] > dist[x][y]){
          dist[nx][ny]=dist[x][y];
          q.push_front({nx,ny});
        }
      }else{
        if(dist[nx][ny] > dist[x][y]){
          dist[nx][ny]=dist[x][y] + 1;
          q.push_back({nx,ny});
        }
        int nx2 = nx + dx[i];
        int ny2 = ny + dy[i];
        if(nx2 < 0 || nx2 >= h || ny2 < 0 || ny2 >= w)continue;
        if(dist[nx2][ny2] > dist[x][y]+1){
          dist[nx2][ny2]=dist[x][y]+1;
          q.push_back({nx2,ny2});
        }
      }
    }
  }


  cout << dist[c][d] << endl;

}

