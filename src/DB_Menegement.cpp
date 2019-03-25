#include "DB_Menegement.h"
#include <iostream>
#include <mysql/mysql.h>
#include <list>
#include "IP_addreses.h"


using namespace std;

list <IP_addreses> Get_IPs()
{
    list <IP_addreses>  lst;
    IP_addreses tmp_ipAddr;

    MYSQL mysql;
    mysql_init(&mysql);
    MYSQL_RES *id_query;
    MYSQL_ROW data_row;

    if(!(mysql_real_connect(&mysql, "localhost", "TI", "rciwiswd04", "TABLICA", 0, NULL, 0)))
        cout<<"Getting IP list Error"<<endl;

    mysql_select_db(&mysql, "TABLICA");

    string sendBuff="SELECT RSB, RSB_IP, LINK FROM RSB";

    if(mysql_query(&mysql, sendBuff.c_str()))
        cout<<"IP list Read Error"<<endl;


    id_query=mysql_store_result(&mysql);
    while(data_row=mysql_fetch_row(id_query))
    {
        tmp_ipAddr.name= data_row[0];
        tmp_ipAddr.address = data_row[1];
        tmp_ipAddr.state = atoi(data_row[2]);
        lst.push_back(tmp_ipAddr);
        }


    mysql_free_result(id_query);
    mysql_close(&mysql);

    return lst;

}

bool Write_state(int state, std::string address)
{
    MYSQL mysql;
    mysql_init(&mysql);
    MYSQL_RES *id_query;
    MYSQL_ROW data_row;

    if(mysql_real_connect(&mysql, "localhost", "TI", "rciwiswd04", "TABLICA", 0, NULL, 0))
        cout<<"Write connection status"<<endl;
    else
    {
        cout<<"Writte status error"<<endl;
        return false;
    }

    mysql_select_db(&mysql, "TABLICA");

    string sendBuff="UPDATE RSB SET LINK = "+to_string(state)+" WHERE RSB_IP='"+address+"'";

    if(mysql_query(&mysql, sendBuff.c_str()))
    {
        cout<<"Write state Error"<<endl;
        mysql_close(&mysql);
        return false;
    }

    mysql_close(&mysql);

    return true;
}
