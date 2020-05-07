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
  string s;
  cin >> s;

  vector<int> l(n+1,0);
  vector<int> r(n+1,0);

  int ans=(1<<30);
  REP(i,n){
    if(s[i]=='W')l[i+1] = l[i]+1;
    else l[i+1] = l[i];
  }

  for(int i = n-1; i >=0; i--){
    if(s[i]=='E')r[i] = r[i+1]+1;
    else r[i] = r[i+1];
  }

  // l[i] : i 番目
  // r[i+1]: i番目
  REP(i,n){
    ans = min(l[i] + r[i+1], ans);
  }
  cout << ans << endl;
}

