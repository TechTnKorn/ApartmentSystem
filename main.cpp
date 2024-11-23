#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include "Apartment.h"
#include "Room.h"
#include "Tenant.h"
#include "Gobal.h"

using namespace std;

//--------------------------------------------------------------------------------------------------------
int main()
{
    int loop=1;
    int i,floor,room,price_rm,pass;
    float ele,water;
    Apartment apartment;
    //owner
    do
    {
        cout << "How many floor do you have : ";
        cin >> floor;
        if(check_error_min(floor,0))
        {
            error();
        }
    }while(check_error_min(floor,0));
    apartment.set_floor(floor);
    do
    {
        cout << "How many room per floor do you have : ";
        cin >> room;
        if(check_error_min(room,0))
        {
            error();
            cout << "Floor : " << apartment.get_floor() << endl;
        }
    }while(check_error_min(room,0));
    apartment.set_room(room);
    for(i=0;!check_error_max(i,apartment.get_floor()*apartment.get_room());i++)//
    {
        apartment.set_rm_floor(i);
    }
    for(i=0;!check_error_max(i,apartment.get_floor()*apartment.get_room());i++)//
    {
        apartment.set_rm_room(i);
        apartment.random_ele(i);
        apartment.random_water(i);
    }
    do
    {
        cout << "Electricity rate per unit is : ";
        cin >> ele;
        if(check_error_min(ele,0))
        {
            error();
            cout << "Your apartment have " << apartment.get_floor() << " floors." << endl;
            cout << "Your apartment have " << apartment.get_room() << " rooms per floor." << endl;
        }
    }while(check_error_min(ele,0));
    apartment.set_ele(ele);
    do
    {
        cout << "Water rate per unit is : ";
        cin >> water;
        if(check_error_min(water,0))
        {
            error();
            cout << "Your apartment have " << apartment.get_floor() << " floors." << endl;
            cout << "Your apartment have " << apartment.get_room() << " rooms per floor." << endl;
            cout << "Electricity cost per unit is " << apartment.get_ele() << " units." << endl;
        }
        }while(check_error_min(water,0));
    apartment.set_water(water);
    do
    {
        cout << "Rent rate : ";
        cin >> price_rm;
        if(check_error_min(price_rm,0))
        {
            error();
            cout << "Your apartment have " << apartment.get_floor() << " floors." << endl;
            cout << "Your apartment have " << apartment.get_room() << " rooms per floor." << endl;
            cout << "Electricity cost per unit is " << apartment.get_ele() << " units." << endl;
            cout << "Water cost per unit is " << apartment.get_water() << " units." << endl;
        }
        }while(check_error_min(price_rm,0));
    apartment.set_price_rm(price_rm);
    //check room
    /*for(i=0;!check_error_max(i,apartment.get_floor()*apartment.get_room());i++)
    {
        cout << i << "=";
        apartment.output_data(i);
        cout << endl;
    }*/
    system("cls");
    //rent
    do//loop1==activate loop0=exit
    {
        int menu;
        do
        {

            cout << "Please select a menu\n"<< "\t1)Register\n" << "\t2)Information\n" << ">>> ";
            cin >> menu;
            if(check_error_not(menu,1)&&check_error_not(menu,2))
               {
                    error();
               }
        }while(check_error_not(menu,1)&&check_error_not(menu,2)&&check_error_not(menu,999));
        system("cls");
        switch(menu)//1=regis 2=info
        {
            case 1:{
                Tenant rent_data;
                char firstname[99],lastname[99];
                int age;
                cout << "Your name is : ";
                cin >> firstname >> lastname;
                do
                {
                    cout << "Your age is : ";
                    cin >> age;
                    if(check_error_min(age,0))
                    {
                        error();
                        cout << "Name : " << firstname << " " << lastname << endl;
                    }
                }while(check_error_min(age,0));
                rent_data.checkin(firstname,lastname,age);//Tenant
//---------------------------------------------------------------find i
                do
                {
                    do//select_floor
                    {
                        cout << "Select the floor that you need : ";
                        cin >> floor;
                        if(!check_error_min(floor,apartment.get_floor())||!check_error_max(floor,1))
                        {
                            error();
                            cout << "Name : " << firstname << " " << lastname << endl;
                            cout << "Age : " << age << endl;
                        }
                    }while(!check_error_min(floor,apartment.get_floor())||!check_error_max(floor,1));
                    do
                    {
                        cout << "Select the room that you need : ";
                        cin >> room;
                        if(!check_error_min(room,apartment.get_room())||!check_error_max(room,1))
                        {
                            error();
                            cout << "Name : " << firstname << " " << lastname << endl;
                            cout << "Age : " << age << endl;
                            cout << "Floor : " << floor << endl;
                        }
                    }while(!check_error_min(room,apartment.get_room())||!check_error_max(room,1));

                    i=0;
                    while(check_error_not(floor,apartment.get_rm_floor(i)))//find floor
                    {
                        i++;
                    }
                    while(check_error_not(room,apartment.get_rm_room(i)))//find room
                    {
                        i++;
                    }
                    if(apartment.is_register(i,1))
                    {
                        error();
                    }
                    //check
                    //cout << "i = "<< i << "\nf = " << rm[i].floor << "\nr = " << rm[i].room_number ;
                }while(apartment.is_register(i,1));
//---------------------------------------------------------------
                cout << "Set your new room's password : ";
                cin >> pass;

                apartment.activate_data(i,rent_data);
                apartment.activate_password(i,pass);
                system("cls");
                apartment.activate_status(i);

                _sleep(2000);
                system("cls");
                //check
                /*cout << i;
                apartment.output(i);
                //rm[i].user.re_bio();*/
                break;
                }
            case 2:{
                int room_number,time=1,ans;
                do
                {
                    do
                    {
                        cout << "What is your room's number (FRR Ex. Floor 4 Room 2 = 402)";
                        if(check_error_max(time,2))
                        {
                            cout << "(" << time << "/3)";
                        }
                        cout << " : ";
                        cin >> room_number;
                        what_room(room_number,floor,room);
                        system("cls");
                    }while(!check_error_min(floor,apartment.get_floor())||!check_error_max(floor,1)||!check_error_min(room,apartment.get_room())||!check_error_max(room,1));
                    int i=0;
                    while(check_error_not(floor,apartment.get_rm_floor(i)))//find floor
                    {
                        i++;
                    }
                    while(check_error_not(room,apartment.get_rm_room(i)))//find room
                    {
                        i++;
                    }
                    //check
                    //cout << i << "=" << apartment.call_password(i);

                    if(apartment.is_register(i,1))
                    {
                        time=1;
                        do
                        {
                            cout << "Room :" << room_number << "\nEnter your password(" << time << "/3) " << ": ";
                            cin >> pass;
                            if(check_error_not(apartment.call_password(i),pass))
                            {
                                error();
                                time++;
                            }
                        }while(check_error_not(apartment.call_password(i),pass)&&check_error_min(time,3));
                        if(check_error_not(apartment.call_password(i),pass)&&check_error_max(time,3))//incorrect>3
                        {
                            do
                            {
                                cout << "Do you want to try again?" << "\n\t1)Yes! \n\t2)No!" << "\n>>> ";
                                cin >> ans;
                                time=1;
                                system("cls");
                            }while(check_error_not(ans,1)&&check_error_not(ans,2));
                            if(check_error_not(ans,1))
                            {
                                break;
                            }
                        }
                        else//correct pass
                        {
                            system("cls");
                            apartment.output_data(i);//data
                            apartment.output_payment(i); //payment
                            ans=2;
                            break;
                        }
                    }
                    else//what_rm
                    {
                        error();
                        time++;
                        //cout << "time=" << time << endl ;
                        if(!check_error_min(time,3))
                        {
                            break;
                        }
                    }
                }while(check_error_min(time,3)||!check_error_not(ans,1));
                break;
            }

            case 999:{
                loop=0;
                break;
            }
        }
    }while(!check_error_not(loop,1));
    return 0;

}
