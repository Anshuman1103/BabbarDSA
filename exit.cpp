#include <iostream>
#include <cstdlib> // for exit()

using namespace std;

int main() {
  int user_input;

  cout << "Enter a number: ";
  cin >> user_input;

  if (user_input == 0) {
    cout << "You entered zero. Exiting program." << endl;
    exit(1); // Indicate error (non-zero exit code)
  } else {
    cout << "You entered a non-zero number. Program continuing." << endl;
  }

  // Code below here won't be executed if user enters 0
  cout << "This message won't be printed if user enters 0." << endl;

  return 0; // This return statement is redundant if exit() is used
}
