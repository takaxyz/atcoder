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

int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];
  int sx=-1, sy=-1, gx=-1, gy=-1;
  REP(i,h)REP(j,w){
    if(s[i][j]=='S'){
      sx = i; sy = j;
    }else if(s[i][j]=='G'){
      gx = i; gy = j;
    }
  }

  vector visited(h, vector(w, vi(4)));
  vi ds;
  int ans = INF;
  vi vs; 

  auto dfs = [&](int i, int j, auto dfs) -> void{
    if(ans != INF)return;

    visited[i][j][ds.back()] = 1;

    if(i == gx && j == gy){
      ans = ds.size();
      vs = ds;
      return;
    }

    REP(k,4){
      if(s[i][j]=='o' && k != ds.back())continue;
      if(s[i][j]=='x' && k == ds.back())continue;

      int ni = i + dx[k];
      int nj = j + dy[k];

      if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
      if(s[ni][nj]=='#')continue;
      if(visited[ni][nj][k])continue;
      ds.pb(k);
      dfs(ni,nj,dfs);
      ds.pop_back();      
    }

  };

  ds.pb(0);
  dfs(sx,sy,dfs);

  if(ans != INF){
    cout << "Yes" << endl;
    FOR(i,1,vs.size()){
      if(vs[i]==0){
        cout << "D";
      }else if(vs[i]==1){
        cout << "R";
      }else if(vs[i]==2){
        cout << "U";
      }else{
        cout << "L";
      }
    }
    cout << endl;

  }else{
    cout << "No" << endl;
  }

}

