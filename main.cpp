#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::cin;

// Using global scopes
#define MAX 25
#define MIN 0

// Prototypes
int main();
void mainMenuLoop();
bool mainMenu();
void changeSuperCoolMenu();
int changeSuperCool(int adjustment = 0);
void showSpecificSuperCoolValue();
string renderMeter(int number);
string renderMeter(string number);


// Main function
int main(){
  // Calling the mainMenuLoop function
  mainMenuLoop();
  return 0;
}
// Main menu loop function
void mainMenuLoop(){
  while(mainMenu()){

  }
}

// Main menu function
bool mainMenu(){
  // Declaring my variables
  string header;
  string user_input;
  bool cont =  true;
  // Printing the menu
  header.assign(3,'*');
  cout << header;
  cout << " Welcome to the Main Menu ";
  header.assign(3,'*');
  cout << header << endl;
  cout << endl;
  cout << "The current SuperCool value is: " << renderMeter(changeSuperCool())<<endl;;
  cout << endl;
  cout << "1. Change the SuperCool value" << endl;
  cout << "2. Show a specific SuperCool value" << endl;
  cout << "Q. Quit the Program" << endl;
  cout << endl;
  cout << "Please enter your choice: ";
  cin >> user_input;

  // Transforming string to lowercase
  transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);
  if(user_input == "1"){
    // Calling to changeSuperCoolMenu function
    changeSuperCoolMenu();
  }
  else if(user_input == "2"){
    // Calling to void showSpecificSuperCoolValue
    showSpecificSuperCoolValue();
  }

  // User selects the option to quit
  else if (user_input == "quit" || user_input == "q") {
    cout << "Okay, quitting!" << endl;
    return false;
  }
  else{
    cout << "Invalid choice!" << endl;
    cout << endl;
    return true;
  }
  while(cont);
  return true;
}

// Function for user option 1
void changeSuperCoolMenu(){
  // Declaring the variables
  string input_one;
  string header;

  // Creating the submenu
  header.assign(3,'*');
  cout << header;
  cout << " Changing the SuperCool Value ";
  header.assign(3,'*');
  cout << header << endl;
  cout << endl;
  cout << "1. Increase the value" << endl;
  cout << "2. Decrease the value" << endl;
  cout << "N. Nevermind" << endl;
  cout << endl;
  cout << "Please enter your choice: ";
  cin >> input_one;

  // Calling to changeSuperCool function
  // If user inputs the number 1
  if (input_one == "1"){
    // Changing the SuperCool with a value of 1
    changeSuperCool(1);
  }
  // If user inputs the number 2
  else if (input_one == "2"){
    // Changing the SuperCool with a value of -1
    changeSuperCool(-1);
  }
  // If the user enters anything other than the options listed
  else{
    cout << "Invalid Choice! Try again." << endl;
    // Calling back to main menu to loop/try again
    mainMenu();
  }

}

int changeSuperCool(int adjustment){
  // Declaring my variables
  static int super_cool = 0;
  // Changing the SuperCool
  super_cool += adjustment;
  if(super_cool < MIN){
    super_cool = MIN;
  }
  if(super_cool > MAX){
    super_cool = MAX;
  }
  return super_cool;
}

string renderMeter(int number){
  // Declaring my variables
  string header1;
  string header2;
  string meter = "";

  // Creating the meter
  header1.assign(number,'*');
  header2.assign(25 - number,'-');
  meter.append("(");
  meter.append(std::to_string(number));
  meter.append(")");
  meter.append(header1);
  meter.append(header2);

  return meter;
}

string renderMeter(string number)
{
  // Declaring my variables
  string header1;
  string header2;
  string meter = "";
  int tmp = std::stoi(number);
  // Disallowing user_input to be below 0 or over 25
  if(tmp < MIN){
    tmp = MIN;
  }
  if(tmp > MAX){
    tmp = MAX;
  }

  // Creating the meter
  header1.assign(tmp,'*');
  header2.assign(MAX - tmp,'-');
  meter.append("(");
  meter.append(number);
  meter.append(")");
  meter.append(header1);
  meter.append(header2);

  return meter;
}

// Function for user option 2
void showSpecificSuperCoolValue(){
  string user_input;
  // Showing a specific input
  cout << "Please enter a value between 0 and 25: ";
  cin >> user_input;
  cout << renderMeter(user_input) << endl;
  cout << endl;
}
