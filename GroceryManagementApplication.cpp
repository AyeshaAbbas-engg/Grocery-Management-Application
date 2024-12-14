#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
void gotoxy(int x, int y)
{

    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void header()
{
    setColor(3);
    cout << "                ###################################################################################################################################" << endl;
    cout << "                ##                                                                                                                               ##" << endl;
    cout << "                ##                                                    GROCERY MANAGEMENT APPLICATION                                             ##" << endl;
    cout << "                ##                                                                                                                               ##" << endl;
    cout << "                ###################################################################################################################################" << endl;
    cout << endl;
}
//----------------------------------------------------------All Checks  functions--------------------------#
string parsedata(string line, int field)
{
    int comma = 1;
    string word = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            comma++;
        }
        else if (comma == field)
        {
            word += line[i];
        }
    }
    return word;
}
char optionpin()
{
    char pin = ' ';
    cout << "Enter Your Option : ";
    pin = getch();
    return pin;
}

bool optcheck(char number)
{
    bool option = true;
    if (!(number == '2' || number == '1'))
    {
        option = false;
    }
    return option;
}
char Updatepin()
{
    bool option = false;
    char pin = ' ';
    while (!option)
    {

        pin = optionpin();
        if (!optcheck(pin))
        {
            cout << "Invalid number ! Only 1 and 2 is allowed \n";
        }
        else
        {
            option = true;
        }
    }
    return pin;
}
bool numberusernorepeatincart(int cartuser[], string number) // this checks that if user has entered the product number in list
{
    bool option = true;
    int num = 0;
    num = stoi(number);
    int h = 0;
    while (cartuser[h] != '\0')
    {
        h++;
    }
    for (int i = 0; i <= h; i++)
    {
        if ((num == cartuser[i]))
        {
            option = false;
            break;
        }
    }
    return option;
}
bool charlenadminuser(char pin) // it check the filhal length of user and admin menu
{
    bool option = true;
    if (!(pin > '0' && pin <= '9'))
    {
        option = false;
    }
    return option;
}
char checkoption()
{
    bool option = false;
    char pin = ' ';
    while (!option)
    {
        pin = optionpin();
        if (!charlenadminuser(pin))
        {
            cout << "Enter Valid number ! \n";
        }
        else
        {
            option = true;
        }
    }
    return pin;
}
bool charlenuser(char pin) // it check the filhal length of user and admin menu
{
    bool option = true;
    if (!(pin >= 'A' && pin <= 'J' || pin >= 'a' && pin <= 'j'))
    {
        option = false;
    }
    return option;
}
char checkoptionuser()
{
    bool option = false;
    char pin = ' ';
    while (!option)
    {
        pin = optionpin();
        if (!charlenuser(pin))
        {
            cout << "Enter Valid Character A-J ! \n";
        }
        else
        {
            option = true;
        }
    }
    return pin;
}
bool noreapeatproduct(string proname, string products[], int &productsidx, int &newpro)
{
    bool option = true;
    for (int i = 0; i < productsidx + newpro; i++)
    {
        if (proname == products[i])
        {
            option = false;
            break;
        }
    }
    return option;
}
bool norepeat(string pass, string password[], int &count) // this is generic code to check repetition!
{
    bool option = true;

    for (int j = 0; j < count; j++)
    {
        if (pass == password[j])
        {
            option = false;
            break;
        }
    }

    return option;
}
bool lenghtcheck(string word) // this is generic code to check the fix length 8!
{
    bool option = true;
    if (word.length() != 8)
    {
        option = false;
    }
    return option;
}
bool checkrequire(string name, int number) // this generic code checks what a user can put !
{
    bool option = true;
    int k = 0;
    while (k < name.length())
    {
        char a = name[k];

        if (!((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9') || (a == '!' || a == '$' || a == '#' || a == '%' || a == '&' || a == '*' || a == '_')))
        {
            option = false;
            break;
        }
        k++;
    }
    return option;
}
bool specilcheck(string name)
{
    bool option = false;
    int k = 0;
    while (k < name.length())
    {
        char a = name[k];
        if (a == '!' || a == '#' || a == '%' || a == '$' || a == '&' || a == '*' || a == '_')
        {
            return true;
        }
        k++;
    }
    return option;
}
bool checkalldigits(string name)
{
    bool option = true;
    int h = 0;
    while (h < name.length())
    {
        if (!((name[h] >= 'a' && name[h] <= 'z') || (name[h] >= 'A' && name[h] <= 'Z') || name[h] == '.' || name[h] == ',' || name[h] == '(' || name[h] == ')' || name[h] == ' '))
        {
            option = false;
            break;
        }
        h++;
    }
    return option;
}
bool checklistexist(string pin) // this checks the accountibility of 8 options in both user and admin menu
{
    bool option = true;
    if (!(pin == "1" || pin == "2" || pin == "3" || pin == "4" || pin == "5" || pin == "6" || pin == "7" || pin == "8"))
    {
        option = false;
    }
    return option;
}
string numberlist()
{

    string pin = " ";

    while (!checklistexist(pin))
    {
        cout << "Enter Your option : ";
        cin >> pin;
        if (!checklistexist(pin))
        {
            cout << "Invalid option ! \n";
        }
    }
    return pin;
}
bool pricequanrange(float price[], int idx) // it checks the range bw 1-1000
{
    bool option = true;
    if (!(price[idx] > 0 && price[idx] <= 1000))
    {
        option = false;
    }
    return option;
}
bool rangesimple(string number)
{
    bool option = true;
    int num = stoi(number);
    if (!(num > 0 && num <= 999))
    {
        option = false;
    }
    return option;
}
bool alpcheck(string products) // it checks the that there will be only alphabets in given string
{
    bool option = true;
    int h = 0;
    while (h < products.length())
    {

        char c = products[h];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
        {
            option = false;
            break;
        }
        h++;
    }
    return option;
}
bool alphacheck(string name)
{
    bool option = true;
    int h = 0;
    while (h < name.length())
    {
        if (!((name[h] >= 'a' && name[h] <= 'z') || (name[h] >= 'A' && name[h] <= 'Z')))
        {
            option = false;
            break;
        }
        h++;
    }
    return option;
}
bool isdigits(string name)
{
    int h = 0;
    bool option = true;
    while (h < name.length())
    {
        if (!(name[h] == '0' || name[h] == '1' || name[h] == '2' || name[h] == '3' || name[h] == '4' || name[h] == '5' || name[h] == '6' || name[h] == '7' || name[h] == '8' || name[h] == '9'))
        {

            option = false;
            break;
        }
        h++;
    }
    return option;
}
bool limit(string number)
{ // this checks the limits between your limits
    bool option = true;
    int range = 0;
    range = stoi(number);
    if (!(range > 0 && range <= 90))
    {
        option = false;
    }
    return option;
}
//---------------------------------------------------------------------------------------------------------
bool pincheck(char pin)
{
    bool option = true;

    if (!(pin == '1' || pin == '2' || pin == '3'))
    {
        option = false;
    }

    return option;
}
char takemainpin()
{
    char pin = ' ';
    cout << "Enter a number 1|2|3 : ";
    pin = getch();
    return pin;
}
char takenumber()
{
    char pin = ' ';

    bool option = false;
    while (!option)
    {
        pin = takemainpin();
        if (!pincheck(pin))
        {
            cout << "Invalid number ! \n";
        }
        else
        {
            option = true;
        }
    }

    return pin;
}
void menu() // 1st menu
{

    cout << "                                                                  ________________________ \n";
    cout << "                                                                  |WHAT DO YOU WANT TO DO|" << endl;
    cout << "                                                                  ------------------------ \n";
    cout << endl;
    cout << "1.Sign Up : " << endl;
    cout << "-----------" << endl;
    cout << "2.Login : " << endl;
    cout << "-----------" << endl;
    cout << "3.Exit : " << endl;
    cout << "-----------" << endl;
    cout << endl;
}

void MenuAdmin() // admin interface
{
    cout << "                                                                   _________________ \n";
    cout << "                                                                   |ADMIN INTERFACE|" << endl;
    cout << "                                                                   ----------------- \n";
    cout << endl;
    cout << "1.Enter New Products : \n";
    cout << "-----------" << endl;
    cout << "2.Update Product details : \n";
    cout << "-----------" << endl;
    cout << "3.Remove Product : \n";
    cout << "-----------" << endl;
    cout << "4.View all listing : \n";
    cout << "-----------" << endl;
    cout << "5.View Users Feedback : \n";
    cout << "-----------" << endl;
    cout << "6.View all Users details : \n";
    cout << "-----------" << endl;
    cout << "7.Change Credentials : \n";
    cout << "------------" << endl;
    cout << "8.Exit : \n";
    cout << "------------" << endl;
}
//-----------------------------------------------------1.Enter new Products !--------------------------------------------
void productsinfile(string products[], float price[], float tax[], float quantity[], int &productsidx)
{

    fstream file;
    file.open("Products.txt", ios::out);
    for (int i = 0; i < productsidx; i++)
    {
        file << products[i] << "," << quantity[i] << "," << tax[i] << "," << price[i] << endl;
    }
    file.close();
}
void readproductsfromfile(string products[], float price[], float tax[], float quantity[], int &productsidx)
{
    productsidx = 0;
    fstream file;
    file.open("Products.txt", ios::in);
    string line;
    string pri;
    string taxx;
    string quan;
    float p, t, q;
    while (getline(file, line))
    {
        products[productsidx] = parsedata(line, 1);
        pri = parsedata(line, 2);
        p = stof(pri);
        quantity[productsidx] = p;
        taxx = parsedata(line, 3);
        t = stof(taxx);
        tax[productsidx] = t;
        quan = parsedata(line, 4);
        q = stof(quan);
        price[productsidx] = q;
        productsidx++;
    }
}
string newprods()
{
    string produxts = " ";
    cout << "Enter how many new products you want to enter : ";
    cin >> produxts;
    return produxts;
}
bool checknewnum(int &newpro, int &productsidx)
{ // this checks the validity that the products number he wants to enter is valid
    bool option = false;
    string newp = " ";
    while (!option)
    {
        newp = newprods();

        if (!(isdigits(newp)))
        {
            cout << "Invalid products number ! only digits are allowed \n";
        }
        else if (!limit(newp))
        {
            cout << "Invalid Input! Enter only integers and no alphabets are allowed \n";
        }
        else
        {
            option = true;
        }
    }
    newpro = stoi(newp);

    return option;
}
string tookname()
{
    string name = " ";
    cout << "Enter the Name of product : ";
    cin >> name;
    return name;
}
bool checknewnumname(string products[], int &newpro, int &productsidx) // it checks the validity of name
{
    bool option;
    string name = " ";
    int str = productsidx;
    for (int i = str; i < newpro + str; i++)
    {
        option = false;
        while (!option)
        {
            name = tookname();
            if (!alpcheck(name))
            {
                cout << "Invalid name no spacing neither special characters nor integers are allowed ! \n";
            }
            else if (!noreapeatproduct(name, products, productsidx, newpro))
            {
                cout << "This name has already entered ! \n";
            }
            else
            {
                option = true;
            }
        }
        products[i] = name;
    }

    return option;
}
string quan()
{
    string quantity = "";
    cout << "Enter the quantity of new Product : ";
    cin >> quantity;
    return quantity;
}
bool checknewquan(float quantity[], int &newpro, int &productsidx)
{
    string took = " ";
    float take = 0.0;
    bool option;
    for (int i = productsidx; i < newpro + productsidx; i++)
    {
        option = false;
        while (!option)
        {
            took = quan();
            if (!(isdigits(took)))
            {
                cout << "Invalid Quantity ! only digits are allowed \n";
            }
            else if (!limit(took))
            {
                cout << "Invalid Quantity range has been set to 1-90 \n";
            }
            else
            {
                option = true;
            }
        }
        take = stof(took);
        quantity[i] = take;
    }
    return option;
}

string pricea()
{
    string name = " ";
    cout << "Enter the Price of new product : ";
    cin >> name;
    return name;
}
bool pricelimit(string range)
{
    bool option = true;
    float num = 0.0;
    num = stof(range);
    if (!(num > 0 && num <= 999))
    {
        option = false;
    }
    return option;
}
bool checknewprice(float price[], int &newpro, int &productsidx)
{
    bool option;
    string took = " ";
    float take = 0.0;
    for (int i = productsidx; i < newpro + productsidx; i++)
    {
        option = false;
        while (!option)
        {
            took = pricea();
            if (!isdigits(took))
            {
                cout << "Invalid Price range ! only digits are allowed \n";
            }
            else if (!pricelimit(took))
            {
                cout << "Invalid price range has been set to 1-1000 \n";
            }
            else
            {
                option = true;
            }
        }
        take = stof(took);
        price[i] = take;
    }
    return option;
}
bool taxrange(string name)
{
    float range = 0.0;
    range = stof(name);
    bool option = true;
    if (!(range > 0 && range <= 20))
    {
        option = false;
    }
    return option;
}
string taxget()
{
    string tax = " ";
    cout << "Enter the Tax of new Product : ";
    cin >> tax;
    return tax;
}
bool newtax(float tax[], int &productsidx, int &newpro)
{
    bool option;
    string took = " ";
    float take = 0.0;
    for (int i = productsidx; i < newpro + productsidx; i++)
    {
        option = false;
        while (!option)
        {
            took = taxget();
            if (!isdigits(took))
            {
                cout << "Invalid tax ! only digits are allowed ! \n";
            }
            else if (!taxrange(took))
            {
                cout << "Invalid TAX range has been set to 1-20 \n";
            }
            else
            {
                option = true;
            }
        }
        take = stof(took);
        tax[i] = take;
    }
    productsidx += newpro;
    return option;
}
void NewProducts(string products[], float price[], float tax[], float quantity[], int &productsidx, int &newpro)
{

    cout << endl;
    cout << "                                                                __________________ \n";
    cout << "                                                                |ADD NEW PRODUCTS| \n";
    cout << "                                                                ------------------ \n";
    cout << endl;
    bool newnum = checknewnum(newpro, productsidx);
    if (newnum)
    {
        bool checkname = checknewnumname(products, newpro, productsidx);
        if (checkname)
        {
            cout << "Name has been entered Successfully ! \n";
        }
        bool checkquan = checknewquan(quantity, newpro, productsidx);
        if (checkquan)
        {
            cout << "Quantity has been entered successfully! \n";
        }
        bool checkprice = checknewprice(price, newpro, productsidx);
        if (checkprice)
        {
            cout << "Price has been entered successfully ! \n";
        }
        bool checktax = newtax(tax, productsidx, newpro);
        if (checktax)
        {
            cout << "Tax has been added successfully ! \n";
        }
    }
}
//-----------------------------------------------------------------------2.update products-----------------------
// --------------------------------------------------------------this section changes the name of products--------------------
bool limitnumberupdated(string number, int productidx)
{
    bool option = true;
    int num = 0;
    num = stoi(number);
    if (!(num > 0 && num <= productidx))
    {
        option = false;
    }
    return option;
}
string takenumberupdated()
{
    string number = " ";
    cout << "Enter the corrosponding number you want to change  : ";
    cin >> number;
    return number;
}
string getupdatedname()
{
    string name = " ";
    cout << " Enter The Updated name : ";
    cin >> name;
    return name;
}
bool Updatedchecks(int &productsidx, string products[], int &newpro)
{
    bool option = false;
    string number = " ";
    string name = " ";
    while (!option)
    {
        number = takenumberupdated();
        if (!isdigits(number))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(number, productsidx))
        {
            cout << "Invalid number ! it should be between 1 and " << productsidx << " \n";
        }
        else
        {
            option = true;
        }
    }
    option = false;
    while (!option)
    {
        name = getupdatedname();
        if (!alphacheck(name))
        {
            cout << "Invalid name ! only alphabets are allowed \n";
        }
        else if (!noreapeatproduct(name, products, productsidx, newpro))
        {
            cout << "This name already exists! \n";
        }
        else
        {
            option = true;
        }
    }
    int idx = stoi(number);
    idx--;
    products[idx] = name;
    return option;
}
void updatenameadmin(int &productsidx, string products[], int &newpro)
{
    cout << endl;
    cout << "                                                            ____________________ \n";
    cout << "                                                            |CHANGE NAME SECTION | \n";
    cout << "                                                            -------------------- \n";
    cout << endl;
    if (Updatedchecks(productsidx, products, newpro))
    {
        cout << "Name has been Changed succesfully ! \n";
    }
}
//-------------------------------------------------------------------------------this section changes the quantity-----------------------------
string quantityadmin()
{
    string quan = " ";
    cout << "Enter the Updated Quantity  : ";
    cin >> quan;
    return quan;
}
bool UpdateQuanChecks(int &productsidx, float quantity[])
{
    bool option = false;
    string number = " ";
    string quantityy = " ";
    while (!option)
    {
        number = takenumberupdated();
        if (!isdigits(number))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(number, productsidx))
        {
            cout << "Invalid number ! it should be between 1 and " << productsidx << " \n";
        }
        else
        {
            option = true;
        }
    }
    option = false;
    while (!option)
    {
        quantityy = quantityadmin();
        if (!(isdigits(quantityy)))
        {
            cout << "Invalid number ! Quantity must contain numeric values  ! \n";
        }
        else if (!(rangesimple(quantityy)))
        {
            cout << "Invalid number ! Range has been fixed between 1-999 ! \n";
        }
        else
        {
            option = true;
        }
    }
    int idx = stoi(number);
    idx--;
    float num = stof(quantityy);
    quantity[idx] = num;
    return option;
}
void updatequantityadmin(int &productsidx, float quantity[])
{
    cout << endl;
    cout << "                                                              ________________________ \n";
    cout << "                                                             |CHANGE QUANTITY SECTION | \n";
    cout << "                                                              ------------------------ \n";
    cout << endl;
    if (UpdateQuanChecks(productsidx, quantity))
    {
        cout << "Quantity has been changed succesfully ! \n";
    }
}
//------------------------------------------------------------------this section changes the price------------------------
string priceadmin()
{
    string price = " ";
    cout << "Enter the Updated Price  : ";
    cin >> price;
    return price;
}
bool Updatepricecheck(int &productsidx, float price[])
{
    bool option = false;
    string number = " ";
    string pricee = " ";
    while (!option)
    {
        number = takenumberupdated();
        if (!isdigits(number))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(number, productsidx))
        {
            cout << "Invalid number ! it should be between 1 and " << productsidx << " \n";
        }
        else
        {
            option = true;
        }
    }
    option = false;
    while (!option)
    {
        pricee = priceadmin();
        if (!(isdigits(pricee)))
        {
            cout << "Invalid number ! Price must contain numeric values  ! \n";
        }
        else if (!(rangesimple(pricee)))
        {
            cout << "Invalid number ! Range has been fixed between 1-999 ! \n";
        }
        else
        {
            option = true;
        }
    }
    int idx = stoi(number);
    idx--;
    float neww = stof(pricee);
    price[idx] = neww;
    return option;
}
void Updatepriceadmin(int &productsidx, float price[])
{
    cout << endl;
    cout << "                                                              _____________________ \n";
    cout << "                                                             |CHANGE PRICE SECTION | \n";
    cout << "                                                              --------------------- \n";
    cout << endl;
    if (Updatepricecheck(productsidx, price))
    {
        cout << "Price has been changed successfully ! \n";
    }
}
//----------------------------------------------------------------this section changes the tax ---------------------
string Taxadmin()
{
    string tax = " ";
    cout << "Enter the Updated Tax  : ";
    cin >> tax;
    return tax;
}
bool UpdateTaxCheck(int &productsidx, float tax[])
{
    bool option = false;
    string number = " ";
    string taxx = " ";
    while (!option)
    {
        number = takenumberupdated();
        if (!isdigits(number))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(number, productsidx))
        {
            cout << "Invalid number ! it should be between 1 and " << productsidx << " \n";
        }
        else
        {
            option = true;
        }
    }
    option = false;
    while (!option)
    {
        taxx = Taxadmin();
        if (!(isdigits(taxx)))
        {
            cout << "Invalid number ! Tax must contain numeric values  ! \n";
        }
        else if (!taxrange(taxx))
        {
            cout << "Invalid Tax! Range has been fixed between 1-20 \n";
        }
        else
        {
            option = true;
        }
    }
    int idx = stoi(number);
    idx--;
    float num = stof(taxx);
    tax[idx] = num;
    return option;
}
void UpdateTaxadmin(int &productsidx, float tax[])
{

    cout << endl;
    cout << "                                                              ___________________ \n";
    cout << "                                                             |CHANGE TAX SECTION | \n";
    cout << "                                                              ------------------- \n";
    cout << endl;
    if (UpdateTaxCheck(productsidx, tax))
    {
        cout << "Tax has been Entered Successfully ! \n";
    }
}
bool updateprodetail(char pin)
{
    bool option = true;
    if (!(pin > '0' && pin <= '4'))
    {
        option = false;
    }
    return option;
}
char updatepin()
{
    bool option = false;
    char pin = ' ';
    while (!option)
    {
        pin = optionpin();
        if (!updateprodetail(pin))
        {
            cout << "Invalid number  \n";
        }
        else
        {
            option = true;
        }
    }
    return pin;
}
void updateproductsdetails()
{
    int option = 0;
    cout << endl;
    cout << "                                                             _________________________ \n";
    cout << "                                                             |UPDATE PRODUCTS DETAILS| \n";
    cout << "                                                             ------------------------- \n";
    cout << endl;
    cout << "Enter what you want to do : \n 1.Change Product Name : \n 2.Change quantity of product : \n 3.Change tax of product : \n 4.Change Price of Product : \n ";
    cout << "Enter your option : ";
}
//-----------------------------------------------------------------3.Delete Section------------------------
string deloption()
{
    string number = " ";
    cout << "Enter the corrosponding Number of Product you want to delete ";
    cin >> number;
    return number;
}
void deletedidxremove(int &delpro, int &productsidx, string products[], float quantity[], float tax[], float price[])
{
    for (int i = delpro; i < productsidx - 1; i++)
    {
        products[i] = products[i + 1];
        quantity[i] = quantity[i + 1];
        tax[i] = tax[i + 1];
        price[i] = price[i + 1];
    }
    productsidx--;
    cout << "Product has been deleted Successfully ! \n";
}
bool DeleteProadmin(int &productsidx, int &delpro)
{
    string number = " ";
    bool option = false;
    while (!option)
    {
        number = deloption();
        if (!isdigits(number))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(number, productsidx))
        {
            cout << "Invalid number ! it should be between 1 and " << productsidx << " \n";
        }
        else
        {
            option = true;
        }
    }
    delpro = stoi(number);
    delpro--;
    return option;
}
void Deleteadmin(int &delpro, int &productsidx, string products[], float quantity[], float tax[], float price[])
{
    cout << endl;
    cout << "                                                              _______________________ \n";
    cout << "                                                             |DELETE PRODUCT SECTION | \n";
    cout << "                                                              ----------------------- \n";
    cout << endl;
    if (DeleteProadmin(productsidx, delpro))
    {
        deletedidxremove(delpro, productsidx, products, quantity, tax, price);
    }
}
//-----------------------------------------------------------5.usersfeedback------------------------
void feedbackfile(string fb[], int &fbcount)
{
    fstream file;
    file.open("feedbacks.txt", ios::app);
    for (int i = 0; i < fbcount; i++)
    {
        file << fb[i] << "\n";
    }
    file.close();
}
void readfeedback(string fb[], int &feedbackphase)
{
    feedbackphase = 0;
    fstream file;
    string line = "";
    file.open("feedbacks.txt", ios::in);
    while (getline(file, line))
    {
        fb[feedbackphase] = line;
        feedbackphase++;
    }
    file.close();
}
void feedback(string fb[], int &feedbackphase)
{
    cout << endl;
    cout << "                                                              _______________________ \n";
    cout << "                                                             |USERS FEEDBACK SECTION | \n";
    cout << "                                                              ----------------------- \n";
    cout << endl;
    if (feedbackphase == 0)
    {
        cout << "     NO feedBack Yet ! \n";
    }
    else
    {

        cout << "All users feedback : \n";

        for (int i = 0; i < feedbackphase; i++)
        {
            cout << i + 1 << ". " << fb[i] << endl;
            cout << endl;
        }
    }
}
//---------------------------------------------------------6.All users detail----
void Usersdetail(string role[], int &phase, string signupname[], string password[])
{
    cout << endl;
    cout << "                                                             __________________ \n";
    cout << "                                                            | ALL USERS DETAIL |\n";
    cout << "                                                             ------------------ \n";
    cout << endl;
    if (phase == 1)
    {
        cout << "           NO USERS DETAILS YET  \n";
    }
    else
    {

        for (int i = 0; i < phase; i++)
        {
            string a = role[i];
            char c = a[0];
            if (c == '2')
            {
                cout << signupname[i] << " \t " << password[i] << " \n";
            }
        }
    }
}
void alldata(string role[], int &phase, string signupname[], string password[])
{
    for (int i = 0; i < phase; i++)
    {
        cout << signupname[i] << " " << password[i] << " " << role[i] << " \n";
    }
}
//-----------------------------7.Change credentials------------------------------------
string prename()
{
    string name = " ";
    cout << "Enter the previous name : ";
    cin >> name;
    return name;
}
string newname()
{
    string name = " ";
    cout << "Enter new name : ";
    cin >> name;
    return name;
}
bool checkprenameexist(string name, int &phase, string names[], int &changecreidx)
{
    bool option = false;
    for (int i = 0; i < phase; i++)
    {
        if ((name == names[i]))
        {
            option = true;
            changecreidx = i;
        }
    }
    return option;
}
bool checklen(string name)
{
    bool option = true;
    if (name.length() < 8)
    {
        option = false;
    }
    return option;
}

bool checkpreviouscred(string signupname[], int &phase, int &changecreidx)
{
    string name = " ";
    string neww = " ";
    bool option = false;
    while (!option)
    {
        name = prename();
        if (!checkprenameexist(name, phase, signupname, changecreidx))
        {
            cout << "No name found \n";
        }
        else
        {
            neww = newname();

            if (!checklen(neww))
            {
                cout << "Length must be of 8 digits or greater \n";
            }
            else if (!norepeat(neww, signupname, phase))
            {
                cout << "This name has already been taken \n";
            }
            else
            {
                option = true;
            }
        }
    }
    signupname[changecreidx] = neww;
    return option;
}
void Changename(string signupname[], int &phase, int &changecreidx)
{
    cout << endl;
    cout << "                                                          ____________________\n";
    cout << "                                                         |CHANGE NAME SECTION |\n";
    cout << "                                                         ----------------------\n";
    cout << endl;
    if (checkpreviouscred(signupname, phase, changecreidx))
    {
        cout << "Name has been changed successfully \n";
    }
}
string prepass()
{
    string pass = " ";
    cout << "Enter The Previous Password : ";
    cin >> pass;
    return pass;
}
string newpass()
{
    string pass = " ";
    cout << "Enter new Password : ";
    cin >> pass;
    return pass;
}
bool checkpreviouscredpass(string password[], int &phase, int &changecreidx)
{
    string pass = " ";
    string neww = " ";
    bool option = false;
    while (!option)
    {
        pass = prepass();
        if (!checkprenameexist(pass, phase, password, changecreidx))
        {
            cout << "No Password found \n";
        }
        else
        {
            neww = newpass();

            if (!lenghtcheck(neww))
            {
                cout << "Length must be of 8 digits \n";
            }
            else if (!norepeat(neww, password, phase))
            {
                cout << "This password is already been taken \n";
            }
            else if (!specilcheck(neww))
            {
                cout << "Password must contain a special character \n";
            }
            else
            {
                option = true;
            }
        }
    }
    password[changecreidx] = neww;
    return option;
}
void Changepass(string password[], int &phase, int &changecreidx)
{
    cout << endl;
    cout << "                                                          ________________________\n";
    cout << "                                                         |CHANGE PASSWORD SECTION |\n";
    cout << "                                                         -------------------------\n";
    cout << endl;
    if (checkpreviouscredpass(password, phase, changecreidx))
    {
        cout << "Password has been changed Successfully \n";
    }
}
void changecredentials()
{
    cout << endl;
    cout << "                                                           ___________________________\n";
    cout << "                                                          |CHANGE CREDENTIALS SECTIONS|\n";
    cout << "                                                          -----------------------------\n";
    cout << endl;
    cout << "What do you want  to do :\n1.Change Name \n2.Change Password \n";
}
//---------------------------------------------------------------USER SECTION--------------------------

void UserMenu()
{

    cout << "                                                            ________________ \n";
    cout << "                                                            |USER INTERFACE| \n";
    cout << "                                                            ---------------- \n";
    cout << endl;
    cout << "A.Browse Products : \n";
    cout << "-----------" << endl;
    cout << "B.Add products : \n";
    cout << "-----------" << endl;
    cout << "C.View Cart : \n";
    cout << "-----------" << endl;
    cout << "D.Upadation : \n";
    cout << "-----------" << endl;
    cout << "E.Delete product : \n";
    cout << "-----------" << endl;
    cout << "F.Checkout : \n";
    cout << "-----------" << endl;
    cout << "G.Feedback : \n";
    cout << "-----------" << endl;
    cout << "H.Change credentials : \n";
    cout << "-----------" << endl;
    cout << "I.All History : \n";
    cout << "-----------" << endl;
    cout << "J.log out : \n";
    cout << "-----------" << endl;
}
//------------------------------------------------------2.Add Products------------------------
string numberinCart()
{
    string number = " ";
    cout << "Enter the Corrosponding  number you want to add in cart : ";
    cin >> number;
    return number;
}
string quaninCart()
{
    string number = " ";
    cout << "Enter the Quantity you want you add in cart : ";
    cin >> number;
    return number;
}
bool quanuserlimit(string quantity, float limit)
{
    bool option = true;
    int num = 0;
    num = stoi(quantity);
    if (!(num > 0 && num <= limit))
    {
        option = false;
    }
    return option;
}
bool Quancheckuser(int &cartnumuser, float quantity[], float quanuser[], int cartuser[])
{
    int cartidx = 0;
    bool option;
    string quann = " ";

    for (int i = 0; i < cartnumuser; i++)
    {
        cartidx = cartuser[i];
        option = false;
        while (!option)
        {
            quann = quaninCart();
            if (!isdigits(quann))
            {
                cout << "Enter Valid number ! only numeric values are allowed \n";
            }
            else if (!quanuserlimit(quann, quantity[cartidx]))
            {
                cout << "Enter Valid quantity ! range has set between 1 and " << quantity[cartidx] << " \n";
            }
            else
            {
                option = true;
            }
        }
        float val = stof(quann);
        quanuser[i] = val;
    }
    return option;
}
bool CheckCart(int &productidx, int &cartnumuser, int cartuser[])
{
    bool option = false;
    string num = " ";
    string Corcart = " ";

    while (!option)
    {
        num = newprods();
        if (!isdigits(num))
        {
            cout << "Invalid number ! only digits numbers \n";
        }
        else if (!limitnumberupdated(num, productidx))
        {
            cout << "Invalid number ! Enter number between 1 and " << productidx << " \n";
        }
        else
        {
            option = true;
        }
    }

    int cart = stoi(num);
    cartnumuser = cart;
    for (int i = 0; i < cartnumuser; i++)
    {
        option = false;

        while (!option)
        {
            Corcart = numberinCart();
            if (!isdigits(Corcart))
            {
                cout << "Invalid number! only digits allowed \n";
            }
            else if (!(limitnumberupdated(Corcart, productidx)))
            {
                cout << "Invalid number ! Enter number between 1 and " << productidx << " \n";
            }
            else
            {
                option = true;
            }
        }
        int display = stoi(Corcart);
        display--;
        cartuser[i] = display;
    }
    return option;
}
void AddProductsincCart(int &productsidx, int &cartnumuser, int cartuser[], float quantity[], float quanuser[])
{
    cout << endl;
    cout << "                                                            _____________________ \n";
    cout << "                                                           |ADD PRODUCTS SECTION | \n";
    cout << "                                                           ----------------------- \n";
    cout << endl;
    if (CheckCart(productsidx, cartnumuser, cartuser))
    {
        cout << "Product has been entered succcessfully ! \n";
    }
    if (Quancheckuser(cartnumuser, quantity, quanuser, cartuser))
    {
        cout << "Quantity has been entered Successfully ! \n";
    }
}
//---------------------------------------------------4.Updation-----------------------------
string tochange()
{
    string change = " ";
    cout << "Enter the new  corrosponding number you want to add in cart : ";
    cin >> change;
    return change;
}
bool ChangeUserpro(int &cartnumuser, int cartuser[], int &productsidx, float quanuser[])
{
    bool option = false;
    string number = " ";
    string nameidx = " ";
    while (!option)
    {
        number = takenumberupdated();
        if (!isdigits(number))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(number, cartnumuser))
        {
            cout << "Invalid number ! it should be between 1 and " << cartnumuser << " \n";
        }
        else
        {
            option = true;
        }
    }
    option = false;
    while (!option)
    {
        nameidx = tochange();
        if (!isdigits(nameidx))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(nameidx, productsidx))
        {
            cout << "Invalid number ! it should be between 1 and " << productsidx << " \n";
        }
        else
        {
            option = true;
        }
    }
    int changename = stoi(number);
    changename--;
    int preidx = stoi(nameidx);
    preidx--;
    cartuser[changename] = preidx;

    return option;
}
void Updatenameuser(int &cartnumuser, int cartuser[], int &productsidx, float quanuser[])
{
    cout << endl;
    cout << "                                                            ____________________ \n";
    cout << "                                                           |CHANGE PRODUCT NAME | \n";
    cout << "                                                           --------------------- \n";
    cout << endl;
    if (ChangeUserpro(cartnumuser, cartuser, productsidx, quanuser))
    {
        cout << "Product has been changed successfully ! \n";
    }
}
bool CheckUpdatequanuser(int &cartnumuser, float quanuser[], float quantity[])
{
    bool option = false;
    int idxquan = 0;
    string number = " ";
    string nameidx = " ";
    int newquan = 0;
    while (!option)
    {
        number = takenumberupdated();
        if (!isdigits(number))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(number, cartnumuser))
        {
            cout << "Invalid number ! it should be between 1 and " << cartnumuser << " \n";
        }
        else
        {
            option = true;
        }
    }
    option = false;
    while (!option)
    {
        nameidx = tochange();
        idxquan = stoi(number);
        idxquan--;
        newquan = stoi(nameidx);
        if (!isdigits(nameidx))
        {
            cout << "Invalid number ! it should only contain numeric values \n";
        }
        else if (!limitnumberupdated(nameidx, quantity[idxquan]))
        {
            cout << "Invalid number ! it should be between 1 and " << quantity[idxquan] << " \n";
        }
        else
        {
            option = true;
        }
    }

    newquan = stoi(number);
    newquan--;
    float quanidx = stof(nameidx);
    quanuser[newquan] = quanidx;
    return option;
}

void Updatequanuser(int &cartnumuser, float quanuser[], float quantity[])
{
    cout << endl;
    cout << "                                                               ________________________ \n";
    cout << "                                                              |CHANGE PRODUCT QUANTITY | \n";
    cout << "                                                              -------------------------- \n";
    cout << endl;
    if (CheckUpdatequanuser(cartnumuser, quanuser, quantity))
    {
        cout << "Quantity has been changed successfully ! \n";
    }
}

void updateproductsdetailsuser()
{
    int option = 0;
    cout << endl;
    cout << "                                                                  _____________________ \n";
    cout << "                                                                  |UPDATE CART SECTION| \n";
    cout << "                                                                  --------------------- \n";
    cout << endl;
    cout << "Enter what you want to do : \n 1.Change Product : \n 2.Change quantity of product  \n ";
}
//-------------------------------------------------------7.Feed Back--------------------------
string responseuser()
{
    string name = " ";
    cout << "press enter to start writing : \n";
    getch();
    cin.ignore();
    cout << "Enter Your Fruitful response : ";
    getline(cin, name);
    return name;
}
bool Checkresponse(string fb[], int &fbcount)
{
    bool option = false;
    string response = " ";
    while (!option)
    {
        response = responseuser();
        if (!checkalldigits(response))
        {
            cout << "Sorry but you cant use anything except for alphabets and(',','.','(',')') \n";
        }
        else
        {
            option = true;
        }
    }
    fb[fbcount] = response;
    return option;
}
//------------------------------------------------------------------3. -view cart-------------------------------
void ViewProductsUser(string products[], int &cartnumuser, int &productsidx, int cartuser[], float quanuser[], float quantity[], float priceuser[], float price[], float taxuser[], float tax[], float &checkout) // shows all the products to both admin and user
{
    cout << endl;
    cout << "                                                                         ___________ \n";
    cout << "                                                                         |VIEW CART| \n";
    cout << "                                                                         ----------- \n";
    cout << endl;
    checkout = 0;

    cout << "| No | Product      |  Quan   |  Tax    |  Price   |\n";
    cout << "|----|--------------|---------|---------|----------|\n";
    for (int i = 0; i < cartnumuser; i++)
    {
        int cartval = cartuser[i];
        cout << "| " << i + 1;
        if (i + 1 < 10)
            cout << "  ";
        else
            cout << " ";
        cout << "| " << products[cartval];
        for (int j = products[cartval].length(); j < 13; j++)
            cout << " ";
        cout << "| " << fixed << setprecision(2) << quanuser[i];
        if (quanuser[cartval] < 10)
            cout << "    ";
        else if (quanuser[cartval] < 100)
            cout << "   ";
        cout << "| " << fixed << setprecision(2) << tax[cartval];
        if (tax[cartval] < 10)
            cout << "    ";
        else
            cout << "   ";
        cout << "| " << fixed << setprecision(2) << ((price[cartval] * quanuser[i]) + (price[cartval] * (tax[cartval] / 100)));
        if (((price[cartval] * quanuser[i]) + (price[cartval] * (tax[cartval] / 100))) < 10000)
            cout << "  ";
        else if (((price[cartval] * quanuser[i]) + (price[cartval] * (tax[cartval] / 100))) < 1000)
            cout << "  ";
        cout << "|\n";
        checkout += (price[cartval] * quanuser[i]) + (price[cartval] * (tax[cartval] / 100));
    }
}
void Checkout(float &checkout)
{
    cout << endl;
    cout << "                                                                ___________ \n";
    cout << "                                                               | CHECKOUTS |\n";
    cout << "                                                               -------------\n";
    cout << endl;
    cout << "_________________________________________________\n";
    cout << "|TOTAL BILL YOU HAVE TO PAY : " << checkout << " /-pkr|\n ";
    cout << "-------------------------------------------------\n";
    cout << endl;
    cout << "                                                               THANK YOU FOR SHOPPING \n";
}
//---------------------------------------------------------5.Delete Product-----------
void Deleteuser(int &deluser, int &cartnumuser, string products[], float quanuser[], float tax[], float price[])
{
    cout << endl;
    cout << "                                                              _______________________ \n";
    cout << "                                                             |DELETE PRODUCT SECTION | \n";
    cout << "                                                              ----------------------- \n";
    cout << endl;
    if (DeleteProadmin(cartnumuser, deluser))
    {
        deletedidxremove(deluser, cartnumuser, products, quanuser, tax, price);
    }
}
void FeedbackUser(string fb[], int &fbcount)
{

    cout << endl;
    cout << "                                                                 ______________________ \n";
    cout << "                                                                 |USER FEEDBACK SECTION| \n";
    cout << "                                                                 ----------------------  \n";
    cout << endl;

    if (Checkresponse(fb, fbcount))
    {
        cout << "YOUR RESPONSE HAS BEEN SUBMITTED SUCCESFULLY ! " << endl;
    }
    fbcount++;
}
//-----------------------------------------------9.All history
void historyinfile(string products[], int &cartnumuser, int &productsidx, int cartuser[], float quanuser[], float price[], float tax[])
{
    fstream file;
    file.open("history.txt", ios::app);
    for (int i = 0; i < cartnumuser; i++)
    {
        int idx = cartuser[i];
        file << products[idx] << "," << quanuser[i] << "," << tax[idx] << "," << ((price[idx] * quanuser[i]) + (price[idx] * (tax[idx] / 100))) << endl;
    }
    file.close();
}
void readfromfilehistory(string userhisproducts[], string userhisprice[], string userhisquan[], string userhistax[], int &hisidx)
{
    string line, qun, taxx, pri;
    float q, t, p;
    hisidx = 0;

    fstream file;
    file.open("history.txt", ios::in);
    while (getline(file, line))
    {
        userhisproducts[hisidx] = parsedata(line, 1);
        qun = parsedata(line, 2);
        userhisquan[hisidx] = qun;
        taxx = parsedata(line, 3);
        userhistax[hisidx] = taxx;
        pri = parsedata(line, 4);
        userhisprice[hisidx] = pri;
        hisidx++;
    }
    file.close();
}
void Historydisplay(string userhisproducts[], string userhisprice[], string userhisquan[], string userhistax[], int &hisidx)
{
    cout << endl;
    cout << "                                                                         ___________ \n";
    cout << "                                                                         | History | \n";
    cout << "                                                                         ----------- \n";
    cout << endl;

    cout << "| No | Product      |  Quan   |  Tax    |  Price   |\n";
    cout << "|----|--------------|---------|---------|----------|\n";
    for (int i = 0; i < hisidx; i++)
    {
        cout << "| " << i + 1;
        if (i + 1 < 10)
            cout << "  ";
        else
            cout << " ";
        cout << "| " << userhisproducts[i];
        for (int j = userhisproducts[i].length(); j < 13; j++)
            cout << " ";
        cout << "| " << fixed << setprecision(2) << userhisquan[i];
        if (userhisquan[i].length() < 10)
            cout << "       ";
        else if (userhisquan[i].length() < 100)
            cout << "       ";
        cout << "| " << fixed << setprecision(2) << userhistax[i];
        if (userhistax[i].length() < 10)
            cout << "      ";
        else
            cout << "      ";
        cout << "| " << fixed << setprecision(2) << userhisprice[i];
        if (userhisprice[i].length() < 10000)
            cout << "    ";
        else if (userhisprice[i].length() < 1000)
            cout << "    ";
        cout << " |\n";
    }
}
//--------------------------------------------------for both user and admin display All products=-------------
void DisplayProducts(string products[], float quantity[], int &productsidx, float tax[], float price[]) // shows all the products to both admin and user
{
    cout << endl;
    cout << "                                                                      __________________ \n";
    cout << "                                                                      |Display PRODUCTS| \n";
    cout << "                                                                      ------------------ \n";
    cout << endl;

    cout << "| No | Product      |  Stock  |  Tax    |  Price   |\n";
    cout << "|----|--------------|---------|---------|----------|\n";
    for (int i = 0; i < productsidx; i++)
    {
        cout << "| " << i + 1;
        if (i + 1 < 10)
            cout << "  ";
        else
            cout << " ";
        cout << "| " << products[i];
        for (int j = products[i].length(); j < 13; j++)
            cout << " ";
        cout << "| " << fixed << setprecision(2) << quantity[i];
        if (quantity[i] < 10)
            cout << "    ";
        else if (quantity[i] < 100)
            cout << "   ";
        cout << "| " << fixed << setprecision(2) << tax[i];
        if (tax[i] < 10)
            cout << "    ";
        else
            cout << "   ";
        cout << "| " << fixed << setprecision(2) << price[i];
        if (price[i] < 100)
            cout << "    ";
        else if (price[i] < 1000)
            cout << "   ";
        cout << "|\n";
    }
}

//------------------------------------------------------------------signup/login--------------------

bool nameconfirm(string signupname[], int &count, int &phase) // ye check krna ky user ny saii saii put kia h sb kch
{
    bool option = false;
    string name = " ";
    while (!option)
    {

        cout << "ENTER YOUR NAME : ";
        cin >> name;
        if (!norepeat(name, signupname, phase))
        {
            cout << "This Name has already been taken! Enter again \n";
        }

        else if (!checklen(name))
        {
            cout << "INVALID LENGTH! It should be of 8 characters or  greater. \n";
        }

        else if (!checkrequire(name, phase))
        {
            cout << "Invalid User name ! \n";
        }
        else
        {
            option = true;
        }
    }
    signupname[phase] = name;
    return option;
}

bool passwordconfirm(string password[], int &count, int &phase)
{ // to confirm password under my validations
    bool option = false;
    string pass = " ";
    while (!option)
    {
        cout << "Enter your password  : ";
        cin >> pass;
        if (!norepeat(pass, password, phase))
        {
            cout << "This Password has already been taken! Enter again \n";
        }
        if (!lenghtcheck(pass))
        {
            cout << "Enter valid length! it must be of 8 characters! \n ";
        }
        if (!checkrequire(pass, phase))
        {
            cout << "Password should contain a speacial character, a integer and alphabets ! \n";
        }
        if (!specilcheck(pass))
        {
            cout << "Password must contain a special character \n";
        }
        else
        {
            option = true;
        }
    }
    password[phase] = pass;
    return option;
}
bool rolenumber(char pin)
{
    bool option = true;
    if (!(pin == '1' || pin == '2'))
    {
        option = false;
    }
    return option;
}
bool roleconfirm(string role[], int &phase) // to confirm the role
{
    char pin = ' ';
    bool option = rolenumber(pin);
    while (!option)
    {

        cout << " 1.ADMIN \n 2.USER \n Enter number corrosponding to your Role  : ";
        pin = getch();
        option = rolenumber(pin);
        if (!option)
        {
            cout << "Enter Valid number! \n";
        }
    }
    role[phase] = pin;
    return option;
}

void signup(string signupname[], string password[], string role[], int &count, int &phase) // signup wala funtion
{
    cout << endl;
    cout << "                                                             ______________ \n";
    cout << "                                                             |SIGN UP PAGE| \n";
    cout << "                                                             -------------- \n";
    cout << endl;
    // phase--;
    bool signnameconfirm = nameconfirm(signupname, count, phase);
    if (signnameconfirm)
    {
        cout << "Entered name successfully!";
        cout << endl;
    }
    bool signpassconfirm = passwordconfirm(password, count, phase);
    if (signpassconfirm)
    {
        cout << "Entered password successfully! ";
        cout << endl;
    }
    bool signroleconfirm = roleconfirm(role, phase);
    if (signroleconfirm)
    {
        cout << "Entered Role Successfully!" << endl;
    }
    phase++;
}
void signupfile(string signupname[], string password[], string role[], int &phase)
{
    fstream File;
    File.open("Signup.txt", ios::out);
    for (int i = 0; i < phase; i++)
    {
        File << signupname[i] << "," << password[i] << "," << role[i] << " \n";
    }
    File.close();
}
bool login(string signupname[], string password[], string role[], int &phase, int &phaserole)
{
    string name = " ";
    string pass = " ";
    string line = " ";
    bool option = false;
    cout << endl;
    cout << "                                                              ____________ \n";
    cout << "                                                              |LOGIN MENU| \n";
    cout << "                                                              ------------ \n";
    cout << endl;
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter Password : ";
    cin >> pass;
    for (int i = 0; i < phase; i++)
    {

        if (name == signupname[i] && pass == password[i])
        {
            option = true;
            phaserole = i;
            break;
        }
    }

    return option;
}
void readsignup(string signupname[], string password[], string role[], int &phase)
{
    phase = 0;
    string line = "";
    fstream file;
    file.open("Signup.txt", ios::in);
    while (getline(file, line))
    {
        signupname[phase] = parsedata(line, 1);
        password[phase] = parsedata(line, 2);
        role[phase] = parsedata(line, 3);
        phase++;
    }
    file.close();
}
void exit()
{
    gotoxy(0, 10);
    cout << "                                       .----------------.  .----------------.  .----------------.  .----------------.\n";
    gotoxy(0, 11);
    cout << "                                      | .--------------. || .--------------. || .--------------. || .--------------. |\n";
    gotoxy(0, 12);
    cout << "                                      | |  _________   | || |  ____  ____  | || |     _____    | || |  _________   | |\n";
    gotoxy(0, 13);
    cout << "                                      | | |_   ___  |  | || | |_  _||_  _| | || |    |_   _|   | || | |  _   _  |  | |\n";
    gotoxy(0, 14);
    cout << "                                      | |   | |_  \\_|  | || |   \\ \\  / /   | || |      | |     | || | |_/ | | \\_|  | |\n";
    gotoxy(0, 15);
    cout << "                                      | |   |  _|  _   | || |    > `' <    | || |      | |     | || |     | |      | |\n";
    gotoxy(0, 16);
    cout << "                                      | |  _| |___/ |  | || |  _/ /'`\\ \\_  | || |     _| |_    | || |    _| |_     | |\n";
    gotoxy(0, 17);
    cout << "                                      | | |_________|  | || | |____||____| | || |    |_____|   | || |   |_____|    | |\n";
    gotoxy(0, 18);
    cout << "                                      | |              | || |              | || |              | || |              | |\n";
    gotoxy(0, 19);
    cout << "                                      | '--------------' || '--------------' || '--------------' || '--------------' |\n";
    gotoxy(0, 20);
    cout << "                                      '----------------'  '----------------'  '----------------'  '----------------' \n";
}
void clearscreen()
{
    cout << "Press any key to continue : ";
    getch();
    system("cls");
}
//---------------------------------------------------------File handling ------------------------------------------------

main()
{
    int phaserole = 0;
    int count = 0;
    int changecreidx = 0;
    int phase = 0;
    string role[100];
    string signupname[100];
    string password[100];
    string products[100];
    float price[100];
    float tax[100];
    float quantity[100];
    string userhisproducts[100];
    string userhisprice[100];
    string userhisquan[100];
    string userhistax[100];
    int hisidx = 0;
    int productsidx = 0;
    int newpro = 0;
    int numname = 0;
    int quannum = 0;
    int taxnum = 0;
    int feedbackphase = 0;
    int pricenum = 0;
    int delpro = 0;
    int cartnumuser = 0;
    int cartuser[100];
    float quanuser[100];
    float priceuser[100];
    float taxuser[100];
    int userproname = 0;
    int userquannum = 0;
    int swapuserpro = 0;
    int deluser = 0;
    string fb[100];
    int fbcount = 0;
    float checkout = 0.0;
    string valusermenu = " ";
    char user = ' ';
    char pin = ' ';
    while (pin != '3')
    {

        readproductsfromfile(products, price, tax, quantity, productsidx);
        readsignup(signupname, password, role, phase);
        readfeedback(fb, feedbackphase);
        system("cls");
        header();
        menu();
        pin = takenumber();
        if (pin == '1')
        {
            system("cls");
            header();
            signup(signupname, password, role, count, phase);
            signupfile(signupname, password, role, phase);
        }
        else if (pin == '2')
        {

            system("cls");
            header();
            bool loginval = login(signupname, password, role, phase, phaserole);
            char option = ' ';
            if (loginval)
            {
                string roleget = role[phaserole];
                char a = roleget[0];
                if (a == '1')
                {
                    while (option != '8')
                    {
                        system("cls");
                        MenuAdmin();
                        option = checkoption();
                        if (option == '1')
                        {
                            system("cls");
                            DisplayProducts(products, quantity, productsidx, tax, price);
                            NewProducts(products, price, tax, quantity, productsidx, newpro);
                            productsinfile(products, price, tax, quantity, productsidx);
                            clearscreen();
                        }
                        else if (option == '2')
                        {
                            system("cls");
                            updateproductsdetails();
                            char update = updatepin();
                            if (update == '1')
                            {
                                system("cls");
                                DisplayProducts(products, quantity, productsidx, tax, price);
                                updatenameadmin(productsidx, products, newpro);
                                productsinfile(products, price, tax, quantity, productsidx);
                                clearscreen();
                            }
                            else if (update == '2')
                            {
                                system("cls");
                                DisplayProducts(products, quantity, productsidx, tax, price);
                                updatequantityadmin(productsidx, quantity);
                                productsinfile(products, price, tax, quantity, productsidx);
                                clearscreen();
                            }
                            else if (update == '3')
                            {
                                system("cls");
                                DisplayProducts(products, quantity, productsidx, tax, price);
                                Updatepriceadmin(productsidx, price);
                                productsinfile(products, price, tax, quantity, productsidx);
                                clearscreen();
                            }
                            else if (update == '4')
                            {
                                system("cls");
                                DisplayProducts(products, quantity, productsidx, tax, price);
                                UpdateTaxadmin(productsidx, tax);
                                productsinfile(products, price, tax, quantity, productsidx);

                                clearscreen();
                            }
                            else
                            {
                                cout << "Input Valid number ! \n";
                            }
                        }
                        else if (option == '3')
                        {
                            system("cls");
                            DisplayProducts(products, quantity, productsidx, tax, price);
                            Deleteadmin(delpro, productsidx, products, quantity, tax, price);
                            productsinfile(products, price, tax, quantity, productsidx);
                            clearscreen();
                        }
                        else if (option == '4')
                        {
                            system("cls");
                            DisplayProducts(products, quantity, productsidx, tax, price);
                            clearscreen();
                        }
                        else if (option == '5')
                        {
                            system("cls");
                            feedback(fb, feedbackphase);
                            clearscreen();
                        }
                        else if (option == '6')
                        {
                            system("cls");
                            Usersdetail(role, phase, signupname, password);
                            clearscreen();
                        }
                        else if (option == '7')
                        {
                            system("cls");
                            changecredentials();
                            char cre = Updatepin();
                            if (cre == '1')
                            {
                                system("cls");
                                Changename(signupname, phase, changecreidx);
                                signupfile(signupname, password, role, phase);
                                clearscreen();
                            }
                            else if (cre == '2')
                            {
                                system("cls");
                                Changepass(password, phase, changecreidx);
                                signupfile(signupname, password, role, phase);
                                clearscreen();
                            }
                        }
                    }
                }
                else if (a == '2')
                {
                    while (true)
                    {
                        system("cls");
                        UserMenu();
                        user = checkoptionuser();
                        if (user == 'A' || user == 'a')
                        {
                            system("cls");
                            DisplayProducts(products, quantity, productsidx, tax, price);
                            clearscreen();
                        }
                        else if (user == 'B' || user == 'b')
                        {
                            system("cls");
                            DisplayProducts(products, quantity, productsidx, tax, price);
                            AddProductsincCart(productsidx, cartnumuser, cartuser, quantity, quanuser);
                            clearscreen();
                        }
                        else if (user == 'C' || user == 'c')
                        {
                            system("cls");
                            ViewProductsUser(products, cartnumuser, productsidx, cartuser, quanuser, quantity, priceuser, price, taxuser, tax, checkout);
                            clearscreen();
                        }
                        else if (user == 'D' || user == 'd')
                        {
                            system("cls");
                            updateproductsdetailsuser();
                            char uppin = Updatepin();
                            if (uppin == '1')
                            {
                                system("cls");
                                ViewProductsUser(products, cartnumuser, productsidx, cartuser, quanuser, quantity, priceuser, price, taxuser, tax, checkout);
                                Updatenameuser(cartnumuser, cartuser, productsidx, quanuser);
                                clearscreen();
                            }
                            else if (uppin == '2')
                            {
                                system("cls");
                                ViewProductsUser(products, cartnumuser, productsidx, cartuser, quanuser, quantity, priceuser, price, taxuser, tax, checkout);
                                Updatequanuser(cartnumuser, quanuser, quantity);
                                clearscreen();
                            }
                        }
                        else if (user == 'E' || user == 'e')
                        {
                            system("cls");
                            ViewProductsUser(products, cartnumuser, productsidx, cartuser, quanuser, quantity, priceuser, price, taxuser, tax, checkout);
                            Deleteuser(deluser, cartnumuser, products, quanuser, tax, price);
                            clearscreen();
                        }
                        else if (user == 'F' || user == 'f')
                        {
                            system("cls");
                            Checkout(checkout);
                            clearscreen();
                        }
                        else if (user == 'G' || user == 'g')
                        {
                            system("cls");
                            FeedbackUser(fb, fbcount);
                            feedbackfile(fb, fbcount);
                            clearscreen();
                        }
                        else if (user == 'H' || user == 'h')
                        {
                            system("cls");
                            changecredentials();
                            char usercre = Updatepin();
                            if (usercre == '1')
                            {
                                system("cls");
                                Changename(signupname, phase, changecreidx);
                                signupfile(signupname, password, role, phase);
                                clearscreen();
                            }
                            else if (usercre == '2')
                            {
                                system("cls");
                                Changepass(password, phase, changecreidx);
                                signupfile(signupname, password, role, phase);
                                clearscreen();
                            }
                        }
                        else if (user == 'I' || user == 'i')
                        {
                            system("cls");
                            readfromfilehistory(userhisproducts, userhisprice, userhisquan, userhistax, hisidx);
                            Historydisplay(userhisproducts, userhisprice, userhisquan, userhistax, hisidx);
                            clearscreen();
                        }
                        else if (user == 'J' || user == 'j')
                        {
                            historyinfile(products, cartnumuser, productsidx, cartuser, quanuser, price, tax);
                            break;
                        }
                    }
                }
            }
            else if (!loginval)
            {
                cout << "You have entered wrong credentials \n";
                clearscreen();
            }
        }
    }
    if (pin == '3')
    {
        system("cls");
        exit();
        Sleep(900);
        system("cls");
    }
}