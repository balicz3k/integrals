#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#define lp 1000

double c_od,c_do;
double f3(double x){
        double y=(pow(x,5)+pow(x,4)-pow(x,3)+pow(x,2)-3)/9;
        return y;      
}      
double f4(double x) {
        double y=x*x*x*x*x-3*x*x*x+4;
        return y;
}
double prostokaty(double( *f)(double)){
        double krok, p, suma=0;
        krok=(c_do-c_od)/lp;
        for(p=c_od; p<=c_do; p+=krok)
                suma+=(*f)(p);
        return suma*krok;        
}
double trapezy(double (*f)(double)){
        double krok,p,s=0,tmp,tmp2;
        krok=(c_do-c_od)/lp;
        tmp=((*f)(c_od));
        for(p=c_od;p<c_do;p+=krok){
                tmp2=(*f)(p+krok);
                s+=(tmp+tmp2)/2;
                tmp=tmp2;
        }
        return s*krok;
}
double mc(double(*f)(double))
{       double min=0,max=0,x,y,z1=c_do-c_od,z2,ff,krok=z1/lp;
        for(double i=c_od;i<=c_do;i+=krok){
                double a=(*f)(i);
                if(a>max)max=a;
                if(a<min)min=a;
        }
        z2=max-min;
        int n=100000,no=0,n2;
        n2=n;
        while(n2-->0){
                x=rand();
                y=rand();
                x=x/RAND_MAX*z1+c_od;
                y=y/RAND_MAX*(z2)+min;
                ff=(*f)(x);
                if(y>0&&ff>y) no++;
                else if(y<0&&ff<y) no--;
        }
        return z1*z2*no/n;
}