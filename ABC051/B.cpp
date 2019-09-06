#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
 
typedef long long int ll;
 
const ll INF=(ll)1e18;
 
int main(){
  int K,S;
  cin >> K >> S;
 
  int ans=0;
  for(int i = 0; i <= K; i++){
    for(int j = 0; j <= K; j++){
      if(S-i-j>=0 && S-i-j<=K)ans++;
    }
  }
  cout << ans << endl;
}