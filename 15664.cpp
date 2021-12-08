#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <list>
#include <deque>
#include <numeric>
#include <set>
#include <climits>
#include <utility>
#include <map>
#include <float.h>
typedef long long ll;
typedef unsigned long long ull;
inline int max( int x, int y ){ return x > y ? x : y ; }
inline int min( int x, int y ){ return x < y ? x : y ; }
inline ll max( ll x, ll y ){ return x > y ? x : y ; }
inline ll min( ll x, ll y ){ return x < y ? x : y ; }
inline ull max( ull x, ull y ){ return x > y ? x : y ; }
inline ull min( ull x, ull y ){ return x < y ? x : y ; }
//ull GCD( ull a, ull b ) { return b ? GCD( b , a%b ) : a; }
int GCD( int a, int b ) { return b ? GCD( b , a%b ) : a; }
#define	ABS(x) ( ((x)<0)?-(x):(x) )
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define INF 1e9+7
#define MOD 10000
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, string> P;
const int MAX_V = 50;

int N, M, tmp;
vector<int> v;
vector<int> ans;

void GO( int cnt, int idx ){
    if( cnt == M ){
        for( auto i:ans ) cout << i << " ";
        cout << "\n";
        return ;
    }
    int temp = 0;
    for( int i=idx; i<N; ++i ){
        if( temp == v[i] ) continue;
        temp = v[i];
        ans.push_back(v[i]);
        GO( cnt+1, i+1 );
        ans.pop_back();
    }
    return ;
}

int main(){
    fastio;
    cin >> N >> M;
    for( int i=0; i<N; ++i ){
        cin >> tmp;
        v.push_back( tmp );
    }
    sort( v.begin(), v.end() );
    GO( 0, 0 );
    return 0;
}
