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
 
int N, M, T, ux=0, uy=0, dx=0, dy=0, tmp, tmp2;
int arr[50][50];
int del[50][50];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
 
bool check( int x, int y ){
	if( x < 0 || y < 0 || x >= N || y>=M ) return false;
	else return true;
}

void VIEW(){
    printf("\n");
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void SPREAD(){
    int cnt, delta;
    memset( del, 0, sizeof(del) );
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            if( arr[i][j] < 5 ) continue;
            cnt = 0;
            delta = arr[i][j] / 5;
            for( int k=0; k<4; ++k ){
                if( check( i+dir_x[k], j+dir_y[k] ) && arr[i+dir_x[k]][j+dir_y[k]] != -1 ){
                    del[i+dir_x[k]][j+dir_y[k]] += delta;
                    cnt++;
                }
            }
            del[i][j] -= delta * cnt;
        }
    }
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            arr[i][j] += del[i][j];
        }
    }
}

void CLEAN(){
    tmp = arr[ux][M-1];
    for( int i=M-1; i>1; --i ){
        arr[ux][i] = arr[ux][i-1];
    }
    tmp2 = arr[0][M-1];
    for( int i=0; i<ux-1; ++i ){
        arr[i][M-1] = arr[i+1][M-1];
    }
    arr[ux-1][M-1] = tmp;
    tmp = arr[0][0];
    for( int i=0; i<M-2; ++i ){
        arr[0][i] = arr[0][i+1];
    }
    arr[0][M-2] = tmp2;
    for( int i=ux-1; i>1; --i ){
        arr[i][0] = arr[i-1][0];
    }
    arr[1][0] = tmp;
    arr[ux][1] = 0;
    
    tmp = arr[dx][M-1];
    for( int i=M-1; i>1; --i ){
        arr[dx][i] = arr[dx][i-1];
    }
    tmp2 = arr[N-1][M-1];
    for( int i=N-1; i>dx+1; --i ){
        arr[i][M-1] = arr[i-1][M-1];
    }
    arr[dx+1][M-1] = tmp;
    tmp = arr[N-1][0];
    for( int i=0; i<M-2; ++i ){
        arr[N-1][i] = arr[N-1][i+1];
    }
    arr[N-1][M-2] = tmp2;
    for( int i=dx+1; i<N-2; ++i ){
        arr[i][0] = arr[i+1][0];
    }
    arr[N-2][0] = tmp;
    arr[dx][1] = 0;
}

int CALC(){
    int ret = 0;
    for( int i=0; i<N; ++i ){
        for( int j=0; j<M; ++j ){
            ret += arr[i][j];
        }
    }
    return ret;
}

int main(){
	scanf("%d %d %d", &N, &M, &T);
	memset( arr, 0, sizeof(arr) );
	for( int i=0; i<N; ++i ){
		for( int j=0; j<M; ++j ){
			scanf("%d", &arr[i][j]);
            if( arr[i][j] == -1 ){
                if( ux != 0 ){
                    dx = i;
                }else{
                    ux = i;
                }
            }
		}
	}
    while( T-- ){
        SPREAD();
        CLEAN();
    }
    printf("%d", CALC()+2);
	return 0;
}
