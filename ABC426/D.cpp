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

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int prev = s[0] - '0';
  int cnt=1;
  vector<P> vs;
  FOR(i,1,n){
    int x = s[i]-'0';
    if(prev == x)cnt++;
    else{
      vs.pb({prev,cnt});
      prev=x;
      cnt=1;
    } 
  }
  vs.pb({prev,cnt});

  vvi c(2,vi(n));
  REP(k,2){
    REP(i,n){
      if(s[i]-'0' == k)c[k][i]=2;
      else c[k][i]=1;
    }
  }

  vvi sum(2,vi(n+1));
  vvi sumr(2,vi(n+1));
  REP(k,2)REP(i,n)sum[k][i+1] += sum[k][i] + c[k][i];
  REP(k,2)for(int i = n-1; i >= 0; i--)sumr[k][i] += sumr[k][i+1] + c[k][i];

  //REP(k,2)REP(i,n+1)printf("%d %d: %d\n",k,i,sum[k][i]);
  //REP(k,2)REP(i,n+1)printf("%d %d: %d\n",k,i,sumr[k][i]);

  // if(vs.size()==1){
  //   cout << 0 << endl;
  //   return;
  // }

  int l = 0;
  int r;
  int ans = INF;
  REP(i,vs.size()){
    r = l + vs[i].second;

    int x = vs[i].first;
    chmin(ans, sum[x][l] + sumr[x][r]);

    l += vs[i].second;
  }

  cout << ans << endl;

}




int main(){
  int t;
  cin >> t;
  REP(_,t)solve();
}

