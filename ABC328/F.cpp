#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
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

using mint = modint1000000007;
// using mint = modint998244353;

class UnionFindTree{
  public:
    vector<int> rank,p,count;
    vector<ll> w;

    UnionFindTree() {}

    UnionFindTree(int size){
      rank.assign(size, 0);
      p.assign(size, 0);
      w.assign(size, 0);
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

    bool unite(int x, int y, ll d){
      int rx = findSet(x);
      int ry = findSet(y);

      if(rx == ry){
        return w[y] - w[x] == -d;
      }


      if(rank[rx] > rank[ry]){
        p[ry] = rx;
        w[ry] = w[x] - w[y] - d;
      }else{
        p[rx] = ry;
        if(rank[rx] == rank[ry]){
          rank[ry]++;
        }
        w[rx] = w[y] - w[x] + d;
      }

      int tmp = count[rx] + count[ry];
      count[rx] = tmp;
      count[ry] = tmp;
      return true;
    }

    int findSet(int x){
      if(x != p[x]){
        int r = findSet(p[x]); 
        w[x] += w[p[x]];
        p[x] = r;
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
  int n,q;
  cin >> n >> q;

  UnionFindTree uf(n);

  REP(i,q){
    int a,b;
    ll d;
    cin >> a >> b >> d;
    a--; b--;
    if(uf.unite(a,b,d))cout << i + 1 << endl;
  }
}

