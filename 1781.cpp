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

bool compare( P p1, P p2 ){
    if( p1.first != p2.first ) return p1.first < p2.first;
    else return p1.second > p2.second;
}

int main(void) {
    
    int N;
    int A, B;
    vector<P> v;
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    cin >> N;
    for( int i=0; i<N; ++i ){
        scanf("%d %d", &A, &B);
        v.push_back(P(A,B));
    }
    
    ll ans = 0;
    sort( v.begin(), v.end(), compare );
    for( int i=0; i<N; ++i ){
        if( pq.empty() ) pq.push( v[i].second );
        else{
            if( v[i].first > pq.size() ) pq.push( v[i].second );
            else{
                if( v[i].second > pq.top() ){
                    pq.pop();
                    pq.push( v[i].second );
                }
            }
        }
    }
    while( !pq.empty() ){
        ans += pq.top();
        pq.pop();
    }
    printf("%lld", ans);
    return 0;
}
