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
  VI r,b;

  REP(i,n){
    int x;
    char c;
    cin >> x >> c;

    if(c=='R'){
      r.push_back(x);
    }else{
      b.push_back(x);
    }
  }
  sort(ALL(r));
  sort(ALL(b));

  for(auto &v: r)cout << v << endl;
  for(auto &v: b)cout << v << endl;
}

