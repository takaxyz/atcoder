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
  int N,K;
  cin >> N >> K;
  vector<int> l(N);
  REP(i,N)cin>>l[i];

  sort(ALL(l), greater<int>());

  int ans=0;
  REP(i,K)ans+=l[i];
  cout << ans << endl;
}

