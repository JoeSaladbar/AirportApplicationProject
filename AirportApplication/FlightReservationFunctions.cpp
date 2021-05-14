// 2021-03-11  FLightReservationFunctions.cpp
//
// This is the function file for the upgraded AirportApplication program.
//
// *************************** HISTORY **********************************
// Joseph Salazar   2021-03-11  Created program

#include "AirportApplicationHeader.h"


char seatArray[ROWS][COLUMNS];

void flightReservationMenu(char seatArray[ROWS][COLUMNS])
{
  char ch = ' ';
  while (ch!='Q'){
    displayReservationMenu();
    ch=inputReservationChoice();
    switch (ch){
        case ('D'): displayChart(seatArray); break;
        case ('R'): reserveSeat(seatArray); break;
        case ('C'): cancelSeat(seatArray); break;
        case ('Q'): std::cout << "Goodbye!\n"; AirportApplicationMenu();
        default : break ;
    }
  }
}

void displayReservationMenu(){
  
    std::cout << std::endl;
    std::cout << "****************************************\n";
    std::cout << " Seat Reservation and Cancellation Menu\n";
    std::cout << "****************************************\n";
    std::cout << "Display Available Seats  :D " << std::endl;
    std::cout << "Reserve Seat             :R " << std::endl;
    std::cout << "Cancel Seat              :C"  << std::endl;
    std::cout << "Quit                     :Q" << std::endl;
    std::cout << "Enter your choice: ";

}

char inputReservationChoice(){
  char ch=' ';
  std::cin>>ch;
  ch=toupper(ch);
  while (ch!='D' &&ch!='R' &&ch!='C' &&ch!='Q'){
    std::cout<<"\nPlease enter a valid choice "<<std::endl;
    displayMenu();
    std::cin>>ch;
    ch=toupper(ch);
  }
  return ch;
}


//populate the displayArray
void fillArray(char seatArray[ROWS][COLUMNS])
{
  for (int i=0;i<ROWS;i++) // rows
    {
    for (int j=0;j<COLUMNS;j++) // columns
      {
          seatArray[i][j]=' '; // fill with blank ' ' char
      }
    }
}

//displays the seat chart
void displayChart(char seatArray[ROWS][COLUMNS]){
    std::cout << "****************\n";
    std::cout << "   Seat Chart\n";
    std::cout << "****************\n";
    std::cout << "   A B C D\n";
    
    for(int i = 0; i < ROWS; i++)
    {
        std::cout << i+1 << " ";
        
        for(int j = 0; j < COLUMNS; j++)
        {
             
            std::cout << std::setw(2) << seatArray[i][j];
        }
        std::cout << "\n";
    }
    
}

//module to reserve seat
void reserveSeat(char seatArray[ROWS][COLUMNS]){
    
    int rowSelect;
    char colSelect;

    std::cout <<" Please enter the row number (1-7): ";
    std::cin >> rowSelect;
   
    std::cout << " Please enter the column letter (A-D): ";
    std::cin >> colSelect;
    int intColumn = toupper(colSelect) - 65;
    
    if(seatArray[rowSelect-1][intColumn] == 'X'){
        std::cout << "Sorry, that seat is not available. \n";
    }
    else{
        seatArray[rowSelect-1][intColumn] = 'X';
        std::cout << "\n Congratulations, your seat is confirmed. \n";
    }
    return;
  
    }
    
//module to cancel seat
void cancelSeat(char seatArray[ROWS][COLUMNS]){
    
    int rowSelect;
    char colSelect;

    std::cout <<" Please enter the row number (1-7): ";
    std::cin >> rowSelect;
    std::cout << " Please enter the column letter (A-D): ";
    std::cin >> colSelect;
    int intColumn = toupper(colSelect) - 65; 
    
    if(seatArray[rowSelect-1][intColumn] == ' '){
        std::cout << "Sorry, that seat has not been booked. \n";
    }
    else{
        seatArray[rowSelect-1][intColumn] = ' ';
        std::cout << "\n Congratulations, your seat is canceled. \n";
    }
    return;
  
    }
    

void seatReservation(){
    
    char seatArray[ROWS][COLUMNS];
    
    fillArray(seatArray);
    seatArray[0][3] = {'X'};
    seatArray[1][1] = {'X'};
    seatArray[3][2] = {'X'};
    seatArray[6][0] = {'X'};
    char selection = ' ';
    do{
        
        flightReservationMenu(seatArray);
        selection = inputReservationChoice();
        
    }
    while(selection!='Q');
    
}
