#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
  ll x1,x2,y1,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  ll dx[8] = {-1,-2,1,2,-1,-2,1,2};
  ll dy[8] = {-2,-1,2,1,2,1,-2,-1};

  REP(i,8){
    ll nx = x1 + dx[i];
    ll ny = y1 + dy[i];

    REP(j,8){
      if(nx + dx[j] == x2 && ny + dy[j] == y2){
        cout << "Yes" << endl;
        return 0;
      }
    }

  }
  cout << "No" << endl;

}