#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

ll mpow(ll n, int m){
  if(n==1 || m ==0)return 1;
  if(n==0)return 0;

  if(m%2==0){
    return mpow(n*n, m/2);
  }else{
    return mpow(n*n, m/2)*n;
  }
}


int main(){
  ll n;
  cin >> n;

  if(n==0){
    cout << 0 << endl;
    exit(0);
  }

  int t=1;
  vector<char> ans;
  while(n!=0){
    if(n%((ll)1<<t)==0){
      ans.emplace_back('0');
    }else{
      ans.emplace_back('1');
      n -= mpow((-2), t-1);
    }
    t++;
  }

  REP(i,ans.size()){
    cout << ans[ans.size()-i-1];
  }
  cout << endl;
}

