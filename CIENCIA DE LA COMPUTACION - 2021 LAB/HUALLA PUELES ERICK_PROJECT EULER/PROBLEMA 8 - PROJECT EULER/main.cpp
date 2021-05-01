#include <iostream>
#include <conio.h>
using namespace std;

long long greatest_product(string expression,int extension, int portion)
{
    int num;
    char digit;
    long long result=1,greatest=0;
    while(expression.length()>=portion)
    {
        result=1;
        for(int i=0;i<portion;i++)
        {
            digit=expression[i];
            num=digit-'0';
            result*=num;
        }
        expression.erase(0,1);
        if(result>=greatest)
            greatest=result;
    }
    return greatest;
}
int main()
{
    string sub_expression1="7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843";
    string sub_expression2="8586156078911294949545950173795833195285320880551112540698747158523863050715693290963295227443043557";
    string sub_expression3="6689664895044524452316173185640309871112172238311362229893423380308135336276614282806444486645238749";
    string sub_expression4="3035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776";
    string sub_expression5="6572733300105336788122023542180975125454059475224352584907711670556013604839586446706324415722155397";
    string sub_expression6="5369781797784617406495514929086256932197846862248283972241375657056057490261407972968652414535100474";
    string sub_expression7="8216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586";
    string sub_expression8="1786645835912456652947654568284891288314260769004224219022671055626321111109370544217506941658960408";
    string sub_expression9="0719840385096245544436298123098787992724428490918884580156166097919133875499200524063689912560717606";
    string sub_expression10="0588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    string final_expression=sub_expression1+sub_expression2+sub_expression3+sub_expression4+sub_expression5+sub_expression6+sub_expression7+sub_expression8+sub_expression9+sub_expression10;

    cout<<"El producto mas grande formado por los 13 digitos adyacentes es: "<<greatest_product(final_expression,final_expression.length(),13)<<endl;
    cout<<"\n PRESIONE ENTER PARA FINALIZAR";
    getch();
    return 0;
}
