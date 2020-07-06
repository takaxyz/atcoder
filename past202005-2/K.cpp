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
//const int INF=(1<<29);

struct box{
  int top;
  int bottom;
};

int main(){
  int N,Q;
  cin >> N >> Q;

  vector<box> B(N);
  vector<int> desk_top(N);

  REP(i,N){
    B[i].top = -1;
    B[i].bottom = -1;
    desk_top[i] = i;
  }

    // REP(i,N){
    //   printf("%d Box_top: %d Box_bottom: %d\n", i, B[i].top, B[i].bottom);
    // }
    // REP(i,N){
    //   printf("%d desk_top: %d\n", i, desk_top[i]);
    // }
  REP(i,Q){
    int f, t, x;
    cin >> f >> t >> x;
    f--;t--;x--;

    int tmp = desk_top[t];
    desk_top[t] = desk_top[f];     
    desk_top[f] = B[x].bottom;     

    B[x].bottom = tmp;
//    B[x].top;

    if(tmp>0)B[tmp].top = x;

    // REP(i,N){
    //   printf("%d Box_top: %d Box_bottom: %d\n", i, B[i].top, B[i].bottom);
    // }
    // REP(i,N){
    //   printf("%d desk_top: %d\n", i, desk_top[i]);
    // }
  }

  VI ans(N);
  REP(i,N){
    int t = desk_top[i];
    while(t>=0){
      ans[t] = i;
      t = B[t].bottom;
    }
  }

  REP(i,N){
    cout << ans[i]+1 << endl;
  }
}

