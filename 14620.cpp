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
using namespace std;
#define INF 1e9
#define MOD 1e9+7
#define PIV 3.14159265358979323846
#define MAXN 200000
typedef pair<int, int> P;
const int MAX_V = 50;


int N, ans=1e9;
int arr[10][10];
bool visited[10][10];
/*
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=M ) return false;
	else return true;
}
*/

void DFS( int num ){
    if( num == 3 ){
        int tmp = 0;
        for( int i=0; i<N; ++i ){
            for( int j=0; j<N; ++j ){
                if( visited[i][j] ) tmp += arr[i][j];
            }
        }
        ans = min( ans, tmp );
        return ;
    }
    for( int i=1; i<N-1; ++i ){
        for( int j=1; j<N-1; ++j ){
            if( !visited[i][j] && !visited[i-1][j] && !visited[i+1][j] && !visited[i][j-1] && !visited[i][j+1] ){
                visited[i][j] = true;
                visited[i-1][j] = true;
                visited[i+1][j] = true;
                visited[i][j-1] = true;
                visited[i][j+1] = true;
                DFS( num+1 );
                visited[i][j] = false;
                visited[i-1][j] = false;
                visited[i+1][j] = false;
                visited[i][j-1] = false;
                visited[i][j+1] = false;
            }
        }
    }
}

int main(){
    memset( arr, 0, sizeof(arr) );
    memset( visited, 0, sizeof(visited) );
    scanf("%d", &N);
    for( int i=0; i<N; ++i ){
        for( int j=0; j<N; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    DFS( 0 );
    printf("%d", ans);
	return 0;
}










