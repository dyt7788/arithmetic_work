#include<iostream>
//图像压缩实验
//将图像进行存放使得空间最小
#include<string>
#include<fstream>
#include<stdio.h>
using namespace std;
int length(int i)//存储像素pi所需的位数
{
    int k=1;
    i = i/2;
    while(i>0)//二进制表示位数
    {
        k++;
        i=i/2;
    }
    return k;
}
void compress(int n,int p[],int s[],int l[],int b[])
{
    int Lmax=256,header=11;//每一段的头要占11
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=length(p[i]);
        int bmax=b[i];
        s[i]=s[i-1]+bmax;
        l[i]=1;
        for(int j=2;j<=i&&j<=Lmax;j++){
            if(bmax<b[i-j+1])
            {
                bmax=b[i-j+1];
            }

            if(s[i]>s[i-j]+j*bmax){
                s[i]=s[i-j]+j*bmax;
                l[i]=j;
            }
        }
        s[i]+=header;
    }
}
void traceback(int n,int &i,int s[],int l[])//怎么样分段
{
    if(n==0)
        return ;
    traceback(n-l[n],i,s,l);
    s[i++]=n-l[n];
}
void output(int s[],int l[],int b[],int n){
    
}