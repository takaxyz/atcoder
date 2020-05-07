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

  int m = n;
  int sn = 0;
  while (m > 0){
    sn += m % 10;
    m /= 10;
  }
  cout << (n%sn==0 ? "Yes" : "No") << endl;
}
