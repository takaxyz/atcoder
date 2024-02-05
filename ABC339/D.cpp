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
const int MOD = 1e9 + 7;

int d[61][61][61][61];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
 
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  vi st;
  REP(i,n)REP(j,n){
    if(s[i][j]=='P'){
      st.pb(i);
      st.pb(j);
    }
  }

  REP(i,n)REP(j,n)REP(k,n)REP(l,n)d[i][j][k][l]=INF;

  d[st[0]][st[1]][st[2]][st[3]]=0;

  auto move = [&](int x, int y, int d ) -> P{

    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx < 0 || nx >= n || ny < 0 || ny >=n){
      return {x,y};
    }

    if(s[nx][ny]=='#')return {x,y};

    return {nx, ny};
  };


  queue<vi> q;
  q.push(st);
  while(!q.empty()){
    auto v = q.front(); q.pop();

    if(v[0]==v[2] && v[1]==v[3]){
      cout << d[v[0]][v[1]][v[2]][v[3]] << endl;
      // cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
      // REP(i,n)REP(j,n)REP(k,n)REP(l,n)printf("%d %d %d %d: %d\n",i,j,k,l,d[i][j][k][l]);
      return 0;
    }

    REP(i,4){
      auto [x1,y1] = move(v[0],v[1],i);
      auto [x2,y2] = move(v[2],v[3],i);
      if(d[x1][y1][x2][y2]!=INF)continue;
      d[x1][y1][x2][y2] = d[v[0]][v[1]][v[2]][v[3]] + 1;
      vi nxt;
      nxt.pb(x1);
      nxt.pb(y1);
      nxt.pb(x2);
      nxt.pb(y2);
      q.push(nxt);
    }
  }

  

  cout << -1 << endl;
}

