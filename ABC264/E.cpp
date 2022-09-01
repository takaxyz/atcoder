#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  int n,m,e;
  cin >> n >> m >> e;
  vector<P> edge(e);
  REP(i,e)cin >> edge[i].first >> edge[i].second;
  int q;
  cin >> q;
  vi x(q);
  set<int> st;
  REP(i,q){
    cin >> x[i];
    x[i]--;
    st.insert(x[i]);
  }

  UnionFindTree tree(n+1);

  vi ans;

  REP(i,e){
    if(st.count(i))continue;
    int ei = i;;

    if(edge[ei].first > n &&  edge[ei].second > n){

    }else if(edge[ei].first <= n &&  edge[ei].second <= n){
      tree.unite(edge[ei].first, edge[ei].second);
    }else{
      int c = min(edge[ei].first, edge[ei].second);

      tree.unite(0, c);
    }
  }


  for(int i = q-1; i>=0; i--){
    ans.emplace_back(tree.getCount(0)-1);

    int ei = x[i];

    if(edge[ei].first > n &&  edge[ei].second > n){


    }else if(edge[ei].first <= n &&  edge[ei].second <= n){
      tree.unite(edge[ei].first, edge[ei].second);
    }else{
      int c = min(edge[ei].first, edge[ei].second);

      tree.unite(0, c);
    }
  }

  reverse(ALL(ans));
  for(auto x: ans)cout << x << endl;
}

