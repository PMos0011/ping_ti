#ifndef DB_MENEGEMENT_H
#define DB_MENEGEMENT_H

#include <list>
#include <iostream>
#include "IP_addreses.h"

std::list <IP_addreses> Get_IPs();

bool Write_state(int state, std::string address);


#endif // DB_MENEGEMENT_H
