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
typedef pair<int, int> P;
const int MAX_V = 50;

int N, K, ans=INF, cnt=0;
bool visited[200000+1];

bool check( int x ){
    if( x<0 || x>100000 ) return false;
    else return true;
}

void BFS(){
    queue<P> q;
    q.push({N,0});
    visited[N] = true;
    while( !q.empty() ){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x] = true;
        if( K == x ){
            if( y < ans ){
                ans = y;
                cnt = 1;
            }else if( y == ans ) cnt++;
        }
        if( check(x+1) && !visited[x+1] ) q.push({x+1,y+1});
        if( check(x-1) && !visited[x-1] ) q.push({x-1,y+1});
        if( check(2*x) && !visited[2*x] ) q.push({2*x,y+1});
    }
    
}

int main(){
    fastio;
    cin >> N >> K;
    memset( visited, 0, sizeof(visited) );
    if( N == K ){
        cout << 0 << "\n";
        cout << 1;
        return 0;
    }else{
        BFS();
        cout << ans << "\n";
        cout << cnt;
    }
    return 0;
}
