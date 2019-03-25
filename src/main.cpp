#include <iostream>
#include <list>
#include "DB_Menegement.h"
#include "ping.h"
#include "functions.h"
#include <unistd.h>

using namespace std;

int main()
{
    list <string> ip_list;
    list <string>::iterator it;


    ip_list=Get_IPs();
    int lst_size=ip_list.size();

    uint8_t connections[2][lst_size];

        for (int j=0; j<lst_size; j++)
            connections[0][j]=0;

            for (int j=0; j<lst_size; j++)
            connections[1][j]=2;

    while (true)
    {
        int counter = 0;

        for (it=ip_list.begin(); it!=ip_list.end(); it++)
        {

            if(ping(*it)<=0)
            {
                connections[0][counter]=1;


            }
            else
                connections[0][counter]=0;

            if(connections[0][counter]!=connections[1][counter])
            {

                if(connections[0][counter]==0)
                {
                    cout<<currentDate()<<" "<<*it<<" connection resume"<<endl;
                    if(Write_state(0,*it))
                        connections[1][counter]=connections[0][counter];
                }
                else
                {
                    cout<<currentDate()<<" "<<*it<<" no connection"<<endl;
                    if(Write_state(1,*it))
                        connections[1][counter]=connections[0][counter];
                }
            }

            counter++;
        }
        sleep(10);
    }

    return 0;
}
