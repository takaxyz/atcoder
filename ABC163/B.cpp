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
  int n,m;
  cin >> n >> m;
  REP(i,m){
    int a;
    cin >> a;
    n -= a;
  }

  cout << (n>=0 ? n : -1 ) << endl;
}

