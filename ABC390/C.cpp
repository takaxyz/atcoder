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
  int min_i = INF, max_i = -1, min_j = INF, max_j = -1;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  REP(i,h)REP(j,w){
    if(s[i][j]=='#'){
      chmin(min_i, i);
      chmax(max_i, i);
      chmin(min_j, j);
      chmax(max_j, j);
    }
  }
  // cout << min_i << endl;
  // cout << max_i << endl;
  // cout << min_j << endl;
  // cout << max_j << endl;
  bool ok=true;
  FOR(i, min_i, max_i+1)FOR(j, min_j, max_j+1){
    if(s[i][j]=='.')ok=false;
  }
  cout << (ok ? "Yes" : "No") << endl;
}

