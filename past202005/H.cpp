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
  int n,l;
  cin >> n >> l;
  vi h(l);
  REP(i,n){
    int x;
    cin >> x;
    h[x]=1;
  }
  vi t(3);
  REP(i,3)cin >> t[i];
  vi dp(l+5, INF);
  dp[0]=0;
  REP(i,l){
    if(h[i]){
      chmin(dp[i+1], dp[i]+t[0]+t[2]);
      chmin(dp[i+2], dp[i]+t[0]+t[2]+t[1]);
      chmin(dp[i+4], dp[i]+t[0]+t[2]+t[1]*3);
    }else{
      chmin(dp[i+1], dp[i]+t[0]);
      chmin(dp[i+2], dp[i]+t[0]+t[1]);
      chmin(dp[i+4], dp[i]+t[0]+t[1]*3);
    }
  }


  if(h[l-1]){
    chmin(dp[l], dp[l-1]+t[0]/2 + t[1]/2 + t[2]);
  }else{
    chmin(dp[l], dp[l-1]+t[0]/2 + t[1]/2);
  }
  if(h[l-2]){
    chmin(dp[l], dp[l-2]+t[0]/2 + t[1]/2*3 + t[2]);
  }else{
    chmin(dp[l], dp[l-2]+t[0]/2 + t[1]/2*3);
  }
  if(l > 2){
    if(h[l-3]){
      chmin(dp[l], dp[l-3]+t[0]/2 + t[1]/2*5 + t[2]);
    }else{
      chmin(dp[l], dp[l-3]+t[0]/2 + t[1]/2*5);
    }
  }
  
  cout << dp[l] << endl;
}

