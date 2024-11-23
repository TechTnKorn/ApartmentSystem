#include "Tenant.h"

void Tenant::checkin(char f[], char l[],int a)
{
    strcpy(firstname,f);
    strcpy(lastname,l);
    age=a;
    //cout << firstname << " " << lastname;
}
void Tenant::get_name()
{
    cout << firstname << " " << lastname << endl;
}
