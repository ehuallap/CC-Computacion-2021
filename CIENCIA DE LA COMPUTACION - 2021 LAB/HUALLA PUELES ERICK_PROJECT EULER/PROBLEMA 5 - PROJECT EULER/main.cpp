#include <iostream>
#include <conio.h>
using namespace std;

long smallest_multiple(int begi_num, int last_num)
{
    long control,MCM=1;
    int quantity=last_num-begi_num+1;
    int *numbers_array=new int[quantity];
    for(int i=0;i<quantity;i++)
    {
        numbers_array[i]=begi_num+i;
    }
    for(int i=2;i<last_num;i++)
    {
        control=0;
        for(int j=0;j<quantity;j++){
            if(numbers_array[j]%i==0)
            {
                numbers_array[j]=numbers_array[j]/i;
                control=1;
            }
        }
        if(control==1){
            MCM*=i;
            i-=1;
        }
    }
    return MCM;
}
int main()
{
    cout<<"El numero positivo mas pequeño divisible entre todos los numeros del 1 al 20 es: "<<smallest_multiple(1,20)<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
