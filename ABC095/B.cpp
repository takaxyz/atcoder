#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

//const ll INF=(ll)1e19;
const int INF=(1<<30);


int main(){
  int n,x;
  cin >> n >> x;
  int m;
  int min_m = INF;;
  REP(i,n){
    cin >> m;
    x -= m;
    min_m = min(min_m,m);
  }
  cout << n + x/min_m << endl;
}

