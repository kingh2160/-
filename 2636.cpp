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
typedef pair<double, int> P;
const int MAX_V = 50;
 
int N, M, ans=0, dx, dy, dix, diy;
int arr[100][100];
bool visited[100][100];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=M ) return false;
	else return true;
}

int BFS(){
    queue<P> q;
    queue<P> chi;
    memset( visited, 0, sizeof(visited) );
    q.push({0,0});
    visited[0][0] = true;
    while( !q.empty() ){
        dx = q.front().first;
        dy = q.front().second;
        q.pop();
        for( int i=0; i<4; ++i ){
            dix = dx + dir_x[i];
            diy = dy + dir_y[i];
            if( check(dix, diy) && !visited[dix][diy] ){
                if( arr[dix][diy] == 0 ){
                    q.push({dix,diy});
                    visited[dix][diy] = true;
                }else{
                    chi.push({dix,diy});
                    visited[dix][diy] = true;
                }
            }
        }
    }
    int ret = (int)chi.size();
    while( !chi.empty() ){
        dx = chi.front().first;
        dy = chi.front().second;
        chi.pop();
        arr[dx][dy] = 0;
    }
    return ret;
}

int main(){
    int time = 0;
    int tmp = 0;
	scanf("%d %d", &N, &M);
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    while( 1 ){
        tmp = BFS();
        if( tmp == 0 ) break;
        time++;
        ans = tmp;
    }
    printf("%d\n%d", time, ans);
	return 0;
}
