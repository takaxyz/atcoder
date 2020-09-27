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

template <typename T>
struct RMQ {
  const T INF = numeric_limits<T>::max();
  int n;
  vector<T> dat;
  RMQ(int n_) : n(), dat(n_ * 4, INF){
    int x = 1;
    while(n_ > x)x *= 2;
    n = x;
  }

  void update(int i, T x){
    i += n -1;
    dat[i] = x;
    while(i > 0){
      i = (i-1)/2; //parent
      // left child: i*2+1
      // right child: i*2+2
      dat[i] = min(dat[i*2 + 1], dat[i*2 + 2]);
    }
  }

  T query(int a, int b) {return query_sub(a,b,0,0,n); }

  T query_sub(int a,int b,int k, int l, int r){
    if(r<=a || b<=l){
      return INF;
    }else if(a<=l && r<=b){
      return dat[k];
    }else{
      T vl = query_sub(a,b,k*2+1, l, (l+r)/2);
      T vr = query_sub(a,b,k*2+2, (l+r)/2, r);
      return min(vl,vr);
    }
  }

  void print(){
    REP(i,2*n-1){
      cout << dat[i] << (i==2*n-2 ? "\n" : " ");
    }
  }

};


int main(){
  int n,q;
  cin >> n >> q;
  RMQ<int> rmq(n);
  REP(i,q){
    int c,x,y;
    cin >> c >> x >> y;
    if(c==0){
      rmq.update(x,y);
    }else{
      cout << rmq.query(x,y+1) << endl;
    }
//    rmq.print();
  }
}