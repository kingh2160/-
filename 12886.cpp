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

int N, M;
int A, B, C;
int sum=0;
bool visited[1000+1][1000+1];
int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check( int x, int y ){
    if( x<0 || y<0 || x>=N || y>=N ) return false;
    else return true;
}

int BFS( int x, int y, int z ){
    queue<P> q;
    int low = min( min(x,y), z );
    int high = max( max(x,y), z );
    visited[low][high] = true;
    q.push({low,high});
    while( !q.empty() ){
        int l = q.front().first;
        int r = q.front().second;
        if( l == sum/3 && r == sum/3 ) return 1;
        q.pop();
        r -= l;
        l += l;
        int tmp1 = min( min(l,r), sum-l-r );
        int tmp2 = max( max(l,r), sum-l-r );
        if( !visited[tmp1][tmp2] ){
            visited[tmp1][tmp2] = true;
            q.push({tmp1,tmp2});
        }else if( !visited[tmp1][sum-tmp1-tmp2] ){
            visited[tmp1][sum-tmp1-tmp2] = true;
            q.push({tmp1,sum-tmp1-tmp2});
        }else if( !visited[sum-tmp1-tmp2][tmp2] ){
            visited[sum-tmp1-tmp2][tmp2] = true;
            q.push({sum-tmp1-tmp2,tmp2});
        }
    }
    return 0;
}

int main(){
    fastio;
    cin >> A >> B >> C;
    memset( visited, 0, sizeof(visited) );
    sum = A+B+C;
    if( sum%3 != 0 ) printf("0");
    else printf("%d", BFS( A, B, C ));
    return 0;
}
