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

bool compare( const P& a, const P& b ){
    if( a.second == b.second ) return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int T, N, input2;
    char input1;
    bool visited[1000000];
    
    cin >> T;
    while( T-- ){
        cin >> N;
        memset( visited, 0, sizeof(visited) );
        priority_queue<P> MaxHeap;
        priority_queue<P, vector<P>, greater<P>> MinHeap;
        for( int i=0; i<N; ++i ){
            cin >> input1 >> input2;
            if( input1 == 'I' ){
                MaxHeap.push( {input2, i} );
                MinHeap.push( {input2, i} );
                visited[i] = true;
            }else{
                if( input2 == -1 ){
                    while( !MinHeap.empty() && !visited[MinHeap.top().second] ) MinHeap.pop();
                    if( !MinHeap.empty() ){
                        visited[MinHeap.top().second] = false;
                        MinHeap.pop();
                    }
                }else{
                    while( !MaxHeap.empty() && !visited[MaxHeap.top().second] ) MaxHeap.pop();
                    if( !MaxHeap.empty() ){
                        visited[MaxHeap.top().second] = false;
                        MaxHeap.pop();
                    }
                }
            }
        }
        while( !MinHeap.empty() && !visited[MinHeap.top().second] ) MinHeap.pop();
        while( !MaxHeap.empty() && !visited[MaxHeap.top().second] ) MaxHeap.pop();
        if( MinHeap.empty() && MaxHeap.empty() ) cout << "EMPTY\n";
        else cout << MaxHeap.top().first << " " << MinHeap.top().first << "\n";
    }
    return 0;
}
