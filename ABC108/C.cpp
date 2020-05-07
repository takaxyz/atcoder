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


int main(){
  int n, k;
  cin >> n >> k;

  ll ans = 0;
  if(k%2==0){
    ans += (n/k)*(n/k)*(n/k);
    ans += ((n-k/2)/k+1)*((n-k/2)/k+1)*((n-k/2)/k);

  }else{
    ans += (n/k)*(n/k)*(n/k);
  }
  cout << ans << endl;
}

