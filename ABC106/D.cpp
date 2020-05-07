#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);

struct CumulativeSum2D {
  vector<vector<int>> data;

  CumulativeSum2D(int w, int h) : data(w+1, vector<int>(h+1, 0)) {}

  void add(int x, int y, int z){
    //++x; ++y; // 0-indexedの場合
    if(x >= data.size() || y >= data[0].size()) return;
    data[x][y] += z;
  }

  void build() {
    for(int i = 1; i < data.size(); i++){
      for(int j = 1; j < data[i].size(); j++){
        data[i][j] += data[i][j-1] + data[i-1][j] - data[i-1][j-1];
      }
    }
  }

  int query(int sx, int sy, int gx, int gy){
    return data[gx][gy] - data[sx-1][gy] - data[gx][sy-1]  + data[sx-1][sy-1];
  }
};

int main(){
  int N,M,Q;
  cin >> N >> M >> Q;

  CumulativeSum2D cs = CumulativeSum2D(N,N);

  REP(i,M){
    int l,r;
    scanf("%d %d", &l,&r);

    cs.add(l,r,1);
  }
  cs.build();

  REP(i,Q){
    int p,q;
    scanf("%d %d", &p,&q);
    cout << cs.query(p,p,q,q) << endl;
  }
}

