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
  int a,b,k;
  cin >> a >> b >>k;

  for(int i=a; i<a+k && i <= b; i++)cout << i << endl;

  for(int i=max(b-k+1,a+k); i <=b; i++)cout << i << endl;

}

