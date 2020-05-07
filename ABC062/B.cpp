#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int h,w;
  cin >> h >> w;
  string hh(w+2, '#');

  cout << hh << endl;
  REP(i,h){
    string a;
    cin >> a;
    cout << "#" << a << "#" << endl;
  }
  cout << hh << endl;

}



