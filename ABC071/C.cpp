#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MOD 1000000007

using namespace std;
 
typedef long long int ll;

const ll INF=(ll)1e18;

int main(){
    int N;
    cin >> N;

    map<ll, int> m;
    vector<ll> a;

    REP(i,N){
        ll tmp;
        cin >> tmp;
        m[tmp]++;
        if(m[tmp] % 2 == 0){
            a.push_back(tmp);
        }
    }
    if(a.size() > 1){
        sort(a.begin(),a.end());
        cout << a[a.size()-1] * a[a.size()-2] << endl;
    }else{
        cout << 0 << endl;
    }

}