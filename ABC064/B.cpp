#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n)cin>>a[i];

  sort(ALL(a));
  cout << a[n-1] - a[0] << endl; 

}


