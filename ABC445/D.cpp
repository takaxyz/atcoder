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
  int H,W,N;
  cin >> H >> W >> N;
  vi h(N), w(N);
  map<int,vector<int>> mh,mw;
  REP(i,N){
    cin >> h[i] >> w[i];
  }

  vi used(N);

  vi h_ord(N);
  vi w_ord(N);
  iota(ALL(h_ord),0);
  iota(ALL(w_ord),0);
  sort(ALL(h_ord),[&](const int& i, const int& j){
      return h[i] > h[j];
    }
  );
  sort(ALL(w_ord),[&](const int& i, const int& j){
      return w[i] > w[j];
    }
  );


  vector<P> ans(N);
  int x=0,y=0;
  int hi=0,wi=0;
  REP(_,N){
    while(used[h_ord[hi]])hi++;
    while(used[w_ord[wi]])wi++;

    if(H == h[h_ord[hi]]){
      used[h_ord[hi]]=1;
      ans[h_ord[hi]] = {x,y};
      W -= w[h_ord[hi]];
      y += w[h_ord[hi]];
    }else{
      used[w_ord[wi]]=1;
      ans[w_ord[wi]] = {x,y};
      x += h[w_ord[wi]];
      H -= h[w_ord[wi]];
    }

  }

  for(auto[x,y]: ans)cout << x + 1 << " " << y + 1 << endl;


}

