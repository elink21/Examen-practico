#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct gaussian{
    float val;
    float a,b,c;
    float move;
    float x;
}g;

struct sigm1
{
    float move;
    float x;
    float val;
}s1;
struct sigm2
{
    float x;
    float val;
}s2;

int main()
{
    g.a=1;g.b=1;g.c=1;
    g.move=-4;
    s1.move=10;

    float inter[10],x;
    int n=0;
    char sigma2[50]="1/(1+exp(-x+10)),";
    char sigma[50]="1/(1+exp(x)),";
    char gauss[50]=" 1*exp(    -(( x-1-4 )**2)/ (2*(1**2))   ) ";
    char address[100]="C:/gnuplot/bin/gnuplot.exe -p -e \"plot sin(x)\" ";
    char end[20]="\"  ";
    strcat(address,sigma2);
    strcat(address,sigma);
    strcat(address,gauss);

    printf("Ingrese valor de x: ");
    scanf("%f",&x);

    printf("X\t Gaussiana\t Sigmoidal 1\t Sigmoidal 2 \t Diff\n");
    for(int i=0;i<=100;i++)
    {

        float a= (float)i/10;
        g.x=a;
        g.val=g.a*exp( -1*(  pow(g.x-g.b+g.move ,2 ) ) / (  2*pow(g.c,2)   ) );
        s1.x=a;
        s1.val=1/(1+exp(-s1.x+s1.move ));
        s2.x=a;
        s2.val=1/(1+exp(s2.x));
        if(fabs(g.val-s1.val)>0.012 &&fabs(g.val-s1.val) <0.014 ) inter[n++]=a;
        if(fabs(g.val-s2.val)>0.012 &&fabs(g.val-s2.val) <0.014 ) inter[n++]=a;
        printf("%f\t %f\t %f\t %f\t %f\n",a,g.val,s1.val,s2.val,fabs(s2.val-s1.val));
    }
    for(int i=0;i<n;i++)
    {
        if(i==0) strcat(address,",");
        char aux[10];
        s1.x=inter[i];
        s1.val=1/(1+exp(-s1.x+s1.move ));
        sprintf(aux,"%f",s1.val);
        strcat(address,aux);
        if(i!=n-1)strcat(address,",");
    }
    g.x=x;
    g.val=g.a*exp( -1*(  pow(g.x-g.b+g.move ,2 ) ) / (  2*pow(g.c,2)   ) );
    s1.x=x;
    s1.val=1/(1+exp(-s1.x+s1.move ));
    s2.x=x;
    s2.val=1/(1+exp(s2.x));
    printf("\nf1(x)= %f \t f2(x)= %f \t f3(x)= %f",g.val,s1.val,s2.val );
    strcat(address,end);
    system(address);
}
