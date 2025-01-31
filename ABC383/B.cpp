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
  int h,w,d;
  cin >> h >> w >> d;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  int ans=0;
  REP(i,h)REP(j,w){
    if(s[i][j]=='#')continue;
    //printf("%d %d\n",i,j);
    vvi c(h,vi(w));
    c[i][j]=1;
    FOR(x, -d, d+1)FOR(y,-d,d+1){
      if(abs(x)+abs(y)>d)continue;
      int ni = i+x;
      int nj = j+y;
      if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
      if(s[ni][nj]=='#')continue;
      c[ni][nj]=1;
    }
    REP(i2,h)REP(j2,w){
      if(i2 <i)continue;
      if(i2==i && j2 <= j)continue;
      if(s[i2][j2]=='#')continue;
      vvi c2 = c;
      c2[i2][j2]=1;
      //printf(": %d %d\n",i2,j2);
      FOR(x, -d, d+1)FOR(y,-d,d+1){
        if(abs(x)+abs(y)>d)continue;
        int ni = i2+x;
        int nj = j2+y;
        if(ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
        if(s[ni][nj]=='#')continue;
        c2[ni][nj]=1;
      }
      int cnt = 0;
      REP(i,h)REP(j,w){
        if(c2[i][j]==1){
          cnt++;
          //printf("--- %d %d\n",i,j);
        }
      }
      chmax(ans,cnt);
      //printf("%d\n",cnt);
    }

  }
  cout << ans << endl;
}

