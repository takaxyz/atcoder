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

int main(){
  int H,W,M;
  cin >> H >> W >> M;

  map<int,int> hmp, wmp;
  vector<P> bomb;
  vi hv(M), wv(M);
  REP(i,M){
    int h,w;

    cin >> h >> w;
    hv[i] = h;
    wv[i] = w;
    hmp[h]++;
    wmp[w]++;
  }

  int max_h = 0;
  int max_w = 0;

  set<int> max_h_set, max_w_set;
  for(auto v: hmp){
    chmax(max_h, v.second);
  }
  for(auto v: hmp){
    if(v.second == max_h){
      max_h_set.insert(v.first);
    }
  }
  for(auto v: wmp){
    chmax(max_w, v.second);
  }
  for(auto v: wmp){
    if(v.second == max_w){
      max_w_set.insert(v.first);
    }
  }

  // for(auto v: max_h_set){
  //   cout << v << endl;
  // }
  // cout << "--" << endl;
  // for(auto v: max_w_set){
  //   cout << v << endl;
  // }

  int cnt=0;
  REP(i,M){
    if(max_h_set.count(hv[i]) == 1 &&  max_w_set.count(wv[i]) == 1)cnt++;
  }
  if(max_h_set.size() * max_w_set.size() == cnt){
    cout << max_h + max_w - 1 << endl;
  }else{
    cout << max_h + max_w << endl;
  }

}

