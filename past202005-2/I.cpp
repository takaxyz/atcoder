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

void dump(vector<vector<int>> &a, vector<int> &r, vector<int> &c, int tran){
  int t = a.size();
  if(tran%2==1){
    REP(i,t)REP(j,t){
      cout << a[r[j]][c[i]] << (j == t-1 ? "\n" : "");
    }
  }else{
    REP(i,t)REP(j,t){
      cout << a[r[i]][c[j]] << (j == t-1 ? "\n" : "");
    }
  }
}


int main(){
  int N,Q;
  cin >> N >> Q;

  VI r(N), c(N);
  REP(i,N)r[i]=i;
  REP(i,N)c[i]=i;
  int tran=0;

  REP(i,Q){
    int q, x, y;
    cin >> q;
    if(q==1){
      cin >> x >> y;
      x--; y--;
      if(tran%2==1){
        swap(c[x], c[y]);
      }else{
        swap(r[x], r[y]);
      }
    }else if(q==2){
      cin >> x >> y;
      x--; y--;
      if(tran%2==1){
        swap(r[x], r[y]);
      }else{
        swap(c[x], c[y]);
      }
    }else if(q==3){
      tran++;
    }else{
      cin >> x >> y;
      x--;y--;
      if(tran%2==1){
        cout << (ll)N * r[y] + c[x] << endl;
      }else{
        cout << (ll)N * r[x] + c[y] << endl;
      }
    }
//    cout << "#" << i << endl;
 //   dump(a,r,c, tran);
  }
}

