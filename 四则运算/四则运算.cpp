// 四则运算.cpp : 定义控制台应用程序的入口
//


#include "stdafx.h"
#include<iostream> 
using namespace std;
#include<stdlib.h>
#include<conio.h>

void DealFenshu(int m, int a[][2])
{
    for(int p=0;p<m;p++)
    {
        int i=(int)rand()%10;
        int j=(int)rand()%10;
        while(j==0||i>=j)
        {
            i=(int)rand()%10;
            j=(int)rand()%10;
        }
        int x=(int)rand()%10;
        int y=(int)rand()%10;
        while(y==0||x>=y)
        {
            x=(int)rand()%10;
            y=(int)rand()%10;
        }
        int k=(int)rand()%100/25;
        switch(k)
        {
            case 0:
                std::cout<<"("<<i<<"/"<<j<<")"<<"+"<<"("<<x<<"/"<<y<<")"<<"=";
                a[p][0]=i*y+x*j;
                a[p][1]=j*y;
                break;
            case 1:
                std::cout<<"("<<i<<"/"<<j<<")"<<"-"<<"("<<x<<"/"<<y<<")"<<"=";
                a[p][0]=i*y-x*j;
                a[p][1]=j*y;
                break;
            case 2:
                std::cout<<"("<<i<<"/"<<j<<")"<<"*"<<"("<<x<<"/"<<y<<")"<<"=";
                a[p][0]=i*x;
                a[p][1]=j*y;
                break;
            case 3:
                a[p][0]=i*y;
                a[p][1]=j*x;
                std::cout<<"("<<i<<"/"<<j<<")"<<"/"<<"("<<x<<"/"<<y<<")"<<"=";
            }
            
            if(p%5==4)
            {
                std::cout<<std::endl;
            }
            else
            {
                std::cout<<'\t';
            }
    }

}
//生成分数题目




void DisplayFenshu(int a[][2],int w,int m)
{
    if(w==1)  //判定条件如果是1则运行以下代码
    {
        for(int q=0;q<m;q++)
        {
            if(a[q][0]==0)
                std::cout<<"0"<<'\t';
            else
                std::cout<<a[q][0]<<"/"<<a[q][1]<<'\t';
            if(q%5==4)
            {
                std::cout<<std::endl;
            }
        }
    }
    else
    {};
}
//给出分数题目对应答案




void DealInt(int m,int a[])
{    
    for(int p=0;p<m;p++)
    {
    int i=(int)rand()%10;
    int j=(int)rand()%10;
    int k=(int)rand()%100/25;
    switch(k)
    {
    case 0:
       std:: cout<<i<<"+"<<j<<"=";
            a[p]=i+j;
        break;
    case 1:
        std::cout<<i<<"-"<<j<<"=";
        a[p]=i-j;
        break;
    case 2:
        std::cout<<i<<"*"<<j<<"=";
        a[p]=i*j;
        break;
    case 3:
        try
        {
        a[p]=i/j;
        std::cout<<i<<"/"<<j<<"=";
        }
        catch(...)
        {
            p--;
        }
        

    }
        
        if(p%5==4)
        {
           std:: cout<<std::endl;
        }
        else
        {
           std:: cout<<'\t';
        }
    }
}
//生成整数题目




void DisplayInt(int a[],int w,int m)
{
    if(w==1)   //判定条件如果是1则运行以下代码
    {
        for(int q=0;q<m;q++)
        {
            std::cout<<a[q]<<'\t';
            if(q%5==4)
            {
                std::cout<<std::endl;
            }
        }
    }
    else
    {};
}
//给出整数题目对应答案



void main()
{
    int p;
    do
    {
        system("cls");
        int a[1000],b[1000][2];
        int m,n,w;
        std::cout<<"请输入生成的四则运算题个数：";
        std::cin>>m;
        std::cout<<std::endl;
        std::cout<<"请输入要生成的四则运算种类(输入1为整数，否则为真分数):";
        std::cin>>n;
        std::cout<<std::endl;
        if(n==1)
        {
            DealInt(m,a);
            std::cout<<std::endl;
        }
        else
        {
            DealFenshu(m,b);
            std::cout<<std::endl;
        }
        std::cout<<"是否输出答案(输入1则输出答案否则不输出答案)"<<std::endl;
        std::cin>>w;
        if(n==1)
        {
            DisplayInt(a,w,m);        
        }
        else
        {
            DisplayFenshu(b,w,m);
        }
        std::cout<<std::endl;
        std::cout<<"是否继续生成运算题(输入1则生成否则不生成)"<<std::endl;
        std::cin>>p;
        std::cout<<std::endl;
    }while(1==p);

}
