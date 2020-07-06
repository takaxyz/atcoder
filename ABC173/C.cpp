#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define PRINT(a)   cout << (a) << endl
#define RALL(v) rbegin(v), rend(v)

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

int main(){
  int H,W,K;
  cin >> H >> W >> K;
  vector<vector<char>> c(H, vector<char>(W));
  REP(i,H)REP(j,W)cin >> c[i][j];

  int ans=0;
  // i 縦、j 横
  REP(i,(1<<H))REP(j,(1<<W)){
    int cnt=0;
    REP(k,H){
      if((i>>k)&1)continue;
      REP(l,W){
        if((j>>l)&1)continue;
        if(c[k][l]=='#')cnt++;

      }
    }
    if(cnt==K)ans++;
  }
  PRINT(ans);
}

