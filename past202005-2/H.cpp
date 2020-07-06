#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e18;
//const int INF=(1<<30);
//const int INF=(1<<29);


int main(){
  int N, L;
  cin >> N >> L;
  vector<ll> dp(L+1,INF);

  vector<int> h(L,0);

  REP(i,N){
    int x;
    cin >> x;
    h[x]=1;
  }
  int t1,t2,t3;
  cin >> t1 >> t2 >> t3;

  dp[0]=0;
  REP(i,L){
    // 1
    if(h[i]==1){
      chmin(dp[i+1], dp[i] + t1 + t3);
    }else{
      chmin(dp[i+1], dp[i] + t1);
    }

    // 2
    if(h[i]==1){
      if(i+2>L){
        chmin(dp[i+1], dp[i] + (t1 + t2)/2 + t3);
      }else{
        chmin(dp[i+2], dp[i] + t1 + t2 + t3);
      }
    }else{
      if(i+2>L){
        chmin(dp[i+1], dp[i] + (t1 + t2)/2);
      }else{
        chmin(dp[i+2], dp[i] + t1 + t2);
      }
    }

    // 3
    if(h[i]==1){
      if(i+4>L){
        chmin(dp[L], dp[i] + t1/2 + (L-i)*t2 - t2/2 + t3);
      }else{
        chmin(dp[i+4], dp[i] + t1 + t2*3 + t3);
      }
    }else{
      if(i+4>L){
        chmin(dp[L], dp[i] + t1/2 + (L-i)*t2 - t2/2);
      }else{
        chmin(dp[i+4], dp[i] + t1 + t2*3);
      }
    }
  }

  cout << dp[L] << endl;
}

