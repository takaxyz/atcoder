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
  int x1,x2,y1,y2;

  cin >> x1 >> y1 >> x2 >> y2;

  int dx = x2 - x1;
  int dy = y2 - y1;

  cout << x2 - dy << " " << y2 + dx << " " << x1 - dy  << " " << y1 + dx << endl;

}

