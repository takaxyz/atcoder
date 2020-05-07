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
  int n,k;
  cin >> n >> k;

  VI x(n);

  REP(i,n)cin >> x[i];

  int ans = (1<<30);
  for(int l = 0; l + k -1 < n; l++){
    int r = l + k -1;
    ans = min(ans, abs(x[l]) + abs(x[r]-x[l]));
    ans = min(ans, abs(x[r]) + abs(x[l]-x[r]));
  }
  cout << ans << endl;

}

