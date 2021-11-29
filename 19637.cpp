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
ull GCD( ull a, ull b ) { return b ? GCD( b , a%b ) : a; }
#define	ABS(x) ( ((x)<0)?-(x):(x) )
using namespace std;
#define INF 1e9
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

int main(void) {
    
    int N, M, tmp;
    map<int, string> m;
    vector<int> v;
    string str;
    
    cin >> N >> M;
    for( int i=0; i<N; ++i ){
        cin >> str >> tmp;
        if( m.find(tmp) == m.end() ){
            m[tmp] = str;
            v.push_back(tmp);
        }
    }
    int ldx, rdx, mid=0, ans=0;
    for( int i=0; i<M; ++i ){
        scanf("%d", &tmp);
        ldx = 0;
        rdx = (int)v.size()-1;
        ans = rdx;
        while( ldx < rdx ){
            mid = (ldx+rdx)/2;
            if( v[mid] < tmp ) ldx = mid+1;
            else{
                rdx = mid;
                ans = min( ans, mid );
            }
        }
        cout << m[v[ans]] << '\n';
    }
    return 0;
}
