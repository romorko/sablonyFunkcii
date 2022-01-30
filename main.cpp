#include <iostream>

template <typename Any>
int cmp(const void *a,const void *b);

template <typename Any>
void swap(Any &a, Any &b);

template <typename Any>
void swap(Any *a, Any *b,int n);

int main()
{
    int x=10;
    int y=5;
    swap<int>(x,y);
    float pole1[] {0.2,1.4,2.3};
    float pole2[] {2.1,6.6,8.8};
    for(auto i:pole1)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    qsort(pole1,3,sizeof (pole1[0]),cmp<float>);
    for(auto i:pole1)
    {
        std::cout<<i<<" ";
    }
    swap(pole1,pole2,3);
    return 0;
}

template <typename Any>
void swap(Any &a, Any &b)
{
    Any temp = a;
    a=b;
    b=temp;
}

template <typename Any>
void swap(Any *a, Any *b,int n)
{
    Any temp;
    for(int i=0;i<n;++i)
    {
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

template <typename Any>
int cmp(const void *a,const void *b)
{
    Any *prvy = (Any *)a;
    Any *druhy= (Any *)b;
    return (*prvy)<(*druhy)?1:(*prvy)>(*druhy)?-1:0;
}
