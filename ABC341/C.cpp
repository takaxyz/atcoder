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

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  string t;
  cin >> t;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  int ans=0;
  REP(i,h)REP(j,w){
    if(s[i][j]=='#')continue;
    bool ok=true;
    int ni = i;
    int nj = j;
    REP(k,n){
      int d;
      if(t[k]=='L'){
        d = 0;
      }else if(t[k]=='R'){
        d = 1;
      }else if(t[k]=='U'){
        d = 2;
      }else if(t[k]=='D'){
        d = 3;
      }
      ni += dx[d]; 
      nj += dy[d]; 
      if(s[ni][nj]=='#'){
        ok = false;
        break;
      }
    }
    if(ok)ans++;
  }
  cout << ans << endl;
}

