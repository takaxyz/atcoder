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

struct Node {
  map<int, int> childs;
  vi ids;

  Node(){

  };

  Node(int id){
    childs = map<int, int>();
    ids = vi();

    ids.pb(id);
  };
};

struct Tri {
  Node root;
  vector<int> pos;
  vector<Node> nodes;
  Tri(){
    nodes = vector<Node>();
    pos = vi();
    root = Node(0);

    nodes.pb(root);
    pos.pb(0);
  };

  void add(int id, int x, int y){
    if(nodes[pos[x]].childs.count(y)){
      int j = nodes[pos[x]].childs[y];
      nodes[j].ids.pb(id);
      pos.pb(j);
    }else{
      nodes[pos[x]].childs[y] = nodes.size();
      nodes.pb(Node(id));
      pos.pb(nodes.size()-1);
    }
  };

  void solve(){

    auto dfs = [&](int id, auto dfs) -> void{
      for(auto x: nodes[id].ids){
        if(x>0)cout << x << endl;
      }

      for(auto [k,v]: nodes[id].childs){
        dfs(v, dfs);
      }
    };

    dfs(0,dfs);

  }

};

int main(){

  int n;
  cin >> n;

  Tri tri;
  REP(i,n){
    int x,y;
    cin >> x >> y;
    tri.add(i+1,x,y);
  }
  tri.solve();
}

