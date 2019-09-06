#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007
 
typedef long long int ll;
 
const ll INF=(ll)1e18;
 
int main(){
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;;
  
  int dx = tx-sx;
  int dy = ty-sy;

  REP(i,dy)cout << 'U';
  REP(i,dx)cout << 'R';
  REP(i,dy)cout << 'D';
  REP(i,dx)cout << 'L';
  cout << 'L';
  REP(i,dy+1)cout << 'U';
  REP(i,dx+1)cout << 'R';
  cout << "DR";
  REP(i,dy+1)cout << 'D';
  REP(i,dx+1)cout << 'L';
  cout << 'U' << endl;;
}