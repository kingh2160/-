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

int dir_x[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };
int dir_y[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
char arr[8][8];
bool visited[9][8][8];
bool flag = false;

bool check( int x, int y ){
    if( x<0 || y<0 || x>7 || y>7 ) return false;
    else return true;
}

void BFS(){
    queue<pair<pair<int, int>, int>> q;
    q.push({{7,0},0});
    while( !q.empty() ){
        int dx = q.front().first.first;
        int dy = q.front().first.second;
        int now = q.front().second;
        if( dx == 0 && dy == 7 ) flag = true;
        
        for( int i=0; i<9; ++i ){
            int dix = dx + dir_x[i];
            int diy = dy + dir_y[i];
            int n_now = min( now+1, 8 );
            if( !check(dix, diy) ) continue;
            if( dix-now >= 0 && arr[dix-now][diy] == '#' ) continue;
            if( dix-now-1 >= 0 && arr[dix-now-1][diy] == '#' ) continue;
            if( !visited[n_now][dix][diy] ){
                visited[n_now][dix][diy] = true;
                q.push({{dix,diy}, n_now});
            }
        }
        q.pop();
    }
    
}

int main(void) {
    
    for( int i=0; i<8; ++i ) scanf("%s", arr[i]);
    memset( visited, 0, sizeof(visited) );
    BFS();
    if( flag ) printf("1");
    else printf("0");
    return 0;
}
