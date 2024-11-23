#ifndef APARTMENT_H
#define APARTMENT_H
#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include "Tenant.h"
#include "Room.h"
#include "Gobal.h"

using namespace std;

class Apartment
{
public:
    Room rm[999];
    int number_room;
    void set_floor(int);
    void set_room(int);
    void set_price_rm(float);
    void set_ele(float);
    void set_water(float);
    void set_number_room(int,int);
    void set_rm_floor(int);
    void set_rm_room(int);
    int get_floor();
    int get_room();
    int get_ele();
    int get_water();
    int get_number_room();
    int get_rm_floor(int);
    int get_rm_room(int);
    bool is_register(int,int);
    void activate_data(int,Tenant);
    void activate_password(int,int);
    int call_password(int);
    void activate_status(int);
    void output_data(int);
    void output_payment(int);
    Room get_rm(int);
    void random_ele(int);
    void random_water(int);
private:
    int floor,room_per_floor;
    float price_rm;
    float ele_rate;
    float water_rate;
};
#endif // APARTMENT_H
