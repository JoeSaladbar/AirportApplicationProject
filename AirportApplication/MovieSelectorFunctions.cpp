// 2021-05-13   AirportApplicationHeader.h
//
// This is the function file for the upgraded MovieSelector module program.
//
// *************************** HISTORY **********************************
// Joseph Salazar   2021-05-13  Created program


#include "AirportApplicationHeader.h"


void movieSelector(){
    
    movie *database[NUM_OF_MOVIES];
    fillDatabase(database);
    selectionSort(database, NUM_OF_MOVIES);
    char ch = ' ';
    while (ch!='Q'){
        displayMovieMenu();
        ch=inputMovieChoice();
        switch (ch){
            case 'D': displayMovies(database);break;
            case 'S': binarySearch(database, NUM_OF_MOVIES); break;
            case 'Q': movieSelector();break;
            default : ;
    }
    }
}

//main display menu
void displayMovieMenu(){
    std::cout << "\n";
    std::cout << "********************************* \n";
    std::cout << "   Movie Selector Menu\n";
    std::cout << "********************************* \n";
    std::cout << "  Display Movie List  : D\n ";
    std::cout << " Search for Movie    : S\n ";
    std::cout << " Quit                : Q\n";
    std::cout << "  Enter your choice: ";
    
}

//input validation for main switch statement
char inputMovieChoice(){
  char ch=' ';
  std::cin>>ch;
  ch=toupper(ch);
  while (ch!='D'&&ch!='S'&&ch!='Q'){
    std::cout<<"\nPlease enter a valid choice "<< std::endl;
    displayMenu();
    std::cin>>ch;
    ch=toupper(ch);
  }
  return ch;
}

//char selection of d or D
void displayMovies(movie *database[NUM_OF_MOVIES]){
    std::cout << std::endl;
    for(int i=0; i<NUM_OF_MOVIES; i++){
        std::cout << std::setw(25) <<database[i]->title;
        std::cout <<" "<< std::setw(10) <<database[i]->stringYear;
        std::cout <<std::setw(25)<< database[i]->director;
        std::cout << std::setw(20)<<database[i]->genre;
        std::cout << std::setw(25)<<database[i]->starring1;
        std::cout <<std::setw(25)<< database[i]->starring2;
        std::cout << std::endl;

    }
    std::cout << std::endl;
    //MovieSelector();
    return;
}

//implementation of iterative binary search algorithm which seraches for an int record of a movie object.
void binarySearch(movie *database[NUM_OF_MOVIES], int NUM_OF_MOVIES){
    int movieSearch;
    std::cout << "  Please enter the year of the movie in YYYY format: ";
    std::cin >> movieSearch;
    int left = 0;
    int right = NUM_OF_MOVIES -1;

    while (left <= right){
        int mid = left + ((right-left)/2);
        if(database[mid]->releaseYear == movieSearch){
            std::cout << "\nMovie found at index position " <<  mid << ".\n" ;
            displayMovies(database);
            return;
        }
        else if(movieSearch < database[mid]->releaseYear){
            right = mid- 1;
            }
        else{
            left  = mid +1;
            }
        }
        std::cout << " Sorry, movie not found. Index -1\n\n";
    return;
   
    }

//fill array of type movies
void fillDatabase(movie *database[NUM_OF_MOVIES]){
    std::ifstream  movies("MovieData.txt");
    std::string line;
    if(movies.is_open()){
        int  i = 0;
        while(i<NUM_OF_MOVIES){
        movie *temp=new movie();
        database[i]=temp;
        
        getline(movies, line);
            
        std::istringstream instream(line);
        getline(instream,database[i]->title,',');\
            
        getline(instream, database[i]->stringYear, ',');
            
        getline(instream, database[i]->director, ',');
            
        getline(instream, database[i]->genre, ',');
            
        getline(instream, database[i]->starring1, ',');
            
        getline(instream,  database[i]->starring2, ',');
            
    
        std::stringstream yearInt(database[i]->stringYear);
        yearInt>>database[i]->releaseYear;
            
        i++;
        }
    }
        else{
            std::cout<<"File error";
        }
}

void selectionSort(movie *database[NUM_OF_MOVIES], int NUM_OF_MOVIES){

    for(int startScan=0; startScan < (NUM_OF_MOVIES -1); startScan++)
    {
        
        movie *temp = nullptr;
        int  minIndex;
        int minValue;
            bool swap = false;
            for(int startScan=0; startScan < NUM_OF_MOVIES ; startScan++)
            {
                
                minIndex = startScan;
                minValue = database[startScan]->releaseYear;
                for(int index = startScan+1; index < NUM_OF_MOVIES; index++){
                    if(database[index]->releaseYear < minValue){
                        minIndex = index;
                        swap = true;
                    }
                }
                if(swap){
                    temp = database[minIndex];
                    database[minIndex] = database[startScan];
                    database[startScan] = temp;
                    swap = false;
                    
                }
            }
    }
}

