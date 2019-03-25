#include "DB_Menegement.h"
#include <iostream>
#include <mysql/mysql.h>
#include <list>


using namespace std;

list <string> Get_IPs()
{
    list <string>  lst;
    // list <string>::iterator it;

    MYSQL mysql;
    mysql_init(&mysql);
    MYSQL_RES *id_query;
    MYSQL_ROW data_row;

    if(mysql_real_connect(&mysql, "localhost", "TI", "rciwiswd04", "TABLICA", 0, NULL, 0))
        cout<<"Data Base Connected, getting IP list"<<endl;
    else
        cout<<"Getting IP list Error"<<endl;

    mysql_select_db(&mysql, "TABLICA");

    string sendBuff="SELECT RSB_IP FROM RSB";

    if(mysql_query(&mysql, sendBuff.c_str()))
        cout<<"IP list Read Error"<<endl;


    id_query=mysql_store_result(&mysql);
    while(data_row=mysql_fetch_row(id_query))
        lst.push_back(data_row[0]);

    //for (it=lst.begin(); it!=lst.end(); it++)
    // cout<<*it<<endl;


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
        cout<<"Data Base Connected, writting status"<<endl;
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
