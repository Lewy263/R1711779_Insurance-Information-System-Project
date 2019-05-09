/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: King_Lewy
 *
 * Created on April 22, 2019, 10:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

/*
 * 
 */

/* STRUCTURE FOR AGENTS LOGIN */
struct agentslogin {
    char name[30];
    char empID[30];
    char pass[30];
};

/* STRUCTURE FOR OFFICIALS LOGIN */
struct officialslogin {
    char name[9];
    char empID[35];
    char pass[35];
};

class user {
public:
    string username;
    string password;

};

/* FUNCTION FOR DISPLAYING MAIN MENU */

void welcome(); //display welcome page
void mainmen(); //display main menu
void usermenu(); //display login page
void user_screen(); //displays page where users can login
void reg(); //display registration page 
void login_official(); //login screen for officials
void login_receptionist(); //login screen for receptionist
void login_agents(); //login screen for agents
void login_admin(); //login screen for administrator
void officials_menu(); //display official menu
void reg_officials(); //displays register menu for officials
void reg_receptionist(); //displays register menu for receptionists
void reg_agents(); //display register menu for agents
void reg_admin(); //displays register menu for admin 
void admin_menu(); //displays admin menu
void edit_user();
void search();
/*initializing variables*/
char choice; //used for choosing choice between login or register
char log; //used for choosing department

void welcome() {
    cout << endl << ("\t\t\t\t             WELCOME TO INSURANCE INFORMATION SYSTEM");
    cout << endl << ("\t\t\t\t       ===================================================");
    cout << endl << ("\t\t\t                       Press Enter to proceed...");
    if (getch() == 13)
        XY :
            usermenu();
}

void usermenu() {
    cout << endl << endl << ("USERMENU");
XY:
    cout << endl << endl << ("1. LOGIN\t\t 2. REGISTER");

    cout << endl << ("ENTER YOUR CHOICE: ");
    cin>>choice;
    if (choice == '1') {
        cout << endl << endl << ("You Have Chosen Login");
        user_screen();
    } else if (choice == '2') {
        cout << endl << endl << ("You Have Chosen Register");
        admin_menu();
    } else
        cout << endl << endl << ("NO MATCH FOUND");
    cout << endl << ("Press Enter to re-Enter The Choice: ");
    if (getch() == 13)

        goto XY;

}

void user_screen() {
    cout << endl << endl << ("Please Choose Your Department");
XY:

    cout << endl << ("1. Official");
    cout << endl << ("2. Receptionist");
    cout << endl << ("3. Agent");
    cout << endl << ("4. Administrator");
    cout << endl << endl << ("Please Enter Option: ");
    cin>>log;
    if (log == '1') {
        cout << endl << endl << ("You Have Chosen To Login As An Official");
        login_official();
       // reg_officials();
    } else if (log == '2') {
        cout << endl << endl << ("You Have Chosen To Login As Receptionist");
        login_receptionist();
       // reg_receptionist();
    } else if (log == '3') {
        cout << endl << endl << ("You Have Chosen To Login As Agent");
        login_agents();
      //  reg_agents();
    } else if (log == '4') {
        cout << endl << endl << ("You Have Chosen To Login As Administrator");
        login_admin();
      //  reg_admin();
        admin_menu();
    } else
        cout << endl << endl << ("NO MATCH FOUND");
    cout << endl << ("Press Enter to re-Enter The Choice: ");
    if (getch() == 13)
        goto XY;

}

void admin_menu() {
    cout << endl << endl << endl << ("Now Logged in As Admin");
    cout << endl << endl << ("WELCOME TO THE ADMININSTRATOR MENU");
    cout << endl << ("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    cout << endl << endl << ("Please Select An Option");
    char op;
    cout << endl << endl << ("1. Create New User");
    cout << endl << ("2. Edit User Details");
    cout << endl << ("3. Delete User");
    cout << endl << ("4. Search User");
    cout << endl << ("Select An Option: ");
    cin>>op;
    if (op == '1') {
        cout << endl << endl << ("Creating New User");
        user_screen();
    } else if (op == '2') {
        cout << endl << endl << ("Editing User Details");
        user_screen();
    } else if (op == '3') {
        cout << endl << endl << ("Deleting User");
        user_screen();
    } else if (op == '4') {
        cout << endl << endl << ("Searching USer");
        search();
    }
}

void reg_officials() {
    cout << endl << ("\t\t\t\t\t REGISTER");

    class userOfficialReg {
    public:
        string username;
        string password;
        string passwordConf;
        string employeeID;

        //user registration

        void OfficialRegDO() {
            ofstream usersFile("OfficialsLogin\\officials.txt");
            if (!usersFile.is_open()) {
                usersFile.open("OfficialsLogin\\officials.txt", ios::app);
            }
            usersFile << username << "  " << password << " " << passwordConf << "  " << employeeID << endl;
            usersFile.close();
        }
    };
    userOfficialReg official;

    cout << endl << endl << "Please Register";
    cout << endl << "Enter username: ";
    cin >> official.username;
    cout << endl << "Enter password: ";
    cin >> official.password;
    cout << endl << "Enter Password Again: ";
    cin >> official.passwordConf;
    if (official.password != official.passwordConf) {
        cout << endl << ("Password Does Not Match");
        reg_officials();
    } else
        cout << endl << "Enter Employee ID: ";
    cin >> official.employeeID;
    official.OfficialRegDO();
    cout << ("Data Saved!");
    getch();
    usermenu();
}

void reg_receptionist() {

    class ReceptionistReg {
    public:
        string username;
        string password;
        string passwordConf;
        string employeeID;

        //user registration

        void ReceptionistRegDO() {
            ofstream usersFile("ReceptionistLogin\\receptionists.txt");
            if (!usersFile.is_open()) {
                usersFile.open("ReceptionistLogin\\receptionists.txt", ios::app);
            }
            usersFile << username << "  " << password << " " << passwordConf << "  " << employeeID << endl;
            usersFile.close();
        }
    };
    ReceptionistReg receptionist;

    cout << endl << endl << "Please Register";
    cout << endl << "Enter username: ";
    cin >> receptionist.username;
    cout << endl << "Enter password: ";
    cin >> receptionist.password;
    cout << endl << "Enter Password Again: ";
    cin >> receptionist.passwordConf;
    if (receptionist.password != receptionist.passwordConf) {
        cout << endl << ("Password Does Not Match");
        reg_receptionist();
    } else
        cout << endl << "Enter Employee ID: ";
    cin >> receptionist.employeeID;
    receptionist.ReceptionistRegDO();
    cout << ("Data Saved!");
    getch();
    usermenu();
}

void reg_agents() {

    class agentsReg {
    public:
        string username;
        string password;
        string passwordConf;
        string employeeID;

        //user registration

        void agentsRegDO() {
            ofstream usersFile("agentsLogin\\agents.txt");
            if (!usersFile.is_open()) {
                usersFile.open("agentsLogin\\agents.txt", ios::app);
            }
            usersFile << username << "  " << password << " " << passwordConf << "  " << employeeID << endl;
            usersFile.close();
        }
    };

    agentsReg agents;
    cout << endl << endl << "Please Register";
    cout << endl << "Enter username: ";
    cin >> agents.username;
    cout << endl << "Enter password: ";
    cin >> agents.password;
    cout << endl << "Enter Password Again: ";
    cin >> agents.passwordConf;
    if (agents.password != agents.passwordConf) {
        cout << endl << ("Password Does Not Match");
        reg_agents();
    } else
        cout << endl << "Enter Employee ID: ";
    cin >> agents.employeeID;
    agents.agentsRegDO();
    cout << ("Data Saved!");
    getch();
    usermenu();
}

void reg_admin() {

    class AdminReg {
    public:
        string username;
        string password;
        string passwordConf;
        string employeeID;

        //user registration

        void AdminRegDO() {
            ofstream usersFile("AdminLogin\\admin.txt");
            if (!usersFile.is_open()) {
                usersFile.open("AdminLogin\\admin.txt", ios::app);
            }
            usersFile << username << "  " << password << " " << passwordConf << "  " << employeeID << endl;
            usersFile.close();
        }
    };
    AdminReg admin;
    //check is username exist

    cout << endl << endl << "Please Register";
    cout << endl << "Enter username: ";
    cin >> admin.username;
    cout << endl << "Enter password: ";
    cin >> admin.password;
    cout << endl << "Enter Password Again: ";
    cin >> admin.passwordConf;
    if (admin.password != admin.passwordConf) {
        cout << endl << ("Password Does Not Match");
        reg_admin();
    } else
        cout << endl << "Enter Employee ID: ";
    cin >> admin.employeeID;
    admin.AdminRegDO();
    cout << ("Data Saved!");
    getch();
    usermenu();
}

void edit_user() {

}

void login_official() {

}

void login_receptionist() {

}

void login_agents() {

}

void login_admin() {


}

void officials_menu() {
    cout << endl << endl << endl << ("Welcome To The Officials Menu");

}

void search() {
    cout << endl << endl << ("Searching for user");
    
}

int main(int argc, char** argv) {
    welcome();
    usermenu();
    login_official();
    login_receptionist();
    login_agents();
    login_admin();
    officials_menu();
    reg_officials();
    reg_receptionist();
    reg_agents();
    reg_admin();
    admin_menu();
    edit_user();
    search();
    return 0;
}

