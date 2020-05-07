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
  bool ok=false;
  REP(i,n/4+1){
    REP(j,n/7+1){
      if(i*4+j*7==n)ok=true;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}

