#include <iostream>
using namespace std;

int main(){

  int choice;
  cout << "Welcome to the Netflix movie recommendation!" << endl;
  cout << "--------------------------------------------" << endl;
  cout << "Choose a movie genre" << endl;
  cout << "1. Action" <<endl;
  cout << "2. Comedy" <<endl;
  cout << "3. Drama" <<endl;
  cout << "4. Sci-fi" <<endl;
  cout << "5. Horror" <<endl;
  cout << "0. Exit" << endl;
  cout << "You chose: ";
  cin >> choice;

  switch (choice){
    case 1: 
      cout << "You chose: Action " << endl;
      cout << "Recommedation:Extraction (2020) - A mercenary embarks on a rescue mission." << endl;
      break;
      case 2: 
      cout << "You chose: Comedy " << endl;
      cout << "Recommendation: Murder Mystery (2019) - A couple gets tangled in a mystery." << endl;
      break;
      case 3: 
      cout << "You chose: Drama " << endl;
      cout << "Recommendation: The Pursuit of Happyness (2006) - Based on true events." << endl;
      break;
      case 4: 
      cout << "You chose: Sci-fi " << endl;
      cout << "Recommendation: Interstellar (2014) - Astronauts travel through a wormhole." << endl;
      break;
      case 5: 
      cout << "You chose: Horror " << endl;
      cout << "Recommendation: The Conjuring (2013) - Paranormal investigators help a family." << endl;
      break;
      case 0: 
      cout << "Exiting program. Goodbye!" << endl;
      default:
      cout << "Invalid choice. Please enter a number (1-5)." << endl;
  }
  
}