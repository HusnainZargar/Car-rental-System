#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
                         
// login
int authenticate();
// admin 
int adminInterface();
int carManagement();
int removeCar();
int temporaryRemoval();
int permanentRemove();
int addCar();
int editCar();
int bookingManagement();
int bookRequest();
int returnRequest();
// user
int userInterface();
int searchCarInterface();
int bookCarInterface();
int billInterface(int);
int billGenerate(int);
int viewBookedCars();
int returnInterface();
// search Functions
int searchByMake(string);
int searchByColor(string);
int searchByEngineCapacity(int);
int searchByHorsePower(int);
int searchByFuelMileage(int);
int searchByRent(int);

// credentials Sturcture
struct credentials
{
   string userName;
   string password; 
   static bool listCredentials(string,string);
};
// Car Attributes Structure 
struct car 
{
   string make;
   string model;
   string color;
   int yearOfManufacture;
   float engineCapacity;
   int horsePower;
   string fuelType;
   float fuelMileage;
   int rent;
   bool available;
   string reason=" Booked!"; // default reason
   void input();
   void output();
};
// Bill and Car Info Structure
struct Bill
{
    int days;
    string Fullname;
    long long int totalAmount;
    bool status=false;
    bool viewBookedCarStatus=false;
    bool isReturn=false;
    int delivery;
    int selectedCar;
    int ID=0;
};
// Array of Cars
const int maxCars = 15; 
car list[maxCars];       
int carCount = 7;  
// Array of Users
const int maxUsers = 3;
Bill bill[maxUsers];
int userCount=0;
//......................................................Main Function................................
int main()
{
    system("cls");
    list[0] = {"Ferrari", "SF90 Stradale", "Red", 2023, 3990, 986, "Hybrid", 7.8, 300000, true};
    list[1] = {"Lamborghini", "Huracan STO", "Green", 2023, 5204, 640, "Petrol", 5.9, 500000, true};
    list[2] = {"Porsche", "911 Turbo S", "White", 2023, 3800, 640, "Petrol", 8.5, 350000, true};
    list[3] = {"McLaren", "720S", "Orange", 2023, 3994, 710, "Petrol", 8.1, 284000, true};
    list[4] = {"Chevrolet", "Corvette Z06", "Red", 2023, 5500, 670, "Petrol", 6.8, 450000, true};
    list[5] = {"Nissan", "GT-R Nismo", "Black", 2023, 3799, 600, "Petrol", 6.8, 320000, true};
    list[6] = {"Bugatti", "Chiron Super Sport", "Blue", 2023, 7993, 1578, "Petrol", 4.2, 1200000, true};

    authenticate();
    return 0;
}
//......................................................Add Car Struct...............................
void car::input()
{
    cin.clear();
    cin.ignore();
   cout<<"\n\t Enter the Make of Car: ";
   getline(cin,make);
   cin.clear();
   cout<<"\t Enter the Car Model: ";
   getline(cin,model);
   cin.clear();
   cout<<"\t Enter the Car Color: ";
   getline(cin,color);
   cout<<"\t Enter the Year of Manufacture: ";
   cin>>yearOfManufacture;
   cout<<"\t Enter the Engine Capacity: ";
   cin>>engineCapacity;
   cout<<"\t Enter HorsePower: ";
   cin>>horsePower;
   cin.clear();
    cin.ignore();
   cout<<"\t Enter Fuel Type: ";
   getline(cin,fuelType);
   cout<<"\t Enter Fuel Mileage(In Km): ";
   cin>>fuelMileage;
   cin.clear();
   cout<<"\t Enter Rent Per Day (Rs.): ";
   cin>>rent;
   available=true;   
}
//......................................................Display Car Struct...........................
void car::output()
{
   cout<<"\n\n\t\t  ------ "<<make<<" "<<model<<" ------"<<endl;
   cout<<"\t Color: "<<color<<endl;
   cout<<"\t Year Of Manufacture: "<<yearOfManufacture<<endl;
   cout<<"\t Engine Capacity: "<<engineCapacity<<" cc"<<endl;
   cout<<"\t HorsePower: "<<horsePower<<" Hp"<<endl;
   cout<<"\t Fuel Type: "<<fuelType<<endl;
   cout<<"\t Fuel Mileage: "<<fuelMileage<<" Km/Liter"<<endl;
   cout<<"\t Status: ";
   if (available==true)
   {
      cout<<" Available "<<endl;
      cout<<"\t\t  ------ Per Day Rent: Rs. "<<rent<<endl;
      cout<<"=================================================================="<<endl;
   }
   else
    {
      cout<<" ********** Not Available ********** "<<endl;
      cout<<"\t Reason: "<<reason<<endl;
      cout<<"=================================================================="<<endl;
    } 
}
//......................................................Credentials List.............................
bool credentials::listCredentials(string u,string p) {
    credentials list[4];
    list[0] = {"Husnain", "Husnain123"};
    list[1] = {"user", "user123"};
    list[2] = {"Umer", "Umer123"};
    list[3] = {"Mujtaba", "Mujtaba123"};
    for (int i = 0; i < 4; i++)
    {
         if (list[i].userName == u && list[i].password == p) 
        {
            return true; 
        }
    }
    return false;
}
//......................................................Authentication Interface.....................
int authenticate()
{
    int attempt=3;
    string userName;
    string password;
    do
    {
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t               ONLINE CAR RENTAL SYSTEM"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t                  ----- LOGIN -----"<<endl;
    cin.clear();
    cout<<"\n\t  Enter Username: ";
    getline(cin,userName);
    cin.clear();
    cout<<"\t  Enter Password: ";
    getline(cin,password); 
    cin.clear();
       if (credentials::listCredentials(userName,password))
        {
            if (userName=="Husnain" && password=="Husnain123")
            {
                adminInterface();
                return 0;
            }
            else{ 
                userInterface(); 
                return 0;
            }
        }   
      else 
      {
         --attempt;
         if (attempt==0)
         {
            cout<<"\n\t       ----Account Locked!----"<<endl;
            _getch();
            return 0;
         }
         cout<<"\n\t  Invalid Credentials! Only "<<attempt<<" Attempt Remains!"<<endl;
         cout<<"\n\n\tEnter Any Key to continoue: ";
         _getch();  
      }
   } while (attempt>0);
   return 0;
}
//......................................................Admin Interface..............................
int adminInterface()
{    
    int choice;
  
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t                    ADMINISTRATOR"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t                 ----- Welcome -----"<<endl;
    cout<<"\n\t              1-   View All Cars Status"<<endl;
    cout<<"\t              2-   Car Management"<<endl;
    cout<<"\t              3-   Booking Management"<<endl;
    cout<<"\t              4-   Exit"<<endl;
    cout<<"\n\t Enter: ";
    cin>>choice;
    cin.ignore();
    switch (choice)
    {
       case 1:
            for (int i = 0; i < carCount; i++) 
              {
                  list[i].output();
              }
              cout<<"\n\t Enter Any Key to continue: ";
              _getch();
              return adminInterface();
              break;
       case 2: 
              carManagement();
              break;
       case 3: 
             bookingManagement();
             break;
       case 4:
             return authenticate();
             break;
       default:
             cout<<"\n\t\t ---Invalid Value!---"<<endl;
             break;
    }

   cout<<"\t Enter Any Key to continoue: ";
   _getch();
   return adminInterface();
}
//......................................................Car Management Interface.....................
int carManagement()
{
    int choice1=0;
  
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t                    Car Management"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t              1-   Add a Car"<<endl;
    cout<<"\t              2-   Remove a Car"<<endl;
    cout<<"\t              3-   Edit Car Details"<<endl;
    cout<<"\t              4-   View All Cars"<<endl;
    cout<<"\t              5-   Back to Main Menu"<<endl;
    cout<<"\n\t Enter: ";
    cin>>choice1;
    switch (choice1)
    {
    case 1:
        addCar();
        break;
    case 2:
        removeCar();
         break;
    case 3:
        editCar();
    break;
    case 4:
           for (int i = 0; i < carCount; i++)
           {
              list[i].output();
           }
    break;
    case 5:
         adminInterface();
    break;
    default:
           cout<<"\n\t\t ---Invalid Value!---"<<endl;
             break;
    }
    
    cout<<"\n\t Enter Any Key to Continoue: ";
     _getch();
     return carManagement();
}
//......................................................Add Car......................................
int addCar()
{
    int count=0;
 
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t                       Add Car"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t How Many Cars Do You Want to Add: ";
    cin>>count;
    for (int i = 0; i < count; i++)
    {
       if (carCount >= maxCars) 
       {
        cout<<"\n\t No more cars can be added. Maximum capacity reached!"<<endl;
       } 
       else 
       {
        cout<<"\n\t               -------- Add Car -------- "<<endl;
        cout<<"\n\t Enter Details for Car "<<i+1<<" : "<<endl;
        list[carCount].input();
        carCount++;  
        cout << "\n\t -------- Car added successfully! -------- " << endl;
      }
    }
       cout<<"\n\t Enter Any Key to Continoue: ";
       _getch();
   return carManagement();
}
//......................................................Remove Car Interface.........................
int removeCar()
{
    int choice=0;
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t                      Remove a Car"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t              1-   Temporary Remove"<<endl;
    cout<<"\t              2-   Permanently Delete"<<endl;
    cout<<"\t              3-   Back to Main Menu"<<endl;
    cout<<"\n\t Enter: ";
    cin>>choice;
    switch(choice)
    {
     case 1:
        temporaryRemoval();  
        break;
     case 2:
        permanentRemove();
        break;
     case 3:
        return adminInterface();
        break;
     default:
       cout<<"\n\t\t ---Invalid Value!---"<<endl;
       break;
    }
     cout<<"\n\t Enter Any Key to Continuoe: ";
     _getch();
     return removeCar();
}
//......................................................Temporary Remove.............................
int temporaryRemoval()
{
    char confirm;
    string reason;
    int carIndex;

    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t                    Temporary Removal"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t            -------- All Car Details --------"<<endl;
    cout<<"\n"<<endl;
    for (int i = 0; i < carCount; i++)
    {
        cout<<"\t"<<i + 1<<"- "<<list[i].make<<" "<<list[i].model<<endl;
    }
    cout<<"\n\t Enter the number of the car you want to remove (1-" << carCount << "): ";
    cin>>carIndex;
    if (carIndex < 1 || carIndex > carCount) 
    {
        cout<<"\n\t Invalid car selection!"<<endl;
        cout<<"\n\t Enter Any Key to Continue: ";
        _getch();
        return removeCar();
    }
    cin.clear();
    cin.ignore();
    --carIndex;
    cout<<"\n\t    -------- "<<list[carIndex].make<<" "<<list[carIndex].model<<" Selected! -------- "<<endl;
    cout<<"\n\t Enter Reason For the Temporary Removal: ";
    getline(cin, reason);
    cout<<"\t Are You Sure (Y/N): ";
    cin>>confirm;
    switch (confirm)
    {
        case 'Y':
        case 'y':
                list[carIndex].available=false;
                list[carIndex].reason=reason;           
                cout<<"\n\n\t      ---------- Successful! Its now Unavailable ----------"<<endl;
                cout<<"\n\t Enter Any Key to Continuoe: ";
                _getch();
                return carManagement();
                break;
        case 'N':
        case 'n':
                cout<<"\n\t        ---------- Process Terminated! ---------- "<<endl;
                cout<<"\n\t Enter Any Key to Continuoe: ";
                _getch();
                return carManagement();
                break;
        default:
                cout<<"\n\t Invalid Key Entered!"<<endl;
                cout<<"\n\t Enter Any Key to Continuoe: ";
                _getch();
                return temporaryRemoval();
                break;
    }
    return removeCar();
}
//......................................................Permanent Remove.............................
int permanentRemove()
{
    int choice=0;
    char confirm;
    int carIndex;

    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t                     Permanently Delete"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t            -------- All Car Details --------"<<endl;
    cout<<"\n"<<endl;
    for (int i = 0; i < carCount; i++)
    {
        cout<<"\t "<<i + 1<<"- "<<list[i].make<<" "<<list[i].model<<endl;
    }
    cout<<"\n\t Enter the number of the car you want to remove (1-" << carCount << "): ";
    cin>>carIndex;
    if (carIndex < 1 && carIndex > carCount)
    {
        cout<<"\n\t Invalid car selection!"<<endl;
        cout<<"\n\t Enter Any Key to Continue: ";
        _getch();
        return removeCar();
    }
    carIndex--;
    cout<<"\n\t Are you sure you want to permanently delete the car "<<list[carIndex].make<<" "<<list[carIndex].model<<"? (Y/N): ";
    cin >> confirm;
    switch (confirm)
    {
        case 'Y':
        case 'y':
             for (int i = carIndex - 1; i < carCount - 1; i++)
              {
                list[i] = list[i + 1];
              }
                carCount--;      
                cout<<"\n\n\t      ---------- Successful! Its now Unavailable ----------"<<endl;
                cout<<"\n\t Enter Any Key to Continuoe: ";
                _getch();
                return carManagement();
                break;
        case 'N':
        case 'n':
                cout<<"\n\t        ---------- Process Terminated! ---------- "<<endl;
                cout<<"\n\t Enter Any Key to Continuoe: ";
                _getch();
                return carManagement();
                break;
        default:
                cout<<"\n\t Invalid Key Entered!"<<endl;
                cout<<"\n\t Enter Any Key to Continuoe: ";
                _getch();
                return temporaryRemoval();
                break;
    }
    cout<< "\n\t Enter Any Key to Continue: ";
    _getch();
    return carManagement();
}
//......................................................Edit a Car...................................
int editCar()
{
    int carIndex;
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t                     Edit Car Details"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t            -------- All Car Details --------"<<endl;
    cout<<"\n"<<endl;
    for (int i = 0; i < carCount; i++)
    {
        cout<<"\t "<<i + 1<<"- "<<list[i].make<<" "<<list[i].model<<endl;
    }
    cout << "\n\t Enter the number of the car you want to Edit (1-" << carCount << ") (0 to Exit) : ";
    cin >> carIndex;
    if (carIndex==0)
    {
        return carManagement();
    }
    
    if (carIndex < 1 || carIndex > carCount) 
    {
        cout<<"\n\t Invalid car selection!"<<endl;
        cout<<"\n\t Enter Any Key to Continue: ";
        _getch();
        return carManagement();
    }
    carIndex--;
    cout<<"\n";
    system("cls");
    list[carIndex].input();
    cout<<"\n\t       ---------- Car Edited Successfully! ----------"<<endl;
    cout<< "\n\t Enter Any Key to Continue: ";
    _getch();
    return carManagement();
}
//......................................................Booking Management Interface.................
int bookingManagement()
{
    int choice=0;
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t                   Booking Management"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t            1-  Manage Car Booking Requests"<<endl;
    cout<<"\t            2-  Manage Car Return Requests"<<endl;
    cout<<"\t            3-  Exit"<<endl;
    cout<<"\n\t Enter: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
         bookRequest();
        break;
    case 2:
         returnRequest();
        break;
    case 3:
         return adminInterface();
         break;
    default:
        cout<<"\n\t Invalid Value!"<<endl;
        break;
    }
    cout<<"\t Enter Any Key To continoue: ";
    _getch();
    return bookingManagement();
    return bookingManagement();
}
//......................................................Booking Requests.............................
int bookRequest()
{
     system("cls");
     bool hasRequests = false;  
     
        for (int i = 0; i < userCount; i++) 
        {
          if (bill[i].viewBookedCarStatus == true ) 
           {
             hasRequests = true;
             break;
           }
       }
        cout<<"\t======================================================="<<endl;
        cout<<"\t                    Booking Requests"<<endl;
        cout<<"\t======================================================="<<endl;
    
    if (hasRequests!=true) 
    {
        cout<<"\t                 ---- No Requests! ----"<<endl;
        cout<<"\t======================================================="<<endl;
        cout<<"\t Enter Any Key to Continue: ";
        _getch();
        return bookingManagement();  
    }

    while (true) 
    {
        system("cls");
        cout<<"\t======================================================="<<endl;
        cout<<"\t                    Booking Requests"<<endl;
        cout<<"\t======================================================="<<endl;
        for (int i = 0; i < userCount; i++) 
        {
            if (bill[i].viewBookedCarStatus == true) 
            {
                cout<<"\n\t             ***** Request No. " <<i + 1<< ": *****"<<endl;
                cout<<"\t Invoice Number: "<< bill[i].ID <<endl;
                cout<<"\t Customer Name: "<< bill[i].Fullname <<endl;
                cout<<"\t Rented Car: "<<list[bill[i].selectedCar].make<<" "<<list[bill[i].selectedCar].model<<endl;
                cout<<"\t Number of Days: "<<bill[i].days<<endl;
                cout<<"\t Total Amount: Rs. "<< bill[i].totalAmount<<endl;
                cout<<"\t Status: ";
                if (bill[i].status == false) 
                {
                    cout<<"Request Pending"<<endl;
                } 
                else 
                {
                    cout<<"Accepted"<<endl;
                    cout<<"\t Delivery Time: "<<bill[i].delivery<<" Hours"<<endl;
                }
                cout << "\t---------------------------------------" << endl;
            }
        }

        int requestNumber;
        cout<<"\n\t Enter the Request Number to Manage (0 to Exit): ";
        cin>>requestNumber;
        if (requestNumber == 0) 
        {
            return bookingManagement();  
        }
        if (requestNumber<1||requestNumber>userCount||bill[requestNumber - 1].viewBookedCarStatus == false) 
        {
            cout<<"\n\t Invalid Request Number! Try Again."<<endl;
            cout<<"\n\t Enter Any Key to Continue: "<<endl;
            _getch();
            continue;
        }
        int index = requestNumber - 1;  
        system("cls");
        cout<<"\n\t======================================================="<<endl;
        cout<<"\t           Manage Request No. " << requestNumber  <<endl;
        cout<<"\t======================================================="<<endl;
        cout<<"\t Invoice Number: "<<bill[index].ID<<endl;
        cout<<"\t Customer Name: "<<bill[index].Fullname<<endl;
        cout<<"\t Rented Car: "<<list[bill[index].selectedCar].make<<" "<<list[bill[index].selectedCar].model<<endl;
        cout<<"\t Number of Days: "<<bill[index].days<<endl;
        cout<<"\t Total Amount: Rs. "<<bill[index].totalAmount<<endl;
        cout<<"\t Status: ";
         if (bill[index].status==false) 
         {
            cout<<"**** Request Pending ****"<<endl;
         } 
         else 
         {
             cout<<"**** Accepted ****"<<endl;
             cout<<"\t ********** Car Will Be Delivered In: "<<bill[index].delivery<<" Hours **********"<<endl;
         } 

        if (bill[index].status == true) 
        {
            cout<<"\n\t ********** This Request Has Already Been Accepted! **********"<<endl;
            cout<<"\t Delivery Time: " << bill[index].delivery<<" Hours"<<endl;
            cout<<"\n\t Enter Any Key to Return: ";
            _getch();
            continue;
        }
        char choice;
        cout<<"\n\t Do You Want to Accept This Request (Y/N): ";
        cin>>choice;
        switch (choice) 
        {
            case 'y':
            case 'Y': 
                bill[index].status = true; 
                cout<<"\t Enter Delivery Time (in Hours): ";
                cin>>bill[index].delivery;  
                cout<<"\n\t -------- Request Accepted! -------- "<<endl; 
                break;
            case 'n':
            case 'N':
                cout<<"\n\t -------- Request Rejected! -------- "<<endl;
                break;
            default:
                cout<<"\n\t Invalid Key Selection! Returning to Request List."<<endl;
                break;
        }
        cout<<"\n\t Enter Any Key to Continue: ";
        _getch();
    }
    return bookingManagement();
}
//......................................................Return Requests..............................
int returnRequest()
{
     system("cls");

     cout<<"\t======================================================="<<endl;
     cout<<"\t                 Returned Cars Request"<<endl;
     cout<<"\t======================================================="<<endl;
     bool hasReturnedCar = false;

    for (int i = 0; i < userCount; i++) 
    {
        if (bill[i].isReturn==true ) 
        {
            hasReturnedCar = true;
            break;
        }
    }
    if (hasReturnedCar!=true) 
    {
        cout<<"\n\t                 ---- No Returned Cars ----"<<endl;
        cout<<"\t======================================================="<<endl; 
        cout<<"\n\t Enter Any Key to Continue: ";
        _getch();
        return bookingManagement();
    }

    for (int i = 0; i < userCount; i++) 
    {
        if (bill[i].isReturn==true ) 
        {
            cout<<"\n\t Car " << i + 1 << ": " <<list[bill[i].selectedCar].make<< " " << list[bill[i].selectedCar].model<<endl;
            cout<<"\t Invoice Number: " << bill[i].ID<<endl;
            cout<<"\t Customer Name: " << bill[i].Fullname<<endl;
            cout<<"\t Total Amount Paid: Rs. " << bill[i].totalAmount<<endl;
            cout<<"\t======================================================="<<endl;
        }
    }

    int manageCarIndex;
 
    cout<<"\n\t ***** Select A Returned Car By Number To Manage (0 to Exit): ";
    cin>>manageCarIndex;
    if (manageCarIndex==0)
    {
        return bookingManagement();
    }
    
    manageCarIndex--; 

    if (manageCarIndex < 0 || manageCarIndex >= userCount || bill[manageCarIndex].status == true || list[bill[manageCarIndex].selectedCar].available == false) 
    {
        cout << "\n\t Invalid Selection! Please Try Again.\n";
        cout << "\t Enter Any Key to Continue: ";
        _getch();
        return returnRequest();
    }

    cout << "\n\t -------- Returned Car Successfully Verified! --------\n";
    cout << "\t=======================================================\n";
    bill[manageCarIndex].isReturn=false; 
    bill[manageCarIndex].viewBookedCarStatus = false;
    cout << "\n\t Enter Any Key to Continue: ";
    _getch();
    return bookingManagement();
}
//......................................................Normal User Interface........................
int userInterface()
{
    int choice=0;
  
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t               ONLINE CAR RENTAL SYSTEM"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t                  -----Welcome-----"<<endl;
    cout<<"\n\t              1-   list All Available Cars"<<endl;
    cout<<"\t              2-   Search For a Car"<<endl;
    cout<<"\t              3-   Book a Car"<<endl;
    cout<<"\t              4-   View Sent Requests for Booked Cars"<<endl;
    cout<<"\t              5-   Return a Car"<<endl;
    cout<<"\t              6-   Exit"<<endl;
    cout<<"\n\t Enter: ";
    cin>>choice;
    cin.ignore();
    switch (choice)
    {
        case 1:
             for (int i = 0; i < carCount; i++)
             {
               list[i].output();
             }
        break;
        case 2:
           searchCarInterface();
        break;
        case 3:
            bookCarInterface();
        break;
        case 4:
            viewBookedCars();
        break;
        case 5:
            returnInterface();
              break;
        break;
        case 6:
            return authenticate();
        break;
       default:
             cout<<"\n\t\t ---Invalid Value!---"<<endl;
             break;
    }
    cout<<"\n\t Enter Any Key To Continoue: ";
    _getch();
    return userInterface();  
}
//......................................................Search Car Interface.........................
int searchCarInterface()
{
    int choice=0;

    string choice1;
    int choice2=0;
    system("cls");
    cout<<"\t======================================================="<<endl;
    cout<<"\t                   Search For a Car"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\n\t                   1-  By Your Budget"<<endl;
    cout<<"\t                   2-  By Car Make"<<endl;
    cout<<"\t                   3-  By Car Color"<<endl;
    cout<<"\t                   4-  By Engine Capacity"<<endl;
    cout<<"\t                   5-  By HorsePower"<<endl;
    cout<<"\t                   6-  By Fuel Mileage"<<endl;
    cout<<"\t                   7-  For Exit"<<endl;
    cout<<"\n\t Enter: ";
    cin>>choice; 
    switch (choice)
    {
    case 1:
        cout<<"\n\t Enter Your Maximum Budget: ";             
        cin>>choice2;
        searchByRent(choice2);
        break;
    case 2:
        cin.ignore();
        cin.clear();
        cout<<"\n\t Enter the Car Make: ";               
        getline(cin,choice1);
        searchByMake(choice1);
        break;
    case 3:
        cin.ignore();
        cin.clear();
        cout<<"\n\t Enter the Car Color: ";               
        getline(cin,choice1);
        searchByColor(choice1);
        break;
    case 4:
       cout<<"\n\t Enter the Maximum Engine Capacity: ";
       cin>>choice2;
       searchByEngineCapacity(choice2);

         break;
    case 5:
        cout<<"\n\t Enter the Maximum HorsePower: ";
        cin>>choice2;
        searchByHorsePower(choice2);
    break;
    case 6:
        cout<<"\n\t Enter the Minimum Fuel Mileage: ";
        cin>>choice2;
        searchByFuelMileage(choice2);
    break;
    case 7: 
     userInterface();
    break;
    default:
             cout<<"\n\t\t ---Invalid Value!---"<<endl;
        break;
    }
    cout<<"\n\t Enter Any Key to Continoue: ";
    _getch();
    return searchCarInterface();
}
//......................................................Search By Make...............................
int searchByMake(string choice)
{ 
         bool found=false;
         for (int i = 0; i < carCount; i++)
         {
             if (list[i].make==choice)
             {
                list[i].output();
                found=true;             
             }    
         }
         if (found!=true)
         {
             cout<<"\n\t     ---------- No Cars Found! ----------"<<endl;
         } 
           cout<<"\n\t Enter any Key to continoue: ";
            _getch();
           return searchCarInterface();       
}
//......................................................Search By Color..............................
int searchByColor(string choice)
{
    bool found=false;
     for (int i = 0; i < carCount; i++)
        {
            if (list[i].color==choice)
            {
                list[i].output();
                found=true;   
            }    
        }
        if (found!=true)
        {
            cout<<"\n\t     ---------- No Cars Found! ----------"<<endl;
        }      
           cout<<"\n\t Enter any Key to continoue: ";
            _getch();
          return searchCarInterface();
}
//......................................................Search By Engine Capacity....................
int searchByEngineCapacity(int choice)
{
    bool found=false;
     for (int i = 0; i < carCount; i++)
        {
            if (list[i].engineCapacity<=choice)
            {
                list[i].output();
                found=true; 
            }    
        }
        if (found!=true)
        {
            cout<<"\n\t     ---------- No Cars Found! ----------"<<endl;
        } 
         cout<<"\n\t Enter any Key to continoue: ";
            _getch();
          return searchCarInterface();
}
//......................................................Search By Horse Power........................
int searchByHorsePower(int choice)
{
        bool found=false;
     for (int i = 0; i < carCount; i++)
        {
            if (list[i].horsePower<=choice)
            {
                list[i].output();
                found=true;  
            }    
        }
        if (found!=true)
        {
            cout<<"\n\t     ---------- No Cars Found! ----------"<<endl;
        } 
         cout<<"\n\t Enter any Key to continoue: ";
            _getch();
          return searchCarInterface();
}
//......................................................Search By Fuel Mileage.......................
int searchByFuelMileage(int choice)
{
        bool found=false;
     for (int i = 0; i < carCount; i++)
        {
            if (list[i].fuelMileage>=choice)
            {
                list[i].output();
                found=true;
            }    
        }
        if (found!=true)
        {
            cout<<"\n\t     ---------- No Cars Found! ----------"<<endl;
        } 
         cout<<"\n\t Enter any Key to continoue: ";
            _getch();
          return searchCarInterface();
}
//......................................................Search By Budget.............................
int searchByRent(int choice)
{
        bool found=false;
       for (int i = 0; i < carCount; i++)
        {
            if (list[i].rent<=choice)
            {
                list[i].output();
                found=true;
                
            }    
        }
        if (found!=true)
        {
            cout<<"\n\t     ---------- No Cars Found! ----------"<<endl;
        } 
          cout<<"\n\t Enter any Key to continoue: ";
            _getch();
          return searchCarInterface();
}
//......................................................Book Car Interface...........................
int bookCarInterface()
{
     char choice;
    system("cls");

    cout << "\t=======================================================" << endl;
    cout << "\t                       Book A Car" << endl;
    cout << "\t=======================================================" << endl;
    cout << "\n" << endl;

    for (int i = 0; i < carCount; i++) {
        cout << "\n\t Car " << i + 1 << " :";
        list[i].output();
        cout << endl;
    }
   
    cout << "\n\n\t ***** Select A Car By Number You Want To Book: ";
    cin >> bill[userCount].selectedCar;
 
    if (bill[userCount].selectedCar < 1 || bill[userCount].selectedCar > carCount) 
    {
    cout << "\n\t -------- Invalid Selection! Please Select A Valid Car Number --------"<<endl;
    cout << "\t Enter Any Key to Try Again: ";
    _getch();  
    return bookCarInterface();    
    }
    
    bill[userCount].selectedCar--;
    
    if (!list[bill[userCount].selectedCar].available)
    {
        cout<<"\t Sorry The Car is Unavailable Right Now! "<<endl;
        cout<<"\t Enter Any Key to Continoue: ";
        _getch();
        return bookCarInterface();
    }
    
    cout<<"\n\t You Selected "<< list[bill[userCount].selectedCar].make<<" "<<list[bill[userCount].selectedCar].model << " (Y/N): ";
    cin>>choice;
    switch (choice) {
        case 'Y':
        case 'y':
            billInterface(userCount);
            break;
        case 'N':
        case 'n':
            cout << "\n\t        ---------- Process Terminated! ---------- " << endl;
            cout << "\n\t Enter Any Key to Continue: ";
            _getch();
            return userInterface();
        default:
            cout << "\n\t Invalid Value Entered! " << endl;
            cout << "\t Enter Any Key to Continue: ";
            _getch();
            return bookCarInterface();
    }
    return userInterface();
}
//......................................................Bill Interface...............................
int billInterface(int userIndex) 
{
    char choice;

    system("cls");
    cin.ignore();
    cin.clear();

    cout << "==================================================================" << endl;
    list[bill[userIndex].selectedCar].output();
    cout << "\n\n\t ***** How Many Days Do You Want (1-7 Days): ";
    cin >> bill[userIndex].days;
    if (bill[userIndex].days >= 1 && bill[userIndex].days <= 7) {
        cin.ignore();
        cin.clear();
        cout << "\n\t ***** Enter Your Full Name: ";
        getline(cin, bill[userIndex].Fullname);
        cout << "\n\t ***** Your Total Payment is: ";
        bill[userIndex].totalAmount = list[bill[userIndex].selectedCar].rent * bill[userIndex].days;
        cout << " Rs. " << bill[userIndex].totalAmount << endl;
        cout << "\n\t ***** Are You Sure You Want to Proceed (Y/N): ";
        cin >> choice;
        switch (choice) {
            case 'Y':
            case 'y':
                list[bill[userIndex].selectedCar].available=false; // make the car unavailable
                bill[userIndex].ID = userIndex + 129; // Assigns a unique ID based on user index
                bill[userIndex].viewBookedCarStatus = true; // so the user can now see the booked cars status   
                userCount++; 
                billGenerate(userIndex);
                break;
            case 'N':
            case 'n':
                cout << "\n\t        ---------- Process Terminated! ---------- " << endl;
                cout << "\n\t Enter Any Key to Continue: ";
                _getch();
                return 0;
            default:
                cout << "\n\t Invalid Key Entered!" << endl;
                cout << "\n\t Enter Any Key to Continue: ";
                _getch();
                return billInterface(userIndex);
        }
    } else {
        cout << "\t Invalid Selection!" << endl;
        cout << "\n\t Enter Any Key to Continue: ";
        _getch();
        return billInterface(userIndex);
    }
    return userInterface();
}
//......................................................Bill Generator...............................
int billGenerate(int userIndex) 
{
    system("cls");

    cout<<"\t======================================================="<<endl;
    cout<<"\t              ---------- Bill ----------"<<endl;
    cout<<"\t======================================================="<<endl;
    cout<<"\t              --- Invoice Number: " << bill[userIndex].ID<< " ---"<<endl;
    cout<<"\n\t Customer Name: " << bill[userIndex].Fullname<< endl;
    cout<<"\t Rented Car: " << list[bill[userIndex].selectedCar].make<<" "<< list[bill[userIndex].selectedCar].model << endl;
    cout<<"\t Number of Days: " << bill[userIndex].days<<endl;
    cout<<"\t Total Amount: Rs. " << bill[userIndex].totalAmount<<endl;
    cout<<"\n\t ********** Status: ";
    if (bill[userIndex].status == false) {
        cout << "Request Pending **********" << endl;
        cout << "\t=======================================================" << endl;
    } else {
        cout << "Accepted **********" << endl;
        cout << "\t ********** Car Will Be Delivered In: " << bill[userIndex].delivery<< " Hours **********" << endl;
    }
    cout << "\n\n\t Enter Any Key to Go to Main Interface: ";
    _getch();
    return userInterface();
}
//......................................................View Booked Car Requests.....................
int viewBookedCars() 
{
    system("cls");

    if (userCount == 0) {
        cout<<"\t======================================================="<<endl;
        cout<<"\t              ---------- Bookings ----------"<<endl;
        cout<<"\t======================================================="<<endl;
        cout<<"\n\t            ****** No Record Found! ******"<<endl;
        cout<<"\t======================================================="<<endl;
        cout<<"\n\n\t Enter Any Key to Continue: ";
        _getch();
        return userInterface();
    }
    cout<<"\t======================================================="<<endl;
    cout<<"\t              ---------- All Bookings ----------"<<endl;
    cout<<"\t======================================================="<<endl;

    for (int i = 0; i < userCount; i++) 
    {
        if (bill[i].isReturn==false)  // so if the car is returned it will not display the cars
        {
        cout<<"\n\t Booking "<<i + 1<<":"<<endl;
        cout<<"\t---------------------------------------"<<endl;
        cout<<"\t Customer Name: "<<bill[i].Fullname<<endl;
        cout<<"\t Rented Car: "<<list[bill[i].selectedCar].make<<" "<<list[bill[i].selectedCar].model<<endl;
        cout<<"\t Number of Days: "<<bill[i].days<<endl;
        cout<<"\t Total Amount: Rs. "<<bill[i].totalAmount<<endl;
        cout<<"\t Status: ";
         if (bill[i].status == false) 
         {
            cout<<"**** Request Pending ****"<<endl;
         } 
         else 
         {
             cout<<"**** Accepted ****"<<endl;
             cout<<"\t ********** Car Will Be Delivered In: "<<bill[i].delivery<<" Hours **********"<<endl;
         } 
        cout<<"\t---------------------------------------"<<endl;
        } 
    }
    cout << "\n\n\t Enter Any Key to Go Back: ";
    _getch();
    return userInterface();
}
//......................................................return a Car Interface.......................   
int returnInterface()
{
    system("cls");
     
    char choice;
    cout<<"\t======================================================="<<endl;
    cout<<"\t                       Return A Car"<<endl;
    cout<<"\t======================================================="<<endl;

    bool hasAcceptedCar = false;

    for (int i = 0; i < userCount; i++) {
        if (bill[i].status == true) 
        {  
            hasAcceptedCar = true;
            break;
        }
    }

    if (hasAcceptedCar!=true) 
    {
        cout<<"\n\t                 ---- No Car To Return ----"<<endl;
        cout<<"\t======================================================="<<endl;
        cout<<"\n\t Enter Any Key to Continue: ";
        _getch();
        return userInterface();
    }

    cout<<"\n\t           ***** Cars Available For Return *****"<<endl;
    for (int i = 0; i < userCount; i++) 
    {
        if (bill[i].status == true) 
        {
            cout<<"\t---------------------------------------"<<endl;
            cout<<"\t Car " <<i + 1<<": "<<list[bill[i].selectedCar].make<<" "<<list[bill[i].selectedCar].model<<endl;
            cout<<"\t Invoice Number: "<<bill[i].ID<<endl;
            cout<<"\t Customer Name: "<<bill[i].Fullname<<endl;
            cout<<"\t Rented For: "<<bill[i].days<<" days"<<endl;
            cout<<"\t Total Amount Paid: Rs. "<<bill[i].totalAmount<<endl;
            cout<<"\t---------------------------------------"<<endl;
        }
    }

    int returnCarIndex;

    cout<<"\n\t ***** Select A Car By Number You Want To Return (0 for Exit): ";
    cin>>returnCarIndex;
    if (returnCarIndex==0)
    {
        return userInterface();
    }
    
    returnCarIndex--; 

    if (returnCarIndex < 0 || returnCarIndex >= userCount || bill[returnCarIndex].status == false) 
    {
        cout << "\n\t Invalid Selection! Please Try Again.\n";
        cout << "\t Enter Any Key to Continue: ";
        _getch();
        return returnInterface();
    }
    
    cout<<"\n\t Are You Sure (Y/N): ";
    cin>>choice;
    switch (choice)
    {
       case 'Y':
       case 'y':
              bill[returnCarIndex].status = false;      
              list[bill[returnCarIndex].selectedCar].available = true; 
              bill[returnCarIndex].isReturn=true; // car is now returned! 
              cout << "\n\t       -------- Car Successfully Returned! --------"<<endl;
              cout << "\t======================================================="<<endl;
        
         break;
       case 'N':
       case 'n':
              cout<<"\n\t       -------- Process Terminated! -------- "<<endl;
              cout << "\t======================================================="<<endl;
              break;
        default:
            cout<<"\n\t       ----- Invalid Input! ----- "<<endl;
        break;
    }
    
    cout << "\n\t Enter Any Key to Continue: ";
    _getch();
    return userInterface();
}   
