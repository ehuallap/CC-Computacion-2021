#include <iostream>
#include <conio.h>
using namespace std;

long sum_even_fibonacci(int limit_value)
{
    int fi1=1;
    int fi2=2;
    int fi3=0;
    long sum=fi2;
    while(fi3<=limit_value)
    {
        if(limit_value<=1){
            sum=0;
            break;
        }
        fi3=fi1+fi2;
        if(fi3%2==0)
            sum+=fi3;
        fi1=fi2;
        fi2=fi3;
    }
    return sum;
}
int main()
{
    int result;
    cout<<"La suma par de Fibonacci, sin que su ultimo valor exceda 4 000 000 es "<<sum_even_fibonacci(4000000)<<endl;
    cout<<"\nPRESIONE ENTER PARA FINALIZAR"<<endl;
    getch();
    return 0;
}
