#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};



void shopping::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "\t\t__________________________\n";
    cout << "\t\t                          \n";
    cout << "\t\t   Supermarket Main Menu     \n";
    cout << "\t\t                          \n";
    cout << "\t\t__________________________\n";
    cout << "\t\t                          \n";
    cout << "\t\t  |   1) Administrator   |\n";
    cout << "\t\t  |                      |\n";
    cout << "\t\t  |   2) Buyer           |\n";
    cout << "\t\t  |                      |\n";
    cout << "\t\t  |   3) Exit            |\n";
    cout << "\t\t  |                      |\n";
    cout << "\t\t   Please select!  \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t   Please login  \n";
        cout << "\t\t   Enter email   \n";
        cin >> email;
        cout << "\t\t    Password     \n";
        cin >> password;

        if (email == "mak123@email.com" && password == "mak123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;
    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "  Please select from the given options ";
    }
    }
    goto m;
}

void shopping::administrator()
{
m:
    int choice;
    cout << "\n\n\t\t\t\t  --   Adminstrator menu -- ";
    cout << "\n\t\t\t\t|___1) Add the product______|";
    cout << "\n\t\t\t\t|                           |";
    cout << "\n\t\t\t\t|___2) Modify the product___|";
    cout << "\n\t\t\t\t|                           |";
    cout << "\n\t\t\t\t|___3) Delete the product___|";
    cout << "\n\t\t\t\t|                           |";
    cout << "\n\t\t\t\t|___4) back to main menu____|";

    cout << "\n\n\t\t\t\t   Please enter your choice  ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "Invalid choice ";
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t         Buyer      \n";
    cout << "\t\t\t\t  __________________\n";
    cout << "                            \n";
    cout << "\t\t\t\t  1) Buy Product    \n";
    cout << "\t\t\t\t                    \n";
    cout << "\t\t\t\t  2) Go Back        \n";
    cout << "\t\t\t\t  Enter your choice : ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;

    default:
        cout << " Invalid choice ";
    }
    goto m;
}

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t            Add new product    ";
    cout << "\n\n\t      Product code of the product  ";
    cin >> pcode;
    cout << "\n\n\t      Name of the product  ";
    cin >> pname;
    cout << "\n\n\t    Price of the product  ";
    cin >> price;
    cout << "\n\n\t    Discount on the product  ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t  Record inserted ! ";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0, c;
    float p, d;
    string n;

    cout << "\n\t   Modify the record  ";
    cout << "\n\t   Product code       ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesn't exist ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product code of new code : ";
                cin >> c;
                cout << "\n\t\t Name of the product : ";
                cin >> n;
                cout << "\n\t\t  Price";
                cin >> p;
                cout << "\n\t\t Discount";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << " "
                      << "\n";
                cout << "\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n\t\t Record not found sorry ! ";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey, token = 0;
    cout << "\n\n\t\t Delete Product ";
    cout << "\n\t\t product code : ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << " File doesn't exit ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfilly ";
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\t Record not found ";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n\t\t|___________________\n";
    cout << "ProNo\t\t Name \t\t Price \n";
    cout << "\n\n\t\t|___________________\n";

    data >> pcode >> pname >> price >> dis;

    while (!data.eof())
    {
        cout << pcode << " " << pname << " " << price << " " << dis << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0, dis = 0, total = 0;

    cout << "\n\n\t\t  ----Receipt----    " << endl;
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n   Empty database  ";
    }
    else
    {
        data.close();

        list();
        cout << "\n_____________________________";
        cout << "\n |                            ";
        cout << "\n |    Please place the order ";
        cout << "\n |                           ";
        cout << "\n |___________________________";

        do
        {
        m:
            cout << "\n\n Enter product code  ";
            cin >> arrc[c];
            cout << "\n\n Enter the product quantity : ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate prodt code .. please try again  and select the product again  ";
                    goto m;
                }
            }
            c++;
            cout << "\n\n  Do u want to buy another product if yes press 'y' else press any key character ...";
            cout << "select the product ";
            cin >> choice;

        } while (choice == 'y');

        cout << "\n\n\t\t____________Receipt__________\n";
        cout << endl;
        cout << "Product No\t Product name \t product Qty \t Price \t Amount \t dis amnt ";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n__________________________";
    cout << "\n\n   Total amount  :  " << total;
}

int main()
{
    shopping s;
    s.menu();
}
