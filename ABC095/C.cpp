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
  int a,b,c,x,y;
  cin >> a >> b >>c >> x >> y;

  if(a+b >= 2*c){
    int ans;
    if(x>y){
      ans = y * 2 * c + (x-y) * a;
      ans = min(ans, 2*x*c);   
    }else{
      ans = x * 2 * c + (y-x) * b;
      ans = min(ans, 2*y*c);   
    }
    cout << ans << endl;

  }else{
    cout << a*x + b*y << endl;
  }

}

