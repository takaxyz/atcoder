#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007
 
typedef long long int ll;
 
const ll INF=(ll)1e19;
//const int INF=(1<<30);
 
 
int main(){
  int x,a,b,c;
  cin >> a >> b >> c >> x;
 
  int ans=0;
  REP(i,a+1)REP(j,b+1)REP(k,c+1){
    if(i*500+j*100+k*50==x)ans++;
  }
  cout << ans << endl;
}