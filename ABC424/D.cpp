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

int toi(string s){
  int ret=0;
  for(auto c: s){
    ret <<= 1;
    ret += (c == '#');
  }
  return ret;
}

int main(){
  int t;
  cin >> t;
  REP(_, t){
    int h,w;
    cin >> h >> w;
    vvi dp(h+1,vi((1<<w),INF));
    vector<string> s(h);
    REP(i,h)cin >> s[i];

    dp[0][0]=0;
    REP(i,h){
      int x = toi(s[i]);
      REP(j,(1<<w)){
        int cnt=0;
        bool ok=true;
        REP(l,w){
          int jj = (j>>l) & 1;
          int xx = (x>>l) & 1;
          if(jj == xx)continue;
          if(jj == 0 && xx == 1)cnt++;
          else ok=false;
        }
        if(!ok)continue;

        REP(k,(1<<w)){
          if(dp[i][k]==INF)continue;

          bool ok=true;
          REP(l,w-1){
            if(((k>>l) & 1) + ((k>>(l+1)) & 1) + ((j>>l) & 1) + ((j>>(l+1)) & 1) == 4)ok=false;
          }
          if(ok)chmin(dp[i+1][j],dp[i][k]+cnt);
        }
      }
    }

    int ans = INF;
    for(auto x: dp[h])chmin(ans,x);
    cout << ans << endl;

  }
}

