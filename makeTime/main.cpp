#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;



int *sorter(int tim1, int tim2, int tim3, int tim4, int tim5, int tim6)
{
    int* t= new int[6];
    t[0] = tim1;
    t[1] = tim2;
    t[2] = tim3;
    t[3] = tim4;
    t[4] = tim5;
    t[5] = tim6;


       for(int i = 0 ; i < 6; i++ )
    {
        for( int j = 0; j < 6 - 1; j++ )
        {
            if( t[ j ] > t[ j + 1 ] )
                swap( t[ j ], t[ j + 1 ] );

        }
    }

    return t;


}




string makeTime(int a, int b, int c, int d, int e, int f)
{
    int * sortedT=sorter(a,b,c,d,e,f);

    if(a+b+c+d+e+f>33 || sortedT[0]>2 || sortedT[2]>5 || sortedT[4]>5
       ||sortedT[5]>9 || sortedT[3]>9)
    {
        cout<<"Can't make a real time"<<endl;
   return 0;
    }

    string time;

    string aa = to_string(sortedT[0]);
    string bb = to_string(sortedT[1]);
    string cc = to_string(sortedT[2]);
    string dd = to_string(sortedT[3]);
    string ee = to_string(sortedT[4]);
    string ff = to_string(sortedT[5]);


    time.append(aa);

    time.append(bb);
    time.append(":");
    time.append(cc);
    time.append(dd);
    time.append(":");
    time.append(ee);
    time.append(ff);

    return time;
}




int main()
{

    cout << "Time is: " << endl;
    cout<<makeTime(2,4,1,1,1,6);

    return 0;
}
