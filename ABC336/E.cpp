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

ll dp[16][2][130][130];

int main(){
  string n;
  cin >> n;

  int sz = n.size();

  ll ans=0;
  FOR(k,1,127){
    REP(i,sz+1)REP(j,2)REP(s,k+1)REP(r,k)dp[i][j][s][r]=0;
    dp[0][0][0][0]=1;
    REP(i,sz)REP(j,2)REP(s,k+1)REP(r,k){
      int x = n[i] - '0';
      REP(d,10){
        int ni = i+1;
        int nj = j;
        int ns = s + d;
        int nr = (r*10 + d)%k;
        if(ns > k)continue;
        // 未定
        if(j==0){
          if(x < d)continue;
          if(x > d)nj = 1;
        }
        dp[ni][nj][ns][nr] += dp[i][j][s][r];
      }
    }

    ans += dp[sz][1][k][0];
    ans += dp[sz][0][k][0];
  }

  cout << ans << endl;
}

