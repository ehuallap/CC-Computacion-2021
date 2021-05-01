#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
long pythagorean()
{
    long result;
    for(int c=0;c<=1000;c++)
    {
        for(int b=0;b<=1000;b++)
        {
            for(int a=0;a<=1000;a++)
            {
                if(a<b && a<c && b<c)
                {
                    if((pow(a,2)+pow(b,2))==pow(c,2) && a+b+c==1000)
                    {
                        cout<<a<<"^2 + "<<b<<"^2 = "<<c<<"^2"<<endl;
                        cout<<" que dan como producto: ";
                        return (a*b*c);
                    }
                }
            }
        }
    }
}
int main()
{
    cout<<"Los 3 unicos numeros pitagoricos son: "<<pythagorean()<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
}
