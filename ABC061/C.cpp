#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<pair<int,int>> list;
  REP(i,n){
    int a,b;
    cin >> a >> b;
    list.push_back(make_pair(a,b));
  }
  sort(list.begin(), list.end());
  ll c=0;
  for(auto itr = list.begin(); itr != list.end(); itr++){
    //cout << itr->first << " " << itr->second << endl;
    c += itr->second;
    if(c >= k){
      cout << itr->first << endl;
      exit(0);
    }
  }
}



