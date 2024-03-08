#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;
#define speed 100

// main variables denoting both ends
int startBankPerson = 3;
int startBankGaint = 3;
int endBankPerson = 0;
int endBankGaint = 0;

// function prototype
int myGame();
char userChoice();
void dashboard(int sp, int sg, int ep, int eg);
void mainDashboard(int sp, int sg, int ep, int eg);
void move_Boat_Forward(char c1, char c2);
void move_Boat_Backward(char c1, char c2);
char userChoiceR();

// starting function -  main
int main()
{
	cout << "\nDo you want to start the game(Y/N): ";
	char c;
	cin >> c;
	
	while(c == 'y' || c == 'Y'){
		int result = myGame();
		// ask user if he/she want to play again.
		if(result == -1){
			cout << "\nDo you want to play the game again(Y/N): ";
			cin >> c;
			// both banks are reset to orignal states
			//  if user want to play again.
			startBankPerson = 3;
			startBankGaint = 3;
			endBankPerson = 0;
			endBankGaint = 0;
		}
	}
	if(c == 'n' || c == 'N'){
		cout << "\nGame is Exited\n";
	}
	return 0;
}

// ------------------------------functions definations----------------------- 

// function that move boat right -> left
void move_Boat_Backward(char c1, char c2)
{
	int k = 10;
	for (int i = 0; i < 10; i++){
		
	   cout << "\n\n" ;
		int j = k;
		while(j>0 ){
			cout << "\t";
			j--;
		}
		cout << "("<< c1 << c2 <<")";
		k--;
		Sleep(speed);
		system ("CLS");
	}
}

// function that move boat left -> right
void move_Boat_Forward(char c1, char c2 = '_')
{
	for(int i = 0; i<10; i++){
		cout << "\n\n" ;
		int j = 0;
		while(j<=i){
			cout << "\t";
			j++;
		}
		cout << "("<< c1 << c2 <<")";
		Sleep(speed);
	    system ("CLS");
	}
}

// boat on right sides...
void mainDashboard(int sp, int sg, int ep, int eg){
	for (int i = 0; i < ep; i++){
		cout << "P" ; 
	}
	for(int i = 0; i < eg; i++){
		cout << "G";
	}
	cout <<"\t\t\t\t\t\t\t\t\t\t\t\t";
	for (int i = 0; i < sp; i++){
		cout << "P" ; 
	}
	for(int i = 0; i < sg; i++){ 
		cout << "G";
	}
	cout <<"\n==========\t\t\t\t\t\t\t\t\t\t(_)==========";	
	
}

// boat on left side...
void dashboard(int sp, int sg, int ep, int eg){
	for (int i = 0; i < ep; i++){
		cout << "P" ; 
	}
	for(int i = 0; i < eg; i++){
		cout << "G";
	}
	cout <<"\t\t\t\t\t\t\t\t\t\t\t\t";
	for (int i = 0; i < sp; i++){
		cout << "P" ; 
	}
	for(int i = 0; i < sg; i++){
		cout << "G";
	}
	cout <<"\n==========()\t\t\t\t\t\t\t\t\t\t==========";	
	
}

// prompt users for Person - p and Gaints - g
char userChoice(){
	char c;
	cout << "\nEnter your choice (P,P,P,G,G,G): ";
	cin >> c;
	c = tolower(c);
	while(c != 'p' && c!= 'g'){
		cout << "\nEnter your choice again(P,P,P,G,G,G): ";
		cin >> c;	
	}
	return c;
}

// prompt for reversing the charachter
char userChoiceR(){
	char c;
	cout << "\nEnter your choice for Reverse(P,P,P,G,G,G): ";
	cin >> c;
	c = tolower(c);
	while(c != 'p' && c!= 'g'){
		cout << "\nEnter your choice again for Reverse(P,P,P,G,G,G): ";
		cin >> c;	
	}
	return c;
}

// main Game functionailty...
//  this function will return 1 in successful case
// this function will return -1 in unsuccessful case.
int myGame(){	
	mainDashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
	while (endBankPerson <= 3 && endBankGaint <= 3){
		// successful case...
		if(endBankGaint == 3 && endBankPerson == 3){
			cout << "\n\n\t\t\t\tBravo!!!";
			return 1;
		}
		// take two inputs from user... as pp, gg, pg
		char c1 = userChoice();
		char c2 = userChoice();
		
		if (c1 == 'p' && c2 == 'p'){
			if(startBankPerson >= 2){
				startBankPerson -= 2;
				endBankPerson += 2;
				move_Boat_Backward(c1, c2);
				dashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
				if (startBankGaint > startBankPerson && (startBankPerson != 0)|| endBankGaint > endBankPerson && (endBankPerson != 0)){
					cout << "\n\n\t\t\t No. of Gaint is Greater.\n";
					cout << "\t\t\t Game is Over!!!";
					return -1;
				} 
				cout << "\nEnter Character to move back.\n";
				cout << "Your Choices: " << c1 << " " << c2 << endl;
				char uc = userChoiceR();
				while(uc != c1 || uc != c2){
					uc = userChoiceR();					
				}
				startBankPerson += 1;
				endBankPerson -= 1;	
				move_Boat_Forward(uc);
				mainDashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
				if (startBankGaint > startBankPerson && (startBankPerson != 0)|| endBankGaint > endBankPerson && (endBankPerson != 0)){
					cout << "\n\n\t\t\t No. of Gaint is Greater.\n";
					cout << "\t\t\t Game is Over!!!";
					return -1;
				}
			}
			
		}else if(c1 == 'g' && c2 == 'g'){
			if(startBankGaint >= 2){
				startBankGaint -= 2;
				endBankGaint += 2;
				move_Boat_Backward(c1, c2);
				dashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
				if (startBankGaint > startBankPerson && (startBankPerson != 0) || endBankGaint > endBankPerson && (endBankPerson != 0)){
					cout << "\n\n\t\t\t No. of Gaint is Greater.\n";
					cout << "\t\t\t Game is Over!!!";
					return -1;
				} 
				cout << "\nEnter Character to move back.\n";
				cout << "Your Choices: " << c1 << " " << c2 << endl;
				char uc = userChoiceR();
				while(uc != c1 || uc != c2){
					uc = userChoiceR();					
				}
				startBankGaint += 1;
				endBankGaint -= 1;
				move_Boat_Forward(uc);
				mainDashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
				
				if (startBankGaint > startBankPerson && (startBankPerson != 0) || endBankGaint > endBankPerson && (endBankPerson != 0)){
					cout << "\n\n\t\t\t No. of Gaint is Greater.\n";
					cout << "\t\t\t Game is Over!!!";
					return -1;
				} 
			}
		}else if ( (c1 == 'p' && c2 == 'g' ) || (c1 == 'g' && c2 == 'p')){
			if(startBankPerson >= 1 && startBankGaint >= 1){
				startBankPerson -= 1;
				startBankGaint -= 1;
				endBankPerson += 1;
				endBankGaint += 1;
				move_Boat_Backward(c1, c2);
				dashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
				if (startBankGaint > startBankPerson && (startBankPerson != 0) || endBankGaint > endBankPerson && (endBankPerson != 0)){
					cout << "\n\n\t\t\t No. of Gaint is Greater.\n";
					cout << "\t\t\t Game is Over!!!";
					return -1;
				} 
				cout << "\nEnter Character to move back.\n";
				cout << "Your Choices: " << c1 << " " << c2 << endl;
				char uc = userChoiceR();
				while(uc != c1 && uc != c2){
					uc = userChoiceR();					
				}
				if(uc == 'p'){
					startBankPerson += 1;
					endBankPerson -= 1;
					move_Boat_Forward(uc);
					mainDashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
				}else{
					startBankGaint += 1;
					endBankGaint -= 1;
					move_Boat_Forward(uc);
					mainDashboard(startBankPerson, startBankGaint, endBankPerson, endBankGaint);
				}
				if (startBankGaint > startBankPerson && (startBankPerson != 0) || endBankGaint > endBankPerson && (endBankPerson != 0)){
					cout << "\n\n\t\t\t No. of Gaint is Greater.\n";
					cout << "\t\t\t Game is Over!!!";
					return -1;
				} 
			}
		}
	}	
}