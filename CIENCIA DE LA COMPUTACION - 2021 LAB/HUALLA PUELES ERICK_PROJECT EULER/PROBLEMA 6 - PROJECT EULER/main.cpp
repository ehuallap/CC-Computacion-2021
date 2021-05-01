#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

long square(int num)
{
    return pow(num,2);
}
long sum_square_diff(int first_n_numbers)
{
    long sum_squares=0,square_sum=0,difference;
    for(int i=0;i<first_n_numbers;i++)
    {
        sum_squares+=square(i+1);
        square_sum+=i+1;
    }
    square_sum=pow(square_sum,2);
    difference=square_sum-sum_squares;
    return difference;
}
int main()
{
    cout<<"La diferencia entre la suma de cuadrados y cuadrado de la suma, de los cien primeros numeros naturales es: "<<sum_square_diff(100)<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
