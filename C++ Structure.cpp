#include<bits/stdc++.h>
using namespace std;
struct Box
{
    double width,height,depth;
    Box()
    {
        width=height=depth=0.0;
    }
    Box(double w,double h,double d)
    {
        width=w;
        height=h;
        depth=d;
    }
    void volume()
    {
        cout<<width*height*depth<<endl;
    }
};

int main()
{
    Box myBox1;
    Box myBox2(12,15,20);
    myBox1.volume();
    myBox2.volume();
}
