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

  map<ll, int> mp;
  vector<ll> v;
  REP(i,N){
    ll a;
    cin >> a;
    mp[a]++;
    if(mp[a]%2==0){
      v.push_back(a);
    }
  }

  sort(ALL(v));
  reverse(ALL(v));

  if(v.size()<2){
    cout << 0 << endl;
  }else{
    cout << v[0] * v[1] << endl;
  }
}


