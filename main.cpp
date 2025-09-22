#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string getRandomMovie(const vector<string>& movies){
  int r = rand() % movies.size();
  return movies[r];
}
char getYesNoInput(){
  char input;
  while (true){
    cin >> input;
    if (input == 'y' || input == 'Y' || input == 'n' || input == 'N'){
      return input;
    }
    cout << "Invalid input. Please enter (y/n): ";
    cin.clear();
    cin.ignore(1000, '\n');
  }
}

int getRatingInput(){
  int rating;
  while(true){
    if (cin >> rating){
      if (rating >= 0 && rating <= 5){
        return rating;
      }
    }
    cout << "Invalid rating. Enter a number between 0-5: ";
    cin.clear();
    cin.ignore(1000, '\n');
  }
}

int main(){

  srand(static_cast<unsigned int>(time(nullptr)));
  int choice;
  int rating;
  vector<string> watchlist;
  vector<int> ratings;

  vector<string> action ={
    "Extraction (2020) - A mercenary embarks on a rescue mission.",
    "Mad Max: Fury Road (2015) - Post-apocalyptic chase.",
    "John Wick (2014) - An ex-hitman seeks vengeance."
  };
  
  vector<string> comedy = {
    "Murder Mystery (2019) - A couple gets tangled in a mystery.",
    "Always Be My Maybe (2019) - Childhood friends reconnect.",
    "The Wrong Missy (2020) - A mistaken invitation leads to chaos."
  };

  vector<string> drama = {
    "The Pursuit of Happyness (2006) - Based on true events.",
    "Marriage Story (2019) - A couple navigates divorce and family struggles.",
    "The Irishman (2019) - A mob hitman's life and regrets are explored."
  };

  vector<string> scifi = {
    "Interstellar (2014) - Astronauts travel through a wormhole.",
    "Dune: Part Two (2024) - Paul Atreides unites with the Fremen to wage war.",
    "Arrival (2016) - A linguist tries to communicate with aliens."
  };
  
  vector<string> horror = {
    "The Conjuring (2013) - Paranormal investigators help a family.",
    "Hereditary (2018) - A family unravels terrifying secrets after a loss.",
    "Bird Box (2018) - Survivors face unseen creatures that drive people to madness."
  };

  cout << "Welcome to the Netflix movie recommendation!" << endl;
  cout << "--------------------------------------------" << endl;
  cout << "Choose a movie genre" << endl;
  cout << "1. Action" <<endl;
  cout << "2. Comedy" <<endl;
  cout << "3. Drama" <<endl;
  cout << "4. Sci-fi" <<endl;
  cout << "5. Horror" <<endl;
  cout << "0. Exit" << endl;
  do{
  cout << "You chose: ";
  cin >> choice;
  
  string picked;
  switch (choice){
    case 1: 
      picked = getRandomMovie(action);
      cout << "You chose: Action " << endl;
      cout << "Recommedation: " << picked << endl;
      break;
      case 2: 
      picked = getRandomMovie(comedy);
      cout << "You chose: Comedy " << endl;
      cout << "Recommendation: " << picked << endl;
      break;
      case 3: 
      picked = getRandomMovie(drama);
      cout << "You chose: Drama " << endl;
      cout << "Recommendation: " << picked << endl;
      break;
      case 4: 
      picked = getRandomMovie(scifi);
      cout << "You chose: Sci-fi " << endl;
      cout << "Recommendation: " << picked << endl;
      break;
      case 5: 
      picked = getRandomMovie(horror);
      cout << "You chose: Horror " << endl;
      cout << "Recommendation: " << picked << endl;
      break;
      case 0: 
      cout << "Exiting program. Goodbye!" << endl;
      break;
      default:
      cout << "Invalid choice. Please enter a number (1-5)." << endl;
      break;
  }
  
  if (choice >= 1 && choice <= 5){
    cout << "Add this movie to your watchlist? (y/n): ";
    char save = getYesNoInput();
    if (save == 'y' || save == 'Y'){
      watchlist.push_back(picked);
      cout << "Saved to watchlist!" << endl;
    }

    cout << "Rate this recommendation (1-5, or 0 to skip): ";
    int rating = getRatingInput();
    if (rating > 0) ratings.push_back(rating);
  }

} while (choice != 0);

if (!watchlist.empty()){
  cout << "Your Watchlist:" << endl;
  for(auto &w : watchlist) cout << "- " << w << endl;
}

if (!ratings.empty()){
  double sum = 0;
  for (int r: ratings) sum += r;
  cout << "Average rating: " << (sum/ratings.size()) << "/5" << endl;
}
}