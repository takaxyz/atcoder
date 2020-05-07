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
  int N;
  int xx=0;
  int yy=0;

  cin >> N;
  int tt=0;
  REP(i,N){
    int t,x,y;
    cin >> t >> x >> y;

    if(abs(x-xx) + abs(y-yy) <= t-tt){
      if((t - tt - abs(x-xx) - abs(y-yy)) % 2 != 0){
        cout << "No" << endl;
        exit(0);
      }
      xx=x;yy=y;tt=t;

    }else{
      cout << "No" << endl;
      exit(0);
    }

  }
  cout << "Yes" << endl;
}

