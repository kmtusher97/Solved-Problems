/*
************************************************
*           * Kamrul Hasan Tusher              *
*           * Jahangirnagar University         *
*           * CSE-45                           *
************************************************
*/
#include <bits/stdc++.h>

using namespace std;

typedef     long long               ll;
typedef     unsigned long long      ull;
typedef     pair<int, int>          pii;
typedef     pair<ll, ll>            pll;
typedef     pair<double, double>    pdd;
typedef     vector<double>          vd;
typedef     vector<ll>              vl;
typedef     vector<int>             vi;
typedef     vector<pii>             vii;
typedef     vector<pll>             vll;
typedef     vector<char>            vcc;
typedef     vector<string>          vss;
typedef     queue<int>              qi;
typedef     queue<pii>              qii;
typedef     priority_queue<int>     pq;
typedef     priority_queue<pii>     pqii;

#define     sc              scanf
#define     pf              printf
#define     NL              printf("\n")
#define     pb              push_back
#define     mk_pr           make_pair
#define     VISITED         1
#define     UNVISITED       0
#define     PI              acos(-1.0)
#define     eps             0.0000001
#define     modulo          1000000007
#define     MX              112345

#define     READ            freopen("INPUT.in", "r", stdin)
#define     WRITE           freopen("OUTPUT.out", "w", stdout)
#define     read            freopen("INPUT.txt", "r", stdin)
#define     write           freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, v)   memset(arr, v, sizeof(arr))
#define     FasterIO        ios_base :: sync_with_stdio( false ); cin.tie( 0 );

int dx4[] = { 0, 0, 1, -1 };    ///4 connected
int dy4[] = { -1, 1, 0, 0 };
int dx8[] = { 0, 0, 1, -1, -1, -1, 1, 1 };  /// 8 connected
int dy8[] = { -1, 1, 0, 0, 1, -1, -1, 1 };

ll LCM( ll a, ll b ) { return ( (a*b)/__gcd( a, b) ); }
ll POW( ll b, ll p ) { if( !p ) { return 1; } ll x = POW( b, p/2 ); x*=x; if( p&1 ) { x*=b; } return x; }
ll bigMod( ll b, ll p, ll m ) {  if( !p ) { return 1; } ll x = bigMod( b, p/2, m ); x = (x*x) % m; if( p&1 ) { x = (b*x) % m; } return x;  }
ll inv_mod( ll x ) { return bigMod( x, modulo-2, modulo ); }
//int prnt[500]; int prnt_find( int x ) { if( x == prnt[x] ) return x; return prnt[x] = prnt_find( prnt[x] ); }

///geometry functions
double reg_hexagon_area( double x ) { return ( (3.0 * sqrt(3.0) * x * x) / 2.0 ); }
double slope( double x1, double x2, double y1, double y2 ) { return ( (y1-y2) / (x1-x2) ); }
double oppst_side_of_angle( double a, double b, double angle ) { angle = (PI*angle)/180.0; return sqrt( a*a + b*b - (2*a*b*cos(angle)) ); }
double eucld_dis( double x1, double y1, double x2, double y2 ) { return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ); }
double trngle_area_hiron( double a, double b, double c ) { double s = (a+b+c)/2.0; return sqrt( s*(s-a)*(s-b)*(s-c) ); }

struct data{ int u, v, w; };

/*..............*/

char f0[1050], f1[1050], f2[1050], febonacci[5001][1050];

void febonacci_numbers()
{
    int i, j, L, L1, sum, carry, digit1, digit2;
    strcpy(f0, "0"), strcpy(f1, "1");
    strcpy(febonacci[0], f0), strcpy(febonacci[1], f1);

    int k;
    for(k=2; k<5001; k++) {

            for(i=strlen(f0)-1, j=strlen(f1)-1, carry=0, L=0; ; i--, j--) {
                digit1 = f0[i] - 48, digit2 = f1[j] - 48;

                if(i < 0) digit1 = 0;
                if(j < 0) digit2 = 0;

                if(i < 0 && j < 0) {
                    if(carry > 0) f2[L++] = carry + 48;
                    break;
                }

                sum = carry + digit1 + digit2;
                carry = sum / 10;
                f2[L++] = (sum % 10) + 48;
            }

        strcpy(f0, f1);

            for(i=L-1, L1=0; i>=0; i--)
                f1[L1++] = f2[i];

            f1[L1] = '\0';

            strcpy(febonacci[k], f1);
    }

}

int main()
{
    febonacci_numbers();

    int N, c;
    while(scanf("%d", &N) == 1) {
        printf("The Fibonacci number for %d is %s\n", N, febonacci[N]);
    }

    return 0;
}
