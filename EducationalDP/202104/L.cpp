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

ll dp[3005][3005];
int n;

ll rec(int l, int r, vi& a){
  if(dp[l][r]!=-1)return dp[l][r];
  if(l==r)return dp[l][r]=0;

  if((n - r + l)%2==0){
    dp[l][r] = max(rec(l+1,r,a)+a[l], rec(l,r-1,a)+a[r-1]);
  }else{
    dp[l][r] = min(rec(l+1,r,a)-a[l], rec(l,r-1,a)-a[r-1]);
  }
  return dp[l][r];
}


int main(){
  cin >> n;
  vi a(n);
  REP(i,n)cin >> a[i];
  memset(dp,-1,sizeof(dp));
  cout << rec(0,n,a) << endl;
}

