#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include "Tenant.h"
#include "Gobal.h"

using namespace std;

class Room
{
public:
    Tenant user;
    int floor_number;
    int room_number;
    int ele_unit,water_unit;
    Room() : floor_number(1), room_number(1), ele_unit(0), water_unit(0), status(0){};
    void data();
    void payment(float,float,float);
    void reg_ed();
    //user
    void select_f(int);
    void select_r(int);
    void enter_data(Tenant);
    void set_password(int);
    int get_password();
    void status_change();
    bool status_check(int);
    void set_ele();
    void set_water();

private:
    int status;//0=empty
    int password;
};
#endif // ROOM_H
