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
const int MOD = 1e9 + 7;

int main(){
  int n,s;
  cin >> n >> s;

  vvi dp(n+1,vi(s+1,-1));
  dp[0][0]=1;

  vi a(n),b(n);

  REP(i,n){
    cin >> a[i] >> b[i];
    REP(j,s+1){
      if(dp[i][j]==-1)continue;
      if(j+a[i]<=s)dp[i+1][j+a[i]]=1;
      if(j+b[i]<=s)dp[i+1][j+b[i]]=1;
    }
  }

  if(dp[n][s]==-1){
    cout << "Impossible" << endl;
    return 0;
  }

  int now=s;
  vector<char> ans;

  for(int i = n-1; i >= 0; i--){
    if(now-a[i] >= 0 && dp[i][now-a[i]]==1){
      ans.pb('A');
      now -= a[i];
    }else if(now-b[i] >= 0 && dp[i][now-b[i]]==1){
      ans.pb('B');
      now -= b[i];
    }
  }

  reverse(ALL(ans));

  for(auto c: ans)cout << c;
  cout << endl;

}

