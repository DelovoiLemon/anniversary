#include <iostream>

#include <sstream> // для std::stringstream
#include <cstdlib> // для exit()
#include <ctime>
//#define DEBUG

using namespace std;

int     currentDate[3];
int     birthDate[3];
int     anniversaryDate[3];

int     daysAnniversary[66] = {50, 100, 300, 500, 1000, 1500, 2000, 2500, 3000, 4000,
                               5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 
                               14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000, 
                               22000, 23000, 24000, 25000, 26000, 27000, 28000, 29000, 
                               30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 
                               38000, 39000, 40000, 41000, 42000, 43000, 44000, 45000, 
                               46000, 47000, 48000, 49000, 50000, 51000, 52000, 53000, 
                               54000, 55000, 56000, 57000, 58000, 59000, 60000};

#include "daysCounter.cpp"




int main(int argc, char *argv[])
{
    currentDateSetter();
    if(argc<= 1)    
    {
        // В некоторых операционных системах, argv[0] может быть просто пустой строкой, без имени программы
 
        // Обрабатываем случай, когда argv[0] может быть пустым или не пустым
        if (argv[0])
            cout << "Usage: " << argv[0] << " <day> <month> <year>" << '\n';
        else
            cout << "Usage: <program name> <day> <month> <year>" << '\n';
 
        exit(1);
    }
    
    #ifdef DEBUG
    printf("argument count = %d\n", argc);
    for(int i=0; i<argc; i++)
    {
        printf("%d: %s\n", i+1, argv[i]);
    }
    #endif
    
    for(int c = 0; c < argc - 1; c++)
    {
        birthDate[c] = atoi(argv[c + 1]);
        #ifdef DEBUG 
        cout << "c = " << c << ", birthDate[c] = " << birthDate[c] << endl;
        #endif
        
    }
    cout << "Day: " << birthDate[0] << ", Month: " << birthDate[1] << ", Year: " << birthDate[2] << "." << endl << endl << endl;
    dateValidation();
    int daysBirth = daysCounter(birthDate[0], birthDate[1], birthDate[2]);
    int daysCurrent = daysCounter(currentDate[0], currentDate[1], currentDate[2]);
    int dateDifference = daysCurrent - daysBirth + 1; 
    int nextAnniversary = nextAnniversaryFinder(dateDifference, currentDate[2]);
    int daysNextAnniversary = nextAnniversary + daysBirth;
    dateConverter(daysNextAnniversary);
    #ifdef DEBUG
        cout << "daysBirth: " << daysBirth << endl;
        cout << "daysCurrent: " << daysCurrent << endl;
    #endif
    cout << "Вам " << dateDifference << " дней\\день." << endl << "Ближайший юбилей - " << nextAnniversary << " дней." << endl << "Ближайший юбилей через " << nextAnniversary - dateDifference << " дней." << endl;
    cout << "Следующий юбилей будет " << anniversaryDate[0] << ", " << month[anniversaryDate[1] - 1] << " " << anniversaryDate[2] << "." << endl;  
    return 0;
}
