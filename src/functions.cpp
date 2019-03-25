#include "functions.h"
#include <iostream>
#include <ctime>

using namespace std;

string currentDate()
{
    string date;
    char buf[40];
    time_t currentTime=time(0);
    struct tm locTime= *localtime(&currentTime);
    strftime(buf,sizeof(buf), "%d-%m-%y %H:%M:%S", &locTime);
    date=buf;
    return(date);

}
