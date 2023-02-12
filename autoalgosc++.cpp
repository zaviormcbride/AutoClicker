#include "autoheader.h"
#include <iostream>
using namespace std;

void ChangeBind(char &ST , char &STP, char &CH)
{
    cin.get();
    printf("START: \n");
    cin.get(ST);
    if(ST>=97)
    ST-=32;    
    cin.get();
    printf("STOP: \n");
    cin.get(STP);
    if(STP>=97)
    STP-=32;  

    cin.get();
    printf("SETTINGS: \n");
    cin.get(CH);
    if(CH>=97)
    CH-=32;  
    cin.get();
}