
/*No of Balanced Binary trees possible if hieght h is given*/

#include<bits/stdc++.h>
using namespace std;
int balancedBT(int h)
{
    if(h==0 || h==1)
    {
        return 1;
    }
    
    int m = pow(10,9) +7;
    //as sum of hieght of sub tree at every node is 0 or 1
    int x=balancedBT(h-1);   
    int y =balancedBT(h-2);

    long res1= (long)x*x;       
    long res2= (long)x*y*2;

    int ans1 = (int)(res1%m);
    int ans2 = (int)(res2%m);

    int ans =(ans1 + ans2)%m;
    return ans;
}
int main()
{
    int h;
    cin>>h;
    int ans=balancedBT(h);
    cout<<ans<<endl;

}
