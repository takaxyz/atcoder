#include<iostream>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
    int N;
    cin >> N;

    int p[N];

    REP(i,N)cin >> p[i];

    int i = 0;
    int ans = 0;
    while(i < N){
        if(p[i] == i + 1){
            ans += 1;
            i += 2;
        }else{
            i++;
        }
    }

    cout << ans << endl;
}