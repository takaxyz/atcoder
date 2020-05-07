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
  ll k;
  cin >> k;

  int n = 50;

  ll p = k/n;
  int q = k%n;

  vector<ll> a(50,0);
  REP(i,50)a[i]=p+i;

  REP(i,q){
    sort(ALL(a));
    a[0]+=n;
    FOR(j,1,a.size())a[j]--;
  }

  cout << n << endl;
  REP(i,n){
    if(i!=0)cout << " ";
    cout << a[i];
  }
  cout << endl;
}

