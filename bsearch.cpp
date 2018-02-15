#include <iostream>
using namespace std;


int bSearch(int a[], int start, int stop, int k)
{
        if(stop>=start)
        {
            int mid=start+(stop-start)/2;   //calculate the mid of the segment between start - stop
            if(k==a[mid])
                return mid; //we found the element we're searching for
            if(k>a[mid])//k is greater than our mid element, so we search in the right subsegment of the vector
                return bSearch(a,mid+1,stop,k);
            return bSearch(a,start,mid-1,k);//k is lower than our mid element, so we search in the left subsegment of the vector
        }
        return -1;
}



int main()
{
    int k=56;//valune we're searching for
    int x[]={6,20,502,905,3000,5000,9100};
    cout<<"LENGTH: "<<sizeof(x)/sizeof(int)<<'\n';//fancy way to determine how many integers are in the vector
    cout<<bSearch(x,0,sizeof(x)/sizeof(int),k);


    k=905;
    cout<<'\n'<<bSearch(x,0,sizeof(x)/sizeof(int),k);
    k=9100;
    cout<<'\n'<<bSearch(x,0,sizeof(x)/sizeof(int),k);

    return 0;
}
