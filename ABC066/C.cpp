#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);

int main(){
  int N;
  cin >> N;

  vector<int> a(N);
  vector<int> b;
  REP(i,N)cin >> a[i];

  if(N%2==0){
    REP(i,N/2){
      b.push_back(a[N-1-i*2]);      
    }
    REP(i,N/2){
      b.push_back(a[i*2]);      
    }
  }else{
    REP(i,N/2+1){
      b.push_back(a[N-1-i*2]);      
    }
    REP(i,N/2){
      b.push_back(a[1+i*2]);      
    }
  }

  cout << b[0];
  FOR(i,1,N){
    cout << " " << b[i];
  }
  cout << endl;

}