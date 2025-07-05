#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

class bank {
private:
    float balance;
    string id,pin, pass, name, fname, address, phone;
public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search_();
    void edit();
    void del();
    void show_records();
    void user_balance();
    void withdraw_atm();
    void check_detail();
};

void introduction(){
    cout << "\n\n\n\n\n\t\t\t  ";
    for(int i=0;i<60;i++){
        cout << "*";
    }
    cout<< "\n\n\t\t\t   ";
    for(int i=0;i<58;i++){
        cout << "*";
    }
    cout << "\n\n\t\t\t    ";
    for(int i=0;i<56;i++){
        cout << "*";
    }
    cout << "\n\n\t\t\t\t\t\t BANK & ATM\n\t\t\t\t\tManagement System Project in C++\n\t\t\t\t\t    by Mayank Pratap Singh";
    cout << "\n\n\n\n\t\t\t    ";
    for(int i=0;i<56;i++){
        cout << "*";
    }
    cout << "\n\n\t\t\t   ";
    for(int i=0;i<58;i++){
        cout << "*";
    }
    cout << "\n\n\t\t\t  ";
    for(int i=0;i<60;i++){
        cout << "*";
    }
    _getch();
    system("cls");
}

void bank::menu() {
    while (true) {
        system("cls");
        cout << "\n\n\t\t\t\t\t\tControl Panel";
        cout << "\n\n\n 1. Bank Management";
        cout << "\n 2. ATM Management";
        cout << "\n 3. Exit";
        cout << "\n\n Enter Your Choice: ";
        int choice;
        cin >> choice;
        char ch1;
        string pin, pass, email;
        switch (choice) {
            case 1:
                system("cls");
                cout << "\n\n\t\t\tLogin Account";
                cout << "\n\n E-Mail: ";
                cin >> email;
                cout << "\n\n Pin Code: ";
                pin.clear();
                for (int i = 0; i < 5; i++) {
                    ch1 = getch();
                    pin += ch1;
                    cout << "*";
                }
                cout << "\n\n Password: ";
                pass.clear();
                for (int i = 0; i < 5; i++) {
                    ch1 = getch();
                    pass += ch1;
                    cout << "*";
                }
                if (email == "mayankpratapsingh679@gmail.com" && pin == "12345" && pass == "12345") {
                    bank_management();
                } else {
                    cout << "\n\n Your E-mail, Pin, or Password is Wrong ... " << endl;
                }
                break;
            case 2:
                atm_management();
                break;
            case 3:
                exit(0);
            default:
                cout << "\n\nInvalid Value .. Please Try Again";
        }
        _getch();
    }
}

void bank::bank_management() {
    while (true) {
        system("cls");
        cout << "\n\n\t\t\tBank Management System";
        cout << "\n\n\n 1. New User";
        cout << "\n 2. Already User";
        cout << "\n 3. Deposit Option";
        cout << "\n 4. Withdraw Option";
        cout << "\n 5. Transfer Option";
        cout << "\n 6. Payment Option";
        cout << "\n 7. Search User Record";
        cout << "\n 8. Edit User Record";
        cout << "\n 9. Delete User Record";
        cout << "\n 10. Show All Records";
        cout << "\n 11. Go Back\n\n";
        cout << "Enter Your Choice : ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                new_user();
                break;
            case 2:
                already_user();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                transfer();
                break;
            case 6:
                payment();
                break;
            case 7:
                search_();
                break;
            case 8:
                edit();
                break;
            case 9:
                del();
                break;
            case 10:
                show_records();
                break;
            case 11:
                return;
            default:
                cout << "\n\nInvalid Value .. Please Try Again";
        }
        _getch();
    }
}

void bank::atm_management() {
    while (true) {
        system("cls");
        cout << "\n\n\t\t\tATM System";
        cout << "\n\n\n 1. User Login And Check Balance";
        cout << "\n 2. Withdraw Amount";
        cout << "\n 3. Account Details";
        cout << "\n 4. Go Back\n";
        cout << "Enter Your Choice : ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                user_balance();
                break;
            case 2:
                withdraw_atm();
                break;
            case 3:
                check_detail();
                break;
            case 4:
                return;
            default:
                cout << "\n\nInvalid Value .. Please Try Again";
        }
        _getch();
    }
}

void bank::new_user() {
    while (true) {
        system("cls");
        fstream file;
        int p;
        float b;
        string n, f, pa, a, ph, i;
        cout << "\n\n\t\tAdd New User";
        cout << "\n\n User ID: ";
        cin >> id;
        cout << "\n\n\t\tName: ";
        cin >> name;
        cout << "\n\n Father Name: ";
        cin >> fname;
        cout << "\n\n\t\tAddress: ";
        cin >> address;
        cout << "\n\n Pin Code (5 digits): ";
        cin >> pin;
        cout << "\n\n\t\tPassword (5 digits) : ";
        cin >> pass;
        cout << "\n\n Phone Number: ";
        cin >> phone;
        cout << "\n\n\t\tCurrent Balance: ";
        cin >> balance;

        file.open("bank.txt", ios::in);
        if (!file) {
            file.open("bank.txt", ios::app | ios::out);
            file << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            file.close();
        } else {
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
            while (!file.eof()) {
                if (i == id) {
                    cout << "\n\n User ID Already Exists...";
                    _getch();
                    return;
                }
                file >> i >> n >> f >> a >> p >> pa >> ph >> b;
            }
            file.close();
            file.open("bank.txt", ios::app | ios::out);
            file << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            file.close();
        }
        cout << "\n\n Added New User Successfully...";
        return;
    }
}

void bank::already_user() {
    system("cls");
    string t_id;
    fstream file;
    cout << "\n\n\t\t\tAlready User Account  ";
    int found = 0;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error!";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                system("cls");
                cout << "\n\n\t\t\tAlready User Account";
                cout << "\n\n User ID : " << id << "    Pin Code: " << pin << "    Password:  " << pass;
                found++;
                break;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        if (found == 0) {
            cout << "User ID Doesn't Exist!";
        }
        file.close();
    }
}

void bank::deposit() {
    fstream file, file1;
    string t_id;
    float dep;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tDeposit Account Option";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\n Amount For Deposit: ";
                cin >> dep;
                balance += dep;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
                cout << "\n\n\t\t\tYour Amount " << dep << " Successfully Deposited";
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "User ID Doesn't Exist!";
        }
    }
}

void bank::withdraw() {
    fstream file, file1;
    string t_id;
    float with;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tWithdraw Account Option";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\n Amount For Withdraw: ";
                cin >> with;
                if (with <= balance) {
                    balance -= with;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\n\t\t\tYour Amount " << with << " Successfully Withdrawn";
                } else {
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\n\t\t\tYour Balance " << balance << " is Less...";
                }
                found++;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "User ID Doesn't Exist!";
        }
    }
}

void bank::transfer() {
    fstream file, file1;
    string s_id, r_id;
    int foundSender = 0, foundReceiver = 0;
    float amount;
    system("cls");
    cout << "\n\n\t\t\tPayment Transfer Option : ";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error!";
    } else {
        cout << "\n\n Enter Sender User ID For Transaction : ";
        cin >> s_id;
        cout << "\n\n Enter Receiver User ID For Transaction : ";
        cin >> r_id;
        cout << "\n\n Enter Transaction Amount : ";
        cin >> amount;

        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (s_id == id && amount <= balance) {
                foundSender = 1;
            }
            if (r_id == id) {
                foundReceiver = 1;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();

        if (foundSender && foundReceiver) {
            file.open("bank.txt", ios::in);
            file1.open("bank1.txt", ios::app | ios::out);
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while (!file.eof()) {
                if (s_id == id) {
                    balance -= amount;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                } else if (r_id == id) {
                    balance += amount;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                } else {
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
            cout << "\n\n\t\t\tTransaction Successful!";
        } else {
            cout << "\n\n\t\t\t User IDs not Found or Balance Insufficient!";
        }
    }
}

void bank::payment() {
    fstream file, file1;
    string t_id;
    float amount;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tPayment Option";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error!";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        cout << "\n\n Amount For Payment : ";
        cin >> amount;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id && balance >= amount) {
                balance -= amount;
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
                cout << "\n\n Payment Successful...";
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "\n\n Payment Failed...";
        }
    }
    _getch();
}

void bank::search_() {
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\n\t\t\tSearch User Record";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error!";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                system("cls");
                cout << "\n\n\t\t\tSearch User Record";
                cout << "\n\n\n User ID: " << id << "  Name: " << name << "  Father's Name: " << fname;
                cout << "\n Address: " << address << "  Pin: " << pin << "  Password: " << pass;
                cout << "\n Phone No.: " << phone << "  Current Balance: " << balance;
                found++;
                break;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0) {
            cout << "\n\n User ID Doesn't Exist!";
        }
    }
    _getch();
}

void bank::edit() {
    system("cls");
    fstream file, file1;
    int found = 0, pi;
    string t_id, n, f, a, p, ph;
    cout << "\n\n\t\t\tEdit User Record : ";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error! ";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\n\t\tName: ";
                cin >> n;
                cout << "\n\n Father Name: ";
                cin >> f;
                cout << "\n\n\t\tAddress: ";
                cin >> a;
                cout << "\n\n Pin Code (5 digits): ";
                cin >> pi;
                cout << "\n\n\t\tPassword: ";
                cin >> p;
                cout << "\n\n Phone Number: ";
                cin >> ph;
                file1 << id << " " << n << " " << f << " " << a << " " << pi << " " << p << " " << ph << " " << balance << "\n";
                cout << "\n\n\n\t\t\tRecord Edited Successfully..";
                found++;
                break;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "\n\n User ID Can't Be Found...";
        }
    }
    _getch();
}

void bank::del(){
    system("cls");
    fstream file, file1;
    int found = 0;
    string t_id;
    cout << "\n\n\t\t\tEdit User Record : ";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error! ";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id) {
                cout << "\n\n\n\t\t\tRecord Deleted Successfully..";
                found++;
                break;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "\n\n User ID Can't Be Found...";
        }
    }
    _getch();
}

void bank :: show_records(){
    system("cls");
    int found = 0;
    fstream file;
    cout << "\n\n\t\t\tShow All User Records -> ";
     file.open("bank.txt",ios::in);
     if(!file){
        cout << "\n\n File Opening Error!";
     }
     else{
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
                cout << "\n\n User ID : " << id;
            cout << "\n Name : " << name;
            cout << "\n Father Name : " << fname;
            cout << "\n Address : " << address;
            cout << "\n Pin : " << pin;
            cout << "\n Password : " << pass;
            cout << "\n Phone Number : " << phone;
            cout << "\n Current Balance : " << balance;
            cout << "\n\n===========================";
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
           found++;
        }
        file.close();
        if(found == 0){
            cout << "\n\n Data Base is Empty!";
        }
     }
}

void bank::user_balance() {
    system("cls");
    fstream file;
    int found = 0;
    string t_id, t,t_pass;
    char ch;
    cout << "\n\n\t\t\tUser Login & Check Balance";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error!";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        cout << "\n\n\t\t\tPin Code : ";
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        t_pass.clear();
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t_pass += ch;
            cout << "*";
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id  && t == pin  && t_pass == pass) {
                cout << "\n\n\t\t\tYour Current Balance is : " << balance;
                found++;
                break;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0) {
            cout << "\n\n\t\t\tUser ID, Pin or Password Invalid!";
        }
    }
    _getch();
}

void bank::withdraw_atm(){
    fstream file, file1;
    char ch;
    string t_id,t_pass,t_pin;
    float with;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tWithdraw Account Option";
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\n\n File Opening Error...";
    } else {
        cout << "\n\n User ID : ";
        cin >> t_id;
        cout << "\n\n\t\t\tPin Code : ";
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        t_pass.clear();
        for (int i = 0; i < 5; i++) {
            ch = _getch();
            t_pass += ch;
            cout << "*";
        }
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id && t_pin == pin && t_pass == pass) {
                cout << "\n\n Amount For Withdraw: ";
                cin >> with;
                if (with <= balance) {
                    balance -= with;
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\n\t\t\tYour Amount " << with << " Successfully Withdrawn";
                    cout << "\n\n\t\t\tYour Balance is : " << balance;
                } else {
                    file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\n\t\t\tYour Balance " << balance << " is Less...";
                }
                found++;
            } else {
                file1 << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << "User ID Doesn't Exist!";
        }
    }
}

void bank::check_detail() {
    fstream file;
    char ch;
    string t_id, t_pass, t_pin;
    int found = 0;

    system("cls");
    cout << "\n\n\t\t\tCheck Detail Option";
    file.open("bank.txt", ios::in);

    if (!file) {
        cout << "\n\n File Opening Error...";
        return;
    }

    cout << "\n\n User ID : ";
    cin >> t_id;

    cout << "\n\n\t\t\tPin Code : ";
    t_pin.clear();
    for (int i = 0; i < 5; i++) {
        ch = _getch();
        t_pin += ch;
        cout << "*";
    }

    cout << "\n\n Password : ";
    t_pass.clear();
    for (int i = 0; i < 5; i++) {
        ch = _getch();
        t_pass += ch;
        cout << "*";
    }

    bool userFound = false;
    while (file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance) {
        if (t_id == id && t_pin == pin && t_pass == pass) {
            cout << "\n\n User ID : " << id;
            cout << "\n Name : " << name;
            cout << "\n Father Name : " << fname;
            cout << "\n Address : " << address;
            cout << "\n Pin : " << pin;
            cout << "\n Password : " << pass;
            cout << "\n Phone Number : " << phone;
            cout << "\n Current Balance : " << balance;
            userFound = true;
            break;
        }
    }

    file.close();

    if (!userFound) {
        cout << "\nUser ID, Pin, or Password is incorrect!";
    }
}

int main() {
    bank obj;
    introduction();
    obj.menu();
    return 0;
}

