// 2021-03-11   AirportApplicationHeader.h
//
// This is the Header file for the upgraded AirportApplication program.
//
// *************************** HISTORY **********************************
// Joseph Salazar   2021-03-11  Created program

#include <iostream>
#include<string>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
#include <iostream>
#include <sstream>




const int NUM_OF_MOVIES = 6;

//struct declaration

struct movie{
    std::string title;
    std::string stringYear;
    int releaseYear;
    std::string director;
    std::string genre;
    std::string starring1;
    std::string starring2;
    
};


#ifndef AirportApplicationHeader_h
#define AirportApplicationHeader_h

using std::istringstream;
using namespace std;

//Main loop for the application.
void AirportApplicationMenu();

//emergencyDecision main
void emergencyDecisions();
//menu selection functions
void communicationsFailure();
void engineFailure();
void inFlightIcing();
void displayEmergencyMenu();
char inputEmergencyChoice();


//flightStatusUpgrade
bool openFile(string fileName, ifstream &inputFile);
void displayError(string message);
char inputStatusChoice();

//seatReservation Functions and constants
const char FULL = 'X';
const char EMPTY = ' ';
const int ROWS =7;
const int COLUMNS = 4;

void seatReservation();

//  Process Request to Display, Reserve or Cancel
void flightReservationMenu(char seatArray[ROWS][COLUMNS]);
void reserveSeat(char seatArray[ROWS][COLUMNS]);
void cancelSeat(char seatArray[ROWS][COLUMNS]);

//populate the and display array
void fillArray(char seatArray[ROWS][COLUMNS]);
void displayChart(char seatArray[ROWS][COLUMNS]);
void cancelSeat(char seatArray[ROWS][COLUMNS]);

void displayReservationMenu();
char inputReservationChoice();

//placeholder module for movie selection program
void movieSelection();

//main function

void flightStatusReporterMenu();


//Header Displays
void displayArrivalHeader();
void displayDepartureHeader();

//this function calculates delay
int calculateDelay(string timeOne, string timeTwo);

//this function displays the outcomes
void displayFlightStatus(string flightNumber, string gateNumber, string airport, string timeOne, string timeTwo,int delay);

//this function is used to display the menu before the switch statement
void displayMenu();


void flightStatusReport();

//sub functions
void displayMenu(); 
char inputChoice();
void emergencySelection();
extern int getReady();
extern int getClientName();
extern int getCurrentBalance();
extern int getAPR();
extern int getMonthlyPayments();



// engineFailure sub-functions
void electricalSystem();
void engineRunning();
void nightFlying();
void landingLight();

void quit();

//movieSelector functions
//main function
void movieSelector();



//Diplay the main menu
void displayMovieMenu();

void displayMovies(movie *database[NUM_OF_MOVIES]);

void searchMovie(movie *database[NUM_OF_MOVIES]);
void binarySearch(movie *database[NUM_OF_MOVIES], int NUM_OF_MOVIES);

char inputMovieChoice();

void selectionSort(movie *database[NUM_OF_MOVIES], int NUM_OF_MOVIES);
void fillDatabase(movie *database[NUM_OF_MOVIES]);

#endif /* AirportApplicationHeader_h */
