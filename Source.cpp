#include <iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<time.h>
#include<string>
#include<fstream>
#include<conio.h>

using namespace std;
#pragma warning(disable:4996)
#pragma warning(disable:6451)


int const rows = 5;
int const col_eco = 10;
int const col_bui = 2;

class Person
{
protected:
    string cnic;
    string name;
    string password;
public:
    Person()
    {
        cnic = "NULL";
        name = "NULL";
        password = "NULL";
    }
    Person(string c, string nm, string psd)
    {
        cnic = c;
        name = nm;
        password = psd;
    }
};

class Administration : public Person
{
private:
    string designation;
    static int Admin_id;
    int aid;

public:
    Administration()
    {
        name = "NULL";
        password = "NULL";
        designation = "NULL";
        aid = 0;
    }
    Administration(string nm, string psd, string desig)
    {
        name = nm;
        password = psd;
        designation = desig;
        aid = Admin_id++;
    }

    void setAdminvalues(string n, string p, string d)
    {
        name = n;
        password = p;
        designation = d;
    }

};

class Country
{
private:
    string cname;
    bool covid_ban;
    int no_of_visits;
    int time_travel;
    double ticketprice_c;
    double ticketprice_d;
public:
    Country()
    {
        cname = "NULL";
        covid_ban = false;
        no_of_visits = 0;
        time_travel = 0;
        ticketprice_c = 0;
        ticketprice_d = 0;
    }
    Country(string cnm, bool a, int nov, int tt)
    {
        cname = cnm;
        covid_ban = a;
        no_of_visits = nov;
        double ticketprice = double(tt * 20000);
        ticketprice_c = ticketprice + (ticketprice * 10) / 100;
        ticketprice_d = ticketprice+ (ticketprice * 10) / 100;
    }

    void intialcountryvalues(string cnm, bool a, int nov, int tt)
    {
        cname = cnm;
        covid_ban = a;
        no_of_visits = nov;
        time_travel = tt;
        double ticketprice = double(tt * 20000);
        ticketprice_c = ticketprice + (ticketprice * 10) / 100;
        ticketprice_d = ticketprice + (ticketprice * 10) / 100;
    }

    void operator++(int)
    {
        this->no_of_visits++;
    }

    void displaycountryvalues()
    {
        cout << left << setw(15) << cname << setw(20) << no_of_visits << setw(15) << (getCovid_ban()?"No":"Yes" )<< setw(10) << endl;
    }

    int visits()
    {
        return no_of_visits;
    }

    string getcountryname()
    {
        return cname;
    }

    void displaycountryname()
    {
        cout << cname;
    }
    void setCovid_ban(bool a)
    {
        covid_ban = a;
    }
    bool getCovid_ban()
    {
        return covid_ban;
    }

    int gettime()
    {
        return time_travel;
    }

    double getticketprice_c()
    {
        return ticketprice_c;
    }

    double getticketprice_d()
    {
        return ticketprice_d;
    }

};

class Airplane
{
private:
    int air_id;
    static int airplane_id;
    int domestic_flight;
    int inter_flight;
    char book_eco[rows][col_eco];
    char book_bui[rows][col_bui];
    int eco_seats;
    int bui_seats;

public:
    Airplane()
    {
        air_id = airplane_id++;
        domestic_flight = 0;
        inter_flight = 0;
        int eco_seats = 50;
        int bui_seats = 10;
        clearseatingeco();
        clearseatingbui();
    }

    void clearseatingeco()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col_eco; j++)
            {
                
                    book_eco[i][j] = ' ';
            }
        }
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col_eco; j++)
            {
                if ((i % 2 == 0) && (j % 2 == 0))
                {
                    book_eco[i][j] = 'x';
                }
                else if ((i % 2 == 1) && (j % 2 == 1))
                {
                    book_eco[i][j] = 'x';
                }
                
            }
        }
    }
    void clearseatingbui()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col_bui; j++)
            {
                if (i % 2 == j % 2)
                {
                    book_bui[i][j] = 'x';
                }
                else
                {
                    book_bui[i][j] = ' ';
                }
            }
        }
    }

    void bookseat_eco(int row, int col)
    {
        while (!(book_eco[row-1][col-1] == ' ' || book_eco[row-1][col-1] == 'O'))
        {
            cout << "Seat not available!"<<endl;
            cout << "Please enter row number: ";
            cin >> row;
            while (!(row - 1 >= 0 && row - 1 <= 4))
            {
                cout << "Please enter row number again: ";
                cin >> row;
            }

            cout << "Please enter coloumn number: ";
            cin >> col;
            while (!(col - 1 >= 0 && col - 1 <= 9))
            {
                cout << "Please enter column number again: ";
                cin >> col;
            }

            bookseat_eco(row, col);

        }
        book_eco[row-1][col-1] = 'O';
        displayeco();
    }
    void bookseat_bui(int row, int col)
    {
        while (!(book_bui[row-1][col-1] == ' ' || book_bui[row-1][col-1] == 'O'))
        {
            cout << "Seat not available!" << endl;
            cout << "Please enter row number: ";
            cin >> row;
            while (!(row - 1 >= 0 && row - 1 <= 4))
            {
                cout << "Please enter row number again: ";
                cin >> row;
            }

            cout << "Please enter coloumn number: ";
            cin >> col;
            while (!(col - 1 >= 0 && col - 1 <= 9))
            {
                cout << "Please enter column number again: ";
                cin >> col;
            }

            bookseat_bui(row, col);

        }


        book_bui[row-1][col-1] = 'O';
        displaybui();

    }
    void displayeco()
    {
        cout<<right<<setw(12)<< "1" << setw(7) << "2" << setw(7) << "3" << setw(7) << "4" << setw(7) << "5" << setw(7) << "6" << setw(7) << "7" << setw(7) << "8" << setw(7) << "9" << setw(7) << "10" <<setw(7)<< endl;
        cout << "         __________________________________________________________________" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << setw(5) << i + 1 << setw(5);
            for (int j = 0; j < 10; j++)
            {
                cout << "|" << book_eco[i][j] << "|" << setw(5);
            }
            cout << endl;
            cout << "         __________________________________________________________________" << endl;
        }
    }
    void displaybui()
    {
        cout << setw(10) << "1" << setw(7) << "2" << endl;
        cout << "         __________" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << setw(5) << i + 1 << setw(5);
            for (int j = 0; j < 2; j++)
            {
                cout << "|" << book_bui[i][j] << "|" << setw(5);
            }
            cout << endl;
            cout << "         __________" << endl;
        }
    }

    void displayairplaneid()
    {
        cout << air_id << endl;
    }

    int getairplaneseats(int i)
    {
        if (i == 1)
        {
            return eco_seats;
        }
        else
        {
            return bui_seats;
        }

    }
};

class Runway
{
private:
    static int runway_id;
    int rid;
    bool availability;

public:
    Runway()
    {
        rid = runway_id++;
        availability = true;
    }

    bool getavailability()
    {
        return availability;
    }
};

class Airport
{
    static int airport_id;
    int arid;

public:
    Airport()
    {
        arid = airport_id++;        
    }

};

class Booking 
{
private:
    Airport* airport;
    Airplane* airplane;
    Runway* runway;
public:
    Booking()
    {
        airport = new Airport[2];
        airplane = new Airplane[10];
        runway = new Runway[5];
    }

    void bookaseat(int i,int j)
    {
        int row = 0, col = 0;
        if (j == 1)
        {
            airplane[i].clearseatingeco();
            airplane[i].displayeco();
            cout << "Please enter row number: ";
            cin >> row;
            while (!(row - 1 >= 0 && row - 1 <= 4))
            {
                cout << "Please enter row number again: ";
                cin >> row;
            }

            cout << "Please enter coloumn number: ";
            cin >> col;
            while (!(col - 1 >= 0 && col - 1 <= 9))
            {
                cout << "Please enter column number again: ";
                cin >> col;
            }

            airplane[i].bookseat_eco(row , col);
        }
        else if (j == 2)
        {
            airplane[i].clearseatingbui();
            airplane[i].displaybui();
            cout << "Please enter row number: ";
            cin >> row;
            while (!(row - 1 >= 0 && row - 1 <= 4))
            {
                cout << "Please enter row number again: ";
                cin >> row;
            }

            cout << "Please enter coloumn number: ";
            cin >> col;
            while (!(col - 1 >= 0 && col - 1 <= 9))
            {
                cout << "Please enter column number again: ";
                cin >> col;
            }

            airplane[i].bookseat_bui(row, col);
        }
        
    }

    void displayairid()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << i + 1 << " ";
            airplane[i].displayairplaneid();
        }
    }

    ~Booking()
    {
        delete airport;
        delete airplane;
        delete runway;

    }



};

class City:public Booking
{
    string cityname;
    int timetravel;
    double ticketprice;
    int booksize;
public:
    City()
    {
        cityname = "NULL";
        timetravel = 0;
        ticketprice = 0;

    }

    City(string cinm, int t)
    {
        cityname = cinm;
        timetravel = t;
        double tp = double(t * 10000);
        ticketprice = tp + (tp * 5) / 100;
    }


    void Citysetvalues(string cinm, int t)
    {
        cityname = cinm;
        timetravel = t;
        double tp = double(t * 10000);
        ticketprice = tp + (tp * 5) / 100;
        
    }

    string getcityname()
    {
        return cityname;
    }

    int gettime()
    {
        return timetravel;
    }

    double getticketprice()
    {
        return ticketprice;
    }

};

class Flightinfo
{
    City city;
    Country country;
    string dropoff;
    string destination;
    int timetravel;
    string timetakeoff;
    string date;
    bool connectingflight;
    double bill;

public:
    Flightinfo()
    {
        dropoff = "NULL";
        destination = "NULL";
        timetravel = 0;
        timetakeoff = "NULL";
        date = "NULL";
    }

    Flightinfo(string drp, string dest, string t, bool a)
    {
        dropoff = drp;
        destination = dest;
        connectingflight = a;
        setflightdatetime();
    }


    void Flightsetvalue(City& c)
    {
        this->city = c;
        timetravel = c.gettime();
        bill = c.getticketprice();
        setflightdatetime();
    }

    void Flightsetvalue(Country& c)
    {
        this->country = c;
        timetravel = c.gettime();
        if (connectingflight == 1)
        {
            bill = c.getticketprice_c();
        }
        else
        {
            bill = c.getticketprice_d();
        }
        setflightdatetime();
    }


    void setflightdatetime()
    {
        time_t T = time(NULL);
        tm* ptr = localtime(&T);
        string d, meridian;
        d = to_string(ptr->tm_mday + rand()%5) + "//" + to_string(ptr->tm_mon) + "//" + to_string(ptr->tm_year + 1900);
        date = d;
        int t = 0;
        if (ptr->tm_hour > 12)
        {
            meridian = "PM";
            t = (ptr->tm_hour) % 12;
        }
        else if (ptr->tm_hour < 12)
        {
            meridian = "AM";
            t = ptr->tm_hour;
        }
        d = to_string(t + 3) + " : " + "00" + " " + meridian;
        timetakeoff = d;

    }

    void display()
    {
        cout << "Dropoff: " << dropoff << endl;
        cout << "Destination: " << destination << endl;
        cout << "Flight Date: " << date << endl;
        cout << "Flight Time: " << timetakeoff << endl;
        cout << "Time Travel: " << timetravel << endl;
        cout << "Ticket price: " << bill << endl;
    }

    void setdropoff(string c)
    {
        dropoff = c;
    }

    void setdestination(string c)
    {
        destination = c;
    }

    void setconnecting(bool a)
    {
        connectingflight = a;

    }

    void settimetravel(int tt)
    {
        timetravel = tt;
    }

    void settimetakeoff(string to)
    {
        timetakeoff = to;
    }

    void setdate(string d)
    {
        date = d;
    }
    void setbill(double b)
    {
        bill = b;
    }
    string getdropoff()
    {
        return dropoff;
    }
    string getdestination()
    {
        return destination;
    }
    int gettimetravel()
    {
        return timetravel;
    }
    string gettimetakeoff()
    {
        return timetakeoff;
    }
    string getdate()
    {
        return date;
    }
    bool getconnectingflight()
    {
        return connectingflight;
    }
    double getbill()
    {
        return bill;
    }

};

class Passenger : public Person
{
private:
    static int passenger_id;
    int pid;
    bool visa;
    int size;
    Flightinfo* F;
public:
    Passenger()
    {
        cnic = "NULL";
        name = "NULL";
        password = "NULL";
        pid = 0;
        visa = true;
        size = 0;
        F = new Flightinfo[size];
    }
    Passenger(string c, string nm, string psd)
    {
        cnic = c;
        pid = passenger_id++;
        name = nm;
        password = psd;
        visa = true;
        size = 0;
        F = new Flightinfo[size];
    }

    void setPassengervalues(string c, string nm, string psd)
    {
        cnic = c;
        name = nm;
        password = psd;
        visa = visavalue();
    }

    void updateflightschedule(Flightinfo *f)
    {
        int a = getsize();
        Flightinfo* temp = new Flightinfo[a + 1];
        for (int i = 0; i < a; i++)
        {
            temp[i] = F[i];
        }
        
        temp[a].setdropoff(f->getdropoff());
        temp[a].setdestination(f->getdestination());
        temp[a].settimetakeoff(f->gettimetakeoff());
        temp[a].settimetravel(f->gettimetravel());
        temp[a].setdate(f->getdate());
        temp[a].setbill(f->getbill());
        temp[a].setconnecting(f->getconnectingflight());
        size++;
        delete[] F;
        F = temp;
        temp = nullptr;
    }

    void displayschedule()
    {
        for (int i = 0; i < size; i++)
        {
            if (F[i].gettimetravel() != 0)
            {
                cout << i + 1 << " ";
                F[i].display();
            }
        }
    }
    void deleteaschedule(int p)
    {
        for (int i = p - 1; i < size; i++)
        {
            if (i < size-1)
            {
                F[i] = F[i + 1];
            }
            else if (i == size - 1)
            {
                F[i].setdropoff("NULL");
                F[i].setdestination("NULL");
                F[i].settimetakeoff("NULL");
                F[i].settimetravel(0);
                F[i].setdate("NULL");
                F[i].setbill(0);
                F[i].setconnecting(0);
            }
        }

        displayschedule();
    }

    bool visavalue()
    {
        srand(time(NULL));
        int num = rand() % 9;
        if (num % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool visacheck()
    {
        return visavalue();
    }
    void setPName(string nm)
    {
        name = nm;
    }
    void setPPassword(string psd)
    {
        password = psd;
    }

    string getPName()
    {
        return name;
    }
    string getPPassword()
    {
        return password;
    }
    int getPid()
    {
        return pid;
    }
    int getsize()
    {
        return size;
    }

};


//sorts the countries on the basis of the number of visits in a ascending order
void setvaluesonnoofvisits(Country* c)
{
    Country temp;
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 25; j++)
        {
            if (c[i].visits() < c[j].visits())
            {
                temp = c[j];
                c[j] = c[i];
                c[i] = temp;

            }
        }
    }
}
//a function that validate the cnic being entered
bool validatecnic(string c)
{
    int count = 0;
    int size = c.length();
    for (int i = 0; i < size; i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
        {
            count++;
        }
    }
    if (count == 13)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//the function that takes input in password and hides it
string hidepassword()
{
    char pass[64];
    int i = 0;
    char a;
    for (i = 0; ; )
    {
        a = getch();
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || (a >= 32 && a <= 47) || (a >= 58 && a <= 64) || (a >= 91 && a <= 96) || (a >= 123 && a <= 126))
        {
            pass[i] = a;
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
        }
        if (a == '\r')
        {
            pass[i] = '\0';
            break;
        }
    }

    return pass;
}
//checks the password whether it is alphanumeric
bool passwordcheck(string p)
{
    bool capitalflag = false, smallflag = false, numberflag = false, specialflag = false;
    int passsize = p.length();
    for (int i = 0; i < passsize; i++)
    {
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            smallflag = true;
        }
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            capitalflag = true;
        }
        else if (p[i] >= '0' && p[i] <= '9')
        {
            numberflag = true;
        }
        else if ((p[i] >=32  && p[i] <=47 ) || (p[i] >= 58 && p[i] <= 64) || (p[i] >= 91 && p[i] <= 96) || (p[i] >= 123 && p[i] <= 126))
        {
            specialflag = true;
        }
    }
    if (capitalflag == true && smallflag == true && numberflag == true && specialflag == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//static members are intialized here
int Airport::airport_id = 1767;
int Airplane::airplane_id = 2000;
int Runway::runway_id = 1;


int main()
{
    //variable for fstream
    Passenger P1;
    Administration A1;
    Booking B;
    fstream myfile;
    //cities
    City city[5];
    //countries
    Country country[25];

    //value of cities being intialized
    city[0].Citysetvalues("Lahore",2 );
    city[1].Citysetvalues("Karachi", 1);
    city[2].Citysetvalues("Islamabad",5 );
    city[3].Citysetvalues("Quetta",3 );
    city[4].Citysetvalues("Peshawar", 2);

    //value of countries being intialized
    country[0].intialcountryvalues("Sirilanka", false, 76,3);
    country[1].intialcountryvalues("India", true, 90,6);
    country[2].intialcountryvalues("Turkey", false, 80,3);
    country[3].intialcountryvalues("Afghanistan", false, 30,5);
    country[4].intialcountryvalues("Australia", false, 45,8);
    country[5].intialcountryvalues("Azerbaijan", false, 50,3);
    country[6].intialcountryvalues("Bangladesh", false, 58, 4);
    country[7].intialcountryvalues("Phillipines", true, 30, 6);
    country[8].intialcountryvalues("China", false, 90, 4);
    country[9].intialcountryvalues("Iran", false, 48, 7);
    country[10].intialcountryvalues("Iraq", false, 49, 7);
    country[11].intialcountryvalues("Saudia Arabia", false, 96, 8);
    country[12].intialcountryvalues("Jordon", false, 42, 9);
    country[13].intialcountryvalues("USA", true, 76, 12);
    country[14].intialcountryvalues("UK", true, 66, 11);
    country[15].intialcountryvalues("New Zealand", false, 67, 9);
    country[16].intialcountryvalues("Germany", false, 56, 10);
    country[17].intialcountryvalues("Austria", false, 60, 12);
    country[18].intialcountryvalues("Lebanon", false, 59, 6);
    country[19].intialcountryvalues("Yemen", false, 59, 9);
    country[20].intialcountryvalues("Russia", false, 50, 8);
    country[21].intialcountryvalues("Bosnia", false, 40, 10);
    country[22].intialcountryvalues("Japan", false, 66, 7);
    country[23].intialcountryvalues("SwitzerLand", false, 78, 10);
    country[24].intialcountryvalues("Syria", false, 59, 10);

    //sorts the country on basis of no of visits
    setvaluesonnoofvisits(country);

    // the npafs main menu
    cout << "WELCOME TO NPAFS" << endl;
    cout << endl;
    cout << "Top 5 most visited countries" << endl;//prints the top most 5 countries with the most number of visits
    cout << left << setw(15) << "Country " << setw(20) << "No_of_visits" << setw(15) << "Flights operational" << setw(10) << endl;
    for (int i = 0; i < 5; i++)
    {
        country[i].displaycountryvalues();
    }
    cout << endl;
    cout << "Choose an Option:" << endl;
    int menuoption = 0, submenuoption = 0, op = 0;
    do
    {
        //flights stats
    mainmenu:
        cout << "[1]-SIGN IN" << endl;
        cout << "[2]-SIGN UP" << endl;
        cout << "[3]-EXIT" << endl;
        cin >> menuoption;

        switch (menuoption)
        {
        case 1:
        {
            do
            {//checks whether the user is a passenger or admin
                submenu:
                cout << "Select an Option: " << endl;
                cout << "[1]-Passenger" << endl;
                cout << "[2]-Administration" << endl;
                cout << "[3]-Back to main menu" << endl;
                cin >> submenuoption;

                switch (submenuoption)
                {
                case 1:
                {
                login:
                    int count = 0;
                    string c, n, p;
                    bool exist = false;
                    cin.ignore();
                    cout << "Please enter cnic without dashes: "<<endl;//takes input in cnic and validates it
                    getline(cin, c);
                    while (!(validatecnic(c)))
                    {
                        cout << "Invalid. Please enter cnic again: ";//will propmt a message if user enter wrong cnic
                        getline(cin, c);
                    }
                    //check for cnic;
                    cout << "Please enter your name: " << endl;
                    getline(cin, n);
                    //check for name;
                    cout << "Please enter your password: " << endl;
                    p = hidepassword();
                    cout << endl;
                   //reads the data from the file passenger to check whter the account is registered or not
                    myfile.open("Passenger.txt", ios::in);
                        while (!myfile.eof())
                        {
                            string cnic = "\0";
                            getline(myfile, cnic);

                                if (c == cnic)
                                {
                                    string name = "\0";

                                    getline(myfile,name);
                                    
                                        if (n == name)
                                        {
                                            string pass = "\0";
                                            getline(myfile,pass);

                                            if(p==pass)
                                            {
                                                exist = true;
                                            }
                                        }
                                }
                        }
                    //if the credentials match with the input the program will proceed otherwise will take back to login
                    if (exist==true)
                    {
                        cout << "Credientials matched!" << endl;
                        P1.setPassengervalues(c, n, p);
                    }
                    else
                    {
                        cout << "Credientials not found!" << endl;
                        cout << "Enter again" << endl;
                        goto login;
                    }
                    myfile.close();//closes the file
                   do
                    {
                    menu:
                        cout << "Please select from the following: " << endl;
                        cout << "[1]-Book a Flight" << endl;
                        cout << "[2]-Cancel a Flight" << endl;
                        cout << "[3]-Change the Flight Time" << endl;
                        cout << "[4]-Back to Submenu" << endl;
                        cin >> op;
                        switch (op)
                        {
                        case 1:
                        {
                            int sizearr = 1;
                            Flightinfo *F = new Flightinfo[sizearr];
                            int citychoice = 0, flightoption = 0, citychoice2 = 0, countrychoice = 0, connectingchoice = 0;
                            cout << "Please select your City" << endl;
                            for (int i = 0; i < 5; i++)
                            {
                                cout << i + 1 << " " << city[i].getcityname() << endl;
                            }
                            cin >> citychoice;
                            while (!(citychoice > 0 && citychoice < 6))
                            {
                                cout << "Invalid Option enter again: ";
                                cin >> citychoice;
                            }
                            F->setdropoff(city[citychoice - 1].getcityname());
                            a:
                            cout << "Flight Option: " << endl;
                            cout << "[1]-Local Flight" << endl;
                            cout << "[2]-International Flight" << endl;
                            cin >> flightoption;

                            while (!(flightoption > 0 && flightoption < 3))
                            {
                                cout << "Invalid Option enter again: ";
                                cin >> flightoption;
                            }

                            if (flightoption == 1)
                            {
                                cout << "Please select a City" << endl;
                                for (int i = 0; i < 5; i++)
                                {
                                    cout << i + 1 << " " << city[i].getcityname() << endl;
                                }
                                cin >> citychoice2;
                                while (!(citychoice2 > 0 && citychoice2 < 6))
                                {
                                    cout << "Invalid Option enter again: ";
                                    cin >> citychoice2;
                                }
                                
                                while ((F->getdropoff() == city[citychoice2 - 1].getcityname()))
                                {
                                    cout << "Please select a City again: " << endl;
                                    cout << "Dropoff and destination cannot be the same!" << endl;
                                    for (int i = 0; i < 5; i++)
                                    {
                                        cout << i + 1 << " " << city[i].getcityname() << endl;
                                    }
                                    cin >> citychoice2;
                                    while (!(citychoice2 > 0 && citychoice2 < 6))
                                    {
                                        cout << "Invalid Option enter again: ";
                                        cin >> citychoice2;
                                    }
                                }
                                int index = 0, classtype = 0;
                                cout << "Please choose from the following: " << endl;
                                cout << "Seat Class Option: " << endl;
                                cout << "[1]-Economic" << endl;
                                cout << "[2]-Buisness" << endl;
                                cin >> classtype;
                                while (!(classtype == 1 || classtype == 2))
                                {
                                    cout << "Enter choice again :";
                                    cin >> classtype;
                                }
                                city[citychoice2 - 1].displayairid();
                                cout << "Please enter the index of airplane: ";
                                cin >> index;
                                city[citychoice2 - 1].bookaseat(index - 1, classtype);
                                F->setdestination(city[citychoice2 - 1].getcityname());
                                F->Flightsetvalue(city[citychoice2 - 1]);
                                F->display();
                                P1.updateflightschedule(F);
                                goto menu;
                            }
                            else if (flightoption == 2)
                            {

                                cout << "Please select from the following: " << endl;
                                cout << "Flight Choice: " << endl;
                                cout << "[1]-Connecting Flight" << endl;
                                cout << "[2]-Direct Flight" << endl;
                                cin >> connectingchoice;

                                while (!(connectingchoice > 0 && connectingchoice < 3))
                                {
                                    cout << "Invalid Option enter again: ";
                                    cin >> connectingchoice;
                                }
                                if (connectingchoice == 1)
                                {
                                    F->setconnecting(true);
                                }
                                else
                                {
                                    F->setconnecting(false);
                                }

                                if (P1.visacheck())
                                {
                                    cout << "Visa APPROVED!" << endl;
                                }
                                else
                                {
                                    cout << "Visa NOT APPROVED. Try again!" << endl;
                                    goto a;
                                }

                                cout << "Please select from the following: " << endl;
                                cout << "Countries list with operational flights: " << endl;
                                for (int i = 0; i < 25; i++)
                                {
                                    if (!(country[i].getCovid_ban()))
                                    {
                                        cout << i + 1 << " " << country[i].getcountryname() << endl;
                                    }
                                }
                                cin >> countrychoice;
                                while (country[countrychoice - 1].getCovid_ban() == 1)
                                {
                                    cout << "Sorry the Country has imposed Covid BAN!" << endl;
                                    cout << "Countries list with operational flights: " << endl;
                                    for (int i = 0; i < 5; i++)
                                    {
                                        if (!(country[i].getCovid_ban()))
                                        {
                                            cout << i + 1 << " " << country[i].getcountryname() << endl;
                                        }
                                    }
                                    cin >> countrychoice;

                                }
                                int index = 0, classtype = 0;
                                cout << "Please choose from the following: " << endl;
                                cout << "Seat Class Option: " << endl;
                                cout << "[1]-Economic" << endl;
                                cout << "[2]-Buisness" << endl;
                                cin >> classtype;
                                while (!(classtype == 1 || classtype == 2))
                                {
                                    cout << "Enter choice again :";
                                    cin >> classtype;
                                }
                                city[citychoice2 - 1].displayairid();
                                cout << "Please enter the index of airplane: ";
                                cin >> index;
                                city[citychoice2 - 1].bookaseat(index - 1, classtype);

                                F->setdestination(country[countrychoice - 1].getcountryname());
                                F->Flightsetvalue(country[countrychoice - 1]);
                                F->display();
                                P1.updateflightschedule(&F[sizearr-1]);
                                goto menu;
                            }

                            break;
                        }
                        case 2:
                        {
                            int flightcancel = 0;
                            P1.displayschedule();
                            cout << "Please select the Flight number you want to cancel: ";
                            cin >> flightcancel;
                            while (flightcancel-1<0 && flightcancel-1>P1.getsize())
                            {
                                cout << "Invalid. Please select the Flight number you want to cancel: ";
                                cin >> flightcancel;
                            }

                            P1.deleteaschedule(flightcancel);
                            break;
                        }
                        case 3:
                        {
                            int choice = 0;
                            cout << "Please select from the following: " << endl;
                            cout << "[1]-Change Time" << endl;
                            cout << "[2]-Change Date" << endl;
                            cin >> choice;
                            if (choice == 1)
                            {
                                int hours;
                                int mins;
                                string meridan;
                                cout << "Enter hours in 24hr format: ";
                                cin >> hours;
                                if (hours > 12)
                                {
                                    meridan = "PM";
                                }
                                else if (hours < 12)
                                {
                                    meridan = "AM";
                                }
                                cout << "Enter mins (0-59): ";
                                cin >> mins;

                                string date = to_string(hours) + " : " + to_string(mins) + " " + meridan;
                                

                            }
                            break;
                        }
                        case 4:
                        {
                            goto submenu;
                            break;
                        }

                        }
                    } while (!(op>0 && op<=4));

                    break;
                }

                case 2:
                {
                    login2:
                    string n, p, desig;

                    cout << "Please enter your name: " << endl;
                    cin.ignore();
                    getline(cin, n);
                    //check for name;
                    cout << "Please enter your password: " << endl;
                    p = hidepassword();
                    cout << endl;

                    cout << "Please enter your designation: " << endl;
                    getline(cin, desig);

                    bool exist = false;
                    //check for password
                    myfile.open("Administration.txt", ios::in);
                    while (!myfile.eof())
                    {
                        string name = "\0";
                        getline(myfile, name);

                        if (n == name)
                        {
                            string pass = "\0";

                            getline(myfile, pass);

                            if (pass == p)
                            {
                                string designation = "\0";
                                getline(myfile, designation);

                                if (desig == designation)
                                {
                                    exist = true;
                                }
                            }
                        }
                    }



                    if (exist == true)
                    {
                        cout << "Credientials matched!" << endl;
                        A1.setAdminvalues(n, p, desig);
                    }
                    else
                    {
                        cout << "Credientials not found!" << endl;
                        cout << "Enter again" << endl;
                        goto login2;
                    }
                    myfile.close();
                    int adminmainmenu = 0, adminsubmenu = 0;
                            do
                            {
                                adminmenu:
                                cout << "Choose from the following: " << endl;
                                cout << "[1]-See Flight Schedule" << endl;
                                cout << "[2]-Manage Covid restrictions" << endl;
                                cout << "[3]-Manage Seating Plan" << endl;
                                cout << "[4]-Manage Flight Inquiry" << endl;
                                cout << "[5]-Back to Submenu" << endl;
                                cin >> adminmainmenu;
                                switch (adminmainmenu)
                                {
                                case 1:
                                {
                                    int flightcancel = 0;
                                    P1.displayschedule();
                                    cout << "Please select the Flight number you want to cancel: ";
                                    cin >> flightcancel;
                                    while (flightcancel - 1 < 0 && flightcancel - 1 > P1.getsize())
                                    {
                                        cout << "Invalid. Please select the Flight number you want to cancel: ";
                                        cin >> flightcancel;
                                    }

                                    P1.deleteaschedule(flightcancel);
                                    break;

                                    break;
                                }
                                case 2:
                                {
                                    int countryindex = 0,banindex=0;
                                    for (int i = 0; i < 5; i++)
                                    {
                                        cout << "[" << i + 1 << "]"<<" ";
                                        country[i].displaycountryname();
                                        cout << endl;
                                    }
                                    cout << "Please enter a index: ";
                                    cin >> countryindex;
                                    while (countryindex-1< 0 && countryindex-1>25)
                                    {
                                        cout << "Please enter a correct index: ";
                                        cin >> countryindex;
                                    }
                                    cout << "[1]-Impose Covid ban" << endl;
                                    cout << "[2]-Remove Covid ban" << endl;
                                    cin >> banindex;
                                    while (banindex< 0 && banindex - 1 > 25)
                                    {
                                        cout << "Please enter a correct option: ";
                                        cin >> banindex;
                                    }
                                    if (banindex == 1)
                                    {
                                        if (country[countryindex - 1].getCovid_ban())
                                        {
                                            cout << "There is already a ban imposed on the country" << endl;
                                        }
                                        else
                                        {
                                            cout << "Ban imposed!" << endl;
                                            country[countryindex - 1].setCovid_ban(1);
                                        }
                                        goto adminmenu;

                                    }
                                    else if (banindex == 2)
                                    {
                                        if (!(country[countryindex - 1].getCovid_ban()))
                                        {
                                            cout << "There is already no ban imposed on the country" << endl;
                                        }
                                        else
                                        {
                                            cout << "Ban Removed!" << endl;
                                            country[countryindex - 1].setCovid_ban(0);
                                        }
                                        goto adminmenu;

                                    }


                                    break;
                                }
                                case 3:
                                {
                                    int citychoice = 0;
                                    cout << "Please select your City" << endl;
                                    for (int i = 0; i < 25; i++)
                                    {
                                        cout << i + 1 << " ";
                                        city[i].getcityname();
                                        cout<< endl;
                                    }
                                    cin >> citychoice;
                                    while (!(citychoice > 0 && citychoice < 6))
                                    {
                                        cout << "Invalid Option enter again: ";
                                        cin >> citychoice;
                                    }
                            
                                    break;
                                }
                                case 4:
                                {

                                }
                                case 5:
                                {
                                    goto submenu;
                                    break;
                                }
                                }
                            } while (adminmainmenu);

                }

                case 3:
                {
                    goto mainmenu;
                    break;
                }
                }
            } while (submenuoption != 3);
            break;
        }

        case 2:
        {
            int count = 0;
            string c;
            string n, p;
            cin.ignore();
            cout << "Please enter your Cnic without dashes: " << endl;
            getline(cin, c);
            while (!(validatecnic(c)))
            {
                cout << "Invalid. Please enter cnic again: ";
                getline(cin, c);
            
            }
            bool exist = false;
            myfile.open("Passenger.txt", ios::in);
            while (!myfile.eof())
            {
                string cnic = "\0";
                getline(myfile, cnic);

                if (c == cnic)
                {
                    exist = true;
                }
            }
            while (exist == true)
            {
                cout << "Cnic already exists!" << endl;
                cout << "Enter Cnic again" << endl;
                cout << "Please enter your Cnic without dashes: " << endl;
                getline(cin, c);
                while (!(validatecnic(c)))
                {
                    cout << "Invalid. Please enter cnic again: ";
                    getline(cin, c);

                }
                while (!myfile.eof())
                {
                    string cnic = "\0";
                    getline(myfile, cnic);

                    if (c == cnic)
                    {
                        exist = true;
                    }
                }
                exist = false;


            }
            myfile.close();
            //check for cnic;
            cout << "Please enter your name: " << endl;
            getline(cin, n);
            //check for name;
            cout << "Enter a password: " << endl;
            p = hidepassword();
            cout << endl;
            while (!(passwordcheck(p)))
            {
                cout << "Invalid. Please enter password again: ";
                cout << "Password must contain Capital, small aplhabets, numbers and special characters: ";
                getline(cin, p);

            }
           

            myfile.open("Passenger.txt", ios_base::app);
            myfile << c << endl; 
            myfile << n << endl;
            myfile << p << endl;
            myfile.close();
            goto mainmenu;
            break;
        }
        case 3:
        {
            exit(0);
        }
        }

        
    } while (menuoption != 3);




}

