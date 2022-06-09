#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

int main(){
  int n;
  cin >> n;
  vi a(n);
  int sum=0;
  REP(i,n){
    cin >> a[i];
    if(a[i]==0){
      a[i]=1;
    }else{
      sum++;
      a[i]=-1;
    }
  }

  vi dp(n);
  dp[0]=a[0];
  int mx = 0;
  chmax(mx, dp[0]);
  REP(i,n-1){
    dp[i+1] = max(dp[i]+a[i+1], a[i+1]);
    chmax(mx, dp[i+1]);
  }
  vi dp2(n);
  int mn = 0;
  dp2[0]=a[0];
  chmin(mn, dp2[0]);
  REP(i,n-1){
    dp2[i+1] = min(dp2[i]+a[i+1], a[i+1]);
    chmin(mn, dp2[i+1]);
  }
  cout << mx - mn + 1 << endl;
}

