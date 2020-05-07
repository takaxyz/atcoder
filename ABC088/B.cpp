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
  REP(i,N)cin>>a[i];

  sort(ALL(a));
  reverse(ALL(a));

  int d=0;
  REP(i,a.size()){
    if(i%2==0)d+=a[i];
    else d-=a[i];
  }
  cout << d << endl;

}

