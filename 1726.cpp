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
 
int N, M;
int arr[100][100];
int ans[100][100][4];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
bool visited[100][100][4];
int target_x, target_y, target_dir;
int source_x, source_y, source_dir;
 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=M ) return false;
	else return true;
}

void BFS(){
	queue<pair<pair<int, int>, int>> q;
	q.push({{source_x, source_y}, source_dir});
	visited[source_x][source_y][source_dir] = true;
	while( !q.empty() ){
		int dx = q.front().first.first;
		int dy = q.front().first.second;
		int dir = q.front().second;
        
        if( dir < 2 ){
            if( !visited[dx][dy][2] ){
                q.push({{dx,dy},2});
                visited[dx][dy][2] = true;
                ans[dx][dy][2] = ans[dx][dy][dir] + 1;
            }
            if( !visited[dx][dy][3] ){
                q.push({{dx,dy},3});            
                visited[dx][dy][3] = true;
                ans[dx][dy][3] = ans[dx][dy][dir] + 1;
            }
        }else{
            if( !visited[dx][dy][0] ){
                q.push({{dx,dy},0});
                visited[dx][dy][0] = true;
                ans[dx][dy][0] = ans[dx][dy][dir] + 1;
            }
            if( !visited[dx][dy][1] ){
                q.push({{dx,dy},1});
                visited[dx][dy][1] = true;            
                ans[dx][dy][1] = ans[dx][dy][dir] + 1;
            }   
        }
        
		for( int i=1; i<4; ++i ){
            int dix = dx + dir_x[dir]*i;
            int diy = dy + dir_y[dir]*i;
            if( !check(dix, diy) ) break;
            if( arr[dix][diy] ) break;
            if( visited[dix][diy][dir] ) continue;
            q.push({{dix,diy},dir});
            visited[dix][diy][dir] = true; 
            ans[dix][diy][dir] = ans[dx][dy][dir] + 1;
        }
		q.pop();
	}
}
 
int main(){
 
	scanf("%d %d", &N, &M);
	memset( arr, 0, sizeof(arr) );
	memset( visited, 0, sizeof(visited) );
	memset( ans, 0, sizeof(ans) );
	for( int i=0; i<N; ++i ){
		for( int j=0; j<M; ++j ){
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d %d %d", &source_x, &source_y, &source_dir);
	scanf("%d %d %d", &target_x, &target_y, &target_dir);
	source_x--; source_y--; source_dir--;
	target_x--; target_y--; target_dir--;
	BFS();
    printf("%d", ans[target_x][target_y][target_dir]);
	return 0;
}
