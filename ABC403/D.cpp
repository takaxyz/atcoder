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
  int n,d;
  cin >> n >> d;
  const int MX = 2000002;
  vector<int> c(MX);
  REP(i,n){
    int a;
    cin >> a;
    c[a]++;
  }

  if(d==0){
    int ans =0;
    for(auto x: c){
      if(x > 1)ans += x-1;
    }
    cout << ans << endl;
    return 0;

  }

  int ans = 0;
  REP(i,d){
    vi vs;
    for(int j = i; j < MX; j += d){
      if(c[j])vs.pb(c[j]);
      else if(vs.size() >= 2){
//        REP(j,vs.size())cout << vs[j] << (j==vs.size()-1 ? "\n" : " ");        
        vvi dp(vs.size()+1,vi(2,INF));
        dp[0][1]=0;
        dp[0][0]=0;
        REP(i,vs.size()){
          chmin(dp[i+1][1], dp[i][0] + vs[i]);
          chmin(dp[i+1][1], dp[i][1] + vs[i]);
          chmin(dp[i+1][0], dp[i][1]);
        }
        ans += min(dp[vs.size()][0],dp[vs.size()][1]);
        vs.clear();
      }else if(vs.size()==1)vs.clear();
    }
  }
  cout << ans << endl;
  
}

