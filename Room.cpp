#include "Room.h"

void Room::data()
{
    cout << "Your room is " << floor_number << setfill('0') << setw(2) << room_number << endl << "Owner :";
    user.get_name();
}
void Room::payment(float ele_rate,float water_rate,float price_rm)
{
    cout  << "Electricity unit : " << ele_unit << " Unit"<< "\nWater unit : " << water_unit << " Unit" << endl;
    cout << "Electricity pay : " << ele_unit*ele_rate << " Baht" << "\nWater pay : " << water_unit*water_rate << " Baht" << "\nRent : " << price_rm << " Baht" ;

    cout << "\nNet price : " << ele_unit*ele_rate+water_unit*water_rate+price_rm << " Baht" << endl << endl;
}
void Room::select_f(int f)
{
    floor_number=f;
}
void Room::select_r(int r)
{
    room_number=r;
}
void Room::status_change()
{
    if(status==0)
    {
        cout << "\t\tComplete!!\n" << "\tWelcome to your new home!!\n";
        status=1;
    }
    else if(status==1)
    {
        cout << "\t\tData was deleted!!\n";
        status=1;
    }
}
void Room::enter_data(Tenant r)
{
    user=r;
}
void Room::set_password(int p)
{
    password=p;
}
int Room::get_password()
{
    return password;
}
bool Room::status_check(int a)
{
    return status==a;
}
void Room::set_ele()
{
    ele_unit=rand()%501;
}
void Room::set_water()
{
    water_unit=rand()%501;
}
