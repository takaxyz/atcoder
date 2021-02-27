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

vector<string> s;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n,m;

int bfs(int x, int y){
  vector<vector<bool>> visited(n,vector<bool>(m,false));
  int ret=0;
  queue<P> q;
  ret++;
  q.push({x,y});
  visited[x][y]=true;

  while(!q.empty()){
    P p = q.front();
    q.pop();
    int xx = p.first;
    int yy = p.second;
    REP(i,4){
      int nx = xx + dx[i];
      int ny = yy + dy[i];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
      if(visited[nx][ny]==true)continue;
      if(s[nx][ny]=='#')continue;

      ret++;
      visited[nx][ny]=true;
      q.push({nx,ny});
    }
  }
  return ret;
}

int main(){
  cin >> n >> m;
  s.resize(n);
  REP(i,n)cin >> s[i];
  int cnt=0;
  REP(i,n)REP(j,m)if(s[i][j]=='.')cnt++;

  int ans=0;
  REP(i,n)REP(j,m){
    if(s[i][j]=='#'){
      s[i][j]='.';
      int x = bfs(i,j);
      if(x==cnt+1){
        ans++;
      }
      s[i][j]='#';
    }
  }
  cout << ans << endl;
}

