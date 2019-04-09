#ifndef DB_MENEGEMENT_H
#define DB_MENEGEMENT_H

#include <list>
#include <iostream>
#include "IP_addreses.h"

bool Get_IPs(std::list <IP_addreses> &lst);

bool Write_state(int state, std::string address);


#endif // DB_MENEGEMENT_H
