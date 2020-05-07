#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  ll H,W;
  cin >> H >> W;

  ll ans = INF;
  FOR(i,1,H){
    ll s1 = i * W;
    ll s2, s3;
    // 縦割り
    s2 = (H-i) * (W/2);
    s3 = (H-i) * (W-(W/2));
    ans = min(ans, max(s1, max(s2,s3)) - min(s1, min(s2,s3)));

    // 横割り
    s2 = (H-i)/2 * W;
    s3 = (H-i-(H-i)/2) * W;
    ans = min(ans, max(s1, max(s2,s3)) - min(s1, min(s2,s3)));    
  }

  ll tmp;
  tmp = H; H = W; W = tmp;

  FOR(i,1,H){
    ll s1 = i * W;
    ll s2, s3;
    // 縦割り
    s2 = (H-i) * (W/2);
    s3 = (H-i) * (W-(W/2));
    ans = min(ans, max(s1, max(s2,s3)) - min(s1, min(s2,s3)));

    // 横割り
    s2 = (H-i)/2 * W;
    s3 = (H-i-(H-i)/2) * W;
    ans = min(ans, max(s1, max(s2,s3)) - min(s1, min(s2,s3)));    
  }

  cout << ans << endl;
}



