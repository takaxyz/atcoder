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
  int n;
  cin >> n;

  VI a(n);
  REP(i,n)cin >> a[i];

  vector<ll> csum(n+1);
  csum[0]=a[0];
  REP(i,n-1)csum[i+1] = csum[i]+a[i+1];

  ll ans=INF;
  int l=0,r=2;
  REP(i,n-3){
    int y=i+1;

    while(l < y-1 && (abs(2*csum[l]-csum[y]) > abs(2*csum[l+1]-csum[y]))){
      l++;
    }

    ll mi=min(csum[l], csum[y]-csum[l]);
    ll ma=max(csum[l], csum[y]-csum[l]);

    while(r < n-2 && (abs(2*csum[r]-csum[y]-csum[n-1]) > abs(2*csum[r+1]-csum[y]-csum[n-1]))){
      r++;
    }

    ll mii=min(csum[r]-csum[y], csum[n-1]-csum[r]);
    ll maa=max(csum[r]-csum[y], csum[n-1]-csum[r]);

    ans=min(ans, max(ma,maa)-min(mi,mii));

  }
  cout << ans << endl;
}

