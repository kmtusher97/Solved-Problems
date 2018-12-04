/*
 UVa problem 537 - Artificial Intelligence?
*/
#include <bits/stdc++.h>
using namespace std;
char question[10000], vlu[100], prifix, unit, prmt;

double find_vlu()
{
    double v=0.0, mlt=1;
    int i, j, L=strlen(vlu), pos;
    bool chk=false;

    for(i=0; i<L; i++)
        if(vlu[i]=='.') { chk=true, pos=i; break; }

    if(chk) {
        for(i=pos-1; i>=0; i--)
            v+=(vlu[i]-48)*mlt, mlt*=10;

        for(i=pos+1, mlt=0.1; i<L; i++)
            v+=(vlu[i]-48)*mlt, mlt/=10.0;
    }
    else
        for(i=L-1; i>=0; i--)
            v+=(vlu[i]-48)*mlt, mlt*=10;

    return v;
}

double prifix_vlu()
{
    double p;

    if(prifix=='m') p=0.001;
    else if(prifix=='k') p=1000.0;
    else if(prifix=='M') p=1000000.0;
    else p=1.0;

    return p;
}

int main()
{
    int t, tc=0;
    scanf("%d", &t);
    getchar();

    while(t--) {
        gets(question);

        int i, j, L=strlen(question), n;
        double voltage, current, power, ans;
        bool V, I, P;
        V=I=P=false;

        printf("Problem #%d\n", ++tc);

        for(i=0; i<L; i++) {
            if(question[i]=='=') {
                if(question[i-1]=='U') {
                    V=true;

                    for(j=i+1, n=0; ; j++) {
                        if(question[j]>='0' && question[j]<='9') vlu[n++]=question[j];
                        else if(question[j]=='.' && (question[j+1]>='0' && question[j+1]<='9')) vlu[n++]=question[j];
                        else break;
                    }
                    vlu[n]='\0';
                    //cout << vlu << endl;
                    if(question[j]=='m' || question[j]=='k' || question[j]=='M') prifix=question[j];
                    else prifix='1';
                    //cout << prifix << endl;
                    voltage=find_vlu()*prifix_vlu();
                    //cout << fixed << setprecision(3) << voltage << endl;
                }
                else if(question[i-1]=='P') {
                    P=true;

                    for(j=i+1, n=0; ; j++) {
                        if(question[j]>='0' && question[j]<='9') vlu[n++]=question[j];
                        else if(question[j]=='.' && (question[j+1]>='0' && question[j+1]<='9')) vlu[n++]=question[j];
                        else break;
                    }
                    vlu[n]='\0';
                    //cout << vlu << endl;
                    if(question[j]=='m' || question[j]=='k' || question[j]=='M') prifix=question[j];
                    else prifix='1';
                    //cout << prifix << endl;
                    power=find_vlu()*prifix_vlu();
                    //cout << fixed << setprecision(3) << power << endl;
                }
                else if(question[i-1]=='I') {
                    I=true;

                    for(j=i+1, n=0; ; j++) {
                        if(question[j]>='0' && question[j]<='9') vlu[n++]=question[j];
                        else if(question[j]=='.' && (question[j+1]>='0' && question[j+1]<='9')) vlu[n++]=question[j];
                        else break;
                    }
                    vlu[n]='\0';
                    //cout << vlu << endl;
                    if(question[j]=='m' || question[j]=='k' || question[j]=='M') prifix=question[j];
                    else prifix='1';
                    //cout << prifix << endl;
                    current=find_vlu()*prifix_vlu();
                    //cout << fixed << setprecision(3) << current << endl;
                }
            }
        }
        if(V && I) ans=voltage*current, unit='W', prmt='P';
        else if(P && V) ans=power/voltage, unit='A', prmt='I';
        else if(P && I) ans=power/current, unit='V', prmt='U';

        printf("%c=%.2lf%c\n\n", prmt, ans, unit);
    }

    return 0;
}
