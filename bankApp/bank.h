//this file includes functions, libraries, and namespaces
//by greyson knippel 10/6/24

//*try not to modify*


#ifndef POINTERS_H
#define POINTERS_H

#include<iostream>
#include<string>
#include<vector>


using namespace std;

//functions used in program

// RunProgram
//this is the main run program function that... runs the program :D
//doesnt return anything
//no parameters
void runProgram();


// PrintMenu
//this function prints the UI so the user can read the options for this program
//doesnt return anything, but prints stuff
//no parameters
void printMenu();


// getUserChoice
//this function gets the user's choice through input in the terminal
//returns an int
//no parameters
int getUserChoiceInt();

double getUserChoiceDouble(); // same thing above, but for doubles

// createNewAccount
//this function will create a new Account that dynamically goes in the vector of Accounts
//returns nothing
//no parameters
void createNewAccount();

// despotMoney
//this function will prompt user which acc# they want to deposit to and how much money they want to deposit
//returns nothing
//no parameters
void depositMoney();

// withdrawMoney
//this function will prompt user which acc# they want to withdraw money from and how much money they want to
//returns nothing
//no parameters
void withdrawMoney();

// checkBalance
//this function will print out the balance for the selected account
//returns nothing
//no parameters
void checkBalance();

// closeAccount
//this function will close an account by getting the account number, deleting that accoount from the heap memory, then deleting the point in vector where it was stored
//returns nothing
//no parameters
void closeAccount();

// listAccounts
//this function will list all the accounts made, and all their details 
//returns nothing
//no parameters
void listAccounts();



// printVecSize
//DEBUGGING TO SEE VECTOR SIZE
//void printVecSize();

#endif