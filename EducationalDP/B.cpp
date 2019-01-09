#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int N, K;

int main(){
    cin >> N >> K;
    ll dp[N];
    
    vector<ll> h(N);
    REP(i,N)cin >> h[i];
    REP(i,N)dp[i]=INF;
    
    dp[0]=0;
    FOR(i,1,N){
      FOR(j,1,K+1){
        if(i-j<0)break;
        if(dp[i] > (dp[i-j] + abs(h[i] - h[i-j]))){
          dp[i] = (dp[i-j] + abs(h[i] - h[i-j]));
        }
      }
    }
    cout << dp[N-1] << endl;
}
