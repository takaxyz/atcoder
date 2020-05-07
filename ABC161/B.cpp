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
  int m,n;
  cin >> n >> m;
  vector<int> a(n);
  int sum=0;
  REP(i,n){
    cin >> a[i];
    sum += a[i];
  }

  sort(ALL(a));
  reverse(ALL(a));

  int cnt=0;
  REP(i,n){
    if(a[i]*4*m >= sum)cnt++;
    else break;
  }
  cout << (cnt>=m ? "Yes" : "No") << endl;

}

