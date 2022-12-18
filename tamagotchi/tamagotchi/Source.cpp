// Leif Bruce
// 12-18-2022
// Cyberpet assessment for CMP101


#include <string>
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;



// This is the starting menu for the cyberpet, it will ask the user if they want to name their pet or not
void nameMenu(string& i){
	cout << "Would you like to name your pet? (y/n)" << endl;
	cin >> i;
	if (i == "y") {
		cout << "What would you like to name your pet?" << endl;
		cin >> i;
	}
	else if (i == "n") {
		i = "Tamagotchi";
	}
	else {
		cout << "Invalid input, please try again" << endl;
		nameMenu(i);
	}
}

// hungerStatus is used to define how hungry the pet is and will be used to determine if the pet is hungry or not through user input
string hungerStatus(int val) {
	if (val <= 0) {
		return "Starving";
	}
	else if (val <= 10) {
		return "Hungry";
	}
	else if (val <= 20) {
		return "Peckish";
	}
	else if (val <= 30) {
		return "Satisfied";
	}
	else if (val <= 40) {
		return "Full";
	}
	else if (val <= 50) {
		return "Stuffed";
	}
	else {
		return "Overfed";
	}
}

// restStatus is used to define how tired the pet is and will be used to determine if the pet is tired or not through user input
string restStatus(int val) {
	if (val <= 0) {
		return "Exhausted";
	}
	else if (val <= 10) {
		return "Tired";
	}
	else if (val <= 20) {
		return "Sleepy";
	}
	else if (val <= 30) {
		return "Rested";
	}
	else if (val <= 40) {
		return "Energized";
	}
	else if (val <= 50) {
		return "Hyper";
	}
	else {
		return "Overactive";
	}
}

// moodStatus is used to define how happy the pet is and will be used to determine if the pet is happy or not through user input
string moodStatus(int val) {
	if (val <= 0) {
		return "Depressed";
	}
	else if (val <= 10) {
		return "Sad";
	}
	else if (val <= 20) {
		return "Meh";
	}
	else if (val <= 30) {
		return "Happy";
	}
	else if (val <= 40) {
		return "Cheerful";
	}
	else if (val <= 50) {
		return "Ecstatic";
	}
	else {
		return "Overjoyed";
	}
}

// This is the main menu for the cyberpet, it will ask the user what they want to do with their pet

// ### Note you can choice all 3 options at the same time
char mainMenu(string x, int& hunger, int& rest, int& mood) {
	char input;
	cout << "Welcome to the world of " << x << "!" << endl; // This will display the name of the pet
	cout << "Hunger: " << hungerStatus(hunger) << endl; // This will display the hunger status of the pet
	cout << "Rest: " << restStatus(rest) << endl; // This will display the rest status of the pet
	cout << "Mood: " << moodStatus(mood) << endl; // This will display the mood status of the pet
	cout << "What would you like to do?" << endl; // This will ask the user what they want to do with their pet
	cout << "1. Feed " << x << endl;
	cout << "2. Put " << x << " to bed" << endl;
	cout << "3. Play with " << x << endl;
	cout << "4. Do nothing" << endl;
	cout << "5. Quit" << endl;
	cin >> input;
	return input;
}
// if the player wants to feed the pet it will add 10 to the hunger status and subtract 5 from the mood and rest status
void feed(string x, int& hunger) { 
	cout << "You feed " << x << endl;
	hunger += 10;
}
// if the player wants to put the pet to bed it will add 10 to the rest status and subtract 5 from the hunger and mood status
void sleep(string x, int& rest) {
	cout << "You put " << x << " to bed" << endl;
	rest += 10;
}
// if the player wants to play with the pet it will add 10 to the mood status and subtract 5 from the hunger and rest status
void play(string x, int& mood) {
	cout << "You play with " << x << endl;
	mood += 10;
}
// if the player wants to do nothing it will subtract 5 from all the status
void nothing(string x) {
	cout << "You do nothing" << endl;
}
// if the player neglects the pet it will subtract 5 from all the status and eventually die from starvation, exhaustion, or depression
void death(int& hunger, int& rest, int& mood) {
	if (hunger <= 0 || rest <= 0 || mood <= 0) { // if any of the status are 0 or below the pet will die
		cout << "Your pet has died" << endl;
		exit(0);
	}
}

int main()
{
	// declaring the variables for the cyberpet all stats are set to 50 to give the player a fighting chance, every time yo choice one thing it will subtract from the other two so you need to balace it out
	// so your pet does not end up dead
	string name;
	int hunger = 50;
	int rest = 50;
	int mood = 50;
	nameMenu(name);
	// this is the main loop for the game, it will keep running until the player chooses to quit
	while (true) {
		char input = mainMenu(name, hunger, rest, mood);
		switch (input) {
		case '1':
			feed(name, hunger);
			break;
		case '2':
			sleep(name, rest);
			break;
		case '3':
			play(name, mood);
			break;
		case '4':
			nothing(name);
			break;
		case '5':
			exit(0);
			break;
		default:
			cout << "Invalid input, please try again" << endl;
			break;
		}
		// subtracting 5 from all the stats
		hunger -= 5;
		rest -= 5;
		mood -= 5;
		death(hunger, rest, mood);
		this_thread::sleep_for(chrono::seconds(1)); // this is used to make the game run slower so the player can read the text
		system("cls");
	}
	return 0;
}