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
  int n,m;
  cin >> n;
  map<string, int> s,t;
  REP(i,n){
    string str;
    cin >> str;
    s[str]++;
  }
  cin >> m;
  REP(i,m){
    string str;
    cin >> str;
    t[str]++;
  }

  int ans=0;
  for(auto &v: s){
    ans=max(ans, v.second - t[v.first]);
  }
  cout << ans << endl;

}

