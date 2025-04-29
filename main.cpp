#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

//CONSTANT GLOBAL VARIABLES-----------------------------------------------------------------------------
const string DEFAULT_NAME = "n/a";
const string DEFAULT_CREATURE_TYPE = "typeless";
const int TYPELIST_SIZE = 4;
const string TYPES_LIST[TYPELIST_SIZE] = { "macara", "ceffyl", "nuggle", "bahamut" };
const int DEFAULT_HEALTH_AND_STRENGTH = 120;
const int DEFAULT_SIZE = 5;
const int ARMY_SIZE = 10;

//CLASSES-----------------------------------------------------------------------------------------------
class Creature {
public:

	void setCreature(string newName, string newType, int newHealth, int newStrength);

	string getName() { return creatureName; }
	string getType() { return creatureType; }
	int  getHealth() { return creatureHealth; }
	int getStrength() { return creatureStrength; }
	int getDamage(string type, int strength);

	Creature() {

		setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH);

	}
	~Creature() {

		setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH);

	}
	Creature(Creature& otherCreature) {

		setCreature(otherCreature.creatureName, otherCreature.creatureType, otherCreature.creatureHealth, otherCreature.creatureStrength);

	}
	Creature(string newName, string newType) {

		setCreature(newName, newType, (rand() % 51) + 50, (rand() % 51) + 50);

	}
	Creature(string newName, string newType, int newHealth, int newStrength) {

		setCreature(newName, newType, newHealth, newStrength);

	}



private:

	string creatureName = DEFAULT_NAME;
	string creatureType = DEFAULT_CREATURE_TYPE;
	int creatureHealth = DEFAULT_HEALTH_AND_STRENGTH;
	int creatureStrength = DEFAULT_HEALTH_AND_STRENGTH;

};
class Army {
public:

	Army();
	~Army();
	Army(string newArmyName, int size);
	Army(Army& otherArmy);

	string getArmyCreatureName(int index) { return creatures[index].getName(); }
	string getArmyCreatureType(int index) { return creatures[index].getType(); }
	string getArmyName() { return armyName; }
	int getArmySize() { return army_size; }

	Creature getCreature(int index) { return creatures[index]; }

	void setCreature(int input, string newName, string newType, int newHealth, int newStrength) { creatures[input].setCreature(newName, newType, newHealth, newStrength); }
	void setCreature(int input, Creature creature) { creatures[input] = creature; }

	int getArmyCreatureHealth(int index) { return creatures[index].getHealth(); }
	int getArmyCreatureStrength(int index) { return creatures[index].getStrength(); }
	int getArmyCreatureDamage(int index) { return creatures[index].getDamage(creatures[index].getType(), creatures[index].getStrength()); }
	int getCreatureCount() { return creatureCount; }

	string toString(int index) {

		ostringstream text;
		text << getArmyCreatureName(index) << " the " << getArmyCreatureType(index);
		return text.str();

	}
	void printTheList(int size);



private:

	int army_size;
	string armyName = DEFAULT_NAME;
	int creatureCount = 0;
	Creature* creatures;

};

//FUNCTION DECLERATIONS---------------------------------------------------------------------------------
string checkName(string name);
string checkType(string type);
int checkHealthAndStrength(int value);
void sortSwitch(Army& army, int input);
void createSwitch(Army &army, int input);
bool sortByString(string string_i, string string_j);

//ENUM--------------------------------------------------------------------------------------------------
enum {

	CREATE = 1,
	QUIT
	
	
};

//MAIN--------------------------------------------------------------------------------------------------
int main()
{

	int userInput = 0;
	while (userInput != QUIT) {

		cout << "\nMenu:\n"
			<< "1. Create an Army from user input\n"
			<< "2. Quit\n"
			<< "Input: ";

		
		cin >> userInput;

		switch (userInput) {
		case CREATE:
		{
			int sizeInput = 0;
			string nameInput = "";

			cout << "Input name of your Army: ";
			cin >> nameInput;
			cout << "Input the size of your Array: ";
			cin >> sizeInput;

			Army thisArmy(nameInput, sizeInput);
			thisArmy.printTheList(sizeInput);

			createSwitch(thisArmy, userInput);
		}
			break;
		case QUIT:
			break;
		default:
			cout << "Invalid choice, try again\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
}

//FUNCTIONS---------------------------------------------------------------------------------------------
string checkName(string name) {

	int count = 0;
	for (char c : name) {
		if (std::isalpha(c)) {
			count++;
		}
	}
	if (count < 3 && name != DEFAULT_NAME) {

		cout << name << " has less than 3 alphabetic characters, setting to defalut..." << endl;
		return DEFAULT_NAME;

	}
	else {

		return name;

	}

}
string checkType(string type) {

	bool validType = false;

	for (int i = 0; i < TYPELIST_SIZE; i++) {

		if (type == TYPES_LIST[i] || type == DEFAULT_CREATURE_TYPE) {

			validType = true;

		}

	}

	if (validType == true) {

		return type;

	}
	else {

		cout << type << "is not 1 of 4 valid types (macara, ceffyl, nuggle, bahamut), setting to default...\n";
		return DEFAULT_CREATURE_TYPE;

	}

}
int checkHealthAndStrength(int value) {

	if (value >= 120 && value <= 250) {

		return value;

	}
	else {

		cout << value << " is either less than 50 or greater than 100, setting to default...\n";
		return DEFAULT_HEALTH_AND_STRENGTH;

	}

}
void sortSwitch(Army &army, int input) {

	enum {

		SORT_NAME = 1,
		SORT_TYPE,
		SORT_HEALTH,
		SORT_STRENGTH,
		SORT_BACK

	};


	while (input != SORT_BACK) {
	
		Creature tempCreature;
		input = 0;

		cout << "\n1. Name\n"
			<< "2. Type\n"
			<< "3. Health\n"
			<< "4. Strength\n"
			<< "5. Back\n"
			<< "Input: ";
		cin >> input;
		
		switch (input) {
		
		case SORT_NAME:
		{
			Army sortedArmy(army);
			for (int i = 0; i < sortedArmy.getArmySize(); i++) {
				for (int j = i + 1; j < sortedArmy.getArmySize(); j++) {

					if (sortByString(sortedArmy.getArmyCreatureName(i), sortedArmy.getArmyCreatureName(j) = true)) {

						tempCreature = sortedArmy.getCreature(i);
						sortedArmy.setCreature(i, sortedArmy.getArmyCreatureName(j), sortedArmy.getArmyCreatureType(j), sortedArmy.getArmyCreatureHealth(j), sortedArmy.getArmyCreatureStrength(j));
						sortedArmy.setCreature(j, tempCreature);
					}

				}
			}
			sortedArmy.printTheList(sortedArmy.getArmySize());
			
		}
			break;
		case SORT_TYPE:
		{
			Army sortedArmy(army);
			cout << "Sorting by type...\n";
			for (int i = 0; i < sortedArmy.getArmySize(); i++) {
				for (int j = i + 1; j < sortedArmy.getArmySize(); j++) {

					if (sortedArmy.getArmyCreatureType(j) < sortedArmy.getArmyCreatureType(i)) {

						tempCreature = sortedArmy.getCreature(i);
						sortedArmy.setCreature(i, sortedArmy.getArmyCreatureName(j), sortedArmy.getArmyCreatureType(j), sortedArmy.getArmyCreatureHealth(j), sortedArmy.getArmyCreatureStrength(j));
						sortedArmy.setCreature(j, tempCreature);
					}

				}
			}
			sortedArmy.printTheList(sortedArmy.getArmySize());
		}
			break;
		case SORT_HEALTH:
		{
			Army sortedArmy(army);
			cout << "Sorting by health...\n";

			for (int i = 0; i < sortedArmy.getArmySize(); i++) {
				for (int j = i + 1; j < sortedArmy.getArmySize(); j++) {

					if (sortedArmy.getArmyCreatureHealth(j) < sortedArmy.getArmyCreatureHealth(i)) {

						tempCreature = sortedArmy.getCreature(i);
						sortedArmy.setCreature(i, sortedArmy.getArmyCreatureName(j), sortedArmy.getArmyCreatureType(j), sortedArmy.getArmyCreatureHealth(j), sortedArmy.getArmyCreatureStrength(j));
						sortedArmy.setCreature(j, tempCreature);
					}
				}
			}
			sortedArmy.printTheList(sortedArmy.getArmySize());
		}
			break;
		case SORT_STRENGTH:
		{
			Army sortedArmy(army);
			cout << "Sorting by strength...\n";
			for (int i = 0; i < sortedArmy.getArmySize(); i++) {
				for (int j = i + 1; j < sortedArmy.getArmySize(); j++) {

					if (sortedArmy.getArmyCreatureStrength(j) < sortedArmy.getArmyCreatureStrength(i)) {

						tempCreature = sortedArmy.getCreature(i);
						sortedArmy.setCreature(i, sortedArmy.getArmyCreatureName(j), sortedArmy.getArmyCreatureType(j), sortedArmy.getArmyCreatureHealth(j), sortedArmy.getArmyCreatureStrength(j));
						sortedArmy.setCreature(j, tempCreature);
					}
				}
			}
			sortedArmy.printTheList(sortedArmy.getArmySize());
		}
			break;
		case SORT_BACK:
			break;
		default:
			cout << "Invalid choice, try again\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
}
void createSwitch(Army &army, int input) {
	
	enum {

		SORT = 1,
		FILTER,
		BACK

	};
	
	
	while (input != BACK) {

		input = 0;

		cout << "\n1. Sort creatures by any field\n"
			<< "2. Filter creatures by health range (inclusive)\n"
			<< "3. Back to menu (This will delete your current Army!)\n"
			<< "Input: ";

		cin >> input;

		switch (input) {
		case SORT:
		{

			sortSwitch(army, input);

		}
			break;
		case FILTER:
		{

			int healthMax;
			int healthMin;
			int filterCount = 0;

			cout << "\n	Enter minimum and maximum health:\n"
				<< "Minimum Health: ";
			cin >> healthMin;
			while (healthMin < 0) {
				cout << "Invalid input, must be larger than 0\n"
					<< "Minimum Health: ";
				cin >> healthMin;
			}
			
			cout << "Maximum health: ";
			cin >> healthMax;
			while (healthMax < healthMin) {
				cout << "Invalid input, must be larger than minimum health\n"
					<< "Minimum Health: ";
				cin >> healthMax;
			}
			cout << "Printing sorted army of " << army.getArmyName() << "..."
				"\n| Creature" << setw(23)
				<< "Health" << setw(10)
				<< "Strength" << setw(5)
				<< "| \n"
				"+" << setw(44) << setfill('-') << "+" << setfill(' ') << endl;
			for (int i = 0; i < army.getArmySize(); i++) {

				if ((army.getArmyCreatureHealth(i) >= healthMin) && (army.getArmyCreatureHealth(i) <= healthMax)) {

					filterCount++;
					cout << "| " << left << setw(26) << army.toString(i) << right << setw(5) << army.getArmyCreatureHealth(i) << setw(5) << "" << right << setw(5) << army.getArmyCreatureStrength(i) << " |\n";
				
				}

			}

			cout << "+" << setw(44) << setfill('-') << "+" << setfill(' ') << endl;


			if (filterCount == 0) {

				cout << "None Found!\n";

			}

		}
		break;
		case BACK:
			break;
		default:
			cout << "Invalid choice, try again\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

	}

}
bool sortByString(string string_i, string string_j) {
 
	if (string_j > string_i) {

		return true;

	}
	else if (string_j < string_i) {

		return false;

	}
	else if (string_j == string_i) {

	}

	int i_count = string_i.length();
	int j_count = string_j.length();
	int smallestSize = min(i_count, j_count);

	for (int i = 0; i < smallestSize;) {
		
		if (string_j[i] > string_i[i]) {
			
			return true;

		}
		else if (string_j[i] < string_i[i]) {

			return false;

		}
		else if (string_j[i] > string_i[i]) {

			i++;

		}
	
	}

	if (j_count < i_count) {
	
		return true;

	}
	else {

		return false;

	}

}


//CLASS FUNCTIONS---------------------------------------------------------------------------------------
void Creature::setCreature(string newName, string newType, int newHealth, int newStrength) {

	creatureName = checkName(newName);
	creatureType = checkType(newType);
	creatureStrength = checkHealthAndStrength(newStrength);
	creatureHealth = checkHealthAndStrength(newHealth);

}
int Creature::getDamage(string type, int strength) {

	return rand() % strength + 1;

}
void Army::printTheList(int size) {

	cout << "Printing army of " << getArmyName() << "..."
		"\n| Creature" << setw(23)
		<< "Health" << setw(10)
		<< "Strength" << setw(5)
		<< "| \n"
		"+" << setw(44) << setfill('-') << "+" << setfill(' ') << endl;

	for (int i = 0; i < size; i++) {

		cout << "| " << left << setw(26) << toString(i) << right << setw(5) << getArmyCreatureHealth(i) << setw(5) << "" << right << setw(5) << getArmyCreatureStrength(i) << " |\n";;

	}
	cout << "+" << setw(44) << setfill('-') << "+" << setfill(' ') << endl;

}

//ARMY CONSTRUCTORS-------------------------------------------------------------------------------------
Army::Army() {

	cout << "Default constructor is running...\n";

	creatures = new Creature[ARMY_SIZE];

	armyName = DEFAULT_NAME;
	creatureCount = ARMY_SIZE;

	for (int i = 0; i < ARMY_SIZE; i++) {

		creatures[i].setCreature(DEFAULT_NAME, DEFAULT_CREATURE_TYPE, DEFAULT_HEALTH_AND_STRENGTH, DEFAULT_HEALTH_AND_STRENGTH);

	}


}
Army::~Army() {

	armyName = DEFAULT_NAME;
	delete[] creatures;

}
Army::Army(string newArmyName, int size) {

	army_size = size;
	try {
		
		creatures = new Creature[army_size];

		if (size == 0) {

			throw size;

		}

	}
	catch (bad_alloc &list) {

		cout << "\nallocation failed, you most likely input an invalid number";
		exit(EXIT_FAILURE);
	}
	catch (int zero) {

		cout << "\ninvalid argument, you most likely input something that isnt an integer or 0";
		exit(EXIT_FAILURE);

	}
	catch(...){

		cout << "\nError";
		exit(EXIT_FAILURE);
	}


	armyName = checkName(newArmyName);
	for (int i = 0; i < army_size; i++) {

		creatures[i].setCreature("CREATURE_" + to_string(i + 1), TYPES_LIST[rand() % 4], (rand() % 131) + 120, (rand() % 131) + 120);

	}

}
Army::Army(Army& otherArmy) {

	armyName = otherArmy.armyName;
	army_size = otherArmy.army_size;
	creatures = new Creature[army_size];

	for (int i = 0; i < army_size; i++) {

		creatures[i] = otherArmy.creatures[i];

	}

}
