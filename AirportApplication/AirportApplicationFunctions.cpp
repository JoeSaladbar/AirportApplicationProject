// 2021-03-11   AirportApplicationHFunctions.cpp
//
// This is the function file for the upgraded AirportApplication program.
//
// *************************** HISTORY **********************************
// Joseph Salazar   2021-03-11  Created program

#include <stdio.h>
#include "AirportApplicationHeader.h"

void AirportApplicationMenu(){
    
    displayMenu();
    char ch = ' ';
    while (ch!='Q'){
        
        ch=inputChoice();
        switch (ch){
            case 'E': emergencyDecisions();break;
            case 'R': flightStatusReporterMenu(); break;
            case 'S': seatReservation(); break;
            case 'M': movieSelector(); break;
            case 'Q': quit();break;
            default : ;
    }
    }
}

//main menu display
void displayMenu(){
    
        std::cout << "********************************* \n";
        std::cout << "  Airport Application Main Menu\n";
        std::cout << "********************************* \n";
        std::cout << " Emergency Decisions in Flight  : E \n";
        std::cout << " Flight Status Report           : R \n";
        std::cout << " Seat Reservation/Cancellation  : S \n";
        std::cout << " Movie Selection in Flight      : M \n";
        std::cout << " Quit                           : Q \n";
        std::cout << " Enter your choice              : ";
}


//input validation for switch statement
char inputChoice(){
  char ch=' ';
  std::cin>>ch;
  ch=toupper(ch);
  while (ch!='E'&&ch!='R'&&ch!='S'&&ch!='M'&&ch!='Q'){
    std::cout<<"\nPlease enter a valid choice "<< std::endl;
    displayMenu();
    std::cin>>ch;
    ch=toupper(ch);
  }
  return ch;
}

//quit function
void quit()
{
 std::cout<<"Goodbye! "<< std::endl;
    exit(0);
}
