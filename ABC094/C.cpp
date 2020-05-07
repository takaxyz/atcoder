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
  cin >> N;

  vector<int> x(N);
  vector<int> y(N);

  REP(i,N){
    int t;
    scanf("%d", &t);
    x[i] = y[i] = t;;
  }
  sort(ALL(y));

  REP(i,N){
    if(x[i]<=y[N/2-1]){
      printf("%d\n",y[N/2]);
    }else{
      printf("%d\n",y[N/2-1]);
    }
  }



}

