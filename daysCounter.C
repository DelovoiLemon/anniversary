char    month[12][4]        = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"}; // Названия месяцев
int     monthDays[13]       = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 29}; // Количество дней в месяцах



int daysCounter(int date, int mon, int year)

{
    int days = 0; // Количество дней
    int mass[3] = {date, mon, year};
    
    for(int y = 0; y < mass[2]; ++y)
    {
        #ifdef DEBUGD
        cout << endl << mass[0] << " " << mass[1] << " " << mass[2] << endl;
        cout << endl << "Year ++: " << y << " " << endl;
        if(y % 4 == 0)
            cout << "Year is vesokosniy, y % 4 = " << y % 4 << endl;
        else
            cout << "Year isn't vesokosniy, y % 4 = " << y % 4 << endl;
        
        #endif
        for(int m = 0; m < 12; ++m)
        {
            #ifdef DEBUGD
            cout << endl << "Mounth ++: " << m + 1 << endl;           
            #endif                
            if(y % 4 == 0 && m == 1)
            {
                days += monthDays[12];
                #ifdef DEBUGD
                cout << "Days ++: " << days << " add: " << monthDays[12] << endl;
                #endif 
            }
            else
            {
                days += monthDays[m];
                #ifdef DEBUGD
                cout << "Days ++: " << days << " add: " << monthDays[m] << endl;
                #endif
            }
            
        }
    }
    #ifdef DEBUGD
    cout << endl << "Year ++: " << mass[2] << " " << endl;

    if(mass[2] % 4 == 0)
        cout << "Year is vesokosniy, y % 4 = " << mass[2] % 4 << endl;
    else
        cout << "Year isn't vesokosniy, y % 4 = " << mass[2] % 4 << endl;
    #endif        
    for(int m = 0; m < mass[1]; ++m)
        {
            #ifdef DEBUGD
            cout << endl << "Mounth ++: " << m + 1 << endl;            
            #endif
            if(mass[2] % 4 == 0 && m == 1)
            {
                days += monthDays[12];
                #ifdef DEBUGD
                                cout << "Days ++: " << days << " add: " << monthDays[12] << endl;
                #endif
            }
            else
            {
                days += monthDays[m];
                #ifdef DEBUGD
                                cout << "Days ++: " << days << " add: " << monthDays[m] << endl;
                #endif
            }
            
        }
    if(mass[2] % 4 == 0 && mass[1] == 2)
    {
        days -= monthDays[12] - mass[0];
    }
    else
    {
        days -= monthDays[mass[1] - 1] - mass[0];
    }
    #ifdef DEBUGD
        cout << endl << "Days --: " << days << " del: " << monthDays[mass[1] - 1] - mass[0] << endl << endl;
        #endif
    return days;
}


int nextAnniversaryFinder(int days, int year)
{
    int anniversaryDays = 0;
    bool found = false;
    for(int i = 0; i < 66; i++)
    {
        if(days < daysAnniversary[i] and days > daysAnniversary[i - 1])
        {
            anniversaryDays = daysAnniversary[i];
            found = true;
            break;
        }
        
    }
    if(found)
    {
        return anniversaryDays;
    }
    else 
        cout << "Year of birth can't be less then " << year - 160 << " or more then current year(" << year << ")." << endl << endl ;
        exit(1);
}


void currentDateSetter()
{
    time_t now = time(0);

    
    tm *ltm = localtime(&now);
    
   // print various components of tm structure.
    #ifdef DEBUG
    cout << "Number of sec since January 1,1900:" << now << endl;

    cout << "Year: " << 1900 + ltm->tm_year<<endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<<  ltm->tm_mday << endl;
    cout << "Time: "<< ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl << endl;
    #endif
    currentDate[0] = ltm->tm_mday;
    currentDate[1] = 1 +ltm->tm_mon;
    currentDate[2] = 1900 + ltm->tm_year;
    cout << "Текущая дата " << currentDate[0] << ", " << month[currentDate[1] - 1] << " " << currentDate[2] << endl << endl; 
    
}


void dateValidation()
{
    if(birthDate[1] > 12 || birthDate[1] <= 0)
    {
        cout << "Incorrectly entered month!" << endl << "Please enter correct date!" << endl;
        exit(1);
    }
    if(birthDate[0] > monthDays[birthDate[1]] || birthDate[0] <= 0)
    {
        cout << "Incorrectly entered day!" << endl << "Please enter correct date!" << endl;
        exit(1);
    }
    
}


void dateConverter(int days)
{
    while(days >= 365)
    {
        if(anniversaryDate[2] % 4 == 0)
        {
            days -= 366;
        }
        else
        {
            days -= 365;
        }
        anniversaryDate[2]++;
        #ifdef DEBUGD
            cout << "Year ++: " << anniversaryDate[2] << ", days: " << days << endl;
        #endif
    }
    
    for(int m = 0; m < 12 && days >= monthDays[m]; m++)
    {
        
        if(m == 1 && anniversaryDate[2] % 4 == 0)
        {
            days -= monthDays[12];
        }
        else
        {
            days -= monthDays[m];            
        }
        anniversaryDate[1]++;
    }
    anniversaryDate[1]++;
    anniversaryDate[0] = days;
    #ifdef DEBUG
        cout << "Year: " << anniversaryDate[2] << endl << "Month: " << anniversaryDate[1] << endl << "Day: " << anniversaryDate[0] << endl;
    #endif
    
}
