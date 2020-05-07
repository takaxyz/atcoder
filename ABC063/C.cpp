#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e18;
const int INF=(1<<30);


int main(){
  int N;
  cin >> N;
  bool flag=true;

  int ans=0;
  int q = INF;
  REP(i,N){
    int s;
    cin >> s;
    ans += s;
    if(s%10!=0){
      q=min(q,s);
    }
  }

  if(ans%10!=0){
    cout << ans << endl;
  }else if(q==INF){
    cout << 0 << endl;
  }else{
    cout << ans - q << endl;
  }



}

