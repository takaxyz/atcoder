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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  REP(i,n)cin >> s[i];

  vector<vector<vector<int>>> ck(n, vector<vector<int>>(m, vector<int>(4)));
  vvi v(n,vi(m));

  auto f = [&](int xi, int yi, auto f) -> void {
    //cout << xi << yi << endl;
    REP(i,4){
      if(ck[xi][yi][i])continue;
      ck[xi][yi][i]=1;

      int nxi = xi + dx[i];
      int nyi = yi + dy[i];
      while(true){
        if(nxi < 0 || nxi >= n || nyi < 0 || nyi >= m)break;
        if(s[nxi][nyi]=='#')break;
        v[nxi][nyi]=1;
        nxi += dx[i];
        nyi += dy[i];
      }
      nxi -= dx[i];
      nyi -= dy[i];

      f(nxi, nyi, f);
    }

  };
  v[1][1]=1;
  f(1,1,f);
  int ans=0;
  REP(i,n)REP(j,m)ans+=v[i][j];
  cout << ans << endl;
}

