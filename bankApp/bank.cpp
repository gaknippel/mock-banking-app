//main program file for the banking stuff :D

#include "bank.h"

  struct Account //main struct to create the "Account" ADT
    {
        string accountHolder;
        double balance;
        int accountNumber;

    };

    vector <Account*> bankAccounts; //vector with pointers to Accounts

    int uniqueCounter = 0; //this is the counter for the unique account number feature (its a global variable)


void runProgram()
{
    cout << "\n" << "--------------------------------" << endl;
    cout << "|" <<    "WELCOME TO GREYSON BANKING CO." << "|" << endl; //cool message that prints at the start
    cout <<         "--------------------------------" << "\n";

    bool isRunning = true; //bool for while loop to determine if the program is running or not
    int userChoiceNum = 0; //int to see user's choice for which action to run

    while(isRunning) //while loop to keep the program running
    {
        printMenu();
        userChoiceNum = getUserChoiceInt();

        if(userChoiceNum == 1)
        {
            createNewAccount();
            uniqueCounter++; //incrementing the unique account system
        }
        if(userChoiceNum == 2) 
        {
            depositMoney();
        }
        if(userChoiceNum == 3) 
        {
            withdrawMoney();
        }
        if(userChoiceNum == 4)
        {
            checkBalance();
        }
        if(userChoiceNum == 5)
        {
            closeAccount();
        }
        if(userChoiceNum == 6)
        {
            listAccounts();
        }
        if (userChoiceNum == 7) //this quits the program and ends the while loop by setting the isRunning to false
        {
            int vecSize = bankAccounts.size();
            for(int i = 0; i < vecSize; i ++) //IMPORTANT deletes any accounts made before exiting program
            {
                delete bankAccounts[i];
            }

            cout << "\n" << "quitting program..." << "ヾ(*ФωФ)βyё βyё☆彡 and thanks for banking with us!" << endl;

            isRunning = false;
        }
        else if (userChoiceNum != 1 && userChoiceNum != 2 && userChoiceNum != 3 && userChoiceNum != 4 && userChoiceNum != 5 && userChoiceNum != 6 && userChoiceNum != 7) //check for invalid choice. still dont know how to fix this bug...
        {
            cout << "\n" << "ERROR!--invalid choice! try again." << "\n";
        }
    }
}

void printMenu() 
{
    cout << "\n" << "^^^^^^^^^^^^^^^choose your option!^^^^^^^^^^^^^^^" << endl;
    cout << "\n" << "1. create new account" << endl;
    cout << "2. deposit money to an account" << endl;
    cout << "3. withdraw money from an account" << endl;
    cout << "4. check your balance for an account" << endl;
    cout << "5. close an account (ACTIONS CANNOT BE UNDONE so be careful)" << endl;
    cout << "6. list all of the accounts" << endl;
    cout << "7. end program" << endl;
    cout << "\n";
}

int getUserChoiceInt()     

{
    string line = "";     
    getline(cin, line);   //use getline to avoid input buffer
    int num = stoi(line); //turns user inputted string to int
    return num;
}

double getUserChoiceDouble() 
{
    string line = "";     
    getline(cin, line); //use getline to avoid input buffer
    double num = stod(line); //turns user inputted string to double
    return num;
}

void createNewAccount() 
{
    Account * acc1 = nullptr; //creates a new Account object it is a pointer because it needs to be put on the heap. (heap accepts memory adresses)
    acc1 = new Account;

    string accName = "";

    double accBalance = 0.0;

    int accNumber = (1000 + uniqueCounter); //this is the unique account number system that increments by 1 every time a new one gets created


    cout<< "\n" << "--------------account creation!--------------" << "\n";
    cout << "\n" << "enter the account name for the new account: ";

    getline(cin, accName); //this is like my "getUserChoice" functions, but for strings.

    acc1->accountHolder = accName; //uses -> operator instead of . operator because acc1 is a pointer.
    
    cout << "\n" << "enter the initial balance you have: ";

    accBalance = getUserChoiceDouble();

    acc1->balance = accBalance;

    acc1->accountNumber = accNumber;

    cout << "\n" << "Account " << "\""  << acc1->accountHolder << "\"" << " successfully created! your account number is: " << acc1->accountNumber << endl;

    bankAccounts.push_back(acc1); //puts the new account the user just made to the back of the bankAccounts vector
}

void depositMoney() 
{
    int chosenAccNum = 0;
    int vecSize = bankAccounts.size(); //sets vecSize to the size of the bankAccounts size (in terms of size of elements)
    double depositAmnt = 0.0;
    bool accFound = false; //bool to determine if the account the user requested was found or not


    cout << "\n" << "--------------deposit money!--------------" << "\n";
    cout << "\n" << "enter the account number for the deposit: ";

    chosenAccNum = getUserChoiceInt();

    for(int i = 0; i < vecSize; i++) //for loop to individually check which bank acc# is in the vector
    {
        if(bankAccounts[i]->accountNumber == chosenAccNum)
        {
            cout << "\n" << "-------------account found!-------------" << endl;
            accFound = true; //we found the account! no error message can appear now if we enter a valid acc#
            cout << "\n" << "how much money would you like to deposit?: ";
            depositAmnt = getUserChoiceDouble();

            if(depositAmnt < 0) //you cant deposit a negative!
            {
                cout << "\n" << "ERROR--you cant deposit negative amounts... try again" << endl;
                break; //i use break in order to break the loop instead of just printing this message and letting you continue
            }
            if(depositAmnt == 0) //you cant deposit 0! (this is just for fun)
            {
                cout << "\n" << "ERROR--you cant deposit 0...(why would you do this?)" << endl;
                break;
            }
           
            bankAccounts[i]->balance += depositAmnt; //add the deposit amount with whatever balance the account previously had

            cout << "\n" << "success! you have deposited " << depositAmnt << "$ on account " << chosenAccNum << endl;
        }   
    }    
    if(accFound == false) //if the user entered a acc# that doesnt exist, this appears.
    {
        cout << "\n" << "ERROR--couldnt find the account you typed. did you mistype it? or do you not have an account?" << endl;
    }


}

void withdrawMoney()
{
    int chosenAccNum = 0;
    int vecSize = bankAccounts.size(); //sets vecSize to the size of the bankAccounts size (in terms of size of elements)
    double withdrawAmnt = 0.0;
    bool accFound = false; //bool to determine if the account the user requested was found or not

    cout << "\n" << "--------------withdraw money!--------------" << "\n";
    cout << "\n" << "enter the account number for the withdraw: ";

    chosenAccNum = getUserChoiceInt();

    for(int i = 0; i < vecSize; i++) //for loop to individually check which bank acc# is in the vector
    {
        if(bankAccounts[i]->accountNumber == chosenAccNum)
        {
            cout << "\n" << "-------------account found!-------------" << endl;
            accFound = true; //we found the account! no error message can appear now if we enter a valid acc#
            cout << "\n" << "how much money would you like to withdraw?: ";
            withdrawAmnt = getUserChoiceDouble();

            if(withdrawAmnt < 0) //you cant withdraw a negative!
            {
                cout << "\n" << "ERROR--you cant withdraw negative amounts... try again" << endl;
                break; //i use break in order to break the loop instead of just printing this message and letting you continue
            }
            if(withdrawAmnt == 0) //you cant withdraw 0! (this is just for fun)
            {
                cout << "\n" << "ERROR--you cant withdraw 0...(why would you do this?)" << endl;
                break;
            }
            if(withdrawAmnt > bankAccounts[i]->balance) //cant withdraw an amount greater than initial balance
            {
                cout << "\n" << "ERROR--you cant withdraw an amount greater than your current balance! " << "(" << bankAccounts[i]->balance << "$)" << " try again." << endl;
                break;
            }
           
            bankAccounts[i]->balance -= withdrawAmnt; //add the deposit amount with whatever balance the account previously had

            cout << "\n" << "success! you have withdrawed " << withdrawAmnt << "$ on account " << chosenAccNum << endl;
        }   
    }

    if(accFound == false) //if the user entered a acc# that doesnt exist, this appears.
    {
        cout << "\n" << "ERROR--couldnt find the account you typed. did you mistype it? or do you not have an account?" << endl;
    }
}

void checkBalance()
{
    int chosenAccNum = 0;
    int vecSize = bankAccounts.size(); //sets vecSize to the size of the bankAccounts size (in terms of size of elements)
    bool accFound = false;

    cout << "\n" << "--------------check balance!--------------" << "\n";
    cout << "\n" << "enter the account number to check which balance: ";

    chosenAccNum = getUserChoiceInt();

    for(int i = 0; i < vecSize; i++)
    {
        if(bankAccounts[i]->accountNumber == chosenAccNum)
        {
            cout << "\n" << "-------------account found!-------------" << endl;
            accFound = true; //we found the account! no error message can appear now if we enter a valid acc#

            cout << "\n" << "the \"" << bankAccounts[i]->accountHolder << "\"(#" << bankAccounts[i]->accountNumber << ")" << " account has a balance of: " << bankAccounts[i]->balance << "$." << endl;
            
        }
    }

    if(accFound == false) //if the user entered a acc# that doesnt exist, this appears.
    {
        cout << "\n" << "ERROR--couldnt find the account you typed. did you mistype it? or do you not have an account?" << endl;
    }
}

void closeAccount()
{
    int chosenAccNum = 0;
    int vecSize = bankAccounts.size(); //sets vecSize to the size of the bankAccounts size (in terms of size of elements)
    bool accFound = false;

    cout << "\n" << "--------------close an account!--------------" << "\n";
    cout << "\n" << "enter the account number to close an account: ";

    chosenAccNum = getUserChoiceInt();

   

    for(int i = 0; i < vecSize; i++)
    {
        if(bankAccounts[i]->accountNumber == chosenAccNum)
        {
            cout << "\n" << "-------------account found!-------------" << endl;
            accFound = true; //we found the account! no error message can appear now if we enter a valid acc#   

            delete bankAccounts[i]; //deletes the account from memory

            bankAccounts.erase(bankAccounts.begin() + i); //removing the vector index that was previously deleted from memory (making the vector smaller)

            //printVecSize();
        }
    }
    
    cout << "\n" << "the chosen account has been successfully closed." << endl; 

    if(accFound == false) //if the user entered a acc# that doesnt exist, this appears.
    {
        cout << "\n" << "ERROR--couldnt find the account you typed. did you mistype it? or do you not have an account?" << endl;
    }

}

void listAccounts()
{
    int vecSize = bankAccounts.size();

    cout  << "\n" << "-----------list of all your accounts-----------" << "\n" << endl;

    if(vecSize == 0)
    {
        cout << "\n" << "you don't have any accounts yet! go make one!" << endl;
    }
    else
    {
        for(int i = 0; i < vecSize; i++)
        {
            cout << "\"" << bankAccounts[i]->accountHolder << "\"" << " (#" << bankAccounts[i]->accountNumber << ") " << "| balance: " << bankAccounts[i]->balance << "$" << endl;
        }
    }

    cout << "\n";
}

/*void printVecSize() //debugging
{
    int vecSize = bankAccounts.size();

    cout << "\n" << "THE VECTOR SIZE IS NOW: " << vecSize << "\n";
}
*/