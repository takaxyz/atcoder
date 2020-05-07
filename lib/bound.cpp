#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  vector<int> a = { 1,4,4,7,7,8,8,11, 13, 19 };

  cout << *(lower_bound(a.begin(),a.end(),4)) << endl;

}


