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
  int a,b,c;
  cin >> a >> b >> c;

  cout << ((a%3==0 || b%3==0 || (a+b)%3==0) ? "Possible" : "Impossible") << endl;
}

