#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int n;
  cin >> n;
  ll ans1 = 0, ans2 = 0;;

  vector<ll> a(n);
  REP(i,n)cin>>a[i];

  ll t;
  //正負
  if(a[0]<=0){
    ans1 += -a[0]+1;
    t = 1;
  }else{
    t = a[0];
  }
  FOR(i,1,n){
    if((t > 0 && t + a[i] >= 0) || (t < 0 && t + a[i] <= 0)){
      ans1 += abs(t+a[i]) + 1;
      if(t> 0){
        t = -1;
      }else{
        t = 1;
      }
    }else{
      t += a[i];
    }
  }

  //負正
  if(a[0]>=0){
    ans2 += a[0]+1;
    t = -1;
  }else{
    t = a[0];
  }
  FOR(i,1,n){
    if((t > 0 && t + a[i] >= 0) || (t < 0 && t + a[i] <= 0)){
      ans2 += abs(t+a[i]) + 1;
      if(t> 0){
        t = -1;
      }else{
        t = 1;
      }
    }else{
      t += a[i];
    }
  }

  cout << min(ans1,ans2) << endl;
}

