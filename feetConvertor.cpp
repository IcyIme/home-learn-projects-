#include<iostream>

/*
Coverter Meter To feet and vice versa
Peter Odrobiòák DATE: 29.6.2022 COMPLETE TIME: 9:20
*/

using namespace std;

const double Con_feet = 3.2808399, Con_meters = 0.3048; //const vars usign to later calcution

string MainMenu() { //returnin string as main menu
	string menu = "Converter meters to feet \n"
		"(1) meter to feet\n"
		"(2) feet to meter\n"
		"(3) Stop Program\n";
	return menu;
}

double convertMeterToFeet(double inputMeter) { //This code sheet can convert Meter to Feet
	return inputMeter * Con_feet;
}

double convertFeetToMeter(double inputFeet) { //This code sheet can convert 
	return inputFeet * Con_meters;
}

int main() {
	bool loop = true;
	while (loop) { //Program Starts here
		double meter = 0, feet = 0;
		int selector;
		cout << MainMenu(); //Prints main menu using by function
		cout << ">>> "; cin >> selector; //Get user input
		switch (selector)//Verify user input and start action by user choice
		{
		case 1: 
			cout << "enter meter: "; cin >> meter; cout << meter << " meter ==> " << convertMeterToFeet(meter) << " feet";
			cout << "\n-------------------------------------\n";
			break;
		case 2: 
			cout << "enter feet: "; cin >> feet; cout << feet << " feet ==> " << convertFeetToMeter(feet) << " meter";
			cout << "\n-------------------------------------\n";
			break;
		case 3:
			loop = false;
			break;
		default: cout << "This options is not exits anymore";break;
		}
		cout << "end";
	}

	return 0;
}
