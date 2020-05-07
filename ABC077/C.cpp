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
  int N;
  cin >> N;
  vector<int> A(N),B(N),C(N);
  REP(i,N)cin >> A[i];
  REP(i,N)cin >> B[i];
  REP(i,N)cin >> C[i];

  sort(ALL(A));
  sort(ALL(B));
  sort(ALL(C));

  ll ans=0;
  for(auto &v: B){
    ans += (lower_bound(ALL(A),v) - A.begin()) *(C.end() - upper_bound(ALL(C),v)); 
  }

  cout << ans << endl;
}

