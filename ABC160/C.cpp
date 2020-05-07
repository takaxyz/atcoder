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
  int k,n;

  cin >> k >> n;
  VI a(n);

  REP(i,n)cin>>a[i];

  int d=-1;

  REP(i,n-1){
    d = max(d, a[i+1]-a[i]);
  }
  d = max(d, a[0]+(k-a[n-1]));

  cout << k-d << endl;

}

