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

int dx[] = {1,0,-1,0,1,-1,-1,1};
int dy[] = {0,1,0,-1,1,-1,1,-1};


int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  vvi d(h,vi(w,INF));

  queue<P> q;

  vector<string> e(h,string(w,'.'));

  REP(i,h)REP(j,w){
    if(s[i][j]=='#'){
      REP(k,8){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
        if(s[ni][nj]=='#')continue;
        e[ni][nj]='#';
      }
    }
  }

  REP(i,h)REP(j,w){
    if(e[i][j]=='#'){
      q.push({i,j});
      d[i][j]=1;
    }
  }

  while(!q.empty()){
    auto [i,j] = q.front();
    q.pop();
    REP(k,8){
      int ni = i + dx[k];
      int nj = j + dy[k];
      if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
      if(d[ni][nj]!=INF)continue;
      d[ni][nj]=d[i][j]+1;
      q.push({ni,nj});
    }
  }
  //REP(i,h)REP(j,w)cout << d[i][j] << (j == w-1 ? "\n" : " ");

  REP(i,h)REP(j,w)cout << (d[i][j]%2 == 0 ? "#" : ".") << (j == w-1 ? "\n" : "");

}

