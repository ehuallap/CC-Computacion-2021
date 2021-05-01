#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

int convertToASCII(string letter, int pos)
{
    int total;
    char x = letter[pos];
    total=int(x);
    return total;
}
void order_strings(string *arra, long longi)
{
    long min, i, j;
    string temp,temp1,aux;
    for (i = 0; i <=longi - 1; i++)
    {
        min = i;
        for (j = i + 1; j < longi; j++){
            temp=arra[min];
            temp1=arra[j];
            if (convertToASCII(temp,0) > convertToASCII(temp1,0))
                min = j;
        }
        aux = arra[min];
        arra[min] = arra[i];
        arra[i] = aux;
    }
}
void mostrar(string *arra, long longi)
{
    for(int i=0;i<longi;i++)
        cout<<"{"<<arra[i]<<"}";
    cout<<endl;
}
int main()
{
    long extension=43,centinel=0;
    string *conjunto=new string[extension],part_string;
    setlocale(LC_ALL, "spanish");

    ifstream expression_a("E:\FICHEROS/ejercicio6_words.txt");
    while (expression_a >> part_string){
        conjunto[centinel]=part_string;
        centinel+=1;
    }
    expression_a.close();
    cout<<"El arreglo sin ordenamiento lexicográfico: "<<endl;
    mostrar(conjunto,extension);
    cout<<"\n"<<endl;
    order_strings(conjunto,extension);
    cout<<"El arreglo con ordenamiento lexicográfico: "<<endl;
    mostrar(conjunto,extension);
    return 0;
}
