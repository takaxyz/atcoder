#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

using ll = long long int;
using P = pair<int,int>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int N,M,X,Y;
  cin >> N >> M >> X >> Y;
  VI x(N),y(M);
  REP(i,N)cin >> x[i];
  REP(i,M)cin >> y[i];

  sort(ALL(x));
  sort(ALL(y));

  if(x.back() < y.front() && X < y.front() && x.back() < Y){
    cout << "No War" << endl;
  }else{
    cout << "War" << endl;
  }

}

