#include "Apartment.h"

void Apartment::activate_data(int i,Tenant r)
{
    rm[i].enter_data(r);
}
void Apartment::activate_password(int i,int p)
{
    rm[i].set_password(p);
}
int Apartment::call_password(int i)
{
    return rm[i].get_password();
}
bool Apartment::is_register(int i,int a)
{
    return rm[i].status_check(a);
}
void Apartment::set_floor(int f)
{
    floor=f;
}
void Apartment::set_room(int r)
{
    room_per_floor=r;
}
int Apartment::get_floor()
{
    return floor;
}
int Apartment::get_room()
{
    return  room_per_floor;
}
int Apartment::get_ele()
{
    return ele_rate;
}
int Apartment::get_water()
{
    return water_rate;
}
void Apartment::set_price_rm(float p)
{
    price_rm=p;
}
void Apartment::set_ele(float e)
{
    ele_rate=e;
}
void Apartment::set_water(float w)
{
    water_rate=w;
}
void Apartment::set_number_room(int f,int r)
{
    number_room=f*r;
}
int Apartment::get_number_room()
{
    return number_room;
}
void Apartment::set_rm_floor(int i)
{
    rm[i].floor_number=i/room_per_floor+1;
}
void Apartment::set_rm_room(int i)
{
    rm[i].room_number=i%room_per_floor+1;
}
int Apartment::get_rm_floor(int i)
{
    return rm[i].floor_number;
}
int Apartment::get_rm_room(int i)
{
    return rm[i].room_number;
}
Room Apartment::get_rm(int i)
{
    return rm[i];
}
void Apartment::activate_status(int i)
{
    rm[i].status_change();
}
void Apartment::output_data(int i)
{
    rm[i].data();
}
void Apartment::output_payment(int i)
{
    rm[i].payment(ele_rate,water_rate,price_rm);
}
void Apartment::random_ele(int i)
{
    rm[i].set_ele();
}
void Apartment::random_water(int i)
{
    rm[i].set_water();
}
