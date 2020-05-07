#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int a[200005];
int b[200005];

int main(){
  ll N;
  cin >> N;

  REP(i,N)cin >> a[i];
  REP(i,N)cin >> b[i];

  ll p=0;
  int ans=0;
  REP(i,28){
    ll a1=0;
    ll b1=0;

    REP(j,N){
      if(a[j]>>i & 1) a1++;
    }
    REP(j,N){
      if(b[j]>>i & 1) b1++;
    }


    if(((a1 + b1) * N - 2 * a1 * b1 + p) % 2 == 1) ans += 1 * (1<<i);

    p = (a1 % 2) * (b1 % 2) + p;

    cout << a1 << " " << b1 << endl;
    cout << ans << endl;
  }
  cout << ans << endl;

}

