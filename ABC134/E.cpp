#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int N;

  cin >> N;

  vector<ll> a;

  REP(i,N){
    ll aa;
    cin >> aa;
    a.push_back(aa);
  }

  vector<ll> c;

  int ans = 0;
  for(int i = N-1; i >= 0; i--){
    ll t = a[i];

    vector<ll>::iterator iter = upper_bound(c.begin(),c.end(), t);
    if(iter == c.end()){
      ans++;
      c.push_back(t);
    }else{
      *iter = t;
    }

    // REP(j,c.size()){
    //   cout << c[j] << " ";
    // }
    // cout << endl;
  }
  cout << ans << endl;
}