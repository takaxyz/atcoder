#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  int a,b;
  char op;

  cin >> a >> op >> b;
  cout <<  (op=='+' ? a+b : a-b) << endl;
}
