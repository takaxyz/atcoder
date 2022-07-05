#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

class UnionFindTree{
  public:
    vector<int> rank,p,count;

    UnionFindTree() {}

    UnionFindTree(int size){
      rank.assign(size, 0);
      p.assign(size, 0);
      count.assign(size,1);
      REP(i,size)makeSet(i);
    }

    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
    }

    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }

    void unite(int x, int y){
      if(findSet(x) == findSet(y))return;

      x = findSet(x);
      y = findSet(y);
      
      if(rank[x] > rank[y]){
        p[y] = x;
      }else{
        p[x] = y;
        if(rank[x] == rank[y]){
          rank[y]++;
        }
      }

      int tmp = count[x] + count[y];
      count[x] = tmp;
      count[y] = tmp;
    }

    int findSet(int x){
      if(x != p[x]){
        p[x] = findSet(p[x]);
      }
      return p[x];
    }

    int getCount(int x){
      return count[findSet(x)];
    }

    void print(){
      REP(i,p.size()){
        cout << p[i] << " ";
      }
      cout << endl;
      REP(i,p.size()){
        cout << rank[i] << " ";
      }
      cout << endl;
    }

};

int main(){
  int n;
  cin >> n;
  vi x(n), c(n);
  REP(i,n){
    cin >> x[i];
    x[i]--;
  }
  REP(i,n)cin >> c[i];

  UnionFindTree tree(n);

  REP(i,n){
    if(!tree.same(i, x[i])){
      tree.unite(i, x[i]);
    }
  }

  ll ans=0;
  vector<bool> visited(n);
  REP(i,n){
    if(visited[tree.findSet(i)])continue;
    visited[tree.findSet(i)]=true;

    vector<bool> ck(n);
    int v = i;
    do {
      ck[v] = true;
      v = x[v];
    }while(!ck[v]);

    int w = v;
    int cur = INF;
    do {
      chmin(cur, c[w]);
      w = x[w];
    }while(v != w);

    ans += cur;
  }
  cout << ans << endl;
}


