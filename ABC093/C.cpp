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
  vector<int> a(3);
  REP(i,3)cin >> a[i];
  sort(ALL(a));

  if((2*a[2]-a[0]-a[1])%2 == 0){
    cout << (2*a[2]-a[0]-a[1])/2 << endl;
  }else{
    cout << (2*a[2]-a[0]-a[1])/2 +2 << endl;
  }
}

