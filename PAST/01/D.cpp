#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int N;
  cin >> N;
  vector<int> v(N+1,0);
  REP(i,N){
    int s;
    cin >> s;
    v[s]++;
  }
  int p = 0;
  int q = 0;
  FOR(i,1,N+1){
    if(v[i]==1)continue;
    if(v[i]==0){
      p = i;
    }else{
      q = i;
    }
  }

  if(p==0){
    cout << "Correct" << endl;
  }else{
    cout << q << " " << p << endl;
  }
}

