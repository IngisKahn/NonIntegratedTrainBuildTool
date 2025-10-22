import std;
import Railroad;

using namespace std;

static int32_t ShowMenu(const string prompt, vector<string> options)
{
	cout << prompt << endl;
	for (size_t i = 0; i < options.size(); ++i)
		cout << i + 1 << ". " << options.at(i) << endl;
	int choice = 0;
	while (true)
	{
		cout << "Enter your choice (1-" << options.size() << "): ";
		cin >> choice;
		if (cin.fail() || choice < 1 || choice >(int)options.size())
		{
			cin.clear(); // clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << "Invalid choice. Please try again." << endl;
		}
		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard any extra input
			break; // valid choice
		}
	}
	return choice;
}

static const vector<shared_ptr<Railroad>> railroads = {
	static_cast<shared_ptr<Railroad>>(make_shared<BNSF>()),
	static_cast<shared_ptr<Railroad>>(make_shared<CanadianNational>()),
	static_cast<shared_ptr<Railroad>>(make_shared<CPCK>()),
	static_cast<shared_ptr<Railroad>>(make_shared<CSXT>()),
	static_cast<shared_ptr<Railroad>>(make_shared<NorfolkSouthern>()),
	static_cast<shared_ptr<Railroad>>(make_shared<UnionPacific>()),
};

int main()
{
	while (true) 
	{
		/*std::string yardmapnumber;    ***For future use
		std::cout << "Enter your yard number: ";
		"\n";
		std::getline(cin, yardmapnumber);*/

		//bool RRENDLOOP = false;

		//while (!RRENDLOOP) {
		cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣠⣾⣿⣿⣋⣭⣤⣤⣤⣤⣤⣤⣤⣸⣿⣿⢿⣿⣷⡄⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠀⠀⢀⣀⣀⣀⡀⠀⣄⣀⣀⣀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⢀⣠⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀
⠀⠀⠀⠀⠀⢰⣿⡿⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣻⣿⣿⡟⠄⢹⣿⣿⡄⠀⠀⠀⢰⣿⣿⣿⣧⠀⠀⠀⠀⣾⣿⣿⡿⠀⢠⣿⣿⣿⠇⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀
⠀⠀⠀⠀⢠⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⠁⠀⣼⣿⡇⠁⠀  ⣾⣿⣿⣿⣿⡆⠀⠀⢰⣿⣿⣿⠃⠀⣾⣿⣿⡟⠀⠚⠛⠋⢛⣿⣿⣿⡟⠛⠛⠛⠃⢸⣿⣿⣿⠉⠉⠉⢹⣿⣿⣿⡇⠘⠋⠛⠛⣿⣿⣿⡟⠋⠛⠛⠃⠀
⠀⠀⠀⢀⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⡏⠀⠀⣿⣿⠁⠀⠀ ⢰⣿⣿⣿⣿⣿⣷⠀⠄⣾⣿⣿⡟⠀⢰⣿⣿⣿⠃⠀⠀⠀⠀⣼⣿⣿⡿⠀⠀⠀⠀⢀⣿⣿⣿⡏⠀⠀⣀⣼⣿⣿⣿⠃⠀⠀⠀⢸⣿⣿⣿⠁⠀⠀⠀⠀⠀
⠀⠀⠀⣾⣿⣧⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣼⣿⣿⡿⠀⠀⢸⣿⡟⠀⠀ ⢀⣿⣿⣿⣏⣿⣿⣿⡆⢸⣿⣿⣿⠁⠀⣾⣿⣿⡏⠀⠀⠀⠀⢠⣿⣿⣿⠃⠀⠀⠀⠀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣟⡉⠁⠀⠀⠀⢀⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀
⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⣿⣿⠁⠀⠀⠀⣸⣿⣿⣿⠄⠸⣿⣿⣿⣿⣿⣿⡏⠀⢸⣿⣿⣿⠁⠀⠀⠀⠀⣾⣿⣿⡟⠀⠀⠀⠀⢠⣿⣿⣿⡏⠉⠉⠉⢻⣿⣿⣿⡄⠀⠀⠀⣸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣿⣿⢛⠛⣿⣿⣿⣿⣿⣿⡿⡛⢻⣿⣿⣿⡿⠀⠀⢰⣿⡟⠀⠀⠀⢀⣿⣿⣿⠇⠀⠀⢿⣿⣿⣿⣿⣿⠀⠀⣿⣿⣿⡏⠀⠀⠀⠀⢰⣿⣿⣿⠁⠀⠀⠀⠀⣼⣿⣿⡿⠀⠀⠀⢀⣼⣿⣿⣿⠁⠀⠀⢀⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣿⣿⣜⣂⣼⣿⣿⣿⣿⣿⣇⣓⣼⣿⣿⣿⠃⢀⠀⣼⣿⠇⠀⠀⠀⣸⣿⣿⡿⠀⠀⠀⠘⣿⣿⣿⣿⠇⠀⣸⣿⣿⣿⠀⠀⠀⠀⠀⣿⣿⣿⡏⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠁⠀⠀⠀⣼⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣾⣿⡿⠀⠀⠀⠀⠛⠛⠛⠃⠀⠀⠀⠀⠛⠛⠛⠛⠀⠀⠛⠛⠛⠃⠀⠀⠀⠀⠘⠛⠛⠛⠁⠀⠀⠀⠀⠚⠛⠛⠛⠛⠛⠛⠛⠛⠋⠁⠀⠀⠀⠀⠐⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠈⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣛⣿⣿⣿⣿⣿⣿⣿⣶⣦⣤⣤⣤⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀NON-INTEGRATED TRAIN BUILD TOOL⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⠛⠛⠋⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀by Hvxlo v1.02⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ 
⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀          

)";

		vector<string> railroadNames;
		for (const auto& rr : railroads)
			railroadNames.push_back(rr->Name());

		auto road = ShowMenu("Enter the Class I railroad you're operating on: ", railroadNames);

		cout << "\033[2J\033[1;1H";

		auto selectedRailroad = railroads[road - 1];

		selectedRailroad->DisplayLogo();

		string trainsymbol;
		auto symbolHelp = selectedRailroad->SymbolHelp();

		while (true)
		{
			cout << "Enter the train symbol you are working on: ";

			if (!symbolHelp.empty())
				cout << endl << symbolHelp << endl << endl;

			getline(cin, trainsymbol);

			if (!trainsymbol.empty())
				break;

			std::cout << "\nYou haven't entered anything or you have not entered an accurate symbol...";
			std::cout << "\n\nPlease press any key to start over...";

			cin.get();

			std::cout << "\033[2J\033[1;1H";
		}

	/*All Road Variables*/
	bool DPU = false;
	bool MULTIDPU = false;

	std::string FOOTAGE;
	std::string TONNAGE;

	int TRAINTYPE;
	int FT;
	int TONS;
	int AUTORACKS;
	int TOTALAUTOS;
	int MAXDPDISTANCE;
	int MAXMULTIDPDISTANCE;

	/*UP Variables*/
	bool UPREGIONLOOP = false;

	std::string UPREGION;

	/*NS Variables*/
	bool AUTORACKS39 = false;
	bool AUTORACKS100 = false;

	int R3N50;
	int R3N75;

	int R4N33T;
	int R4N25FT;


	/*
	  Footage
	*/

	/*UP*/
	//if (RRCHOICE == "UP") 
	//{
	//	while (UPREGIONLOOP == false) {
	//		std::cout << "UP 'East' specifies train makeup east of Picacho AZ, Cheyenne WY and Denver CO\n";
	//		std::cout << "UP 'West' specifies train makeup west of these locations\n";
	//		std::cout << "Please input your operational region: ";
	//
	//		std::getline(std::cin, UPREGION);
	//
	//		if (!RRCHOICE.empty()) {
	//			//std::transform(UPREGION.begin(), UPREGION.end(), UPREGION.begin(), ::toupper);
	//			UPREGIONLOOP = true;
	//		}
	//		else {
	//			std::cout << "Invalid entry - press any key to try again...";
	//			cin.get();
	//		}
	//	}
	//}

	/*ALL ROADS*/
	cout << "Total train length: ";
	if (std::getline(std::cin, FOOTAGE)) {
		std::istringstream iss(FOOTAGE);
		if (iss >> FT) {
			FT = std::stoi(FOOTAGE);
		}
		else {
			std::cerr << "Error: Invalid number entered for footage";
		}
	}
	else {
		std::cerr << "Error: Invalid number entered for tonnage" << std::endl;
	}


	/*
	  Tonnage
	*/
	std::cout << "Total train tonnage: ";
	if (std::getline(std::cin, TONNAGE)) {
		std::istringstream iss(TONNAGE);
		if (iss >> TONS) {
			TONS = std::stoi(TONNAGE);
		}
		else {
			std::cerr << "Error: Invalid number entered for tonnage" << std::endl;
		}
	}
	else {
		std::cerr << "Error: Invalid number entered for tonnage" << std::endl;
	}


	/*
	NS REGION
	  Rule #1: Calculations for determining if train requires distributed power
	  Rule #2: DPU may only be 8500ft from the lead locomotive consist
	  Rule #3: Calculations for displaying the range in which distributed power should be positioned

	UP REGION
		*Calculations for determining if train requires distributed power
		*Calculations for displaying the range in which distributed power should be positioned
	*/
	/*UP*/
	//if (RRCHOICE == "UP" && UPREGION == "EAST") {
	//	if (FT > 15000) {
	//		MULTIDPU = true;
	//		MAXDPDISTANCE = 8500;
	//	}
	//	else if (FT >= 10000) {
	//		DPU = true;
	//		MAXDPDISTANCE = 10000;
	//	}
	//}
	//else if (RRCHOICE == "UP" && UPREGION == "WEST") {
	//	if (FT > 15000) {
	//		MULTIDPU = true;
	//		MAXDPDISTANCE = 6000;
	//	}
	//	else if (FT >= 12000 && TONS > 14000) {
	//		DPU = true;
	//		MAXDPDISTANCE = 8500;
	//	}
	//}

	/*NS*/
	//if (RRCHOICE == "NS") {
	//	R3N50 = FT * 0.50;
	//	R3N75 = FT * 0.75;
	//
	//	if (R3N50 >= 8500) {
	//		R3N50 = 8500;
	//	}
	//
	//	if (R3N75 >= 8500) {
	//		R3N75 = 8500;
	//	}
	//
	//	if (INTERMODAL && FT >= 12000) {
	//		DPU = true;
	//	}
	//	else if (!INTERMODAL && FT >= 10000) {
	//		DPU = true;
	//	}
	//}

	/*
	  Rule #5: Weight behind mid DPU must not exceed 75% of the total capacity of the mid-DPU when there is no rear end power
	*/


	/*
	  Rule #6: Checks to see if train has exceeded max EOCC cars
		Non-DPU = 70 MAX (and 40MPH restriction if more than 39 not on rear end of train)
		DPU = 100 MAX
	*/

	std::cout << "\nHow many total autoracks are in the train? ";
	std::cin >> TOTALAUTOS;
	//
	//if (RRCHOICE == "UP" && TOTALAUTOS > 60) {
	//	std::cout << "\nNOTE: Union Pacific designates trains carrying 60 or more autoracks to be limited to 80 total cars";
	//}
	//if (RRCHOICE == "NS") {
	//	if (TOTALAUTOS > 39) {
	//		std::cout << "\nHow many autoracks are not positioned on the rear end of your train? ";
	//		std::cin >> AUTORACKS;
	//
	//		if (AUTORACKS > 70) {
	//			DPU = true;
	//		}
	//
	//		if (DPU) {
	//			if (AUTORACKS > 100) {
	//				AUTORACKS100 = true;
	//			}
	//		}
	//		else if (!DPU) {
	//			if (AUTORACKS > 39) {
	//				AUTORACKS39 = true;
	//			}
	//		}
	//	}
	//}


	/*
	  Rule #8: Tonnage behind rear-most locomotive consist must be less than the coupler force limit
	  **Create library of trains with coupler force limits

	  Rule #9: Total tonnage of train must not exceed the combined tonnage rating of the locomotives in the train
	  **Create library of trains with tonnage ratings
	*/


	/*
	  Rule #10: Check TIH/PIH segment allowance
	*/

	/*
	  Displays entered tonnage and footage and summarizes rules calculations
	*/

	std::cout << "\n\n\n" << trainsymbol << std::endl;
	std::cout << "Train length: " << FT << "ft" << std::endl;
	std::cout << "Train weight: " << TONS << "T" << std::endl;

	/*
	  Checks all rules to see if distributed power is required and displays positioning requirements and displays rule results
	  Rule #7: Reminder about blocks of 30 or more empties not on the rear of the train
	*/
	//
	//if (RRCHOICE == "NS") {
	//	if (AUTORACKS39) {
	//		std::cout << "Speed Limit: " << "40mph" << std::endl;
	//	}
	//	else {
	//		std::cout << "Speed Limit: " << "N/A" << std::endl;
	//	}
	//
	//	if (DPU) {
	//		std::cout << "\n-- Train requires distributed power" << std::endl;
	//
	//		if (FT >= 8500) {
	//			std::cout << "-- DPU must be positioned between " << R3N50 << "ft " << "and " << R3N75 << "ft" << std::endl;
	//		}
	//		else {
	//			std::cout << "-- DPU must be positioned between " << R3N50 << "ft " << "and the rear end of the train" << std::endl;
	//		}
	//	}
	//}
	//
	//else if (RRCHOICE == "UP") {
	//	if (DPU && RRCHOICE == "UP") {
	//		std::cout << "\n-- Train requires distributed power\n\n";
	//		std::cout << "DPU may be positioned at most " << MAXDPDISTANCE << "ft away from the lead consist" << std::endl;
	//	}
	//
	//	if (MULTIDPU && RRCHOICE == "UP") {
	//		std::cout << "\n-- Train requires mid and rear DPU consists" << std::endl;
	//		std::cout << "Mid DPU may be positioned at most " << MAXDPDISTANCE << "ft away from the lead consist" << std::endl;
	//		std::cout << "Rear DPU may be positioned at most " << MAXDPDISTANCE << "ft away from the mid consist" << std::endl;
	//	}
	//
	//	else {
	//		std::cout << "\n-- Train does not require distributed power" << std::endl;
	//	}
	//}
	//
	//
	//if (RRCHOICE == "NS") {
	//	if (TONS > 8000) {
	//		R4N33T = 0.33 * TONS;
	//		R4N25FT = 0.25 * FT;
	//
	//		cout << "\n-- Train is greater than 8000T so may not have more than " << R4N33T << " tons in the last " << R4N25FT << " ft of train" << std::endl;
	//	}
	//
	//	if (TOTALAUTOS > 70) {
	//		if (AUTORACKS100 || DPU == true) {
	//			std::cout << "-- A maximum of 100 autoracks are allowed on a DPU train" << std::endl;
	//		}
	//		else {
	//			std::cout << "-- A maximum of 70 autoracks are allowed on a non-DPU train" << std::endl;
	//		}
	//	}
	//
	//
	//	std::cout << "\nREMINDER: 30 or more empties not positioned on the rear end of the train should be rearranged to be on the rear end of the train \n\n";
	//}

	std::cout << "\n\n\nPress any key and enter to run again or type 'exit' to finish...\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//std::getline(cin, userInputProceed);




	/* NS OB-12 Checks
		--#1 If train is 10k ft or more, DPU is required
		--#2 Distance between lead power and consecutive DPU power must be less than 8500ft
		--#3 If an origin train, DPU must be positioned within 50-75% of train length ; if work train, 35-100%
		--#4 If train is > 8000T, no more than 33.0% of tonnage can be in rear 25.0% of length
		--#5 Weight behind mid DPU must be less than 75% of the total capacity of the locomotives in the mid-DPU when there is no rear end power
		--#6 How many EOCC cars? (autoracks in FYM) DPU = 100 max / Non-dpu = 70 max
		--#7 No blocks of 30 or more empties not on rear
		--#8 Weight behind rear-most consist must be less than coupler force limit
		--#9 Total tonnage of train must not exceed the combined tonnage rating of the locomotives
		--#10 TIH/PIH cars traveling a non TIH/PIH route segment
	*/

	std::cout << "\033[2J\033[1;1H";

	//if (userInputProceed == "exit")
	break;
}

return 0;

}