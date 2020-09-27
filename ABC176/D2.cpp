#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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
const int MOD = 1e9 + 7;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){
  int H,W;
  cin >> H >> W;
  int ch, cw, dh, dw;
  cin >> ch >> cw >> dh >> dw;
  ch--;cw--;dh--;dw--;

  vector<string> s(H);
  REP(i,H)cin >> s[i];

  deque<P> q;
  q.emplace_back(ch,cw);

  vvi dist(H, vi(W,INF));
  dist[ch][cw]=0;

  while(!q.empty()){
    int x = q.front().Fi;
    int y = q.front().Se;
//    printf("%d : %d -- %d\n",x,y,dist[x][y]);
    q.pop_front();
    int now = dist[x][y];

    if(dist[x][y] != now) continue;
    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
      if(s[nx][ny]=='#')continue;
      if(dist[nx][ny]<=now)continue;
      dist[nx][ny]=now;
      q.emplace_front(nx,ny);
    }

    FOR(i,-2,3)FOR(j,-2,3){
      int nx=x+i;
      int ny=y+j;
      if(nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
      if(s[nx][ny]=='#')continue;
      if(dist[nx][ny]<=now+1)continue;
      dist[nx][ny] = now+1;

      q.emplace_back(nx,ny);
    }
  }

  // REP(i,H)REP(j,W){
  //   cout << dist[i][j] << (j==W-1 ? "\n" : " ");
  // }

  int ans = dist[dh][dw];
  if(ans==INF)ans=-1;
  cout << ans << endl;
}

