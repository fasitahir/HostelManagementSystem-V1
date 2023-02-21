#include <iostream>
#include <conio.h>
using namespace std;

//................................. Prototypes.........................................

void header();
int loginMenu();
void clearFunction();
bool signUp(string username, string password, string role);
string signIn(string username, string password, string role);

// Manager
void managerwindows();
void managerProduct();
void addproduct();
void viewproduct();
void thresholdfunc();
void addThreshold();
void viewThreshold();
void deleteproduct();
void manageWorkers();
void addWorkers();
void viewWorkers();
void removeWorkers();
void manageExpenses();
void expensesWorkers();
void expensesProducts();
void otherExpenses();
void overallExpenses();
void manageAttendance();
void addAttendance();
void viewAttendances();
void viewReview();

// Cashier
void cashierWindows();
void addMenu();
void viewMenu();
void updateMenu();
void changePrice();
void removeItem();
void recieveOrder();
void viewOrder();
void removeOrder();
void calculateBill();

// Customer
void customerWindows();
void userReview();
void billDivider();
void tipCalculator();

//................................... Global Data.......................................

const int MAX_SIZE = 100;

// for login-singup
string userNames[MAX_SIZE] = {"fasi", "a", "b"};
string passwords[MAX_SIZE] = {"123", "123", "123"};
string roles[MAX_SIZE] = {"manager", "cashier", "customer"};

// for products - manager
string products[MAX_SIZE];
string thresholdProduct[MAX_SIZE];
float quantity[MAX_SIZE];
float thresholdvalues[MAX_SIZE];

// for workers - manager
string workers[MAX_SIZE];
string workerRoles[MAX_SIZE];
float workerSalaries[MAX_SIZE];
string workerTimings[MAX_SIZE];

// for expenses - manager
float totalPriceProduct[MAX_SIZE];
float sideExpenses[MAX_SIZE];

// for attendence - manager
string attendences[MAX_SIZE];

// for Cashier
string menuNames[MAX_SIZE];
float menuPrices[MAX_SIZE];
string customerNames[MAX_SIZE];
int orderQuantity[MAX_SIZE];
string orderName[MAX_SIZE];

// for customer
string serviceReviews[MAX_SIZE];
string foodReviews[MAX_SIZE];
string environmentReviews[MAX_SIZE];

// global variables
int usercount = 3;
int productCount = 0;
int thresholdcount = 0;
float thresholdvalue;
int workerscount = 0;
float sumSalaries = 0;
float sumProductPrices = 0;
float sumOtherExpenses = 0;
int attendanceCount = 0;
int menuCount = 0;
int customerCount = 0;
int customerLogins = 0;
int reviewCount = 0;

string productName;

main()
{
    system("CLS");
    int option;
    string username, password, role;

    while (option != 3)
    {
        header();
        option = loginMenu();
        // sign up
        if (option == 1)
        {
            bool check;
            system("cls");
            header();
            cout << "signUp\n";

            cout << "Enter User Name: ";
            cin >> username;

            cout << "\nEnter Password: ";
            cin >> password;
            // cout << "Temp psw:" << password << endl;

            cout << "Enter role(Manager ,Cashier ,Customer): ";
            cin >> role;

            check = signUp(username, password, role);

            if (check == true)
            {
                cout << "Username and pasword already exist.\n Try with different username and password.";
            }
            else if (check == false)
            {
                cout << "Signed Up Successfully!";
            }

            clearFunction();
        }
        // sign in
        else if (option == 2)
        {
            string check;
            system("cls");
            header();
            cout << "SignIn" << endl;

            cout << "Enter UserName: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            check = signIn(username, password, role);

            // manager windows
            if (check == "manager" || check == "Manager")
            {
                managerwindows();
            }
            // cashier windows
            else if (check == "Cashier" || check == "cashier")
            {
                cashierWindows();
            }
            // customer
            else if (check == "Customer" || check == "customer")
            {
                customerWindows();
            }
            else if (check == "Incorrect")
            {
                cout << "Incorrect user name or password";
            }

            clearFunction();
        }
    }
}

// login menu
int loginMenu()
{
    int option;
    cout << "1. SignUp" << endl;
    cout << "2. SignIn" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> option;
    return option;
}

// SignUp Functionality
bool signUp(string username, string password, string role)
{
    bool check = false;
    for (int i = 0; i < usercount; i++)
    {
        if (username == userNames[i] && password == passwords[i])
        {
            check = true;
            return check;
        }
    }

    userNames[usercount] = username;
    passwords[usercount] = password;
    roles[usercount] = role;
    usercount++;

    return check;
}

// signIn functionality

string signIn(string username, string password, string role)
{

    for (int i = 0; i < usercount; i++)
    {

        if (username == userNames[i] && password == passwords[i])
        {
            return roles[i];
        }
    }

    return "Incorrect";
}

//...................................................... manager windows/menu............................................................

void managerwindows()
{
    int coption;
    int moption;

    string check;
    while (moption != 6)
    {
        system("cls");
        header();
        cout << "\n\tManager windows. \n";
        cout << "1. Products.\n";
        cout << "2. Workers.\n";
        cout << "3. Expenses.\n";
        cout << "4. Attendence.\n";
        cout << "5. View user review.\n";
        cout << "6. Back.\n";
        cout << "Enter your selection: ";
        cin >> moption;

        if (moption == 1)
        {
            managerProduct();
        }

        else if (moption == 2)
        {
            manageWorkers();
        }

        else if (moption == 3)
        {
            manageExpenses();
        }

        else if (moption == 4)
        {
            manageAttendance();
        }
        else if (moption == 5)
        {
            viewReview();
        }
    }
}

//........................................... manager - product menu
void managerProduct()
{
    int poption;
    while (poption != 5)
    {
        getch();
        system("cls");
        header();

        cout << "\n\tManager Window - Products \n";
        cout << "1. Add products.\n";
        cout << "2. View available product.\n";
        cout << "3. Threshold.\n";
        cout << "4. Delete product.\n";
        cout << "5. Back.\n";
        cout << "Enter your selection: ";
        cin >> poption;

        if (poption == 1)
        {
            addproduct();
        }
        if (poption == 2)
        {
            viewproduct();
        }
        if (poption == 3)
        {
            thresholdfunc();
        }
        if (poption == 4)
        {
            deleteproduct();
        }
    }
}

//...................addproduct - product - manager
void addproduct()
{
    int option;
    while (option != 0)
    {
        getch();
        system("cls");
        header();
        cout << "\n\tAdd Product\n";

        cout << "Enter product name: ";
        cin >> products[productCount];

        cout << "Enter Quantity: ";
        cin >> quantity[productCount];
        productCount++;

        cout << "Enter 0 to exit or anyother key to continue adding.....";
        cin >> option;

        system("cls");
        header();
    }
}

//................... view products - product - manager
void viewproduct()
{
    getch();
    system("cls");
    header();

    cout << "\n\tView Product\n";

    cout << "Product"
         << "\t\t"
         << "quantity\n";
    for (int i = 0; i < productCount; i++)
    {
        cout << products[i] << "\t\t" << quantity[i] << "\n";
    }
    getch();
}

//.................... set threshold - product - manager
void thresholdfunc()
{
    float threshold;
    int option;
    string productName;

    while (option != 4)
    {
        getch();
        system("cls");
        header();
        cout << "\n\tSet Threshold\n";

        cout << "1. Add threshold.\n";
        cout << "2. View the status of products.\n";
        cout << "3. Update threshold.\n";
        cout << "4. Back.\n";
        cout << "Enter your choice....";
        cin >> option;
        if (option == 1)
        {
            addThreshold();
        }

        else if (option == 2)
        {
            viewThreshold();
        }
    }
}

// ....................add value of threshold - product - manager
void addThreshold()
{

    getch();
    system("cls");
    header();

    cout << "\n\tAdd Threshold\n";

    cout << "Enter product name: ";
    cin >> thresholdProduct[thresholdcount];

    cout << "Enter threshold value: ";
    cin >> thresholdvalues[thresholdcount];
    thresholdcount++;
}

//......................view threshold - product - manager
void viewThreshold()
{
    int count = 0;
    getch();
    system("cls");
    header();

    cout << "Enter product name you want to check threshold of: ";
    cin >> productName;

    for (int i = 0; i < thresholdcount; i++)
    {
        for (int j = 0; j < thresholdcount; j++)
        {
            if (productName == thresholdProduct[j])
            {
                cout << productName << " " << thresholdProduct[j] << endl;
                if (thresholdvalues[j] < quantity[i])
                {
                    cout << "You have  " << quantity[i] - thresholdvalues[j] << " amount of " << productName << " more than threshold";
                }

                else if (thresholdvalues[j] > quantity[i])
                {
                    cout << "You need " << thresholdvalues[j] - quantity[i] << " amount of " << productName;
                }

                else if (thresholdvalues[j] == quantity[i])
                {
                    cout << "Collect the product before it run out";
                }

                else
                {
                    cout << "No threshold set yet";
                }
                break;
            }
            break;
        }
    }
}

// .....................delete product - product - manager
void deleteproduct()
{
    string deleteproduct;
    bool flag = false;
    if (productCount != 0)
    {
        getch();
        system("cls");
        header();
        cout << "\n\t Remove Product\n";
        cout << "Enter name of product you want to delete: ";
        cin >> deleteproduct;

        for (int i = 0; i < productCount; i++)
        {
            if (products[i] == deleteproduct)
            {
                flag = true;
                for (int j = i; j < productCount - 1; j++)
                {
                    products[j] = products[j + 1];
                    quantity[j] = quantity[j + 1];
                }
                productCount--;
                break;
            }
        }

        if (flag == false)
        {
            cout << "No Such Product Found";
        }
    }
    else
    {
        cout << "No Product Available yet";
    }
}

//.....................................................manager - workers
void manageWorkers()
{
    int option;

    while (option != 4)
    {
        getch();
        system("cls");
        header();
        cout << "\n\tManager Windows - Manage Workers\n";
        cout << "1. Add new worker.\n";
        cout << "2. Remove worker.\n";
        cout << "3. View Available workers.\n";
        cout << "4. Back.\n";
        cout << "Enter your selection: ";
        cin >> option;
        if (option == 1)
        {
            addWorkers();
        }

        else if (option == 2)
        {
            removeWorkers();
        }

        else if (option == 3)
        {
            viewWorkers();
        }
    }
}

//........................workers - add worker
void addWorkers()
{
    getch();
    system("cls");
    header();
    cout << "\n\tManage Workers - Add worker \n";
    int option;
    while (option != 0)
    {
        cout << "Enter worker name: ";
        cin >> workers[workerscount];

        cout << "Enter worker role: ";
        cin >> workerRoles[workerscount];

        cout << "Enter salary of worker: ";
        cin >> workerSalaries[workerscount];

        cout << "Enter worker timing: ";
        cin >> workerTimings[workerscount];

        workerscount++;

        cout << "Press 0 to exit to workers windows and any other key to continue......";
        cin >> option;

        system("cls");
        header();
    }
}

//........................workers - View Workers
void viewWorkers()
{
    getch();
    system("cls");
    header();
    cout << "\n\t Followings are the available worker\n";

    if (workerscount != 0)
    {

        cout << "Name"
             << "\t\t"
             << "Role"
             << "\t\t"
             << "Time"
             << "\t\t"
             << "Salary"
             << "\n\n";
        for (int i = 0; i < workerscount; i++)
        {
            cout << workers[i] << "\t\t" << workerRoles[i] << "\t\t" << workerTimings[i] << "\t\t" << workerSalaries[i] << endl;
        }
    }
    else
    {
        cout << "No worker added yet";
    }

    getch();
}

//........................workers - remove worker
void removeWorkers()
{
    string workerNameRemove;
    bool flag = false;
    if (workerscount != 0)
    {
        getch();
        system("cls");
        header();
        cout << "\n\t Remove Workers\n";

        cout << "Enter name of Worker you want to remove: ";
        cin >> workerNameRemove;

        for (int i = 0; i < workerscount; i++)
        {
            if (workers[i] == workerNameRemove)
            {
                for (int j = i; j < workerscount - 1; j++)
                {

                    flag = true;
                    workers[j] = workers[j + 1];
                    workerRoles[j] = workerRoles[j + 1];
                    workerSalaries[j] = workerSalaries[j + 1];
                    workerTimings[j] = workerTimings[j + 1];
                }
                workerscount--;
                break;
            }
        }
        if (flag == false)
        {
            cout << "No such worker available";
        }
    }

    else
    {
        cout << "No worker added yet";
    }
}

//........................................................Manager - Expenses
void manageExpenses()
{
    int option;

    while (option != 5)
    {
        getch();
        system("cls");
        header();
        cout << "\n\tManager Windows - Expenses\n";
        cout << "1. Total workers salaries.\n";
        cout << "2. Total Expenses for products.\n";
        cout << "3. Total other expenses.\n";
        cout << "4. Overall Total Expenses\n";
        cout << "5. Back.\n";
        cout << "Enter your selection: ";
        cin >> option;

        if (option == 1)
        {
            expensesWorkers();
        }

        else if (option == 2)
        {
            expensesProducts();
        }
        else if (option == 3)
        {
            otherExpenses();
        }
        else if (option == 4)
        {
            overallExpenses();
        }
    }
}

// ......................................Expenses - Workers salaries

void expensesWorkers()
{
    getch();
    system("cls");
    header();

    cout << "\n\tExpenses - Workers Salaries\n\n";
    if (workerscount != 0)
    {

        cout << "Name"
             << "\t\t"
             << "Role"
             << "\t\t"
             << "Time"
             << "\t\t"
             << "Salary"
             << "\n\n";
        for (int i = 0; i < workerscount; i++)
        {
            cout << workers[i] << "\t\t" << workerRoles[i] << "\t\t" << workerTimings[i] << "\t\t" << workerSalaries[i] << endl;
        }

        cout << "\n....................................TOTAL............................................\n\n";
        for (int i = 0; i < workerscount; i++)
        {
            sumSalaries = sumSalaries + workerSalaries[i];
        }

        cout << "Total Expenses on salary is: " << sumSalaries;
    }
    else
    {
        cout << "No worker added yet";
    }
}

// ......................................Expenses - Products
void expensesProducts()
{
    getch();
    system("cls");
    header();
    int pricePerUnit;

    cout << "\n\tExpenses - Workers Salaries\n\n";
    if (productCount != 0)
    {
        for (int i = 0; i < productCount; i++)
        {
            cout << "Product Name: " << products[i] << endl;
            cout << "Enter " << products[i] << " price per unit: ";
            cin >> pricePerUnit;
            cout << endl;
            totalPriceProduct[i] = pricePerUnit * quantity[i];
        }

        cout << "\n\nProduct Name \t\t Available Quantity \t\t Price\n\n";

        for (int i = 0; i < productCount; i++)
        {
            cout << products[i] << " \t\t\t\t " << quantity[i] << " \t\t\t " << totalPriceProduct[i] << "\n";
            sumProductPrices = sumProductPrices + totalPriceProduct[i];
        }

        cout << "\n....................................TOTAL............................................\n\n";

        cout << "Total Expenses on Products are: " << sumProductPrices;
    }
    else
    {
        cout << "No product available!!";
    }
}

// ......................................Expenses - Others
void otherExpenses()
{
    int option;
    getch();
    system("cls");
    header();
    int otherExpensesCount = 0;

    cout << "\n\tExpenses - Other Exepenses\n\n";

    while (option != 0)
    {

        cout << "Add Small expenses: ";
        cin >> sideExpenses[otherExpensesCount];
        otherExpensesCount++;

        cout << "Enter '0' to exit and any other key to continue adding...";
        cin >> option;

        cout << endl;
    }

    for (int i = 0; i < otherExpensesCount; i++)
    {
        sumOtherExpenses = sideExpenses[i] + sumOtherExpenses;
    }

    cout << "\n\n.........................TOTAL OTHER EXPENSES..............................\n\n";

    cout << "Total other expenses are: " << sumOtherExpenses;
}

//.......................................Expenses - Total
void overallExpenses()
{
    getch();
    system("cls");
    header();
    cout << "\n\tExpenses - Total Exepenses\n\n";

    int totalExpenses = 0;

    totalExpenses = sumOtherExpenses + sumProductPrices + sumSalaries;

    cout << "Total Salaries      "
         << "\t\t\t" << sumSalaries << "\n";
    cout << "Total Product Prices"
         << "\t\t\t" << sumProductPrices << "\n";
    cout << "Total Other Expenses"
         << "\t\t\t" << sumOtherExpenses << "\n";

    cout << "\n....................TOTAL..........................\n";

    cout << "Total Expenses are"
         << "\t\t\t" << totalExpenses;
}

//........................................................Manager - Attendences
void manageAttendance()
{
    int option;

    while (option != 3)
    {
        getch();
        system("cls");
        header();

        cout << "\n\tManager Window - Attendance\n\n";

        cout << "1. Mark Attendance of worker.\n";
        cout << "2. View attendance of workers.\n";
        cout << "3. Back.\n";

        cout << "Enter your selection: ";
        cin >> option;
        if (option == 1)
        {
            addAttendance();
        }
        else if (option == 2)
        {
            viewAttendances();
        }
    }
}
//..........................................Attendances - add attendance
void addAttendance()
{
    getch();
    system("cls");
    header();

    cout << "\n\tAttebdance - Add Attendance\n\n";

    if (attendanceCount > 5)
    {
        attendanceCount = 0;
    }

    cout << "\nAdd Attendence of day " << attendanceCount + 1 << "\n";

    for (int i = 0; i < workerscount; i++)
    {
        cout << workers[i] << " is (p/a): ";
        cin >> attendences[i];
        cout << "\n";
    }
    attendanceCount++;
}

//..........................................Attendances - view attendance
void viewAttendances()
{
    getch();
    system("cls");
    header();

    cout << "\n\tAttebdance - view Attendance\n\n";

    for (int j = 0; j < attendanceCount; j++)
    {
        cout << "\nAttendance of day " << j + 1 << "\n\n";
        cout << "Name"
             << "\t\t\t"
             << "Attendance\n\n";
        for (int i = 0; i < workerscount; i++)
        {
            cout << workers[i] << "\t\t\t" << attendences[i];
            cout << "\n";
        }
    }
}

//.........................................................Manager - view Review
void viewReview()
{
    getch();
    system("cls");
    header();

    cout << "\n\tManager - View Reviews\n\n";

    if (reviewCount != 0)
    {
        for (int i = 0; i < reviewCount; i++)
        {
            cout << "\n\tFOOD REVIEW      \n\n";
            cout << "Customer " << i + 1 << "\t\t" << foodReviews[i];

            cout << "\n\tSERVICES REVIEW   \n\n";
            cout << "Customer " << i + 1 << "\t\t" << serviceReviews[i];

            cout << "\n\tEnvironment Review\n\n";
            cout << "Customer " << i + 1 << "\t\t" << environmentReviews[i];
            getch();
        }
    }

    else
    {
        cout << "No Review added";
        getch();
    }
}

//..............................................................CASHIER..................................................................
void cashierWindows()
{
    int coption;
    while (coption != 8)
    {
        getch();
        system("cls");
        header();

        cout << "\n\tCashier window \n";
        cout << "1. Add Menu.\n";
        cout << "2. View Menu.\n";
        cout << "3. Update Menu.\n";
        cout << "4. Receive Order.\n";
        cout << "5. View Order.\n";
        cout << "6. Remove Order.\n";
        cout << "7. Calculate Bill.\n";
        cout << "8. Back.\n";
        cout << "Enter your selection: ";
        cin >> coption;

        if (coption == 1)
        {
            addMenu();
        }

        else if (coption == 2)
        {
            viewMenu();
        }

        else if (coption == 3)
        {
            updateMenu();
        }

        else if (coption == 4)
        {
            recieveOrder();
        }

        else if (coption == 5)
        {
            viewOrder();
        }

        else if (coption == 6)
        {
            removeOrder();
        }

        else if (coption == 7)
        {
            calculateBill();
        }
    }
}

//........................................Cashier - Add Menu
void addMenu()
{
    getch();
    system("cls");
    header();

    cout << "\n\tAdd Menu - Cashier \n";
    int option;
    while (option != 0)
    {
        cout << "Add name of Food in menu: ";
        cin >> menuNames[menuCount];

        cout << "Enter price of that food: ";
        cin >> menuPrices[menuCount];

        cout << "Enter '0' to exit or any other key to continue adding.....";
        cin >> option;

        menuCount++;

        system("cls");
        header();
        cout << "\n\tAdd Menu - Cashier \n";
    }
}

//........................................Cashier - View Menu
void viewMenu()
{
    getch();
    system("cls");
    header();

    if (menuCount != 0)
    {
        cout << "\n\tView Menu - Cashier \n";

        cout << "Names"
             << "\t\t\t"
             << "Prices\n\n";

        for (int i = 0; i < menuCount; i++)
        {
            cout << menuNames[i] << "\t\t\t" << menuPrices[i] << "\n";
        }
    }

    else
    {
        cout << "\n No menu availble yet\n";
    }
}

//........................................Cashier - Update Menu
void updateMenu()
{
    int option;
    while (option != 3)
    {
        getch();
        system("cls");
        header();
        cout << "\n\t Cashier Windows - Update Menu\n";
        cout << "1. Change Price\n";
        cout << "2. Remove item\n";
        cout << "3. Back\n";

        cout << "Enter your selection: ";
        cin >> option;
        if (option == 1)
        {
            changePrice();
        }
        else if (option == 2)
        {
            removeItem();
        }
    }
}

//.........................................Update Menu - Change Prices
void changePrice()
{
    string changePriceName;
    float newPrice;
    bool flag = false;
    getch();
    system("cls");
    header();
    if (menuCount != 0)
    {
        cout << "\n\tUpdate Menu - Change prices\n";

        cout << "Enter Name of the Item you want to change Price of: ";
        cin >> changePriceName;

        cout << "Enter new price: ";
        cin >> newPrice;
        for (int i = 0; i < menuCount; i++)
        {
            if (changePriceName == menuNames[i])
            {
                flag = true;
                menuPrices[i] = newPrice;
                break;
            }
        }

        if (flag == false)
        {
            cout << "\nNo such item found\n";
        }
    }

    else
    {
        cout << "\nNo menu Added yet.\n";
    }
}

//.........................................Update Menu - Remove Item
void removeItem()
{

    string removeItemName;
    bool flag = false;

    getch();
    system("cls");
    header();

    if (menuCount != 0)
    {
        cout << "\n\tUpdate Menu - Remove Items\n";

        cout << "Enter Name of the Item you want to remove: ";
        cin >> removeItemName;

        for (int i = 0; i < menuCount; i++)
        {

            if (removeItemName == menuNames[i])
            {
                flag = true;
                for (int j = i; j < menuCount - 1; j++)
                {
                    menuNames[j] = menuNames[j + 1];
                    menuPrices[j] = menuPrices[j + 1];
                }
                menuCount--;
                break;
            }
        }
        if (flag == false)
        {
            cout << "\nNo item found \n";
        }
    }
    else
    {
        cout << "\nNo menu available yet\n";
    }
}

//........................................Cashier - Recieve Order
void recieveOrder()
{
    int option;

    while (option != 0)
    {

        getch();
        system("cls");
        header();

        cout << "\n\tCashier - Recieve Order\n\n";

        cout << "Enter Name of customer: ";
        cin >> customerNames[customerCount];

        cout << "Enter Name of item: ";
        cin >> orderName[customerCount];

        cout << "Enter quantity: ";
        cin >> orderQuantity[customerCount];

        customerCount++;

        cout << "Enter '0' to exit or any other key to take another order...";
        cin >> option;
        system("cls");
        header();
    }
}

//........................................Cashier - View Order
void viewOrder()
{
    getch();
    system("cls");
    header();

    cout << "\n\tCashier - Recieve Order\n\n";

    cout << "Name"
         << "\t\t\t"
         << "Order"
         << "\t\t\t"
         << "Qunatity\n\n";

    for (int i = 0; i < customerCount; i++)
    {
        cout << customerNames[i] << "\t\t\t" << orderName[i] << "\t\t\t" << orderQuantity[i];
        cout << endl;
    }
}

//.......................................Cashier - Remove Order
void removeOrder()
{
    string removeOrderName;
    bool flag = false;

    getch();
    system("cls");
    header();

    if (customerCount != 0)
    {
        cout << "\n\tCashier - Remove Order\n";

        cout << "Enter Name of the Customer you want to remove: ";
        cin >> removeOrderName;

        for (int i = 0; i < customerCount; i++)
        {

            if (removeOrderName == customerNames[i])
            {
                flag = true;
                for (int j = i; j < customerCount - 1; j++)
                {
                    customerNames[j] = customerNames[j + 1];
                    orderQuantity[j] = orderQuantity[j + 1];
                    orderName[j] = orderName[j + 1];
                }
                customerCount--;
                break;
            }
        }
        if (flag == false)
        {
            cout << "\nNo item found \n";
        }
    }
    else
    {
        cout << "\nNo menu available yet\n";
    }
}

//........................................Cashier - Bill Calculate
void calculateBill()
{
    bool flag = false;

    string billItemName;
    int quantitybill;
    float bill;

    getch();
    system("cls");
    header();

    if (menuCount != 0)
    {
        cout << "\n\tCashier - Calculate Bill\n";
        cout << "Enter Item Name: ";
        cin >> billItemName;

        cout << "Enter Quantity: ";
        cin >> quantitybill;

        for (int i = 0; i < menuCount; i++)
        {
            if (billItemName == menuNames[i])
            {
                bill = menuPrices[i] * quantitybill;
            }
        }
    }

    cout << "Total Bill is: " << bill;
}

//......................................................CUSTOMER....................................................................
void customerWindows()
{

    int option;
    while (option != 5)
    {
        getch();
        system("cls");
        header();
        cout << "\n\tCustomer window \n\n";

        cout << "1. See Menu.\n";
        cout << "2. Enter Review.\n";
        cout << "3. Bill divider.\n";
        cout << "4. Tip Calculator.\n";
        cout << "5. Back\n";
        cout << "Enter your selection: ";
        cin >> option;

        if (option == 1)
        {
            viewMenu();
        }

        else if (option == 2)
        {
            userReview();
        }

        else if (option == 3)
        {
            billDivider();
        }

        else if (option == 4)
        {
            tipCalculator();
        }
    }
}

//........................................Customer - add review
void userReview()
{

    getch();
    system("cls");
    header();

    cout << "\n\tCustomer window - add review \n\n";

    cout << "give review in this way : Poor , Bad , Average , Good , Excelent\n";

    cout << "\nRate services: \n";
    cin >> serviceReviews[reviewCount];

    cout << "Rate Food: \n";
    cin >> foodReviews[reviewCount];

    cout << "Rate Environment: \n";
    cin >> environmentReviews[reviewCount];
    reviewCount++;

    cout << "Thank You for review have a nice day";
}

//.......................................Customer - divide Bill
void billDivider()
{
    float totalbill;
    int peoplecount;

    float divided_bill;

    getch();
    system("cls");
    header();

    cout << "\n\tCustomer window - Divide Bill \n\n";

    cout << "Enter Total Bill: ";
    cin >> totalbill;

    cout << "Number of people: ";
    cin >> peoplecount;

    divided_bill = totalbill / peoplecount;

    cout << "Bill per person is: " << divided_bill;
}

//.......................................Customer - Tip Calculator
void tipCalculator()
{
    float totalbill, totalmoney, remaining, percentTip;
    int peoplecount;

    float tip;

    getch();
    system("cls");
    header();

    cout << "\n\tCustomer window - Tip Calculator \n\n";

    cout << "Enter total Money you gave: ";
    cin >> totalmoney;

    cout << "Enter total bill: ";
    cin >> totalbill;

    remaining = totalmoney - totalbill;

    if (remaining > 0)
    {

        cout << "Enter percentage of tip you want to give from remaining money (" << remaining << ") : ";
        cin >> percentTip;

        float remainingAfter = remaining - ((percentTip / 100) * remaining);

        tip = remaining - remainingAfter;

        cout << "You gave tip: " << tip << endl;
        if (remaining > 0)
        {
            cout << "Remaining money is: " << remainingAfter;
        }
    }
    else
    {
        cout << "Can not give tip";
    }
}

//......................................Clear Function
void clearFunction()
{
    getch();
    system("CLS");
}
// header
void header()
{
    cout << "*****************************************************************************************************\n";
    cout << "********************************  HOTEL MANAGEMENT SYSTEM  ******************************************\n";
    cout << "*****************************************************************************************************\n\n\n";
}