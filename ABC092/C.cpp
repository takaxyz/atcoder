#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;

  vector<ll> a(N+2);

  a[0] = 0;
  REP(i,N)cin >> a[i+1];
  a[N+1] = 0;

  ll sum=0;
  FOR(i,1,N+2){
    sum += abs(a[i]-a[i-1]);
  }

  FOR(i,1,N+1){
    cout << sum - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]-a[i-1]) << endl;
  }


}

