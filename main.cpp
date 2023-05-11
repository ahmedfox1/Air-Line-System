#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <chrono>
#include <thread>
#include <Windows.h>
#include<ctime>
using namespace std;
using namespace this_thread;
using namespace chrono;
#define max_lines 100
struct information_usesrs
{
    string email, password, username, address, number, id;
}users[100], userlogin;
struct information_admin
{
    string email, password, username;
} admins[100], adminlogin;
struct PaymentMethod {
    string type;
    double fee_percent;
};
struct flight_booked
{
    string depatureplace, arrivalplace, departure_date, arrival_date, departure_time, arrival_time, flightlong, flightnumber;
    string payments;
}booked[max_lines];
//globalvariable signup and login
int users_numbers = 0;
int admin_number = 0;
int new_user = 0;
int counter = 0;
//function signup and login
void choosesignup();
void signupuser();
void data();
void login();
void filldata();
int home();
//admin code-----------------------------------------------------------
//---admin---
int number_new_admins = 0;
//functions
void user_list();
int exit();
void admins_list();
void add_admin();
int modify_admins();
int admin_menu();
void addflight();
void deletflight();
void modifyflight();
void menu_modify_flights();
void modify_admin();
void flights_details();
void log_out();
void modify_users();
void compeletlogin(string x);
//============================================
//global arrays related to admin code----------------------------------
struct flight_added
{
    string depatureplace, arrivalplace, departure_date, arrival_date, departure_time, arrival_time, flightlong;

}added[max_lines];
string Seats_of_Eco_Class[max_lines] = { "" };
string Seats_of_Eco_Pre_Class[max_lines] = { "" };
string Seats_of_F_Class[max_lines] = { "" };
string Seats_of_B_Class[max_lines] = { "" };
//---flights---

int num_flights ;
//============================================
//seats
void add_Seats();
void Seats_F();
void Seats_Eco();
void Seats_Eco_Pre();
void Seats_B();
int  line_1 = 0, line_2 = 0, line_3 = 0, line_4 = 0;
void delete_seats();
void seats();
string Seat_num;
string booked_F_Seats[max_lines];
string booked_Eco_Seats[max_lines];
string booked_Eco_Pre_Seats[max_lines];
string booked_B_Seats[max_lines];
int Chosen_F_Seat = 0, Chosen_B_Seat = 0, Chosen_Eco_Seat = 0, Chosen_Eco_Pre_Seat = 0;
void assign_seat();
//============================================
//user
int shifting = 0;
int count1;
int choice_modify;
int j = 0;
int lines_u_id = 0;
char choseclas;
int correct;
//============================================
//user code
void user_menu();
//user information
void UsersInfo();
void edit_info();
// ticket price
char paymenttype();
double chooseclasses();
double calculateFee(double amount, PaymentMethod method);
double ticketprice();
//============================================================
// ticket information
void user_flight();
void ticketinfo();
//===================reservation====================
void reservation_menu();
void cur_date_time();
void reservation();
void edit_reservation();
void previous_reservations();
void cancel_reservation();
void searchflights();
int flightbooked;
int reservation_month[max_lines];
string reservation_date_time[max_lines];
//additional function
void warning();
void game();
int main()
{

    data();

    home();

    return 0;
}
//==================================== home ====================================
int home() {

    int reply;

    cout << "\n\t\t\t***************************************************************************\n";
    cout << "\t\t\t\t                            Welcome    \n";
    cout << "\t\t\t***************************************************************************\n";
    cout << "\t\t\t\t\t\t    do you have an account ? \n\t\t     if you have an account choose login and if you do not have please choose sign up \n ";
    cout << " \n\t\t\t\t\t\t\t   1: Sign up \n\t\t\t\t\t\t\t   2: Login \n\t\t\t\t\t\t\t   3: Exit";

    while (true) {
        cout << "\n\n\t\t\t\t\t\t\tYour answer is : ";
        if (cin >> reply && reply >= 1 && reply <= 3) {
            break;
        }
        else {

            cin.clear();
            char buffer[100];
            cin.ignore(100, '\n');
            cout << " there is an error Please enter again : " << endl;
        }
    }
    switch (reply)
    {
        case (1):
            signupuser();
            break;
        case(2):
            login();
            break;
        case (3):
            exit();
            return 0;
        default:
            break;
    }
}

//==============================sign up user =============================
void signupuser() {

    string checkpass;
    counter = users_numbers + new_user;

    system("cls");
    while (true) {
        new_user++;
        cout << "\t\t\t\t    Hello sir please answer the following question ^-^\n";
        cout << "\n Please enter the username : ";
        cin.ignore();
        getline(cin, users[counter].username);
        cout << "\n please enter the address : ";
        cin.ignore();
        getline(cin, users[counter].address);
        cout << "\n please enter the phone number : ";
        cin.ignore();
        getline(cin, users[counter].number);
        cout << "\n please enter the email : ";
        cin >> users[counter].email;
        cout << "\nplease enter the password : ";
        cin >> users[counter].password;
        cout << "\nplease enter the password again : ";
        cin >> checkpass;
        for (int i = users_numbers; i < counter; i++) {
            users[counter].id = users_numbers + 1;
        }

        while ((users[counter].password != checkpass)) {

            cout << "there is a mistake please try again \n ";
            cout << "\nplease enter the password : ";
            cin >> users[counter].password;
            cout << "\nplease enter the password again : ";
            cin >> checkpass;

        }
        break;
    }
    cout << "\n\t\t\t\t congratulation sign up completed \n ";
    cout << "\n\t\t\t\t now you are an user \n ";
    filldata();
    choosesignup();
}
//==============================choose signup=============================================
void choosesignup()
{
    char answer;
    cout << "\n press y if you want to register another account | to login press any key  \n";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        signupuser();
    }
    else
    {
        login();
    }
}
//===============================================login==============================
void login()
{
    string solution;
    system("cls");
    cout << "\n\n\t\t\t\t press a if you are an admin and press any key if you are user : ";
    cin >> solution;
    compeletlogin(solution);
}
//================================loading bar============================================
void loadingBar()
{

    system("color 0B");


    char a = 177, b = 219;
    cout << "\n";
    cout << "\n\n\n\n\t\t\t\t\t\t\tLoading...\n\n";
    cout << "\t\t\t\t\t\t";


    for (int i = 0; i < 26; i++)
        cout << ("%c", a);


    cout << ("\r");
    cout << ("\t\t\t\t\t\t");


    for (int i = 0; i < 26; i++) {
        cout << ("%c", b);


        Sleep(100);
    }
}
//============================complete login =========================
void compeletlogin(string solution)
{
    string mail;
    string pass;

    if (solution == "a" || solution == "A") {
        system("cls");
        cout << "\n\t\t\t\t\t\t please answer the following \n";
        cout << "\n please enter the email : ";
        cin >> mail;
        for (; j <= admin_number; j++) {
            if (admins[j].email == mail) {

                cout << "\n please enter the password : ";
                char ch;
                while (true) {
                    ch = _getch();
                    if (ch == '\r' || ch == '\n') {
                        break;
                    }
                    else {
                        pass += ch;
                        cout << "*";
                    }
                }
                while (admins[j].password != pass) {
                    pass = "";
                    cout << "\nthere is a mistake in password \nplease try again : ";
                    char ch;
                    while (true) {
                        ch = _getch();
                        if (ch == '\r' || ch == '\n') {
                            break;
                        }
                        else {
                            pass += ch;
                            cout << "*";
                        }
                    }
                }
                if (admins[j].password == pass) {
                    system("cls");
                    cout << "\ncongratulation you correctly logged in \n";
                    adminlogin.email = admins[j].email;
                    adminlogin.password = admins[j].password;
                    adminlogin.username = admins[j].username;

                    HANDLE col;
                    col = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(col, 4);
                    cout << "\t\t\t\t\t*****************************************\n";
                    cout << "\t\t\t\t\t*\t     "" Welcome " << adminlogin.username << "   \t\t*\n";
                    cout << "\t\t\t\t\t*****************************************";
                    loadingBar();
                    SetConsoleTextAttribute(col, 15);
                    sleep_for(nanoseconds(2));
                    sleep_until(system_clock::now() + seconds(1));
                    system("cls");
                    admin_menu();
                    break;
                }

            }
        }
        j = 0;
        for (; j < admin_number; j++)
        {
            if (admins[j].email != mail)
            {
                cout << "There is a mistake . Please Enter The Email again\n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));

                compeletlogin(solution);
            }
        }
    }
    else {
        system("cls");
        cout << "\n\t\t\t\t\t\t please answer the following \n";
        cout << "\n please enter the email : ";
        cin >> mail;

        for (; j <= users_numbers; j++) {
            if (users[j].email == mail) {

                cout << "\n please enter the password : ";
                char ch;
                while (true) {
                    ch = _getch();
                    if (ch == '\r' || ch == '\n') {
                        break;
                    }
                    else {
                        pass += ch;
                        cout << "*";
                    }
                }
                while (users[j].password != pass) {
                    pass = "";
                    cout << "\nthere is a mistake in password please try again : ";
                    char ch;
                    while (true) {
                        ch = _getch();
                        if (ch == '\r' || ch == '\n') {
                            break;
                        }
                        else {
                            pass += ch;
                            cout << "*";
                        }
                    }
                }
                if (users[j].password == pass) {
                    cout << "\ncongratulation you correctly logged in \n";
                    userlogin.email = users[j].email;
                    userlogin.password = users[j].password;
                    userlogin.number = users[j].number;
                    userlogin.address = users[j].address;
                    userlogin.username = users[j].username;
                    userlogin.id = users[j].id;


                    HANDLE col;
                    col = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(col, 4);
                    cout << "\t\t\t\t\t  *****************************************\n";
                    cout << "\t\t\t\t\t  *\t     "" Welcome " << userlogin.username << "    \t\t*\n";
                    cout << "\t\t\t\t\t  *****************************************";
                    loadingBar();
                    SetConsoleTextAttribute(col, 15);
                    sleep_for(nanoseconds(2));
                    sleep_until(system_clock::now() + seconds(1));
                    system("cls");
                    user_menu();
                    break;
                }

            }
        }
        j = 0;
        for (; j < users_numbers; j++)
        {
            if (users[j].email != mail)
            {
                cout << "There is a mistake . Please Enter The email again\n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                compeletlogin(solution);
            }
        }
    }
}
//================================user menu =======================
void user_menu()
{

    int  Choice;
    char choice2;

    cout << "\t\t\t\t\t\tWelcome to Our AirLine System ^_^" << endl;
    cout << "\t\t\t**********************************************************************************\n";
    cout << "\t\t\t\t\t     Please choose from the following Menu" << endl;
    cout << "\t\t\t**********************************************************************************\n";
    cout << "\t\t\t\t1.Show profile Info       \t\t 2.Update profile Info." << endl;
    cout << "\t\t\t\t3.show reservation menu    \t\t 4.search flight " << endl;
    cout << "\t\t\t\t5.display ticket info\t\t 6.display tips and warning" << endl;
    cout << "\t\t\t\t7.log out                    \t\t 8.exit " << endl;
    cout << "\t\t\t\t9.save                        \t\t 10. lets play\n";
    cout << "Please Enter your Choice Number : ";
    cin >> Choice;
    while (Choice < 1 || Choice>10) {

        cout << " Invalid Choice number.\n";
        cout << "****************************************\n";
        cout << " Enter your Choice Again : ";
        cin >> Choice;

    }

    switch (Choice)
    {
        case 1:
            system("cls");
            UsersInfo();
            break;
        case 2:
            system("cls");
            edit_info();

            break;
        case 3:
            system("cls");
            reservation_menu();
            break;
        case 4:
            system("cls");
            searchflights();
            break;
        case 5:
            system("cls");
            ticketinfo();
            break;
        case 6:
            system("cls");
            warning();
            break;
        case 7:
            system("cls");
            log_out();
            break;
        case 8:
            system("cls");
            exit();
            break;
        case 9:
            system("cls");
            system("cls");
            filldata();
            system("cls");
            cout << " \n \t\t\t saved successfully ";
            cout << "to back to home menu press any key | to exit press y : ";
            cin >> choice2;
            if (choice2 == 'y' || choice2 == 'Y')
            {
                cout << "\t\t\t\t                                 Bye:(  \n";
                cout << "\t\t\t***********************************************************************************\n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                exit(0);


            }
            else
            {
                system("cls");
                user_menu();

            }

            break;
        case 10:
            system("cls");
            game();
            break;
        default:
            break;
    }
}
//==================reservation code===========================
void cur_date_time()
{
    time_t tim = time(0);
    tm* gottime = localtime(&tim);
    int second = gottime->tm_sec;
    int minute = gottime->tm_min;
    int hour = gottime->tm_hour;
    int day = gottime->tm_mday;
    int month = gottime->tm_mon + 1;
    int year = gottime->tm_year + 1900;
    string dayname;
    switch (gottime->tm_wday)
    {
        case 0:
            dayname = "Sun";
            break;
        case 1:
            dayname = "Mon";
            break;
        case 2:
            dayname = "Tue";
            break;
        case 3:
            dayname = "Wed";
            break;
        case 4:
            dayname = "Thu";
            break;
        case 5:
            dayname = "Fri";
            break;
        case 6:
            dayname = "Sat";
            break;
        default:
            break;
    }
    reservation_month[flightbooked] = month;
    reservation_date_time[flightbooked] = dayname + " " + to_string(day) + "/" + to_string(month) + "/" + to_string(year) +
                                          " " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);

}
void reservation_menu() {
    int  Choice = 0;


    cout << "\t\t\t\t\t     Please choose from the following Menu" << endl;
    cout << "\t\t\t**********************************************************************************\n";
    cout << "\t\t\t\t\t1.make a reservation  \t\t2.edit reservation" << endl;
    cout << "\t\t\t\t\t3.cancel reservation  \t\t4.previous reservations";
    cout << endl;
    cout << " Please Enter your Choice  : ";
    cin >> Choice;
    while (Choice < 1 || Choice>4) {

        cout << " Invalid Choice number.\n";
        cout << "****************************************\n";
        cout << " Enter your Choice Again : ";
        cin >> Choice;

    }

    switch (Choice) {
        case 1:
            system("cls");
            reservation();
            break;
        case 2:
            system("cls");
            edit_reservation();
            break;
        case 3:
            system("cls");
            cancel_reservation();
            break;
        case 4:
            system("cls");
            previous_reservations();
            break;
        default:
            break;

    }
}
void previous_reservations() {

    cout << "\t\t\t\t\t                 previous reservations" << endl;
    cout << "\t\t\t**********************************************************************************\n";

    for (int i = 0; i < flightbooked; i++)
    {
        cout << "\n\t\t\t\t\tbooked details\n";
        cout << "\n Departure place          : ";
        cout << booked[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << booked[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << booked[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << booked[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << booked[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << booked[i].arrival_date;
        cout << "\n reservation date and time: ";
        cout << "\n reservation date and time: ";
        cout << reservation_date_time[i];
    }
    char choice;
    cout << "\nto edit reservation press (y) and to display ticket info press (a) and to back to main menu press any key : ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {

        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        edit_reservation();
    }
    else if (choice == 'A' || choice == 'a')
    {
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        ticketinfo();
    }
    else {
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        user_menu();
    }
}
void cancel_reservation()
{
    cout << "\t\t\t\t\t                 cancel reservations" << endl;
    cout << "\t\t\t**********************************************************************************\n";
    int choice = 0;
    char choice2;
    for (int i = 0; i < flightbooked; i++) {
        cout << "t\t\t\t\treservation details \n";
        cout << "\n reservation number       : " << i++;
        cout << "\n Departure place          : ";
        cout << booked[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << booked[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << booked[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << booked[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << booked[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << booked[i].arrival_date;
        cout << "\n reservation date and time: ";
        cout << reservation_date_time[i];
    }
    cout << "choose reservation number you want to cancel : ";
    cin >> choice;
    cout << "are you sure you want to cancel this reservation  \n\n";
    cout << "\n Departure place          : ";
    cout << booked[choice - 1].depatureplace;
    cout << "\n Date of flight departure : ";
    cout << booked[choice - 1].departure_date;
    cout << "\n Time of flight departure : ";
    cout << booked[choice - 1].departure_time;
    cout << "\n Arrival place            : ";
    cout << booked[choice - 1].arrivalplace;
    cout << "\n Time of flight arrival   : ";
    cout << booked[choice - 1].arrival_time;
    cout << "\n Date of flight arrival   : ";
    cout << booked[choice - 1].arrival_date;
    cout << "\n reservation date and time: ";
    cout << reservation_date_time[choice - 1];

    cout << "if are you sure press y if you want to ignore cancel press any key : ";
    cin >> choice2;
    if (choice2 == 'Y' || choice2 == 'y')
    {
        booked[choice - 1].depatureplace = nullptr;

        added[choice - 1].departure_date = nullptr;

        booked[choice - 1].departure_time = nullptr;

        booked[choice - 1].arrivalplace = nullptr;

        booked[choice - 1].arrival_time = nullptr;

        booked[choice - 1].arrival_date = nullptr;

        reservation_date_time[choice - 1] = nullptr;
        cout << " Your reservation has been successfully cancelled ";
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        char answer ;
        cout << "press any to return to main menu \n";
        cin >> answer;
        user_menu();

    }
    else
    {
        cout << "Your reservation has not been cancelled";
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        char answer ;
        cout << "press any to return to main menu \n";
        cin >> answer;
        user_menu();
    }

}
void edit_reservation()
{
    int choice = 0;
    int choice2 = 0;
    char choice3;

    for (int i = 0; i < flightbooked; i++)
    {
        cout << "reservation number            : " << i++ << endl;
        cout << "booked details \n";
        cout << "\n Departure place          : ";
        cout << booked[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << booked[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << booked[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << booked[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << booked[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << booked[i].arrival_date;
        cout << "\n booked date and time     : ";
        cout << reservation_date_time[i];
    }
    cout << "\n choose reservation number you want to edit : ";
    cin >> choice;
    system("cls");

    cout << "\nAvailable flights:\n";
    for (int i = 0; i < num_flights; i++) {
        cout << "flight number : " << i + 1;
        cout << "\n Departure place          : ";
        cout << added[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << added[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << added[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << added[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << added[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << added[i].arrival_date;
        cout << "\n------------------------------------------------------------\n";

    }
    cout << "Choose flight number you want to booked : ";
    cin >> choice2;
    cout << "Are you sure you want to replace this reservation ? : \n\n";
    cout << "\n Departure place          : ";
    cout << booked[choice - 1].depatureplace;
    cout << "\n Date of flight departure : ";
    cout << booked[choice - 1].departure_date;
    cout << "\n Time of flight departure : ";
    cout << booked[choice - 1].departure_time;
    cout << "\n Arrival place            : ";
    cout << booked[choice - 1].arrivalplace;
    cout << "\n Time of flight arrival   : ";
    cout << booked[choice - 1].arrival_time;
    cout << "\n Date of flight arrival   : ";
    cout << booked[choice - 1].arrival_date;
    cout << "\n reservation date and time: ";
    cout << reservation_date_time[choice - 1];
    cout << "\n------------------------------------------------------------\n\n";

    cout << "with this : \n\n";

    cout << "\n Departure place          : ";
    cout << added[choice2 - 1].depatureplace;
    cout << "\n Date of flight departure : ";
    cout << added[choice2 - 1].departure_date;
    cout << "\n Time of flight departure : ";
    cout << added[choice2 - 1].departure_time;
    cout << "\n Arrival place            : ";
    cout << added[choice2 - 1].arrivalplace;
    cout << "\n Time of flight arrival   : ";
    cout << added[choice2 - 1].arrival_time;
    cout << "\n Date of flight arrival   : ";
    cout << added[choice2 - 1].arrival_date;
    cout << "\n------------------------------------------------------------\n\n";
    cout << "if are you sure press y if you want to cancel press any key : ";
    cin >> choice3;
    if (choice3 == 'Y' || choice3 == 'y')
    {
        booked[choice - 1].depatureplace = added[choice2 - 1].depatureplace;
        booked[choice - 1].departure_date = added[choice2 - 1].departure_date;
        booked[choice - 1].departure_time = added[choice2 - 1].departure_time;
        booked[choice - 1].arrivalplace = added[choice2 - 1].arrivalplace;
        booked[choice - 1].arrival_time = added[choice2 - 1].arrival_time;
        booked[choice - 1].arrival_date = added[choice2 - 1].arrival_date;
        cout << "your reservation has been updated ";
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        user_menu();
    }
    else {

        cout << "your reservation has not updated ";
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        user_menu();

    }
}
void reservation() {
    int choice = 0;
    char choice2;

    cout << "\n\t\t\t\tAvailable flights:\n";
    for (int i = 0; i < num_flights; i++) {
        cout << "flight number : " << i + 1;
        cout << "\n Departure place          : ";
        cout << added[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << added[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << added[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << added[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << added[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << added[i].arrival_date;
        cout << "\n------------------------------------------------------------\n";

    }
    cout << "\t\t\t\tChoose flight number you want to booked : ";

    cout << "\n\n\t\t\t\t\t\t\tYour answer is : ";
    cin >> choice;
    if (choice < 0 || choice > num_flights) {
        cout << "Invalid choice. Please enter again : ";
        while (true) {
            cout << "\n\n\t\t\t\t\t\t\tYour answer is : ";
            cin >> choice;
        }
    } else {
        cout << "\n now please assign a seat \n";
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        assign_seat();
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        ticketprice();
        booked[flightbooked].depatureplace = added[choice - 1].depatureplace;
        booked[flightbooked].departure_time = added[choice - 1].departure_time;
        booked[flightbooked].departure_date = added[choice - 1].departure_date;
        booked[flightbooked].arrivalplace = added[choice - 1].arrivalplace;
        booked[flightbooked].arrival_time = added[choice - 1].arrival_time;
        booked[flightbooked].arrival_date = added[choice - 1].arrival_date;
        booked[flightbooked].flightnumber = to_string(choice);
        booked[flightbooked].payments = to_string(ticketprice());
        system("cls");

        cout << "t\t\t\t\tbooked details \n";
        cout << "\n flight number     :";
        cout << booked[flightbooked].flightnumber;
        cout << "\n Departure place          : ";
        cout << booked[flightbooked].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << booked[flightbooked].departure_date;
        cout << "\n Time of flight departure : ";
        cout << booked[flightbooked].departure_time;
        cout << "\n Arrival place            : ";
        cout << booked[flightbooked].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << booked[flightbooked].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << booked[flightbooked].arrival_date;
        cout << "\nyour seat(s)                : ";
        cout << Seat_num;
        cout << "\n reservation date and time: ";
        cur_date_time();
        cout << reservation_date_time[flightbooked];

        cout << "\n------------------------------------------------------------\n";
        char choice3;
        cout << "to confirm booking press (y) to cancel press any key ";
        cin >> choice3;
        if (choice3 == 'y' || choice3 == 'Y') {
            char choice4 = ' ';
            cout << "you confirmed successfully\n";
            flightbooked++;
            cout << "to back to main menu press any key | press (y) if you want to make another reservation : ";
            cin >> choice4;
            if (choice4 == 'Y' || choice4 == 'y') {
                system("cls");
                reservation();

            } else {

                system("cls");
                user_menu();

            }
        } else {
            booked[flightbooked].depatureplace.clear();
            booked[flightbooked].departure_time.clear();
            booked[flightbooked].departure_date.clear();
            booked[flightbooked].arrivalplace.clear();
            booked[flightbooked].arrival_time.clear();
            booked[flightbooked].arrival_date.clear();
            booked[flightbooked].flightnumber.clear();
            booked[flightbooked].payments.clear();
            cout << "booked canceled\n";
            cout << "to back to main menu press any key | press y if you want to make another reservation : ";
            char choice5;
            cin >> choice5;
            if (choice5 == 'Y' || choice5 == 'y') {
                system("cls");
                reservation();

            } else {

                system("cls");
                user_menu();

            }
        }
    }
}

// -----------------ticket info--------------------------
void ticketinfo() {

    string answer;
    string clas;
    switch (choseclas) {
        case '1':
            clas = "1stclass";
            break;
        case '3':
            clas = "bussiness";
            break;
        case '4':
            clas = "premium economy";
            break;
        case '2':
            clas = "economy";
            break;
    }
    for (int i = 0; i < flightbooked; i++) {
        cout << "*************The Ticket Of Flight*************" << '\n';
        cout << " Ticket Number                : 202210" << i + 1<<endl;
        cout << " Name                         : " << userlogin.username << endl;
        cout << " ID                           : " << userlogin.id<< endl;
        cout << " Seat Number                  : " << Seat_num[i] << endl;
        cout << " Flight Number                : " << booked[i].flightnumber<< endl;
        cout << " Date and time of reservation : " << reservation_date_time[flightbooked]<< endl;
        cout << " Departure country            : " << booked[i].depatureplace<< endl;
        cout << " Arrival Country              : " << booked[i].arrivalplace<< endl;
        cout << " Departure date               : " << booked[i].departure_date << endl;
        cout << " Arrival date                 : " << booked[i].arrival_date<< endl;
        cout << " Departure time               : " << booked[i].departure_time << endl;
        cout << " Arrival time                 : " << booked[i].arrival_time << endl;
        cout << " Flight long                  : " << booked[i].flightlong << endl;
        cout << " Ticket class                 : " << choseclas<< endl;
        cout << " Ticket price                 : " << booked[i].payments << endl;
        cout<<"---------------------------------------------------------------"<< endl;
    }
    sleep_for(nanoseconds(2));
    sleep_until(system_clock::now() + seconds(1));

    cout << "To Go To the Main Menu Press (y)\n";
    cin >> answer;
    if (answer == "Y" || answer == "y") {
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        user_menu();
    }
}
//==================user info =================================
void UsersInfo() {
    char letter;

    cout << "\t\t\t\t\t\t\t User Account \n";
    cout << "\t\t\t\t ****************************************************\n";
    cout << "Users Info :\n";
    cout << "------------------------------\n";
    cout << "User Name : " << users[j].username << endl;
    cout << "ID : " << lines_u_id << endl;
    cout << "Email :" << users[j].email << endl;
    cout << "Address :" << users[j].address << endl;
    cout << "phone number :" << users[j].number << endl;
    cout << endl;
    sleep_for(nanoseconds(2));
    sleep_until(system_clock::now() + seconds(1));
    cout << "--------------------------------\n";
    cout << "If you want To Edit press (y) | to back to home menu press any key ";
    cin >> letter;
    if (letter == 'y' || letter == 'Y') {
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");

        edit_info();
    }
    else {
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        user_menu();
    }
}
//============================= edit user info ===============================
void edit_info() {
    int choice = 0;
    char choice2;
    string pass;
    cout << "\t\t\t\tchoose what you want to edit : ";
    cout << "\n\t 1. Email \t\t 2.Username \t\t 3. Phone \t\t 4. Address \t\t 5. Password \n";
    cin >> choice;
    while (choice <= 0 || choice > 5) {
        cout << "Invalid input. Please enter a valid choice number : ";
        cin >> choice;
    }

    switch (choice) {

        case 1:
            cout << "\n" << "\t\tEnter new Email : ";
            cin >> users[j].email;
            cout << "\t\t\t\t\tEmail changed successfully \n";
            sleep_for(nanoseconds(2));
            sleep_until(system_clock::now() + seconds(1));
            cout << "if you want to make another edit press (y) | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                edit_info();

            }
            else {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                user_menu();

            }
            break;
        case 2:
            cout << "\n" << "\t\tEnter new Username : ";
            cin >> users[j].username;
            cout << "\t\t\t\t\tUsername changed successfully \n";
            sleep_for(nanoseconds(2));
            sleep_until(system_clock::now() + seconds(1));
            cout << "if you want to make another edit press y | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                edit_info();

            }
            else {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                user_menu();

            }
            break;
        case 3:
            cout << "\n" << "\t\tEnter new Phone : ";
            cin >> users[j].number;
            cout << "\t\t\t\t\tPhone changed successfully \n";
            sleep_for(nanoseconds(2));
            sleep_until(system_clock::now() + seconds(1));
            cout << "if you want to make another edit press y | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                edit_info();

            }
            else {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                user_menu();

            }
            break;
        case 4:
            cout << "\n" << "\t\tEnter new Address : ";
            cin >> users[j].address;
            cout << "\t\t\t\t\tAddress changed successfully \n";
            sleep_for(nanoseconds(2));
            sleep_until(system_clock::now() + seconds(1));
            cout << "if you want to make another edit press y | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                edit_info();

            }
            else {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                user_menu();

            }
            break;
        case 5:

            cout << "\n" << "\t\tEnter new Password : ";
            cin >> pass;
            cout << "\t\tEnter the new password again : ";
            cin >> users[j].password;
            if (pass != users[j].password) {
                while (true) {
                    cout << " password doesn't match enter again ";
                    cout << "\n" << "\t\tEnter new Password : ";
                    cin >> pass;
                    cout << "\t\tEnter the new password again : ";
                    cin >> users[j].password;
                    if (pass == users[j].password)
                        break;
                }
                break;
            }
            cout << "\t\t\t\t\tPassword changed successfully \n";
            sleep_for(nanoseconds(2));
            sleep_until(system_clock::now() + seconds(1));
            cout << "if you want to make another edit press y | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                edit_info();

            }
            else {
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                user_menu();

            }
            break;
        default:;
    }
}
//================================seat user ==================================
void assign_seat() {

    bool isEmpty = false;
    string answer;
    bool isAvail = false;
    do {
        cout << "Assign a Seat Number \n";
        cout << "-----------------------------------\n";
        cout << "Select a Class :\n" << "1.First Class\t\t" << "2.Economy Class\n" << "3.Business Class\t"
             << "4.Economy Premium Class \n";
        cin >> answer;
        if (answer < "1" || answer > "4") {
            cout << "UnAvailable Choice \n";
        }
    } while (answer < "1" || answer > "4");
    if (answer == "1") {

        choseclas = '1';

        do {
            cout << "Available Seats In First Class : \n";
            cout << "---------------------------\n";
            for (int i = 0; i < (line_1); i++) {
                if (Seats_of_F_Class[0] == " ") {
                    cout << "Sorry! .There is no Available Seat ( reservation Completed)\n";
                    isEmpty = true;
                }
                if (i % 5 == 0) {
                    cout << endl;
                }
                if (i == (line_1)-1) {
                    cout << Seats_of_F_Class[i];
                    break;
                }
                cout << Seats_of_F_Class[i] << "\t ";
            }
            if (isEmpty)
                break;
            cout << endl;
            cout << "****************************\n";
            cout << "Select Your Seat:\n";
            cin >> Seat_num;

            for (int i = 0; i < (line_1); i++) {
                if (Seat_num == Seats_of_F_Class[i]) {
                    booked_F_Seats[Chosen_F_Seat++] = Seat_num;
                    isAvail = true;
                    break;
                }
            }

            if (isAvail) {
                cout << " Your Seat number is " << Seat_num << " In  First Class \n";
            }
            else {
                cout << "Unavailable Seat number . please Select another Seat \n";
                continue;
            }
        } while (!isAvail);
        for (int s = 0; s < (line_1); s++) {
            if (Seat_num == Seats_of_F_Class[s]) {
                for (int k = s; k < (line_1); k++)
                    Seats_of_F_Class[k] = Seats_of_F_Class[k + 1];
            }
        }
        line_1--;
    }
    else if (answer == "2") {

        choseclas = '2';

        do {

            cout << "Available Seats In Economy Class: \n";
            cout << "---------------------------\n";
            for (int i = 0; i < line_2; i++) {
                if (Seats_of_Eco_Class[0] == " ") {
                    cout << "Sorry! .There is no Available Seat ( reservation Completed)\n";
                    isEmpty = true;
                }
                if (i % 5 == 0) {
                    cout << endl;
                }

                if (i == line_2 - 1) {
                    cout << Seats_of_Eco_Class[i];
                    break;
                }
                cout << Seats_of_Eco_Class[i] << "\t";
            }
            if (isEmpty)
                break;
            cout << endl;
            cout << "****************************\n";
            cout << "Select Your Seat:\n";
            cin >> Seat_num;

            for (int i = 0; i < line_2; i++) {
                if (Seat_num == Seats_of_Eco_Class[i]) {
                    booked_Eco_Seats[Chosen_Eco_Seat++] = Seat_num;
                    isAvail = true;
                    break;
                }
            }

            if (isAvail) {
                cout << " Your Seat number is " << Seat_num << " In Economy Class\n";

            }
            else {
                cout << "Unavailable Seat number . please Select another Seat \n";
                continue;
            }

        } while (!isAvail);

        for (int s = 0; s < line_2; s++) {
            if (Seat_num == Seats_of_Eco_Class[s]) {

                for (int k = s; k < line_2; k++)
                    Seats_of_Eco_Class[k] = Seats_of_Eco_Class[k + 1];
            }

        }
        line_2--;

    }
    else if (answer == "3") {

        choseclas = '3';

        do {

            cout << "Available Seats In Business Class: \n";
            cout << "-----------------------------------------\n";
            for (int i = 0; i < line_3; i++) {
                if (Seats_of_B_Class[0] == " ") {
                    cout << "Sorry! .There is no Available Seat ( reservation Completed)\n";
                    isEmpty = true;
                }
                if (i % 5 == 0) {
                    cout << endl;
                }
                if (i == line_3 - 1) {
                    cout << Seats_of_B_Class[i];
                    break;
                }
                cout << Seats_of_B_Class[i] << "\t";
            }
            if (isEmpty)
                break;
            cout << endl;
            cout << "****************************\n";
            cout << "Select Your Seat:\n";
            cin >> Seat_num;

            for (int i = 0; i < line_3; i++) {
                if (Seat_num == Seats_of_B_Class[i]) {
                    booked_B_Seats[Chosen_B_Seat++] = Seat_num;
                    isAvail = true;
                    break;
                }
            }

            if (isAvail) {
                cout << " Your Seat number is " << Seat_num << " In  Bussiness Class\n";

            }
            else {
                cout << "Unavailable Seat number . please Select another Seat \n";
                continue;
            }

        } while (!isAvail);

        for (int s = 0; s < line_3; s++) {
            if (Seat_num == Seats_of_B_Class[s]) {

                for (int k = s; k < line_3; k++)
                    Seats_of_B_Class[k] = Seats_of_B_Class[k + 1];
            }

        }
        line_3--;
    }
    else {

        choseclas = '4';
        do {

            cout << "Available Seats In Economy Premium Class: \n";
            cout << "-----------------------------------------\n";
            for (int i = 0; i < line_4; i++) {
                if (Seats_of_Eco_Pre_Class[0] == " ") {
                    cout << "Sorry! .There is no Available Seat ( reservation Completed)\n";
                    isEmpty = true;
                }
                if (i % 5 == 0) {
                    cout << endl;
                }
                if (i == line_4 - 1) {
                    cout << Seats_of_Eco_Pre_Class[i];
                    break;
                }
                cout << Seats_of_Eco_Pre_Class[i] << "\t";
            }
            if (isEmpty)
                break;
            cout << endl;
            cout << "****************************\n";
            cout << "Select Your Seat:\n";
            cin >> Seat_num;

            for (int i = 0; i < line_4; i++) {
                if (Seat_num == Seats_of_Eco_Pre_Class[i]) {
                    booked_Eco_Pre_Seats[Chosen_Eco_Pre_Seat++] = Seat_num;
                    isAvail = true;
                    break;
                }
            }

            if (isAvail) {
                cout << " Your Seat number is " << Seat_num << " In Economy Premium Class\n";

            }
            else {
                cout << "Unavailable Seat number . please Select another Seat \n";
                continue;
            }

        } while (!isAvail);

        for (int s = 0; s < line_4; s++) {
            if (Seat_num == Seats_of_Eco_Pre_Class[s]) {

                for (int k = s; k < line_4; k++)
                    Seats_of_Eco_Pre_Class[k] = Seats_of_Eco_Pre_Class[k + 1];
            }

        }
        line_4--;
    }
    cout << "if you want to assign another another seat press (y) | Press any key to continue  \n";
    cin >> answer;
    if (answer == "y" || answer == "Y") {
        assign_seat();
    }

}
//---------------------------------------------------------------------
void warning() {
    string answer;
    cout << "These are some tips that can help you during your travels :\n ";
    cout << "1.Keep the necessary papers and documents in your carry-on bag\n";
    cout
            << "2.You must check the documents necessary for travel and whether you need to obtain a visa to enter the country to which you will travel, well in advance of the date of travel, as well as ensure the validity of the passport\n";
    cout
            << "3.Take only the necessary supplies (please note that your registered baggage should not exceed 32 kg per piece, according to occupational safety rules)\n";
    cout
            << "4.We advise you to prepare the bags quietly a few days before travel, and also distinguish your bags from other bags. We also recommend placing a label bearing your information in case your bags are lost.\n";
    cout
            << "5.it is better to be at the airport 3 hours before the flight time in the case of international flights and 2 hours on domestic flights, in order to complete your travel procedures, register bags, reach the boarding hall, and avoid any delays in procedures that would prevent you from catching your plane.\n";
    cout
            << "6.It is advised to take a photocopy of the passport and ticket and keep the photocopy in a different place than the one you put the original in, and this will be very useful if you lose one of them.\n";
    cout << "These are things that are forbidden to take with you on the flight:\n";
    cout << "1.Compressed gases (flammable, non-flammable and toxic) such as aerosols, camping gas\n";
    cout << "2.Firearms, ammunition, swords and knives.\n";
    cout << "3.Explosives, incendiary materials, flammable materials, toxic materials, and compressed gases.\n";
    cout << "4.Chemical reagents , Active and radioactive materials\n";
    cout << "5.Dangerous goods (such as mercury, toxic substances, magnetized materials or harmful substances)\n";
    cout << "6.Bags with alarms or lithium batteries installed\n";
    cout
            << "7.All liquid and gel materials, toothpaste, liquid cosmetics, and perfumes are not allowed to be carried in hand luggage.\n";
    cout << "8.Cigarette lighters are not allowed in all baggage.\n";
    cout
            << "9.Mobility entertainment devices such as electric personal balance skateboards are prohibited to be used on EgyptAir flights as cabin baggage or as carry-on baggage.\n";
    cout
            << "We hope that you have benefited from these tips and warnings, and we wish you a successful flight without any problems\n";
    sleep_for(nanoseconds(2));
    sleep_until(system_clock::now() + seconds(1));
    cout << "to go to main menu press y \n";
    cin >> answer;
    if (answer == "y" || answer == "Y") {
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
        user_menu();
    }
}
//===========================================================================
//===========================================================================
double ticketprice() {
    PaymentMethod cash = { "Cash", 0 };
    PaymentMethod credit_card = { "Credit Card", 3.5 };
    PaymentMethod paypal = { "PayPal", 2.9 };
    PaymentMethod fawry = { "fawry", 2.9 };
    PaymentMethod bitcoin = { "Bitcoin", 1.5 };
    int type;
    double amount = chooseclasses();
    char method;
    method = paymenttype();
    string answer;
    double payes ;
    switch (method) {
        case '1':
            payes = calculateFee(amount, cash);
            break;
        case '2':
            payes = calculateFee(amount, credit_card);
            break;
        case '3':
            payes = calculateFee(amount, paypal);
            break;
        case '4':
            payes = calculateFee(amount, bitcoin);
            break;
        case '5':
            payes = calculateFee(amount, fawry);
            break;
    }
    cout << "your ticket price is : " << payes << endl;
    sleep_for(nanoseconds(2));
    sleep_until(system_clock::now() + seconds(1));
    cout << "to go to main menu press y ";
    cin >> answer;
    if (answer == "y" || answer == "Y")
        sleep_for(nanoseconds(2));
    sleep_until(system_clock::now() + seconds(1));
    system("cls");
    user_menu();
    return payes;
}
//===========================================================================
double chooseclasses() {
    char reply;
    double amount;
    cout << " \n 1.if the age between  0 and 10  \n 2.if the age more than 10  \n ";
    cout << "choose your range of age :" ;
    cin >> reply;
    switch (reservation_month[flightbooked]) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 11:
        case 12:
            switch (choseclas) {
                case 1:

                    if (reply == 1) {
                        amount = 7000;
                    }
                    else if (reply == 2) {
                        amount = 6000;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
                case 2:

                    if (reply == 1) {
                        amount = 6000;
                    }
                    else if (reply == 2) {
                        amount = 5000;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
                case 3:

                    if (reply ==1) {
                        amount = 4000;
                    }
                    else if (reply == 2) {
                        amount = 2500;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
                case 4:

                    if (reply == 1) {
                        amount = 3000;
                    }
                    else if (reply == 2 ) {
                        amount = 2500;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
            }
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            switch (choseclas) {
                case 1:

                    if (reply == 1) {
                        amount = 5000;
                    }
                    else if (reply == 2) {
                        amount = 4000;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
                case 2:

                    if (reply == 1) {
                        amount = 3000;
                    }
                    else if (reply == 2) {
                        amount = 2500;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
                case 3:

                    if (reply == 1) {
                        amount = 2000;
                    }
                    else if (reply == 2) {
                        amount = 1500;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
                case 4:

                    if (reply == 1) {
                        amount = 2000;
                    }
                    else if (reply == 2) {
                        amount = 1500;
                    }
                    else {
                        cout << "there is a mistake please try again \n";
                        chooseclasses();
                    }
                    break;
            }
            break;
    }
    if (correct == 8)
    {
        amount = (10 * amount) / 100;
    }
    return amount;
}
//===========================================================================
char paymenttype() {
    bool done = true;
    string answer;
    do {
        cout
                << " \n please replay with method type\n 1:cash  \n 2:credit card \n 3:paypal \n 4:bitcoin  \n 5:fawry \n  ";
        cin >> answer;
        if (answer == "1") {
            return '1';
        }
        else if (answer == "2") {
            return '2';
        }
        else if (answer == "3") {
            return '3';
        }
        else if (answer == "4") {
            return '4';
        }
        else if (answer == "5") {
            return '5';
        }
        else {
            cout << "\n invalid answer please try again\n";
            done = false;
        }

    } while (done == false);
}
//===========================================================================
double calculateFee(double amount, PaymentMethod method) {
    double fee, final;
    fee = amount * method.fee_percent / 100;
    final = amount + fee;

    return final;

}
//===========================================================================
//-----------------------------------admin code-----------------------------------
//---------- user list ---------------
void user_list() {
    char choice;
    cout << "\t\t\t\t                          User list  \n";
    cout << "\t\t\t**********************************************************************\n";
    for (int i = 0; i < users_numbers; i++) {
        cout << i + 1;
        cout << ".";
        cout << "\nEmail    : " << users[i].email;
        cout << "\nUsername : " << users[i].username;
        cout << "\nPhone    : " << users[i].number;
        cout << "\nAddress  : " << users[i].address;
        cout << "\nPassword : " << users[i].password << endl;
        cout << "*************************\n";
    }

    cout << "to edit any user  press (y) | to  back to home page press any key \n";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        system("cls");
        modify_users();
    }
    else {
        system("cls");
        admin_menu();

    }
}
//==========================================================================
//--------------------------- exit ---------------------------
int exit() {
    char choice;
    cout << " if you don't save press (y) to exit after save | press any key to exit : ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {

        filldata();
        exit(0);
    }
    else {
        cout << "\t\t\t\t                                 Bye:(  \n";
        cout << "\t\t\t***********************************************************************************\n";
        sleep_for(nanoseconds(2));
        sleep_until(system_clock::now() + seconds(1));
        exit(0);
    }
    return 0;
}
//==========================================================================
//------------------------add admin ----------------------------------
void add_admin() {
    char choice;
    char choice2;
    if (admin_number < 11) {
        cout << "\t\t\t\t                      Add New Admin  \n";
        cout << "\t\t\t**********************************************************************\n";
        cout << "\t\t\t\t\t\t enter the username : ";
        cin >> admins[admin_number].username;
        cout << "\t\t\t\t\t\t enter the email : ";
        cin >> admins[admin_number].email;
        cout << "\t\t\t\t\t\t enter the password : ";
        cin >> admins[admin_number].password;
        admin_number++;
        cout << "\n\t\t\t\t\t\tNew admin add successfully\n\n";
        cout << "\t\t\t**********************************************************************\n";
        cout << "if you want to add another admin press (y) | to back to home menu press any key : ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            system("cls");
            add_admin();
        }
        else {
            system("cls");
            admin_menu();
        }
    }
    else {
        cout << "\t\t\t\tmaximum admins number reached ";
        cout << " press any key to back to home menu \n";
        cin >> choice2;
        if (choice2) {
            system("cls");
            admin_menu();
        }
    }
}
//==========================================================================
//------------------------------ admin list ------------------------------------
void admins_list() {
    char choice;
    cout << "\t\t\t\t                      Admin list  \n";
    cout << "\t\t\t**********************************************************************\n";
    cout << endl;
    for (int i = 0; i < admin_number; i++) {
        cout << i + 1;
        cout << ".\n" << "Email : " << admins[i].email;
        cout << "\n""Username : " << admins[i].username;
        cout << "\n""Password : " << admins[i].password << endl;
        cout << "*************************\n";
    }
    cout << endl;

    cout << "if you want to edit any admins press (y) | to  back to home press any key : ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        system("cls");
        modify_admins();
    }
    else {
        system("cls");

        admin_menu();
    }
}
//==========================================================================
//-------------------------- modify admin ----------------------------------------
int modify_admins() {

    cout << "\n\n\t\t\t  **********************************************************************\n";
    cout << "\t\t\t  ************************** Modify Admin ******************************\n";
    for (int i = 0; i < admin_number; i++) {
        cout << i + 1;
        cout << ".\n" << "Email : " << admins[i].email;
        cout << "\n""Username : " << admins[i].username;
        cout << "\n""Password : " << admins[i].password << endl;
        cout << "*************************\n";
    }
    cout << "choose admin number you want to edit : ";
    cin >> choice_modify;
    while (choice_modify <= 0 || choice_modify > admin_number) {
        cout << "Invalid input. Please enter a valid admin number: ";

        cin >> choice_modify;
    }
    switch (choice_modify) {
        case 1:
            system("cls");
            modify_admin();
            break;
        case 2:
            system("cls");
            modify_admin();
            break;
        case 3:
            system("cls");
            modify_admin();
            break;
        case 4:
            system("cls");
            modify_admin();
            break;
        case 5:
            system("cls");
            modify_admin();
            break;
        case 6:
            system("cls");
            modify_admin();

            break;
        case 7:
            system("cls");
            modify_admin();
            break;
        case 8:
            system("cls");
            modify_admin();
            break;
        case 9:
            system("cls");
            modify_admin();
            break;
        case 10:
            system("cls");
            modify_admin();
            break;
        default:
            system("cls");
            modify_admin();
            break;
    }
    return 0;
}
//==========================================================================
//---------------------------- admin menu ------------------------------
int admin_menu() {
    cout << "\n\t\t\t**********************************************************************\n";
    cout << "\t\t\t\t               Welcome to Admin Home page ^_^  \n";
    cout << "\t\t\t**********************************************************************\n";
    cout << endl;
    cout << "\t\t\t\t\t Please Choose from the following Menu\n";
    cout << "\t\t\t\t--------------------------------------------------------\n";
    cout << "\t\t\t\t\t1. Add Flights\t\t2. Flights Details\n";
    cout << "\t\t\t\t\t3. Modify Flights \t4. Modify users\n";
    cout << "\t\t\t\t\t5. Admins list\t\t6. Users List\n";
    cout << "\t\t\t\t\t7. Add admins\t\t8. Modify Admins\n";
    cout << "\t\t\t\t\t9. seats\t\t10. Save\n";
    cout << "\t\t\t\t\t11. Log out\t\t12. Exit\n";

    int choice;
    cout << "\n\t\t\t\t\t\t Enter Your Choice : ";
    cin >> choice;
    cout << endl;
    while (choice < 1 || choice > 12) {
        cout << "\t\t\t\tYou entered an invalid choice. Please choose again.\n";
        cout << "\n\t\t\t\t\t\t Enter Your Choice : ";

        cin >> choice;
        cout << endl;
    }
    switch (choice) {
        case 1:
            system("cls");
            addflight();
            break;
        case 2:
            system("cls");
            flights_details();
            break;
        case 3:
            system("cls");
            menu_modify_flights();
            break;
        case 4:
            system("cls");
            modify_users();
            break;
        case 5:
            system("cls");
            admins_list();
            break;
        case 6:
            system("cls");
            user_list();
            break;
        case 7:
            system("cls");
            add_admin();
            break;
        case 8:
            system("cls");
            modify_admins();
            break;
        case 9:
            system("cls");
            seats();
            break;
        case 10:
            char choice;
            system("cls");
            filldata();
            system("cls");
            cout << " \n \t\t\t saved successfully ";
            cout << "to back to home menu press any key | to exit press y : ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                cout << "\t\t\t\t                                 Bye:(  \n";
                cout
                        << "\t\t\t***********************************************************************************\n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                exit(0);


            }
            else {
                system("cls");
                admin_menu();

            }

            break;
        case 11:
            system("cls");
            log_out();
            break;
        case 12:
            system("cls");
            exit();
            break;
        default:;
    }
}
//==========================================================================
//------------------------- menu modify flights -----------------------------
void menu_modify_flights() {
    int numberofoption;
    cout << "                                               Updating Flights" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "Available options " << endl;
    cout << "1. Delete flights" << endl;
    cout << "2. Modify flights" << endl;
    while (true) {
        cout << "Enter the number of option you want : ";
        cin >> numberofoption;
        while (numberofoption < 1 || numberofoption > 2) {
            cout << "\t\t\t\tYou entered an invalid choice. Please choose again.\n";
            cout << "\n\t\t\t\t\t\t Enter Your Choice : ";
            cin >> numberofoption;

        }

        switch (numberofoption) {
            case 1: {
                system("cls");
                deletflight();
                break;
            }
            case 2: {
                system("cls");
                modifyflight();
                break;
            }
            default:;
        }
    }
}
//==========================================================================
//-------------------------- add flights ----------------------------------
void addflight() {
    string option;
    cout
            << "\n                                                            Adding Flights                                              "
            << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "Add new flight \n" << endl;
    cout << "Add Departure place : ";
    cin.ignore();
    getline(cin, added[num_flights].depatureplace);
    cout << "\nAdd date of Flight departure e.g(12/02/2023) : ";
    getline(cin, added[num_flights].departure_date);
    cout << "\nAdd time of flight departure e.g(02:30) : ";
    getline(cin, added[num_flights].departure_time);
    cout << "\nAdd Arrival place : ";
    getline(cin, added[num_flights].arrivalplace);
    cout << "\nAdd date of Flight arrive e.g(12/02/2023) : ";
    getline(cin, added[num_flights].arrival_date);
    cout << "\nAdd time of flight arrive e.g(02:30) : ";
    getline(cin, added[num_flights].arrival_time);

    num_flights++;
    //===================================================
    //===================================================
    cout << "If you want to add another flight press (y) | Press any key if you want the main menu :";
    cin >> option;
    cin.ignore();
    if (option == "y" || option == "Y") {
        system("cls");
        addflight();
    }
    else {
        system("cls");
        admin_menu();
    }
}
//==========================================================================
//------------------- delete flight ---------------------------
void deletflight() {
    char remenu;
    count1 = num_flights;
    system("cls");

    for (int i = 0; i < num_flights - shifting; i++) {
        cout << "The number of flight : " << i + 1;
        cout << "\n Departure place          : ";
        cout << added[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << added[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << added[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << added[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << added[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << added[i].arrival_date;
        cout << "\n------------------------------------------------------------\n";

    }
    int delflight;
    cout << "Which flight you want to delete:";
    cin >> delflight;
    added[count1 - shifting].arrivalplace;
    added[count1 - shifting].arrival_date;
    added[count1 - shifting].arrival_time;
    added[count1 - shifting].depatureplace;
    added[count1 - shifting].departure_date;
    added[count1 - shifting].departure_time;

    for (int i = 0; i <= num_flights - shifting; i++) {
        if (i == delflight - 1) {
            for (int j = i; j < num_flights; j++) {
                added[j].arrivalplace = added[j + 1].arrivalplace;
                added[j].arrival_date = added[j + 1].arrival_date;
                added[j].arrival_time = added[j + 1].arrival_time;
                added[j].depatureplace = added[j + 1].depatureplace;
                added[j].departure_date = added[j + 1].departure_date;
                added[j].departure_time = added[j + 1].departure_time;
            }
        }
    }
    shifting++;
    cout << "=========================================================\n";
    for (int c = 0; c < num_flights - shifting; c++) {
        cout << "The number of flight : " << c + 1;
        cout << "\n Departure place          : ";
        cout << added[c].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << added[c].departure_date;
        cout << "\n Time of flight departure : ";
        cout << added[c].departure_time;
        cout << "\n Arrival place            : ";
        cout << added[c].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << added[c].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << added[c].arrival_date;
        cout << "\n------------------------------------------------------------\n";
    }
    cout << "If you want to delete another flight press (y) you want to return to the main menu press any key: ";
    cin >> remenu;
    if (remenu == 'y' || remenu == 'Y') {
        system("cls");
        deletflight();
    }
    else {
        system("cls");
        admin_menu();
    }

}
//==========================================================================
//--------------------- modify flight ----------------------------
void modifyflight() {
    int modify;
    int choice;
    char remenu;
    system("cls");
    for (int i = 0; i < num_flights - shifting; i++) {
        cout << "The number of flight : " << i + 1;
        cout << "\n Departure place          : ";
        cout << added[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << added[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << added[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << added[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << added[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << added[i].arrival_date;
        cout << "\n------------------------------------------------------------\n";
    }
    cout << "Which flight you want to modify:";
    cin >> modify;
    cout << "1. Departure place\t\t2. Date of flight departure\t\t3.Time of flight departure\n";
    cout << "4. Arrival place  \t\t5. Date of flight arrival  \t\t6.Time of flight arrival\n";
    cout << "choose what you want to modify : ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Enter new departure place : ";
            cin.ignore();
            getline(cin, added[modify - 1].depatureplace);
            break;

        case 2:
            cout << "Enter new departure date exp(12/02/2023) : ";
            cin .ignore();
            getline(cin, added[modify - 1].departure_date);
            break;

        case 3:
            cout << "Enter new departure time exp(02:30) : ";
            cin .ignore();
            getline(cin, added[modify - 1].departure_time);
            break;
        case 4:
            cout << "Enter new Arrival place :";
            cin .ignore();
            getline(cin, added[modify - 1].arrivalplace);
            break;
        case 5:
            cout << "Enter new departure date exp(12/02/2023) : ";
            cin .ignore();
            getline(cin, added[modify - 1].arrival_date);

            break;
        case 6:
            cout << "Enter new departure time exp(02:30) : ";
            cin .ignore();
            getline(cin, added[modify - 1].arrival_time);
            break;
    }
    for (int i = 0; i < num_flights - shifting; i++) {
        cout << "The number of flight : " << i + 1;
        cout << "\n Departure place          : ";
        cout << added[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << added[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << added[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << added[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << added[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << added[i].arrival_date;
        cout << "\n------------------------------------------------------------\n";
    }
    cout << "If you want to make another edit press   (y) | to return to the main menu press any key : ";
    cin >> remenu;
    if (remenu == 'y' || remenu == 'Y') {
        system("cls");
        modifyflight();
    }
    else {
        admin_menu();}
}
//==========================================================================
//----------------------------- modify admin---------------------------
void modify_admin() {
    int choice2;
    char choice3;
    cout << "\n\t\t 1. email \t\t 2.username \t\t 3. password \n";
    cout << "\n\t\t\t\tchoose what you want to edit : ";
    cin >> choice2;
    if (choice2 == 1) {
        cout << ".\n" << "Enter new Email : ";
        cin >> admins[choice_modify - 1].email;
        cout << "\t\t\t\tEmail changed successfully \n";

    }
    else if (choice2 == 2) {
        cout << ".\n" << "Enter new username : ";
        cin >> admins[choice_modify - 1].username;
        cout << "\t\t\t\tusername changed successfully \n";
    }
    else {
        cout << ".\n" << "Enter new password : ";
        cin >> admins[choice_modify - 1].password;
        cout << "\t\t\t\tpassword changed successfully \n";
    }
    cout << "to make another edit press (y) | to back to home menu press any key : ";
    cin >> choice3;
    if (choice3 == 'y' || choice3 == 'Y') {
        system("cls");
        modify_admins();
    }
    else {
        system("cls");
        admin_menu();
    }
}
//==========================================================================
void searchflights() {
    string d_date;
    string choice;
    cout << "Search available flight by the date exp(12/02/2023) : ";
    cin >> d_date;
    for (int i = 0; i < num_flights; i++) {
        if (d_date == added[i].departure_date) {
            cout << i + 1 << ". From" << added[i].depatureplace << "to" << added[i].arrivalplace << " on "
                 << added[i].departure_date
                 << " at " << added[i].departure_time;

        }
    }
    cout << "if you wanna return to main menu press any key : ";
    cin >> choice;
    user_menu();
}
//==========================================================================
//---------------------- flights details -----------------------
void flights_details() {

    char choice ;

    for (int i = 0; i < num_flights - shifting; i++) {
        cout << "The number of flight : " << i + 1;
        cout << "\n Departure place          : ";
        cout << added[i].depatureplace;
        cout << "\n Date of flight departure : ";
        cout << added[i].departure_date;
        cout << "\n Time of flight departure : ";
        cout << added[i].departure_time;
        cout << "\n Arrival place            : ";
        cout << added[i].arrivalplace;
        cout << "\n Time of flight arrival   : ";
        cout << added[i].arrival_time;
        cout << "\n Date of flight arrival   : ";
        cout << added[i].arrival_date;
        cout << "\n------------------------------------------------------------\n";

    }
    cout << "\t\t\t\t\t to back to home menu press any key : ";
    cin >> choice;
    while (true) {
        system("cls");
        admin_menu();
        break;
    }
}
//==========================================================================
//-------------------- modify users ----------------------------------------
void modify_users() {
    int choice = 0;
    char choice2 ;
    cout << "\n\n\t\t\t  **********************************************************************\n";
    cout << "\t\t\t  ************************** Modify users ******************************\n";
    for (int i = 0; i < users_numbers; i++) {
        cout << i + 1;
        cout << ".";
        cout << "\nEmail    : " << users[i].email;
        cout << "\nUsername : " << users[i].username;
        cout << "\nPhone    : " << users[i].number;
        cout << "\nAddress  : " << users[i].address;
        cout << "\nPassword : " << users[i].password << endl;
        cout << "*************************\n";
    }
    cout << "choose user number you want to edit : ";
    cin >> choice_modify;
    while (choice_modify <= 0 || choice_modify > users_numbers) {
        cout << "Invalid input. Please enter a valid user number: ";
        cin >> choice_modify;
    }
    cout << "\t\t\t\tchoose what you want to edit : ";
    cout << "\n\t 1. Email \t\t 2.Username \t\t 3. Phone \t\t 4. Address \t\t 5. Password \n";
    cin >> choice;
    while (choice <= 0 || choice > 5) {
        cout << "Invalid input. Please enter a valid choice number : ";
        cin >> choice;
    }

    switch (choice) {

        case 1:
            cout << "\n" << "\t\tEnter new Email : ";
            cin >> users[choice_modify - 1].email;
            cout << "\t\t\t\t\tEmail changed successfully \n";
            cout << "if you want to make another edit press (y) | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                system("cls");
                modify_users();

            }
            else {
                system("cls");
                admin_menu();

            }
            break;
        case 2:
            cout << "\n" << "\t\tEnter new Username : ";
            cin >> users[choice_modify - 1].username;
            cout << "\t\t\t\t\tUsername changed successfully \n";
            cout << "if you want to make another edit press (y) | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                system("cls");
                modify_users();

            }
            else {
                system("cls");
                admin_menu();

            }
            break;
        case 3:
            cout << "\n" << "\t\tEnter new Phone : ";
            cin >> users[choice_modify - 1].number;
            cout << "\t\t\t\t\tPhone changed successfully \n";
            cout << "if you want to make another edit press (y) | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                system("cls");
                modify_users();

            }
            else {
                system("cls");
                admin_menu();

            }
            break;
        case 4:
            cout << "\n" << "\t\tEnter new Address : ";
            cin >> users[choice_modify - 1].address;
            cout << "\t\t\t\t\tAddress changed successfully \n";
            cout << "if you want to make another edit press (y) | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                system("cls");
                modify_users();

            }
            else {
                system("cls");
                admin_menu();

            }
            break;
        case 5:
            cout << "\n" << "\t\tEnter new Password : ";
            cin >> users[choice_modify - 1].password;
            cout << "\t\t\t\t\tPassword changed successfully \n";
            cout << "if you want to make another edit press (y) | to back to home menu press any key : ";
            cin >> choice2;
            if (choice2 == 'Y' || choice2 == 'y') {
                system("cls");
                modify_users();

            }
            else {
                system("cls");
                admin_menu();

            }
            break;
        default:;
    }
}
//==========================================================================
//------------------------------ log out  --------------------------------------
void log_out() {
    system("cls");
    char choice;
    cout << "\t\t------------------------------ log out  -------------------------------------- \n";
    cout << " if you dont save press (y) to save after log out  | press any key to log out : ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {

        filldata();
        home();

    }
    else {

        home();

    }
}
//==================================================================================
//--------------------------- seats ---------------------------------
void seats() {
    int choice = 0;
    cout << "  \n                                             \t\t Seats" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "\t\t\t\t\t 1. Add seats \t\t\t\t 2. delete seats \n";
    cout << "choose from menu : ";

    cin >> choice;
    while (choice < 1 || choice >= 3) {
        cout << "\t\t\t\tYou entered an invalid choice. Please choose again.\n";
        cout << "\n\t\t\t\t\t\t Enter Your Choice : ";
        cin >> choice;
        cout << endl;
    }

    switch (choice) {
        case 1:
            system("cls");
            add_Seats();

            break;
        case 2:
            system("cls");
            delete_seats();

            break;
    }
}
//-----------------------------------------------------------
void add_Seats() {
    int choice;
    cout << "  \n                                             \t\tAdd Seats" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------"
            << endl;
    cout << "\n\t\t\t\t\t1. First Class\t\t2. Economy Class\n";
    cout << "\t\t\t\t\t3. Business Class \t4. Economy Premium Class\n\n";
    cout << "Select the Class You want to add Seats to : ";
    cin >> choice;
    while (choice > 4 || choice < 1) {
        cout << "Invalid choice. Please enter a number again : ";
        cin >> choice;
    }

    switch (choice) {
        case 1:
            Seats_F();
            break;
        case 2:
            Seats_Eco();
            break;
        case 3:
            Seats_B();
            break;
        case 4:
            Seats_Eco_Pre();
            break;
        default:
            cout << "Invalid choice.\n";
    }
}
//--------------------------- delete seats ------------
void delete_seats() {

    string Seat;
    char letter;
    int choice = 0;
    cout << "  \n                                             \t\tdelete Seats" << endl;
    cout
            << "------------------------------------------------------------------------------------------------------------------------"
            << endl;

    cout << "\n\t\t\t\t\t1. First Class\t\t2. Economy Class\n";
    cout << "\t\t\t\t\t3. Business Class \t4. Economy Premium Class\n\n";
    cout << "choose class you want : ";
    cin >> choice;
    while (choice < 1 || choice >= 5) {
        cout << "\t\t\t\tYou entered an invalid choice. Please choose again.\n";
        cout << "\n\t\t\t\t\t\t Enter Your Choice : ";
        cin >> choice;
        cout << endl;
    }
    switch (choice) {

        case 1:
            cout << "Seats Of First Class :\n";

            for (int l = 0; l < line_1; l++) {
                if (l == line_1 - 1) {
                    cout << Seats_of_F_Class[l];
                    cout << endl;
                    break;
                }
                if (l % 5 == 0)
                    cout << endl;
                cout << Seats_of_F_Class[l] << "\t";
            }
            cout << "\nEnter the seat you want to delete : ";
            cin >> Seat;

            for (int l = 0; l < line_1; l++) {
                if (Seat == Seats_of_F_Class[l]) {

                    for (int l_line = l; l_line < line_1; l_line++)
                        Seats_of_F_Class[l_line] = Seats_of_F_Class[l_line + 1];

                }
            }
            line_1--;
            cout << "If you want to confirm the delete ,press (y)and to cancel update press any key  : ";
            cin >> letter;
            if (letter == 'y' || letter == 'Y') {
                for (int l = 0; l < line_1; l++) {
                    if (l % 5 == 0)
                        cout << endl;
                    cout << Seats_of_F_Class[l] << "\t";
                }
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                cout << "if you want to delete another seat press y and to return to main menu press any key \n";
                cin >> letter;
                if (letter == 'y' || letter == 'Y') {
                    system("cls");
                    delete_seats();
                } else {
                    system("cls");
                    admin_menu();
                }

            } else {
                cout << "Update cancelled \n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                admin_menu();
                break;
            }
            break;
        case 2:
            cout << "Seats Of Economy Class :\n";

            for (int l = 0; l < line_2; l++) {
                if (l == line_2 - 1) {
                    cout << Seats_of_Eco_Class[l] << endl;
                    break;
                }
                if (l % 5 == 0)
                    cout << endl;
                cout << Seats_of_Eco_Class[l] << "\t";
            }
            cout << "\nEnter the seat you want to delete : ";
            cin >> Seat;
            for (int l = 0; l < line_2; l++) {
                if (Seat == Seats_of_Eco_Class[l]) {

                    for (int l_line = l; l_line < line_2; l_line++)
                        Seats_of_Eco_Class[l_line] = Seats_of_Eco_Class[l_line + 1];
                }
            }
            line_2--;
            cout << "If you want to confirm the delete ,press (y) and to cancel update press any key :\n ";
            cin >> letter;
            if (letter == 'y' || letter == 'Y') {
                for (int l = 0; l < line_2; l++) {
                    if (l % 5 == 0)
                        cout << endl;
                    cout << Seats_of_Eco_Class[l] << "\t";
                }
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                cout << "if you want to delete another seat press y and to return to main menu press any key \n";
                cin >> letter;
                if (letter == 'y' || letter == 'Y') {
                    system("cls");
                    delete_seats();
                } else {
                    system("cls");
                    admin_menu();
                }
            } else {
                cout << "Update cancelled \n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                admin_menu();
                break;
            }


            break;
        case 3:
            cout << "Seats of Business Class :\n";

            for (int l = 0; l < line_3; l++) {
                if (l == line_3 - 1) {
                    cout << Seats_of_B_Class[l] << endl;
                    break;
                }
                if (l % 5 == 0)
                    cout << endl;
                cout << Seats_of_B_Class[l] << "\t";
            }
            cout << "\nEnter the seat you want to delete : ";
            cin >> Seat;
            for (int l = 0; l < line_3; l++) {
                if (Seat == Seats_of_B_Class[l]) {

                    for (int l_line = l; l_line < line_3; l_line++)
                        Seats_of_B_Class[l_line] = Seats_of_B_Class[l_line + 1];
                }
            }
            line_3--;
            cout << "If you want to confirm the delete ,press (y) and to cancel update press any key \n ";
            cin >> letter;
            if (letter == 'y' || letter == 'Y') {
                for (int l = 0; l < line_3; l++) {
                    if (l % 5 == 0)
                        cout << endl;
                    cout << Seats_of_B_Class[l] << "\t";

                }
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                cout << "if you want to delete another seat press y and to return to main menu press any key \n";
                cin >> letter;
                if (letter == 'y' || letter == 'Y') {
                    system("cls");
                    delete_seats();
                } else {
                    system("cls");
                    admin_menu();
                }
            }

            else {
                cout << "Update cancelled \n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                admin_menu();
                break;
            }

            break;
        case 4:
            cout << "Seats Of Economy Premium Class :\n";
            for (int l = 0; l < line_4; l++) {
                if (l == line_4 - 1) {
                    cout << Seats_of_Eco_Pre_Class[l] << endl;
                    break;
                }
                if (l % 5 == 0)
                    cout << endl;
                cout << Seats_of_Eco_Pre_Class[l] << "\t";
            }


            cout << "Enter the seat you want to delete : ";
            cin >> Seat;
            for (int l = 0; l < line_4; l++) {
                if (Seat == Seats_of_Eco_Pre_Class[l]) {

                    for (int l_line = l; l_line < line_4; l_line++)
                        Seats_of_Eco_Pre_Class[l_line] = Seats_of_Eco_Pre_Class[l_line + 1];
                }
            }
            line_4--;
            cout << "If you want to confirm the update ,press (y) and to cancel update press any key :\n ";
            cin >> letter;
            if (letter == 'y' || letter == 'Y') {

                for (int l = 0; l < line_4; l++) {
                    if (l % 5 == 0)
                        cout << endl;
                    cout << Seats_of_Eco_Pre_Class[l] << "\t";

                }
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                cout << "if you want to delete another seat press y and to return to main menu press any key \n";
                cin >> letter;
                if (letter == 'y' || letter == 'Y') {
                    system("cls");
                    delete_seats();
                }
                else {
                    system("cls");
                    admin_menu();}

            }
            else {
                cout << "Update cancelled \n";
                sleep_for(nanoseconds(2));
                sleep_until(system_clock::now() + seconds(1));
                system("cls");
                admin_menu();
                break;

            }
            break;
    }
}
//----------------------------------------------------------------------------
//-------------seat first class --------------------------------------
void Seats_F() {
    char letter;
    cout << "Seats Of First Class :\n";

    for (int l = 0; l < line_1; l++) {
        if (l == line_1 - 1) {
            cout << Seats_of_F_Class[l];
            cout << endl;
            break;
        }
        if (l % 5 == 0)
            cout << endl;
        cout << Seats_of_F_Class[l] << "\t";
    }

    while (true) {
        cout << "Enter the Seat number that you want to add : \n";

        cin >> Seats_of_F_Class[line_1];
        for (int l = 0; l <= line_1; l++) {
            if (l == line_1) {
                cout << Seats_of_F_Class[l];
                cout << endl;
                break;
            }
            if (l % 5 == 0)
                cout << endl;
            cout << Seats_of_F_Class[l] << "\t";
        }


        line_1++;

        cout << "Do you want to Add another Seats Press (y) | to back to home menu press any key  \n";
        cin >> letter;

        if (letter == 'y' || letter == 'Y') {
            system("cls");
            add_Seats();

        }
        else {
            system("cls");
            admin_menu();
        }
    }

}
//------------------seats eco ---------------------------
void Seats_Eco() {

    char letter;
    cout << "Seats Of economic Class :\n";

    for (int l = 0; l < line_1; l++) {
        if (l == line_1 - 1) {
            cout << Seats_of_Eco_Class[l];
            cout << endl;
            break;
        }
        if (l % 5 == 0)
            cout << endl;
        cout << Seats_of_Eco_Class[l] << "\t";
    }

    while (true) {
        cout << "Enter the Seat number that you want to add : \n";

        cin >> Seats_of_Eco_Class[line_1];
        for (int l = 0; l <= line_1; l++) {
            if (l == line_1) {
                cout << Seats_of_Eco_Class[l];
                cout << endl;
                break;
            }
            if (l % 5 == 0)
                cout << endl;
            cout <<Seats_of_Eco_Class[l] << "\t";
        }


        line_1++;

        cout << "Do you want to Add another Seats Press (y) | to back to home menu press any key  \n";
        cin >> letter;

        if (letter == 'y' || letter == 'Y') {
            system("cls");
            add_Seats();

        }
        else {
            system("cls");
            admin_menu();
        }
    }
}
//------------------seats b ---------------------------
void Seats_B() {
    char letter;
    cout << "Seats of Business Class :\n";

    for (int l = 0; l < line_3; l++) {
        if (l == line_3 - 1) {
            cout << Seats_of_B_Class[l] << endl;
            break;
        }
        if (l % 5 == 0)
            cout << endl;
        cout << Seats_of_B_Class[l] << "\t";
    }
    while (true) {
        cout << "Enter the Seat number that you want to add : \n";

        cin >> Seats_of_B_Class[line_3];

        for (int l = 0; l <= line_3; l++) {
            if (l == line_3) {
                cout << Seats_of_B_Class[l] << endl;
                break;
            }
            if (l % 5 == 0)
                cout << endl;
            cout << Seats_of_B_Class[l] << "\t";
        }

        line_3++;
        cout << "Do you want to Add another Seats Press (y) | to back to home menu press any key  \n";
        cin >> letter;

        if (letter == 'y' || letter == 'Y') {
            system("cls");
            add_Seats();

        }
        else {
            system("cls");
            admin_menu();
        }
    }
}
//------------------seats eco pre ---------------------------
void Seats_Eco_Pre() {

    char letter;
    cout << "Seats Of Economy Premium Class :\n";
    for (int l = 0; l < line_4; l++) {
        if (l == line_4 - 1) {
            cout << Seats_of_Eco_Pre_Class[l] << endl;
            break;
        }
        if (l % 5 == 0)
            cout << endl;
        cout << Seats_of_Eco_Pre_Class[l] << "\t";
    }


    while (true) {
        cout << "Enter the Seat number that you want to add : \n";

        cin >> Seats_of_Eco_Pre_Class[line_4];

        for (int l = 0; l <= line_4; l++) {
            if (l == line_4) {
                cout << Seats_of_Eco_Pre_Class[l] << endl;
                break;
            }
            if (l % 5 == 0)
                cout << endl;
            cout << Seats_of_Eco_Pre_Class[l] << "\t";
        }
        line_4++;


        cout << "Do you want to Add another Seats Press (y) | to back to home menu press any key  \n";
        cin >> letter;

        if (letter == 'y' || letter == 'Y') {
            system("cls");
            add_Seats();

        }
        else {
            system("cls");
            admin_menu();
        }
    }
}
//===========================================================================
//-----------------game------------------------------------------------
void game() {

    string questions[10] = {
            "Which of the following is Tricontinental Country?",
            "Famous fast food restaurant company Burger King belongs to which Country?",
            "Office of strategic service (OSS) was old name of which Intelligence agency?",
            "The first person to draw the map of earth?",
            "Who laid first step on the Moon?",
            "What is the name of Chinese parliament?",
            "Ogaden desert is present in__________?",
            "Capital of America is___________?",
            "Wadi Rum which resemblance to the surface of Mars is located in__________?",
            "Borneo Island is in which Ocean?"
    };
    string options[10][4] = {
            {"chad","Chile","Mali","Swaziland"},
            {"America","England","Turkey","None of these"},
            {"MI6","CIA","ISI","N.O.T"},
            {"Heraclitus","phythagoras","Anaximander","Thales"},
            {"LMP Edgar","CMP Stuart","Neil Armstrong","None of them"},
            {"National Assembly","National people’s Congress","Fedral parliament","None"},
            {"Europe","Asia","Africa","America"},
            {"Washington Dc","Alaska","Hawaii","California"},
            {"Argentina","Israel","Jordan","Egypt"},
            {"Indian Ocean","Pacific Ocean","Arctic Ocean","Atlantic"},
    };
    string correctOptions[10] = {
            "Chile","America","CIA","Anaximander",
            "Neil Armstrong","National people’s Congress","Africa",
            "Washington DC","Jordan","Pacific Ocean"
    };
    int userOptions[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int totalQs = 10;
    int op;

    //----- Conducting Quiz -----
    for (int i = 0; i < totalQs; i++) {
        cout << "Question # " << (i + 1) << endl;
        cout << questions[i] << endl;
        cout << "1." << options[i][0] << endl;
        cout << "2." << options[i][1] << endl;
        cout << "3." << options[i][2] << endl;
        cout << "4." << options[i][3] << endl << endl;

        cout << "Select Option (1-4) or 0 to skip and press enter: ";
        cin >> userOptions[i];
        cout << endl << "-----------------------------" << endl << endl;
    }

    //----- Printing Correct Options -----
    cout << "======= ======= ======= ======= " << endl;
    cout << "======= Correct Options ======= " << endl;
    cout << "======= ======= ======= ======= " << endl;

    for (int i = 0; i < totalQs; i++) {
        cout << "Question # " << (i + 1) << endl;
        cout << questions[i] << endl;
        cout << "1." << options[i][0] << endl;
        cout << "2." << options[i][1] << endl;
        cout << "3." << options[i][2] << endl;
        cout << "4." << options[i][3] << endl;

        if (userOptions[i] == 0) {
            cout << "You Skipped this Question." << endl;
        }
        else {
            cout << "You Selected : " << options[i][userOptions[i] - 1] << endl;
        }
        cout << "Correct Option : " << correctOptions[i] << endl << endl;

        cout << "Press any key to continue..." << endl;
        getch();
        cout << endl << "------------------" << endl;
    }

    //----- Printing Result -----
    cout << endl << endl;
    cout << "======= ======= ======= ======= " << endl;
    cout << "=======      Result     ======= " << endl;
    cout << "======= ======= ======= ======= " << endl;


    int incorrect = 0;
    int skipped = 0;
    for (int i = 0; i < totalQs; i++) {
        if (userOptions[i] != 0) {
            if (correctOptions[i] == options[i][userOptions[i] - 1]) {
                correct++;
            }
            else {
                incorrect++;
            }
        }
        else {
            skipped++;
        }
    }
    cout << "Total Questions : " << totalQs << endl;
    cout << "Correct : " << correct << endl;
    cout << "In-Correct : " << incorrect << endl;
    cout << "Skipped : " << skipped << endl;
    string x;
    cout << "press any key to back to main menu : ";
    cin >> x;
    sleep_for(nanoseconds(2));
    sleep_until(system_clock::now() + seconds(1));
    user_menu();
}
//===========================================================================
//---------read data from file ---------------------------------
void data() {

    //------------------ read users username -----------------
    int lines_u_username = 0;
    fstream file_u_username;
    file_u_username.open("users_usernames.txt");
    if (file_u_username.fail()) {
        cout << "file failed to open (users1username.txt)." << endl;

    }
    while (!file_u_username.eof()) {
        getline(file_u_username, users[lines_u_username].username);
        lines_u_username++;
    }

    users_numbers = lines_u_username;

    file_u_username.close();
    //------------------ read users password --------------------------
    int lines_u_password = 0;
    fstream file_u_password;
    file_u_password.open("users_passwords.txt");
    if (file_u_password.fail()) {
        cout << "file failed to open (users passwords.txt)." << endl;

    }
    while (!file_u_password.eof()) {
        getline(file_u_password, users[lines_u_password].password);
        lines_u_password++;

    }

    file_u_password.close();

    //----------read users emails ------------------
    int lines_u_emails = 0;
    fstream file_u_emails;
    file_u_emails.open("users_emails.txt");
    if (file_u_emails.fail()) {
        cout << "file failed to open (users emails.txt)." << endl;

    }
    while (!file_u_emails.eof()) {


        getline(file_u_emails, users[lines_u_emails].email);
        lines_u_emails++;
    }

    file_u_emails.close();
    //----------read users phone ------------------
    int lines_u_phone = 0;
    fstream file_u_phone;
    file_u_phone.open("users_phones.txt");
    if (file_u_phone.fail()) {
        cout << "file failed to open (users phone.txt)." << endl;

    }
    while (!file_u_phone.eof()) {
        getline(file_u_phone, users[lines_u_phone].number);
        lines_u_phone++;

    }

    file_u_phone.close();
    //---------- read users address ------------------
    int lines_u_address = 0;
    fstream file_u_address;
    file_u_address.open("users_address.txt");
    if (file_u_address.fail()) {
        cout << "file failed to open (users address.txt)." << endl;

    }
    while (!file_u_address.eof()) {
        getline(file_u_address, users[lines_u_address].address);
        lines_u_address++;

    }


    file_u_address.close();
    //---------- read users id ------------------

    fstream file_u_id;
    file_u_id.open("users_id.txt");
    if (file_u_id.fail()) {
        cout << "file failed to open (users id.txt)." << endl;

    }
    while (!file_u_id.eof()) {
        getline(file_u_id, users[lines_u_id].id);
        lines_u_id++;

    }

    file_u_id.close();
    //------------------- read admin username ----------------------------
    fstream file_a_username;
    int lines_a_username = 0;
    file_a_username.open("admins_username.txt");
    if (file_a_username.fail()) {
        cout << "file failed to open (admins_username)." << endl;
    }

    while (!file_a_username.eof()) {
        getline(file_a_username, admins[lines_a_username].username);
        lines_a_username++;
    }
    file_a_username.close();

    //----------------- read admin password ----------------------
    fstream file_a_password;
    int lines_a_password = 0;
    file_a_password.open("admins_passwords.txt");
    if (file_a_password.fail()) {
        cout << "file failed to open (admins_passwords)." << endl;
    }

    while (!file_a_password.eof()) {
        getline(file_a_password, admins[lines_a_password].password);
        lines_a_password++;
    }
    file_a_password.close();
    //--------------------- read admin email -----------
    fstream file_a_email;
    int lines_a_email = 0;
    file_a_email.open("admins_email.txt");
    if (file_a_email.fail()) {
        cout << "file failed to open (admins_email)." << endl;
    }

    while (!file_a_email.eof()) {
        getline(file_a_email, admins[lines_a_email].email);
        lines_a_email++;

    }
    admin_number = lines_a_email;
    file_a_email.close();

    //---------------- read flights----------------------------------

    //------------------- read departure place --------------------------

    ifstream departureplace("departureplace.txt");
    int departureplace_lines = 0;
    if (departureplace.fail()) {
        cout << "file failed to open departureplace.txt." << endl;

    }
    while (!departureplace.eof()) {
        getline(departureplace, added[departureplace_lines].depatureplace);
        departureplace_lines++;

    }

    departureplace.close();

    //------------------- read arrival place -------------------------------------

    ifstream arrivralplace("arrivralplace.txt");
    int arrivralplace_lines = 0;
    if (arrivralplace.fail()) {
        cout << "file failed to open arrivralplace.txt." << endl;

    }
    while (!arrivralplace.eof()) {
        getline(arrivralplace, added[arrivralplace_lines].arrivalplace);
        arrivralplace_lines++;

    }
    arrivralplace.close();

    //------------------- read flight long -------------------------------------
    ifstream flightlong("flightlong.txt");
    int flightlong_lines = 0;
    if (flightlong.fail()) {
        cout << "file failed to open flightlong.txt" << endl;

    }
    while (!flightlong.eof()) {
        getline(flightlong, added[flightlong_lines].flightlong);
        flightlong_lines++;

    }
    flightlong.close();

    //------------------- read arrival date -------------------------------------
    ifstream arrival_date("arrival_date.txt");
    int arrival_date_lines = 0;
    if (arrival_date.fail()) {
        cout << "file failed to open arrival_date.txt" << endl;

    }
    while (!arrival_date.eof()) {
        getline(arrival_date, added[arrival_date_lines].arrival_date);
        arrival_date_lines++;

    }
    arrival_date.close();
    //------------------- read arrival time -------------------------------------
    ifstream arrival_time("arrival_time.txt");
    int arrival_time_lines = 0;
    if (arrival_time.fail()) {
        cout << "file failed to open arrival_time.txt" << endl;

    }
    while (!arrival_time.eof()) {
        getline(arrival_time, added[arrival_time_lines].arrival_time);
        arrival_time_lines++;

    }
    arrival_time.close();
    //------------------- read departure date -------------------------------------
    ifstream departure_date("departure_date.txt");
    int departure_date_lines = 0;
    if (departure_date.fail()) {
        cout << "file failed to open departure_date.txt" << endl;

    }
    while (!departure_date.eof()) {
        getline(departure_date, added[departure_date_lines].departure_date);
        departure_date_lines++;

    }
    departure_date.close();
    //------------------- read departure date -------------------------------------
    ifstream departure_time("departure_time.txt");
    int departure_time_lines = 0;
    if (departure_time.fail()) {
        cout << "file failed to open departure_time.txt" << endl;

    }
    while (!departure_time.eof()) {
        getline(departure_time, added[departure_time_lines].departure_time);
        departure_time_lines++;

    }
    departure_time.close();
    num_flights = arrivralplace_lines;
    //---------------------------------Read First Class seats---------------------
    line_1 = 0;

    ifstream my_file("First_Class_Seats.txt");

    if (my_file.fail()) {
        cout << "file failed to open First class Seats" << endl;
    }

    while (!my_file.eof()) {

        getline(my_file, Seats_of_F_Class[line_1]);
        line_1++;
    }
    my_file.close();
    //-------------------------------Read Economy Class Seats------------------------------
    line_2 = 0;
    ifstream My_file("Economy_Class_Seats.txt");

    if (My_file.fail()) {
        cout << "file failed to open Economy Class Seats" << endl;
    }

    while (!My_file.eof()) {

        getline(My_file, Seats_of_Eco_Class[line_2]);
        line_2++;
    }
    My_file.close();
    //-----------------------Read Business Pre Class-----------------------
    line_3 = 0;
    ifstream my_File("B_Class_Seats.txt");

    if (my_File.fail()) {
        cout << "file failed to open Business Class Seats" << endl;
    }

    while (!my_File.eof()) {

        getline(my_File, Seats_of_B_Class[line_3]);
        line_3++;
    }
    my_File.close();
    //------------------------------Read Eco Pre Seats----------------------
    line_4 = 0;
    ifstream My_File("Eco_Pre_Class_Seats.txt");

    if (My_File.fail()) {
        cout << "file failed to open Economy Premium Seats" << endl;
    }
    while (!My_File.eof()) {

        getline(My_File, Seats_of_Eco_Pre_Class[line_4]);
        line_4++;
    }
    My_File.close();
    //------------------------------Read booked reservation depatureplace----------------------
    int booked_reservation_lines = 0;
    ifstream booked_reservation_departure("booked_reservation_departure.txt");

    if (booked_reservation_departure.fail()) {
        cout << "file failed to open booked_reservation" << endl;
    }
    while (!booked_reservation_departure.eof()) {

        getline(booked_reservation_departure, booked[booked_reservation_lines].depatureplace);
        booked_reservation_lines++;
    }
    flightbooked = booked_reservation_lines;
    booked_reservation_departure.close();


    //------------------------------Read booked reservation departure date----------------------
    int booked_reservation_departure_date_lines = 0;
    ifstream booked_reservation_departure_date("booked_reservation_departure_date.txt");

    if (booked_reservation_departure_date.fail()) {
        cout << "file failed to open booked_reservation_departure_date" << endl;
    }
    while (!booked_reservation_departure_date.eof()) {

        getline(booked_reservation_departure_date, booked[booked_reservation_departure_date_lines].departure_date);
        booked_reservation_departure_date_lines++;
    }
    booked_reservation_departure_date.close();


    //------------------------------Read booked reservation departure time----------------------
    int booked_reservation_departure_time_lines = 0;
    ifstream booked_reservation_departure_time("booked_reservation_departure_time.txt");

    if (booked_reservation_departure_time.fail()) {
        cout << "file failed to open booked_reservation_departure_time" << endl;
    }
    while (!booked_reservation_departure_time.eof()) {

        getline(booked_reservation_departure_time, booked[booked_reservation_departure_time_lines].departure_time);
        booked_reservation_departure_time_lines++;
    }
    booked_reservation_departure_time.close();


    //------------------------------Read booked reservation arrive place----------------------
    int booked_reservation_arriveplace_lines = 0;
    ifstream booked_reservation_arriveplace("booked_reservation_arriveplace.txt");

    if (booked_reservation_arriveplace.fail()) {
        cout << "file failed to open booked_reservation_arriveplace" << endl;
    }
    while (!booked_reservation_arriveplace.eof()) {

        getline(booked_reservation_arriveplace, booked[booked_reservation_arriveplace_lines].arrivalplace);
        booked_reservation_arriveplace_lines++;
    }
    booked_reservation_arriveplace.close();


    //------------------------------Read booked reservation arrive date----------------------
    int booked_reservation_arrive_date_lines = 0;
    ifstream booked_reservation_arrive_date("booked_reservation_arrive_date.txt");

    if (booked_reservation_arrive_date.fail()) {
        cout << "file failed to open booked_reservation_arrive_date" << endl;
    }
    while (!booked_reservation_arrive_date.eof()) {

        getline(booked_reservation_arrive_date, booked[booked_reservation_arrive_date_lines].arrival_date);
        booked_reservation_arrive_date_lines++;
    }
    booked_reservation_arrive_date.close();


    //------------------------------Read booked reservation arrive time----------------------
    int booked_reservation_arrive_time_lines = 0;
    ifstream booked_reservation_arrive_time("booked_reservation_arrive_time.txt");

    if (booked_reservation_arrive_time.fail()) {
        cout << "file failed to open booked_reservation_arrive_time" << endl;
    }
    while (!booked_reservation_arrive_time.eof()) {

        getline(booked_reservation_arrive_time, booked[booked_reservation_arrive_time_lines].arrival_time);
        booked_reservation_arrive_time_lines++;
    }
    booked_reservation_arrive_time.close();
    //---------------------------------read payments of tickets ------------------------------
    int booked_reservation_ticket_price_line_ = 0;
    ifstream booked_reservation_ticket_price("booked_reservation_ticket_price.txt");
    if (booked_reservation_ticket_price.fail()) {
        cout << "file failed to open booked_reservation_ticket_price" << endl;
    }
    while (!booked_reservation_ticket_price.eof()) {
        getline(booked_reservation_ticket_price, booked[booked_reservation_ticket_price_line_].payments);
        booked_reservation_ticket_price_line_++;
    }
    booked_reservation_ticket_price.close();

}
//==========================================================================
//----------data save in files-----------
void filldata() {
    counter = users_numbers + new_user;
    //------------------- write users username -----------------

    ofstream file_u_username;

    file_u_username.open("users_usernames.txt");
    file_u_username << users[0].username;
    for (int i = 1; i < counter; i++) {
        file_u_username << endl << users[i].username;
    }
    file_u_username.close();

    //------------------write users password ---------------------------

    ofstream file_u_password;
    file_u_password.open("users_passwords.txt");
    file_u_password << users[0].password;
    for (int i = 1; i < counter; i++) {
        file_u_password << endl << users[i].password;
    }
    file_u_password.close();

    //-----------------write users email ---------------------------

    ofstream file_u_emails;
    file_u_emails.open("users_emails.txt");
    file_u_emails << users[0].email;
    for (int i = 1; i < counter; i++) {
        file_u_emails << endl << users[i].email;
    }
    file_u_emails.close();

    //-----------------write users phone  ---------------------------

    ofstream file_u_phone;
    file_u_phone.open("users_phones.txt");
    file_u_phone << users[0].number;
    for (int i = 1; i < counter; i++) {
        file_u_phone << endl << users[i].number;
    }
    file_u_phone.close();

    //-----------------write users address  ---------------------------

    ofstream file_u_address;
    file_u_address.open("users_address.txt");
    file_u_address << users[0].address;
    for (int i = 1; i < counter; i++) {
        file_u_address << endl << users[i].address;
    }
    file_u_address.close();


    //-----------------write users id  ---------------------------


    ofstream file_u_id;
    file_u_id.open("users_id.txt");
    file_u_id << users[0].id;
    for (int i = 1; i < counter; i++) {
        file_u_id << endl << users[i].id;
    }
    file_u_id.close();


    //----------------- write admin username   ---------------------------


    ofstream file_a_username;
    file_a_username.open("admins_username.txt");
    file_a_username << admins[0].username;
    for (int i = 1; i < admin_number; i++) {
        file_a_username << endl << admins[i].username;
    }
    file_a_username.close();


    //----------------- write admin passwords  ---------------------------


    ofstream admins_passwords;
    admins_passwords.open("admins_passwords.txt");
    admins_passwords << admins[0].password;
    for (int i = 1; i < admin_number; i++) {
        admins_passwords << endl << admins[i].password;
    }
    admins_passwords.close();

    //----------------- write admin email  ---------------------------

    ofstream file_a_email;
    file_a_email.open("admins_email.txt");
    file_a_email << admins[0].email;
    for (int i = 1; i < admin_number; i++) {
        file_a_email << endl << admins[i].email;
    }
    file_a_email.close();



    //--------- write data of flights ----------------

    //--------- write arrival date ----------------
    ofstream arrival_date("arrival_date.txt");
    arrival_date << added[0].arrival_date;
    for (int i = 1; i < num_flights; i++) {
        arrival_date << endl << added[i].arrival_date;
    }
    arrival_date.close();

    //--------- write arrival time ----------------
    ofstream arrival_time("arrival_time.txt");
    arrival_time << added[0].arrival_time;
    for (int i = 1; i < num_flights; i++) {
        arrival_time << endl << added[i].arrival_time;
    }
    arrival_time.close();


    //--------- write arrivalplace ----------------
    ofstream arrivralplace("arrivralplace.txt");
    arrivralplace << added[0].arrivalplace;
    for (int i = 1; i < num_flights; i++) {
        arrivralplace << endl << added[i].arrivalplace;
    }
    arrivralplace.close();


    //--------- write departure date ----------------
    ofstream departure_date("departure_date.txt");
    departure_date << added[0].departure_date;
    for (int i = 1; i < num_flights; i++) {
        departure_date << endl << added[i].departure_date;
    }
    departure_date.close();


    //--------- write departure time ----------------
    ofstream departure_time("departure_time.txt");
    departure_time << added[0].departure_time;
    for (int i = 1; i < num_flights; i++) {
        departure_time << endl << added[i].departure_time;
    }
    departure_time.close();


    //--------- write departure place ----------------
    ofstream departureplace("departureplace.txt");
    departureplace << added[0].depatureplace;
    for (int i = 1; i < num_flights; i++) {
        departureplace << endl << added[i].depatureplace;
    }
    departureplace.close();


    //--------- write  booked arrive place ----------------
    ofstream booked_reservation_arriveplace("booked_reservation_arriveplace.txt");
    booked_reservation_arriveplace << booked[0].arrivalplace;
    for (int i = 1; i < flightbooked; i++) {
        booked_reservation_arriveplace << endl << added[i].arrivalplace;
    }
    booked_reservation_arriveplace.close();


    //--------- write  booked arrive date ----------------
    ofstream booked_reservation_arrive_date("booked_reservation_arrive_date.txt");
    booked_reservation_arrive_date << booked[0].arrival_date;
    for (int i = 1; i < flightbooked; i++) {
        booked_reservation_arrive_date << endl << added[i].arrival_date;
    }
    booked_reservation_arrive_date.close();


    //--------- write  booked arrive time ----------------
    ofstream booked_reservation_arrive_time("booked_reservation_arrive_time.txt");
    booked_reservation_arrive_time << booked[0].arrival_time;
    for (int i = 1; i < flightbooked; i++) {
        booked_reservation_arrive_time << endl << added[i].arrival_time;
    }
    booked_reservation_arrive_time.close();


    //--------- write  booked departure place ----------------
    ofstream booked_reservation_departure("booked_reservation_departure.txt");
    booked_reservation_departure << booked[0].depatureplace;
    for (int i = 1; i < flightbooked; i++) {
        booked_reservation_departure << endl << added[i].depatureplace;
    }
    booked_reservation_departure.close();


    //--------- write  booked departure date ----------------
    ofstream booked_reservation_departure_date("booked_reservation_departure_date.txt");
    booked_reservation_departure_date << booked[0].departure_date;
    for (int i = 1; i < flightbooked; i++) {
        booked_reservation_departure_date << endl << added[i].departure_date;
    }
    booked_reservation_departure_date.close();


    //--------- write  booked departure date ----------------
    ofstream booked_reservation_departure_time("booked_reservation_departure_time.txt");
    booked_reservation_departure_time << booked[0].departure_time;
    for (int i = 1; i < flightbooked; i++) {
        booked_reservation_departure_time << endl << added[i].departure_time;
    }
    booked_reservation_departure_time.close();




    //-------------------------Write Economy Class Seats------------------------------
    ofstream my_File("Economy_Class_Seats.txt");
    my_File << Seats_of_Eco_Class[0];
    for (int i = 1; i < line_2; i++) {
        my_File << endl << Seats_of_Eco_Class[i];
    }
    my_File.close();

    //------------------------Write Business Class Seats------------------
    ofstream mY_File("B_Class_Seats.txt");
    mY_File << Seats_of_B_Class[0];
    for (int i = 1; i < line_3; i++) {
        mY_File << endl << Seats_of_B_Class[i];
    }
    mY_File.close();


    //---------------------------Write Economy Premium-------------------
    ofstream My_File("Eco_Pre_Class_Seats.txt");
    My_File << Seats_of_Eco_Pre_Class[0];
    for (int i = 1; i < line_4; i++) {
        My_File << endl << Seats_of_Eco_Pre_Class[i];
    }
    My_File.close();


    //-------------------------Write First Class-----------

    ofstream mY_file("First_Class_Seats.txt");
    mY_file << Seats_of_F_Class[0];
    for (int i = 1; i < line_1; i++) {
        mY_file << endl << Seats_of_F_Class[i];
    }
    mY_file.close();
    //-------------------------write ticket price --------------------
    ofstream booked_reservation_ticket_price("booked_reservation_ticket_price.txt");
    booked_reservation_ticket_price.open("booked_reservation_ticket_price.txt");
    booked_reservation_ticket_price << booked[0].payments << endl;
    for (int i = 1; i < flightbooked; i++) {
        booked_reservation_ticket_price << booked[i].payments << endl;

    }
    booked_reservation_ticket_price.close();
}
