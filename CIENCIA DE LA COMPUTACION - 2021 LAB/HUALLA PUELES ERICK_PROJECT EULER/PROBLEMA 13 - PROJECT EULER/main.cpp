#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    long double sum = 1;
    long double num;
    ifstream fin("E:\FICHEROS/PROBLEM 13 EULER.txt");

    while (fin >> num) {
        sum += num;
    }
    fin.close();
    cout.precision(12);
    cout<<"Los primeros diez digitos se pueden ver en la respuesta a continuacion: "<<sum<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
