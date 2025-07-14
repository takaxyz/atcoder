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

int main(){
  int n,h,w;
  cin >> n >> h >> w;

  vi a(n),b(n);
  REP(i,n)cin >> a[i] >> b[i];

  vi ord(n);
  REP(i,n)ord[i]=i;

  auto topos = [&](int x, int y) { return x * w + y; };
  auto tox = [&](int pos) { return pos / w; };
  auto toy = [&](int pos) { return pos % w; };

  do{
    vi used(h*w);

    auto check = [&](int p, int a, int b){
      int x = tox(p);
      int y = toy(p);
      if(x + a > h || y + b > w)return false;
      bool ok = true;
      REP(i,a)REP(j,b)if(used[topos(x+i,y+j)])ok=false;
      return ok;
    };


    REP(f,(1<<n)){
      int p = 0;
      REP(j,h*w)used[j]=0;

      REP(i, ord.size()){
        int aa = a[ord[i]];
        int bb = b[ord[i]];
        if((f >> i) & 1)swap(aa,bb);

        while(p < h*w && used[p]==1)p++;
        if(p == h*w){
//          REP(i,ord.size())cout << ord[i] << (i == ord.size()-1 ? "\n" : " ");
          cout << "Yes" << endl;
          return 0;
        }

        if(check(p, aa, bb)){
//          printf("%d - %d : %d %d %d\n", i, ord[i], p , aa, bb);
          int x = tox(p);
          int y = toy(p);
          REP(i,aa)REP(j,bb)used[topos(x+i,y+j)]=1;
        }
      }
      
      bool ok = true;
      REP(j,h*w)if(used[j]==0)ok = false;
      if(ok){
//          REP(i,ord.size())cout << ord[i] << (i == ord.size()-1 ? "\n" : " ");
        cout << "Yes" << endl;
        return 0;
      }
    }


  }while(next_permutation(ALL(ord)));

  cout << "No" << endl;

}

