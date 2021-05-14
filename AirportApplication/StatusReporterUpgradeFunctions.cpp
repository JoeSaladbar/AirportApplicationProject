// 2021-03-09   StatusReporterUpgradeFunctions.cpp.
//
// This is the function file for the upgraded FlightStatus program.
//
// *************************** HISTORY **********************************
// Joseph Salazar   2021-03-09  Created program

#include "AirportApplicationHeader.h"


bool openArrivalFile(ifstream &arrival)
{
  arrival.open("Arrivals.txt");
  if (arrival.is_open())
    return true;
   
  else
      cout << "File Error. Please exit the application. \n";
    return false;
}


// this method takes in a file variable as a reference paramenter
bool openDepartureFile(ifstream &departure)
{
    departure.open("Departures.txt");
    if (departure.is_open())
        return true;
    else
        
        cout << "File Error. Please exit the application. \n";
        return false;
}
    
 //calculates the delay and then displays the information

void processArrivalFile(ifstream &arrival)
{
  string flightNumber,gateNumber,airport,timeOne,timeTwo;
  int delay;
  std::string line;

  displayArrivalHeader();
  while(!arrival.eof())
  {
      getline(arrival, line);
      istringstream instream(line);
      instream >> flightNumber;
      instream >> gateNumber;
      instream >> airport;
      instream >> timeOne;
      instream  >> timeTwo;

      delay=calculateDelay(timeOne, timeTwo);
      displayFlightStatus(flightNumber,gateNumber,airport,timeOne,timeTwo,delay);
  }
  
}

void processDepartureFile(ifstream &departure)
{
    std::string flightNumber, gateNumber,airport, timeOne, timeTwo;
    std::string line; 
    int delay;
    displayDepartureHeader();
    while(!departure.eof())
    {
        getline(departure, line);
        istringstream instream(line);
        instream >> flightNumber;
        instream >> gateNumber;
        instream >> airport;
        instream >> timeOne;
        instream  >> timeTwo;
      
      delay=calculateDelay(timeOne, timeTwo);
        displayFlightStatus(flightNumber,gateNumber,airport,timeOne,timeTwo,delay);
    }
}

//this function displays the required message for the arrival selection
void displayArrivalHeader()
{
  cout<<"\n**********************************************************"<<endl;
  cout<<" AA Airlines Arrival Information From LAX Los Angeles  "<<endl;
  cout<<"**********************************************************"<<endl;
  cout<<endl;
   cout<<setw(8)<<"  Flight# " <<setw(4)<<"Gate#"<<setw(10)<<right<<"Airport"<<setw(16)<<"Scheduled"<<setw(10) <<"Expected"<<setw(6)<<"Delay"<<endl;
   cout<<endl;

}

//this function displays the required message for the departure selection
void displayDepartureHeader()
{
  cout<<"\n***********************************************************"<<endl;
  cout<<" AA Airlines Departure Information From LAX Los Angeles  "<<endl;
  cout<<"**********************************************************"<<endl;
  cout<<endl;
   cout<<setw(8)<<"  Flight# " <<setw(4)<<"Gate#"<<setw(10)<<right<<"Airport"<<setw(16)<<"Scheduled"<<setw(10) <<"Expected"<<setw(6)<<"Delay"<<endl;
   cout<<endl;

}

//this converts the string characters to integers and calculates the delay.
int calculateDelay(string timeOne, string timeTwo)
{
  int time1=stoi(timeOne);// converts string to integer
  int time2=stoi(timeTwo);
  int min1,min2,hr1,hr2;
  int delay=0;
  hr1=time1/100;  // processes hhmm by taking the leftmost two digits as hours
  hr2=time2/100;
  min1=time1%100;// processes hhmm by taking the rightmost two digits as minutes

  min2=time2%100;
  int hourDiff;
  if (time2<time1)
  {
    hourDiff= (hr1+hr2)%12; // or alternately hourDif= (12-hr1+hr2);
  }
  else
  hourDiff=hr2-hr1;
  if (min1>min2)
    hourDiff--;
    delay = (hourDiff*60)+((60-min1+min2)%60);
  return delay;
}

void displayFlightStatus(string flightNumber, string gateNumber, string airport, string timeOne, string timeTwo,int delay)
{
  cout<<setw(8)<<flightNumber<<setw(4)<<gateNumber<<setw(20)<<airport<<setw(8)<<timeOne<<setw(8) <<timeTwo<<setw(8)<<delay<<endl;
}
void arrivalChoice()
{
ifstream arrival;
  if (openArrivalFile(arrival))
    processArrivalFile(arrival);
}

void departureChoice(){
  ifstream departure;
  if (openDepartureFile(departure))
    processDepartureFile(departure);
}

void displayStatusMenu()
    {
  cout<<endl;
  std::cout << "*********************************\n";
  cout<<" Flight Status Reporter Menu\n";
  std::cout << "*********************************\n";
  cout<<"Arrivals Report  : A "<<endl;
  cout<<"Departure Report : D "<<endl;
  cout<<"Quit             : Q "<<endl;
  cout<<"Enter your choice: ";

}
char inputStatusChoice(){
  char ch=' ';
  cin>>ch;
  ch=toupper(ch);
  while (ch!='A'&&ch!='D'&&ch!='Q'){
    cout<<"\nPlease enter a valid choice "<<endl;
    displayMenu();
    cin>>ch;
    ch=toupper(ch);
  }
  return ch;
}

void flightStatusReporterMenu()
{
  char ch = ' ';
  while (ch!='Q'){
    displayStatusMenu();
    ch=inputStatusChoice();
    switch (ch){
        case 'Q':  std::cout << "Goodbye!\n"; AirportApplicationMenu(); 
      case 'A':  arrivalChoice();break;
      case 'D':  departureChoice();break;
      default : ;
    }
  }
}

