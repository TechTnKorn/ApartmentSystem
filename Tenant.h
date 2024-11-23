#ifndef TENANT_H
#define TENANT_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

class Tenant
{
public:
    void checkin(char [],char [],int);
    void checkout();
    void get_name();//recheckdata
    //int num_member,num_room;
private:
    char firstname[99],lastname[99];
    int age;
};
#endif // TENANT_H
