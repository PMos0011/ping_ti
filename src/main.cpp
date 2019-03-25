#include <iostream>
#include <list>
#include "DB_Menegement.h"
#include "ping.h"
#include "functions.h"
#include <unistd.h>
#include "IP_addreses.h"

using namespace std;

int main()
{
cout<<currentDate()<<" Application start"<<endl;
    while (true)
    {
        list <IP_addreses> ip_list;
        list <IP_addreses>::iterator it;

        ip_list=Get_IPs();

        for (it=ip_list.begin(); it!=ip_list.end(); it++)
        {
            IP_addreses tmp_ipAdd = *it;
            if(ping(tmp_ipAdd.address)<=0)
            {
                if(tmp_ipAdd.state==0)
                {
                    Write_state(1,tmp_ipAdd.address);
                    cout<<currentDate()<<" "<<tmp_ipAdd.name<<" "<<tmp_ipAdd.address<<" - connectiol lost"<<endl;
                }
            }
            else
            {
                if(tmp_ipAdd.state==1)
                {
                    Write_state(0,tmp_ipAdd.address);
                    cout<<currentDate()<<" "<<tmp_ipAdd.name<<" "<<tmp_ipAdd.address<<" - connectiol resume"<<endl;
                }
            }
        }


        ip_list.clear();
        sleep(30);
    }

    return 0;
}
