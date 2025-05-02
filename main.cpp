//Matteo Podesta
//Lab #7

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

const string DEFAULT_NAME = "n/a";
const string DEFAULT_CREATURE_TYPE = "typeless";
const int TYPELIST_SIZE = 4;
const string TYPES_LIST[TYPELIST_SIZE] = { "macara", "ceffyl", "nuggle", "bahamut" };
const int DEFAULT_HEALTH_AND_STRENGTH = 120;
const int DEFAULT_SIZE = 5;
const int ARMY_SIZE = 10;

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

string checkName(string name);
string checkType(string type);
int checkHealthAndStrength(int value);
void sortSwitch(Army& army, int input);
void createSwitch(Army &army, int input);
bool sortByString(string string_i, string string_j);

enum {

	CREATE = 1,
	QUIT
	
	
};

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

/*
FINAL TEST RUNS:

-------
TEST 1:
Menu:
1. Create an Army from user input
2. Quit
Input: 1
Input name of your Army: 1
Input the size of your Array: 123
1 has less than 3 alphabetic characters, setting to defalut...
Printing army of n/a...
| Creature                 Health  Strength |
+-------------------------------------------+
| CREATURE_1 the ceffyl       166       247 |
| CREATURE_2 the macara       124       163 |
| CREATURE_3 the nuggle       227       134 |
| CREATURE_4 the macara       231       192 |
| CREATURE_5 the ceffyl       125       179 |
| CREATURE_6 the bahamut      141       233 |
| CREATURE_7 the bahamut      154       185 |
| CREATURE_8 the macara       142       223 |
| CREATURE_9 the macara       249       188 |
| CREATURE_10 the macara      234       188 |
| CREATURE_11 the bahamut     219       231 |
| CREATURE_12 the nuggle      120       155 |
| CREATURE_13 the bahamut     125       219 |
| CREATURE_14 the nuggle      220       134 |
| CREATURE_15 the nuggle      239       192 |
| CREATURE_16 the macara      233       196 |
| CREATURE_17 the ceffyl      122       176 |
| CREATURE_18 the macara      127       163 |
| CREATURE_19 the ceffyl      197       141 |
| CREATURE_20 the ceffyl      243       139 |
| CREATURE_21 the macara      171       142 |
| CREATURE_22 the nuggle      227       146 |
| CREATURE_23 the macara      127       154 |
| CREATURE_24 the macara      214       187 |
| CREATURE_25 the nuggle      124       168 |
| CREATURE_26 the nuggle      174       192 |
| CREATURE_27 the ceffyl      230       131 |
| CREATURE_28 the bahamut     162       231 |
| CREATURE_29 the macara      239       170 |
| CREATURE_30 the macara      228       165 |
| CREATURE_31 the macara      249       202 |
| CREATURE_32 the bahamut     174       155 |
| CREATURE_33 the nuggle      124       237 |
| CREATURE_34 the ceffyl      188       237 |
| CREATURE_35 the bahamut     161       172 |
| CREATURE_36 the nuggle      199       211 |
| CREATURE_37 the ceffyl      163       236 |
| CREATURE_38 the ceffyl      197       189 |
| CREATURE_39 the nuggle      173       185 |
| CREATURE_40 the ceffyl      126       239 |
| CREATURE_41 the nuggle      242       179 |
| CREATURE_42 the macara      128       205 |
| CREATURE_43 the bahamut     221       236 |
| CREATURE_44 the macara      222       222 |
| CREATURE_45 the ceffyl      200       229 |
| CREATURE_46 the nuggle      181       180 |
| CREATURE_47 the bahamut     250       191 |
| CREATURE_48 the bahamut     154       232 |
| CREATURE_49 the ceffyl      234       121 |
| CREATURE_50 the nuggle      237       237 |
| CREATURE_51 the nuggle      247       176 |
| CREATURE_52 the nuggle      206       158 |
| CREATURE_53 the macara      149       223 |
| CREATURE_54 the bahamut     191       238 |
| CREATURE_55 the macara      184       221 |
| CREATURE_56 the bahamut     231       205 |
| CREATURE_57 the nuggle      193       235 |
| CREATURE_58 the macara      136       193 |
| CREATURE_59 the macara      220       168 |
| CREATURE_60 the bahamut     238       138 |
| CREATURE_61 the ceffyl      173       138 |
| CREATURE_62 the bahamut     155       207 |
| CREATURE_63 the macara      169       240 |
| CREATURE_64 the bahamut     210       180 |
| CREATURE_65 the macara      242       202 |
| CREATURE_66 the ceffyl      187       151 |
| CREATURE_67 the ceffyl      150       202 |
| CREATURE_68 the macara      148       191 |
| CREATURE_69 the macara      133       129 |
| CREATURE_70 the macara      162       124 |
| CREATURE_71 the macara      200       124 |
| CREATURE_72 the ceffyl      203       175 |
| CREATURE_73 the bahamut     200       169 |
| CREATURE_74 the bahamut     135       120 |
| CREATURE_75 the nuggle      232       191 |
| CREATURE_76 the macara      188       216 |
| CREATURE_77 the macara      246       135 |
| CREATURE_78 the ceffyl      220       190 |
| CREATURE_79 the ceffyl      156       160 |
| CREATURE_80 the nuggle      229       187 |
| CREATURE_81 the nuggle      232       195 |
| CREATURE_82 the ceffyl      154       218 |
| CREATURE_83 the bahamut     150       214 |
| CREATURE_84 the bahamut     134       209 |
| CREATURE_85 the macara      143       132 |
| CREATURE_86 the nuggle      159       151 |
| CREATURE_87 the bahamut     121       126 |
| CREATURE_88 the nuggle      226       122 |
| CREATURE_89 the ceffyl      224       154 |
| CREATURE_90 the bahamut     186       185 |
| CREATURE_91 the ceffyl      240       169 |
| CREATURE_92 the ceffyl      221       217 |
| CREATURE_93 the macara      163       141 |
| CREATURE_94 the ceffyl      136       165 |
| CREATURE_95 the ceffyl      179       215 |
| CREATURE_96 the bahamut     225       144 |
| CREATURE_97 the nuggle      222       187 |
| CREATURE_98 the nuggle      166       179 |
| CREATURE_99 the macara      228       136 |
| CREATURE_100 the nuggle     148       165 |
| CREATURE_101 the macara     130       140 |
| CREATURE_102 the macara     195       192 |
| CREATURE_103 the nuggle     225       163 |
| CREATURE_104 the macara     233       135 |
| CREATURE_105 the nuggle     146       205 |
| CREATURE_106 the bahamut    178       155 |
| CREATURE_107 the bahamut    137       204 |
| CREATURE_108 the ceffyl     231       205 |
| CREATURE_109 the ceffyl     142       128 |
| CREATURE_110 the macara     243       241 |
| CREATURE_111 the macara     130       158 |
| CREATURE_112 the nuggle     162       156 |
| CREATURE_113 the macara     142       224 |
| CREATURE_114 the bahamut    240       241 |
| CREATURE_115 the ceffyl     246       130 |
| CREATURE_116 the macara     236       249 |
| CREATURE_117 the ceffyl     145       235 |
| CREATURE_118 the nuggle     199       186 |
| CREATURE_119 the ceffyl     129       203 |
| CREATURE_120 the nuggle     185       175 |
| CREATURE_121 the bahamut    158       134 |
| CREATURE_122 the nuggle     164       243 |
| CREATURE_123 the macara     212       228 |
+-------------------------------------------+

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: 1

1. Name
2. Type
3. Health
4. Strength
5. Back
Input: 3
Sorting by health...
Printing army of n/a...
| Creature                 Health  Strength |
+-------------------------------------------+
| CREATURE_12 the nuggle      120       155 |
| CREATURE_87 the bahamut     121       126 |
| CREATURE_17 the ceffyl      122       176 |
| CREATURE_25 the nuggle      124       168 |
| CREATURE_33 the nuggle      124       237 |
| CREATURE_2 the macara       124       163 |
| CREATURE_5 the ceffyl       125       179 |
| CREATURE_13 the bahamut     125       219 |
| CREATURE_40 the ceffyl      126       239 |
| CREATURE_18 the macara      127       163 |
| CREATURE_23 the macara      127       154 |
| CREATURE_42 the macara      128       205 |
| CREATURE_119 the ceffyl     129       203 |
| CREATURE_111 the macara     130       158 |
| CREATURE_101 the macara     130       140 |
| CREATURE_69 the macara      133       129 |
| CREATURE_84 the bahamut     134       209 |
| CREATURE_74 the bahamut     135       120 |
| CREATURE_94 the ceffyl      136       165 |
| CREATURE_58 the macara      136       193 |
| CREATURE_107 the bahamut    137       204 |
| CREATURE_6 the bahamut      141       233 |
| CREATURE_8 the macara       142       223 |
| CREATURE_113 the macara     142       224 |
| CREATURE_109 the ceffyl     142       128 |
| CREATURE_85 the macara      143       132 |
| CREATURE_117 the ceffyl     145       235 |
| CREATURE_105 the nuggle     146       205 |
| CREATURE_68 the macara      148       191 |
| CREATURE_100 the nuggle     148       165 |
| CREATURE_53 the macara      149       223 |
| CREATURE_83 the bahamut     150       214 |
| CREATURE_67 the ceffyl      150       202 |
| CREATURE_82 the ceffyl      154       218 |
| CREATURE_7 the bahamut      154       185 |
| CREATURE_48 the bahamut     154       232 |
| CREATURE_62 the bahamut     155       207 |
| CREATURE_79 the ceffyl      156       160 |
| CREATURE_121 the bahamut    158       134 |
| CREATURE_86 the nuggle      159       151 |
| CREATURE_35 the bahamut     161       172 |
| CREATURE_28 the bahamut     162       231 |
| CREATURE_112 the nuggle     162       156 |
| CREATURE_70 the macara      162       124 |
| CREATURE_37 the ceffyl      163       236 |
| CREATURE_93 the macara      163       141 |
| CREATURE_122 the nuggle     164       243 |
| CREATURE_1 the ceffyl       166       247 |
| CREATURE_98 the nuggle      166       179 |
| CREATURE_63 the macara      169       240 |
| CREATURE_21 the macara      171       142 |
| CREATURE_61 the ceffyl      173       138 |
| CREATURE_39 the nuggle      173       185 |
| CREATURE_32 the bahamut     174       155 |
| CREATURE_26 the nuggle      174       192 |
| CREATURE_106 the bahamut    178       155 |
| CREATURE_95 the ceffyl      179       215 |
| CREATURE_46 the nuggle      181       180 |
| CREATURE_55 the macara      184       221 |
| CREATURE_120 the nuggle     185       175 |
| CREATURE_90 the bahamut     186       185 |
| CREATURE_66 the ceffyl      187       151 |
| CREATURE_34 the ceffyl      188       237 |
| CREATURE_76 the macara      188       216 |
| CREATURE_54 the bahamut     191       238 |
| CREATURE_57 the nuggle      193       235 |
| CREATURE_102 the macara     195       192 |
| CREATURE_38 the ceffyl      197       189 |
| CREATURE_19 the ceffyl      197       141 |
| CREATURE_36 the nuggle      199       211 |
| CREATURE_118 the nuggle     199       186 |
| CREATURE_45 the ceffyl      200       229 |
| CREATURE_71 the macara      200       124 |
| CREATURE_73 the bahamut     200       169 |
| CREATURE_72 the ceffyl      203       175 |
| CREATURE_52 the nuggle      206       158 |
| CREATURE_64 the bahamut     210       180 |
| CREATURE_123 the macara     212       228 |
| CREATURE_24 the macara      214       187 |
| CREATURE_11 the bahamut     219       231 |
| CREATURE_78 the ceffyl      220       190 |
| CREATURE_14 the nuggle      220       134 |
| CREATURE_59 the macara      220       168 |
| CREATURE_92 the ceffyl      221       217 |
| CREATURE_43 the bahamut     221       236 |
| CREATURE_44 the macara      222       222 |
| CREATURE_97 the nuggle      222       187 |
| CREATURE_89 the ceffyl      224       154 |
| CREATURE_96 the bahamut     225       144 |
| CREATURE_103 the nuggle     225       163 |
| CREATURE_88 the nuggle      226       122 |
| CREATURE_22 the nuggle      227       146 |
| CREATURE_3 the nuggle       227       134 |
| CREATURE_30 the macara      228       165 |
| CREATURE_99 the macara      228       136 |
| CREATURE_80 the nuggle      229       187 |
| CREATURE_27 the ceffyl      230       131 |
| CREATURE_108 the ceffyl     231       205 |
| CREATURE_4 the macara       231       192 |
| CREATURE_56 the bahamut     231       205 |
| CREATURE_75 the nuggle      232       191 |
| CREATURE_81 the nuggle      232       195 |
| CREATURE_104 the macara     233       135 |
| CREATURE_16 the macara      233       196 |
| CREATURE_10 the macara      234       188 |
| CREATURE_49 the ceffyl      234       121 |
| CREATURE_116 the macara     236       249 |
| CREATURE_50 the nuggle      237       237 |
| CREATURE_60 the bahamut     238       138 |
| CREATURE_15 the nuggle      239       192 |
| CREATURE_29 the macara      239       170 |
| CREATURE_91 the ceffyl      240       169 |
| CREATURE_114 the bahamut    240       241 |
| CREATURE_65 the macara      242       202 |
| CREATURE_41 the nuggle      242       179 |
| CREATURE_20 the ceffyl      243       139 |
| CREATURE_110 the macara     243       241 |
| CREATURE_77 the macara      246       135 |
| CREATURE_115 the ceffyl     246       130 |
| CREATURE_51 the nuggle      247       176 |
| CREATURE_31 the macara      249       202 |
| CREATURE_9 the macara       249       188 |
| CREATURE_47 the bahamut     250       191 |
+-------------------------------------------+

1. Name
2. Type
3. Health
4. Strength
5. Back
Input: 2
Sorting by type...
Printing army of n/a...
| Creature                 Health  Strength |
+-------------------------------------------+
| CREATURE_6 the bahamut      141       233 |
| CREATURE_7 the bahamut      154       185 |
| CREATURE_11 the bahamut     219       231 |
| CREATURE_13 the bahamut     125       219 |
| CREATURE_28 the bahamut     162       231 |
| CREATURE_32 the bahamut     174       155 |
| CREATURE_35 the bahamut     161       172 |
| CREATURE_43 the bahamut     221       236 |
| CREATURE_47 the bahamut     250       191 |
| CREATURE_48 the bahamut     154       232 |
| CREATURE_54 the bahamut     191       238 |
| CREATURE_56 the bahamut     231       205 |
| CREATURE_60 the bahamut     238       138 |
| CREATURE_62 the bahamut     155       207 |
| CREATURE_64 the bahamut     210       180 |
| CREATURE_73 the bahamut     200       169 |
| CREATURE_74 the bahamut     135       120 |
| CREATURE_83 the bahamut     150       214 |
| CREATURE_84 the bahamut     134       209 |
| CREATURE_87 the bahamut     121       126 |
| CREATURE_90 the bahamut     186       185 |
| CREATURE_96 the bahamut     225       144 |
| CREATURE_106 the bahamut    178       155 |
| CREATURE_107 the bahamut    137       204 |
| CREATURE_114 the bahamut    240       241 |
| CREATURE_121 the bahamut    158       134 |
| CREATURE_17 the ceffyl      122       176 |
| CREATURE_37 the ceffyl      163       236 |
| CREATURE_66 the ceffyl      187       151 |
| CREATURE_67 the ceffyl      150       202 |
| CREATURE_72 the ceffyl      203       175 |
| CREATURE_38 the ceffyl      197       189 |
| CREATURE_40 the ceffyl      126       239 |
| CREATURE_78 the ceffyl      220       190 |
| CREATURE_79 the ceffyl      156       160 |
| CREATURE_82 the ceffyl      154       218 |
| CREATURE_19 the ceffyl      197       141 |
| CREATURE_45 the ceffyl      200       229 |
| CREATURE_20 the ceffyl      243       139 |
| CREATURE_89 the ceffyl      224       154 |
| CREATURE_27 the ceffyl      230       131 |
| CREATURE_91 the ceffyl      240       169 |
| CREATURE_92 the ceffyl      221       217 |
| CREATURE_94 the ceffyl      136       165 |
| CREATURE_95 the ceffyl      179       215 |
| CREATURE_49 the ceffyl      234       121 |
| CREATURE_1 the ceffyl       166       247 |
| CREATURE_5 the ceffyl       125       179 |
| CREATURE_108 the ceffyl     231       205 |
| CREATURE_109 the ceffyl     142       128 |
| CREATURE_34 the ceffyl      188       237 |
| CREATURE_115 the ceffyl     246       130 |
| CREATURE_117 the ceffyl     145       235 |
| CREATURE_119 the ceffyl     129       203 |
| CREATURE_61 the ceffyl      173       138 |
| CREATURE_42 the macara      128       205 |
| CREATURE_23 the macara      127       154 |
| CREATURE_44 the macara      222       222 |
| CREATURE_76 the macara      188       216 |
| CREATURE_77 the macara      246       135 |
| CREATURE_24 the macara      214       187 |
| CREATURE_4 the macara       231       192 |
| CREATURE_2 the macara       124       163 |
| CREATURE_29 the macara      239       170 |
| CREATURE_53 the macara      149       223 |
| CREATURE_85 the macara      143       132 |
| CREATURE_30 the macara      228       165 |
| CREATURE_55 the macara      184       221 |
| CREATURE_31 the macara      249       202 |
| CREATURE_58 the macara      136       193 |
| CREATURE_59 the macara      220       168 |
| CREATURE_93 the macara      163       141 |
| CREATURE_16 the macara      233       196 |
| CREATURE_8 the macara       142       223 |
| CREATURE_18 the macara      127       163 |
| CREATURE_99 the macara      228       136 |
| CREATURE_101 the macara     130       140 |
| CREATURE_102 the macara     195       192 |
| CREATURE_104 the macara     233       135 |
| CREATURE_63 the macara      169       240 |
| CREATURE_9 the macara       249       188 |
| CREATURE_65 the macara      242       202 |
| CREATURE_10 the macara      234       188 |
| CREATURE_110 the macara     243       241 |
| CREATURE_111 the macara     130       158 |
| CREATURE_113 the macara     142       224 |
| CREATURE_21 the macara      171       142 |
| CREATURE_68 the macara      148       191 |
| CREATURE_116 the macara     236       249 |
| CREATURE_69 the macara      133       129 |
| CREATURE_70 the macara      162       124 |
| CREATURE_71 the macara      200       124 |
| CREATURE_123 the macara     212       228 |
| CREATURE_57 the nuggle      193       235 |
| CREATURE_15 the nuggle      239       192 |
| CREATURE_75 the nuggle      232       191 |
| CREATURE_97 the nuggle      222       187 |
| CREATURE_98 the nuggle      166       179 |
| CREATURE_25 the nuggle      124       168 |
| CREATURE_100 the nuggle     148       165 |
| CREATURE_33 the nuggle      124       237 |
| CREATURE_26 the nuggle      174       192 |
| CREATURE_103 the nuggle     225       163 |
| CREATURE_46 the nuggle      181       180 |
| CREATURE_105 the nuggle     146       205 |
| CREATURE_80 the nuggle      229       187 |
| CREATURE_81 the nuggle      232       195 |
| CREATURE_12 the nuggle      120       155 |
| CREATURE_36 the nuggle      199       211 |
| CREATURE_3 the nuggle       227       134 |
| CREATURE_50 the nuggle      237       237 |
| CREATURE_112 the nuggle     162       156 |
| CREATURE_86 the nuggle      159       151 |
| CREATURE_51 the nuggle      247       176 |
| CREATURE_88 the nuggle      226       122 |
| CREATURE_52 the nuggle      206       158 |
| CREATURE_22 the nuggle      227       146 |
| CREATURE_118 the nuggle     199       186 |
| CREATURE_39 the nuggle      173       185 |
| CREATURE_120 the nuggle     185       175 |
| CREATURE_14 the nuggle      220       134 |
| CREATURE_122 the nuggle     164       243 |
| CREATURE_41 the nuggle      242       179 |
+-------------------------------------------+

1. Name
2. Type
3. Health
4. Strength
5. Back
Input: 5

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: 2

		Enter minimum and maximum health:
Minimum Health: 200
Maximum health: 300
Printing sorted army of n/a...
| Creature                 Health  Strength |
+-------------------------------------------+
| CREATURE_3 the nuggle       227       134 |
| CREATURE_4 the macara       231       192 |
| CREATURE_9 the macara       249       188 |
| CREATURE_10 the macara      234       188 |
| CREATURE_11 the bahamut     219       231 |
| CREATURE_14 the nuggle      220       134 |
| CREATURE_15 the nuggle      239       192 |
| CREATURE_16 the macara      233       196 |
| CREATURE_20 the ceffyl      243       139 |
| CREATURE_22 the nuggle      227       146 |
| CREATURE_24 the macara      214       187 |
| CREATURE_27 the ceffyl      230       131 |
| CREATURE_29 the macara      239       170 |
| CREATURE_30 the macara      228       165 |
| CREATURE_31 the macara      249       202 |
| CREATURE_41 the nuggle      242       179 |
| CREATURE_43 the bahamut     221       236 |
| CREATURE_44 the macara      222       222 |
| CREATURE_45 the ceffyl      200       229 |
| CREATURE_47 the bahamut     250       191 |
| CREATURE_49 the ceffyl      234       121 |
| CREATURE_50 the nuggle      237       237 |
| CREATURE_51 the nuggle      247       176 |
| CREATURE_52 the nuggle      206       158 |
| CREATURE_56 the bahamut     231       205 |
| CREATURE_59 the macara      220       168 |
| CREATURE_60 the bahamut     238       138 |
| CREATURE_64 the bahamut     210       180 |
| CREATURE_65 the macara      242       202 |
| CREATURE_71 the macara      200       124 |
| CREATURE_72 the ceffyl      203       175 |
| CREATURE_73 the bahamut     200       169 |
| CREATURE_75 the nuggle      232       191 |
| CREATURE_77 the macara      246       135 |
| CREATURE_78 the ceffyl      220       190 |
| CREATURE_80 the nuggle      229       187 |
| CREATURE_81 the nuggle      232       195 |
| CREATURE_88 the nuggle      226       122 |
| CREATURE_89 the ceffyl      224       154 |
| CREATURE_91 the ceffyl      240       169 |
| CREATURE_92 the ceffyl      221       217 |
| CREATURE_96 the bahamut     225       144 |
| CREATURE_97 the nuggle      222       187 |
| CREATURE_99 the macara      228       136 |
| CREATURE_103 the nuggle     225       163 |
| CREATURE_104 the macara     233       135 |
| CREATURE_108 the ceffyl     231       205 |
| CREATURE_110 the macara     243       241 |
| CREATURE_114 the bahamut    240       241 |
| CREATURE_115 the ceffyl     246       130 |
| CREATURE_116 the macara     236       249 |
| CREATURE_123 the macara     212       228 |
+-------------------------------------------+

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: 3

Menu:
1. Create an Army from user input
2. Quit
Input: 2

C:\Users\Matteo\source\repos\Lab 7 DMA\x64\Debug\Lab 7 DMA.exe (process 12656) exited with code 0.
Press any key to close this window . . .


-------
TEST 2, trying to make a list that is too large:
Menu:
1. Create an Army from user input
2. Quit
Input: 1
Input name of your Army: gaming
Input the size of your Array: 111111111111111111111111111111111111111111111111111111111111111111111111111111

allocation failed, you most likely input an invalid number
C:\Users\Matteo\source\repos\Lab 7 DMA\x64\Debug\Lab 7 DMA.exe (process 14240) exited with code 1.
Press any key to close this window . . .


-------
TEST 3, letter input for list size:
Menu:
1. Create an Army from user input
2. Quit
Input: 1
Input name of your Army: 12
Input the size of your Array: a

invalid argument, you most likely input something that isnt an integer or 0
C:\Users\Matteo\source\repos\Lab 7 DMA\x64\Debug\Lab 7 DMA.exe (process 19144) exited with code 1.
Press any key to close this window . . .


-------
TEST 4, negative number sized array:
Menu:
1. Create an Army from user input
2. Quit
Input: 1
Input name of your Army: aaaa
Input the size of your Array: -100

allocation failed, you most likely input an invalid number
C:\Users\Matteo\source\repos\Lab 7 DMA\x64\Debug\Lab 7 DMA.exe (process 1588) exited with code 1.
Press any key to close this window . . .


TEST 5, Inputting an invalid input for all options after creating an army:

Menu:
1. Create an Army from user input
2. Quit
Input: no
Invalid choice, try again

Menu:
1. Create an Army from user input
2. Quit
Input: a
Invalid choice, try again

Menu:
1. Create an Army from user input
2. Quit
Input: 1
Input name of your Army: amongus
Input the size of your Array: 10
Printing army of amongus...
| Creature                 Health  Strength |
+-------------------------------------------+
| CREATURE_1 the ceffyl       166       247 |
| CREATURE_2 the macara       124       163 |
| CREATURE_3 the nuggle       227       134 |
| CREATURE_4 the macara       231       192 |
| CREATURE_5 the ceffyl       125       179 |
| CREATURE_6 the bahamut      141       233 |
| CREATURE_7 the bahamut      154       185 |
| CREATURE_8 the macara       142       223 |
| CREATURE_9 the macara       249       188 |
| CREATURE_10 the macara      234       188 |
+-------------------------------------------+

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: gaming
Invalid choice, try again

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: 12
Invalid choice, try again

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: 1

1. Name
2. Type
3. Health
4. Strength
5. Back
Input: yes
Invalid choice, try again

1. Name
2. Type
3. Health
4. Strength
5. Back
Input: 09
Invalid choice, try again

1. Name
2. Type
3. Health
4. Strength
5. Back
Input: 5

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: 2

		Enter minimum and maximum health:
Minimum Health: -10
Invalid input, must be larger than 0
Minimum Health: 200
Maximum health: -10
Invalid input, must be larger than minimum health
Minimum Health: 0
Invalid input, must be larger than minimum health
Minimum Health: 199
Invalid input, must be larger than minimum health
Minimum Health: 200
Printing sorted army of amongus...
| Creature                 Health  Strength |
+-------------------------------------------+
+-------------------------------------------+
None Found!

1. Sort creatures by any field
2. Filter creatures by health range (inclusive)
3. Back to menu (This will delete your current Army!)
Input: 3

Menu:
1. Create an Army from user input
2. Quit
Input: 2

C:\Users\Matteo\source\repos\Lab 7 DMA\x64\Debug\Lab 7 DMA.exe (process 4124) exited with code 0.
Press any key to close this window . . .
*/
