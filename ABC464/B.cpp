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
  vector<string> c(h);
  REP(i,h)cin >> c[i];

  int lh = 0,rh = h,lw = 0,rw = w;
  REP(i,h){
    int cnt=0;
    REP(j,w)if(c[i][j]=='#')cnt++;
    if(cnt)break;
    lh++;
  }
  for(int i = h-1; i >= 0; i--){
    int cnt=0;
    REP(j,w)if(c[i][j]=='#')cnt++;
    if(cnt)break;
    rh--;
  }
  REP(i,w){
    int cnt=0;
    REP(j,h)if(c[j][i]=='#')cnt++;
    if(cnt)break;
    lw++;
  }
  for(int i = w-1; i >= 0; i--){
    int cnt=0;
    REP(j,h)if(c[j][i]=='#')cnt++;
    if(cnt)break;
    rw--;
  }

  FOR(i,lh,rh){
    FOR(j,lw,rw)cout << c[i][j];
    cout << endl;
  }
}

