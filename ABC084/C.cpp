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
  vector<int> C(N),S(N),F(N);

  REP(i,N){
    cin >> C[i];
    cin >> S[i];
    cin >> F[i];
  }

  REP(i,N-1){
    int t=0;
    FOR(j,i,N-1){
      if(S[j]<=t){
        t=((t-S[j]+F[j]-1)/F[j])*F[j] + S[j] + C[j];
      }else{
        t=S[j]+C[j];
      }
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}

