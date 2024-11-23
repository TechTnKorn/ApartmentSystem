#include "Gobal.h"

void error()
{
    system("cls");
    cout << "\a\t\tError!!!" << "\n\t    Please try again\n"
    << "_______________________________________________\n\n";
}
void what_room(int num,int &f,int &r)
{
    f=num/100;
    r=num%100;
}
bool check_error_min(int a,int b)
{
    return a<=b;
}
bool check_error_max(int a,int b)
{
    return a>=b;
}
bool check_error_not(int a,int b)
{
    return a!=b;
}
