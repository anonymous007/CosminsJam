#include <iostream>
using namespace std;


int bSearch(int a[], int start, int stop, int k)
{
    int mid=(stop-start)/2;//we determine the middle value of the vector
    if(start>0)
        return -1;//returned when we didn't find the element
    if(k==a[mid])
        return mid;//returned when we found the element k in array a
    else if(k>a[mid])//if the value k is greater than our mid value, we look in the second half, again.
        return bSearch(a, mid, stop, k);
    else//otherwise, we look in the first half, again.
        return bSearch(a, start, mid,k);
}



int main()
{
    int k=56;//valune we're searching for
    int x[]={6,20,502,905,3000,5000,9100};
    cout<<"LENGTH: "<<sizeof(x)/sizeof(int)<<'\n';//fancy way to determine how many integers are in the vector
    cout<<bSearch(x,0,sizeof(x)/sizeof(int),k);


    k=905;
    cout<<'\n'<<bSearch(x,0,sizeof(x)/sizeof(int),k);

    return 0;
}
