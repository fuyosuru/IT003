#include <bits/stdc++.h>
#include <ctime>
#include <string>
using namespace std;
double a[2000000],b[2000000];
string xau(int x)
{
    string p="0123456789";
    string ans="";
    while(x>0)
        {
            ans=p[x%10]+ans;
            x/=10;
        }
    return ans;
}
void heapify(int n,int i)
{
    int tonhat=i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[tonhat])
        tonhat = l;
    if (r < n && a[r] > a[tonhat])
        tonhat = r;
    if (tonhat != i)
    {
        swap(a[i],a[tonhat]);
        heapify(n,tonhat);
    }
}
void heapSort(int n)
{
    for (int i=n/2-1;i>=0;i--)
        heapify(n, i);

    for (int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(i,0);
    }
}
int goqs(int id,int l,int r)
{
    double num=a[id];
    while(true)
    {
        while(r>l && a[r]>num)
            r--;
        while(l<r && a[l]<num)
            l++;
        if(l>=r)
            return r;
        swap(a[l],a[r]);
        l++;
        r--;
    }
}
void qs(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    int p=goqs(mid,l,r);
    qs(l,p);
    qs(p+1,r);
}
void ms(int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    ms(l,mid);
    ms(mid+1,r);
    int i=l,j=mid+1,id=l;
    while(id++<=r)
    {
        if((a[i]>a[j] || i==mid+1) && j<=r)
            {
                b[id-1]=a[j];
                j++;
                continue;
            }
        else
        {
            b[id-1]=a[i];
            i++;
            continue;
        }
    }
    for(int k=l;k<=r;k++)
        a[k]=b[k];
}
int main()
{
   clock_t star,en;
   for(int i=1;i<=10;i++)
   {
       string name="Test"+xau(i)+".inp";
       freopen(name.c_str(),"r",stdin);

       for(int j=1;j<=1e6;j++)
        cin>>a[j];
        star=clock();
        ms(1,1e6);
       en=clock();
       cout<<name<<" mergesort:"<<double(en-star)/CLOCKS_PER_SEC<<"s\n";
       fclose(stdin);
   }
   for(int i=1;i<=10;i++)
   {
       string name="Test"+xau(i)+".inp";
       freopen(name.c_str(),"r",stdin);

       for(int j=1;j<=1e6;j++)
        cin>>a[j];
        star=clock();
        qs(1,1e6);
       en=clock();
       cout<<name<<" quicksort:"<<double(en-star)/CLOCKS_PER_SEC<<"s\n";
       fclose(stdin);
   }
   for(int i=1;i<=10;i++)
   {
       string name="Test"+xau(i)+".inp";
       freopen(name.c_str(),"r",stdin);

       for(int j=1;j<=1e6;j++)
        cin>>a[j];
        star=clock();
        sort(a+1,a+1000000+1);
       en=clock();
       cout<<name<<" sort c++:"<<double(en-star)/CLOCKS_PER_SEC<<"s\n";
       fclose(stdin);
   }
   for(int i=1;i<=10;i++)
   {
       string name="Test"+xau(i)+".inp";
       freopen(name.c_str(),"r",stdin);

       for(int j=1;j<=1e6;j++)
        cin>>a[j-1];
        star=clock();
        heapSort(1e6);
       en=clock();
       cout<<name<<" heapsort:"<<double(en-star)/CLOCKS_PER_SEC<<"s\n";
       fclose(stdin);
   }
}
