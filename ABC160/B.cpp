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
  int x;
  cin >> x;

  int ans=0;
  ans += (x / 500) * 1000;
  x %= 500;
  ans += (x/5)*5;

  cout << ans << endl;
}

