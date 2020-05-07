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
  VI a(n);

  REP(i,n)cin >> a[i];
  sort(ALL(a));

  map<int, ll> mp;
  REP(i,n){
    int l = i;
    int r = n-l-1;

    mp[a[i]] += min(l,r) + 1;
    mp[a[i]] += ;

  }

  for(auto &v: mp){
    cout << v.first << " " << v.second << endl;
  }
}

