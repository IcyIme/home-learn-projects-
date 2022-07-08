#include <iostream>

int main() {
	//define data types
	const float Mercury = 0.38;
	const float Venus = 0.91;
	const float Mars = 0.38;
	const float Jupiter = 2.34;
	const float Saturn = 1.06;
	const float Uranus = 0.92;
	const float Neptune = 1.19;

	float WeightOnEarth;
	float result = 0;
	int SelectedPlanet;

	//asking and getting data from user
	std::cout << "enter weight: ";
	std::cin >> WeightOnEarth;
	std::cout << "enter planet where u want fight: ";
	std::cin >> SelectedPlanet;

	//compare data and start some code which corresponds to users choice and calcute it
	switch (SelectedPlanet)
	{
	case 1:
		result = WeightOnEarth * Mercury;
		std::cout << result;
		break;
	case 2:
		result = WeightOnEarth * Venus;
		std::cout << result;
		break;
	case 3:
		result = WeightOnEarth * Mars;
		std::cout << result;
		break;
	case 4:
		result = WeightOnEarth * Jupiter;
		std::cout << result;
		break;
	case 5:
		result = WeightOnEarth * Saturn;
		std::cout << result;
		break;
	case 6:
		result = WeightOnEarth * Uranus;
		std::cout << result;
		break;
	case 7:
		result = WeightOnEarth * Neptune;
		std::cout << result;
		break;
	default:
		std::cout << "Error";
		break;
	}

	return 0;
}
