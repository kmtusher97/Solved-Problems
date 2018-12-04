/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 1000

char s[MX_N], t[MX_N];

struct Suffix_Array {
        char T[MX_N];
        int n, c[MX_N];
        int RA[MX_N], tempRA[MX_N];
        int SA[MX_N], tempSA[MX_N];

        int Phi[MX_N], PLCP[MX_N], LCP[MX_N];

        void init( char* t ) {
          n = strlen(t);
          for(int i=0; i<n; i++) T[i] = t[i];
          T[n++] = '%';
        }

        void countingSort( int k ) {
          memset(c, 0, sizeof c);
          for(int i=0; i<n; i++) c[i+k < n ? RA[i+k] : 0]++;
          for(int i=0, sm=0, t; i<max(300, n); i++)
            t = c[i], c[i] = sm, sm += t;
          for(int i=0; i<n; i++)
            tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
          for(int i=0; i<n; i++) SA[i] = tempSA[i];
        }

        void constructSA() {
          for(int i=0; i<n; i++) SA[i] = i, RA[i] = T[i];
          for(int k=1, r; k<n; k<<=1) {
            countingSort( k );
            countingSort( 0 );
            tempRA[SA[0]] = r = 0;
            for(int i=1; i<n; i++)
              tempRA[SA[i]] = ( RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k] ) ? r : ++r;
            for(int i=0; i<n; i++) RA[i] = tempRA[i];
            if( RA[SA[n-1]]==n-1 ) break;
        } }

        void computeLCP() {
          Phi[SA[0]] = -1;
          for(int i=1; i<n; i++) Phi[SA[i]] = SA[i-1];
          for(int i=0, L=0; i<n; i++) {
            if( Phi[i]==-1 ) {
              PLCP[i] = 0; continue;
            }
            while( T[i+L]==T[Phi[i]+L] ) L++;
            PLCP[i] = L;
            L = max(0, L-1);
          }
          for(int i=0; i<n; i++) LCP[i] = PLCP[SA[i]];
        }

        void print() {
          for(int i=0; i<n; i++) printf("%4d\t%2d\t%s\n", SA[i], LCP[i], T+SA[i]);
        }

        /*------------------------------------------------------*/
        bool check( int i, int j, int &l1 ) {
          i = ( (SA[i]<l1) ? 1 : 2 );
          j = ( (SA[j]<l1) ? 1 : 2 );
          return (i!=j);
        }

        void findMaxLCP( int& ret, int& l1 ) {
          for(int i=1; i<n; i++) if( check( i, i-1, l1 ) ) {
            ret = max(ret, LCP[i]);
          }
        }

        void printSolution( int& lcp, int& l1 ) {
          char last[MX_N];
          memset(last, '.', sizeof last);
          for(int i=1; i<n; i++) if( LCP[i]==lcp && check( i, i-1, l1 ) ) {
              bool ok = false;
              for(int j=SA[i], k=0; j<SA[i]+lcp; j++, k++) if( T[j]!=last[k] ) {
                ok = true; break;
              }
              if( !ok ) continue;
              for(int j=SA[i], k=0; j<SA[i]+lcp; j++, k++) {
                printf("%c", T[j]), last[k] = T[j];
              }
              printf("\n");
        } }
        /*------------------------------------------------------*/
} SA;

int main() {
  int caseno = 0;
  while( scanf("%s", s)!=EOF ) {
    if( caseno++ ) printf("\n");
    int a, b;
    strcpy(t, s);
    strcat(t, "#");
    a = strlen(t);
    scanf("%s", s);
    strcat(t, s);

    SA.init( t );
    SA.constructSA();
    SA.computeLCP();
    //SA.print();

    int lcp = 0;
    SA.findMaxLCP( lcp, a );
    if( lcp ) SA.printSolution( lcp, a );
    else printf("No common sequence.\n");
  }
  return 0;
}
