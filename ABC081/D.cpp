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
  vector<int> a(N);

  int a_max = -10000000;
  int a_min = 10000000;
  int a_max_i, a_min_i;
  REP(i,N){
    int a;
    cin >> a;
    if(a > a_max){
      a_max = a;
      a_max_i = i;
    }
    if(a < a_min){
      a_min = a;
      a_min_i = i;
    }
  }
  if(abs(a_max) >= abs(a_min)){
    cout << 2*N-2 << endl;
    REP(i,N){
      if(i == a_max_i)continue;
      cout << a_max_i+1 << " " << i+1 << endl;
    }
    REP(i,N-1){
      cout << i+1 << " " << i+2 << endl;
    }

  }else{
    cout << 2*N-2 << endl;
    REP(i,N){
      if(i == a_min_i)continue;
      cout << a_min_i+1 << " " << i+1 << endl;
    }
    REP(i,N-1){
      cout << N-i << " " << N-i-1 << endl;
    }

  }



}

