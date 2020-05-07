#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int n, m;
  cin >> n >> m;

  if(n%2!=0){
    int t = (n / 2) * 2 - 1;
    FOR(i,1,m+1){
      printf("%d %d\n",i,i+t);
      t -= 2;
    }
  }else{
    int t = (n / 2) * 2 - 2;
    FOR(i,1,m+1){
      printf("%d %d\n",i,i+t);
      t -= 2;
    }

  }

}

