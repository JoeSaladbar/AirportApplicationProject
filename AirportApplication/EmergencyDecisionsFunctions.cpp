// 2021-02-11   EmergencyDecisionsFunctions.cpp
//
// This is the function file for the EmergencyDecisionsMenu program. 
//
// *************************** HISTORY **********************************
// Joseph Salazar   2021-02-11  Created program

#include <iostream>
#include <stdio.h>
#include "AirportApplicationHeader.h"

char engineSelect = ' ';
char engineSelect1 = ' ';
char engineSelect2 = ' ';
char engineSelect3 = ' ';
char engineSelect4 = ' ';
char engineSelect5 = ' ';
char engineSelect6 = ' ';
char engineSelect7 = ' ';

char selection;
void emergencyDecisions()
{
    while (selection!='Q')
    {
        displayEmergencyMenu();
        selection=inputEmergencyChoice();
        emergencySelection();
    }
}

void emergencySelection()
{
switch(selection)//Here is a switch statement that calls functions based on user input.
        {
            
             case ('C'): communicationsFailure(); break;
             case ('E'): engineFailure(); break;
             case ('I'): inFlightIcing();   break;
            case ('Q'): std::cout << "\nGoodbye!\n"; AirportApplicationMenu(); break; //  quit function replaced with main Airport application menu in sub-programs, per assignment directions
             
         }
}

void displayEmergencyMenu()
{
    std::cout<<std::endl;
    std::cout<<"***************************\n";
    std::cout << " Emergency Decisions Menu\n";
    std::cout<<"***************************\n";
    std::cout << "Communications Failure  : C "<<std::endl;
    std::cout << "Engine Failure          : E "<<std::endl;
    std::cout << "Inflight Icing          : I "<<std::endl;
    std::cout << "Quit                    : Q "<<std::endl;
    std::cout << "Enter your choice       :";
}

char inputEmergencyChoice()
{
  char selection =' ';
  std::cin >> selection;
  selection = toupper(selection);
  while (selection!='C'&&selection!='E'&&selection!='I'&&selection!='Q')
  {
    std::cout<<"\nPlease enter a valid choice "<< std::endl;
    //std::cin.clear(); //comment these lines if fails to compile
    //std::cin.ignore(9999,'\n'); //
    displayMenu();
    std::cin>>selection;
    selection = toupper(selection);
  }
  return selection;
}
void communicationsFailure()
{
    std::cout << "Switch to Alternate Radio.\n";
    AirportApplicationMenu();
}

void engineFailure()
{
    do
    {   std::cout << "Are you airborne?: ";
        std::cin >> engineSelect;
        engineSelect = toupper(engineSelect);
    }
    while((engineSelect != 'Y') && (engineSelect != 'N'));
    {
        if (engineSelect != 'Y'){
        std::cout << "Have a drink and call a mechanic. \n";
            AirportApplicationMenu();}
    else
        do
        {   std::cout << "Is the electrical system working?: ";
            std::cin >> engineSelect1;
            engineSelect1 = toupper(engineSelect1);
        }
        while((engineSelect1 != 'Y') && (engineSelect1 != 'N'));
        if (engineSelect1 == 'N')
            std::cout << "Turn on the Master Switch.\n";
        else
                    engineRunning();
        
    }
    
}

void engineRunning()
{
    do
    {   std::cout << "Has the engine stopped running?: ";
        std::cin >> engineSelect2;
        engineSelect2 = toupper(engineSelect2);
    }
    while((engineSelect2 != 'Y') && (engineSelect2 != 'N'));
    if(engineSelect2 == 'N')
    {
        do
        {   std::cout << "Is the outside air temperature < 32 degrees?: ";
            std::cin >> engineSelect3;
            engineSelect3 = toupper(engineSelect3);
        }
        while((engineSelect3 != 'Y') && (engineSelect3 != 'N'));
        if(engineSelect3 == 'N')
            std::cout << "Switch to other fuel tank. \n";
        else
            std::cout << "Turn on Carburator Heat. \n";
    }
    else
    {
        do
        {
            std::cout << "Are you over mountains?: ";
            std::cin >> engineSelect4;
            engineSelect4 = toupper(engineSelect4);
        }
        while((engineSelect4 != 'Y') && (engineSelect4 != 'N'));
        if(engineSelect4 =='Y')
        {
            nightFlying();
        }
        else
        {
            do
            {
                std::cout << "Are you over water?: ";
                std::cin >> engineSelect7;
                engineSelect7 = toupper(engineSelect7);
            }
            while((engineSelect7 != 'Y') && (engineSelect7 != 'N'));
            if (engineSelect7 == 'Y')
            {
                std::cout << "Inflate your life vest, make an emergency landing. \n";
                AirportApplicationMenu();
            }
            else
            {
                std::cout << "Make an emergency landing on a road. \n";
                AirportApplicationMenu();
            }
            
        }
            
        
    }
}

void nightFlying()
{
    
    do
    {
        std::cout << "Are you flying at night?: ";
        std::cin >> engineSelect5;
        engineSelect5 = toupper(engineSelect5);
    }
    while((engineSelect5 != 'Y') && (engineSelect5 != 'N'));
    if(engineSelect5 =='Y')
    {
        landingLight();
    }
}

void landingLight()
{
    do
    {
        std::cout << "Turn on the landing light and look out the window. Do you like what you see?: ";
        std::cin >> engineSelect6;
        engineSelect6 = toupper(engineSelect6);
    }
    while((engineSelect6 != 'Y') && (engineSelect6 != 'N'));
    if(engineSelect6 == 'Y')
    {
        std::cout << "Make an emergency landing.\n";
        AirportApplicationMenu();
    }
    else
    {
        std::cout << "Turn off the landing light.\n";
        AirportApplicationMenu();
    }
    
}

void inFlightIcing() // uses estimate variable
{
    float estimate;
    do
    {
        std::cout << "Estimate the amount of ice on the wings. (0mm to 10mm): ";
        std:: cin >> estimate;
    }
    while((estimate < 0) && (estimate > 10));
    
    if (estimate < 1)
    {
        std::cout << "Use 5% power.\n";
    }
    else if ((estimate >= 1) && (estimate < 5))
    {
        std::cout << "Use 20% power.\n";
    }
    else if ((estimate >= 5 ) && (estimate <=9))
    {
        std::cout << "Use 65% power.\n";
    }
    else if (estimate > 9)
    {
        std::cout << "Use 100% power.\n";
    }
}
