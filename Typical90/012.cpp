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

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

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

int h,w,q;

int to_i(int r, int c){
  return r*w+c;
}
int main(){
  cin >> h >> w >> q;

  vvi m(h ,vi(w,0));

  UnionFindTree tree(h*w);
  REP(i,q){
    int t;
    cin >> t;
    if(t==1){
      int r,c;
      cin >> r >> c;
      r--;c--;
      m[r][c]=1;

      REP(j,4){
        int nr = r + dr[j];
        int nc = c + dc[j];
        if(nr < 0 || nr >=h || nc <0 || nc >=w)continue;
        if(m[nr][nc]==1){
          tree.unite(to_i(r,c), to_i(nr,nc));
        }
      }

    }else{
      int ra,ca,rb,cb;
      cin >> ra >> ca >> rb >> cb;
      ra--;ca--;rb--;cb--;
      if(m[ra][ca] != 1 || m[rb][cb] != 1){
        cout << "No" << endl;
        continue;
      }

      if(tree.same(to_i(ra,ca), to_i(rb,cb))){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
}

