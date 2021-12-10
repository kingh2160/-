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
#define MOD 1000000000
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;

int ans = INF, tmp;
bool visited[10000+1];
bool visit[10000];
void BFS( int A, int B ){
    memset( visit, 0, sizeof(visit) );
    queue<P> q;
    q.push( {A,0} );
    visit[A] = true;
    while( !q.empty() ){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if( x == B ) ans = min( ans, y );
        for( int i=1; i<10; ++i ){
            tmp = x % 1000;
            tmp += 1000*i;
            
            if( !visit[tmp] && !visited[tmp] ){
                q.push({tmp, y+1});
                visit[tmp] = true;
            }
        }
        for( int i=0; i<10; ++i ){
            tmp = x / 1000;
            tmp *= 1000;
            tmp += x % 100;
            tmp += i * 100;
            if( !visit[tmp] && !visited[tmp] ){
                q.push({tmp, y+1});
                visit[tmp] = true;
            }
        }
        for( int i=0; i<10; ++i ){
            tmp = x / 100;
            tmp *= 100;
            tmp += x % 10;
            tmp += i * 10;
            if( !visit[tmp] && !visited[tmp] ){
                q.push({tmp, y+1});
                visit[tmp] = true;
            }
        }
        for( int i=0; i<10; ++i ){
            tmp = x / 10;
            tmp *= 10;
            tmp += i;
            if( !visit[tmp] && !visited[tmp] ){
                q.push({tmp, y+1});
                visit[tmp] = true;
            }
        }
        
    }
}

int main(){
    fastio;
    int TC, A, B;
    memset( visited, 0, sizeof(visited) );
    visited[1] = true;
    for( int i=2; i<=(int)sqrt(10000); ++i ){
        if( visited[i] ) continue;
        for( int j=i+i; j<=10000; j+=i ) visited[j] = true;
    }
    cin >> TC;
    while( TC-- ){
        cin >> A >> B;
        ans = INF;
        BFS(A, B);
        if( ans == INF ) cout << "Impossible" << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
