export module Railroad:CSXT;

import :Base;
using namespace std;

export class CSXT : public Railroad
{
public:
	virtual string Name() const override { return "CSX Transportation"; }
	virtual void DisplayLogo() const override
	{
		std::cout << "⠀⠀⠀⢀⣤⣶⣾⣿⣿⣿⣷⣶⣤⣶⣶⣶⡆⠀⢀⣴⣾⣿⣿⣷⣦⣶⣶⣶⡆⢰⣶⣶⣶⣶⣶⣶⣶⢰⣶⣶⣶⣶⣶⣶⣶\n";
		std::cout << "⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢠⣿⣿⣿⣿⡿⠿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿\n";
		std::cout << "⢠⣿⣿⣿⣿⡿⠋⠉⠁⠉⠉⠻⣿⣿⣿⣿⡇⢸⣿⣿⣿⣯⠀⠀⠸⣿⣿⣿⡇⠀ ⠙⣿⣿⣿⣷⣄⢀⣾⣿⣿⣿⠟⠁\n";
		std::cout << "⣾⣿⣿⣿⡏⠀⠀⠀ ⠀⠀⠀ ⠀⠀⠀⠀⠘⢿⣿⣿⣿⣷⣦⣤⣀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⡿⠋\n";
		std::cout << "⣿⣿⣿⣿⡇⠀⠀  ⠀⠀⠀  ⠀⠀⠀⠀⠀⠘⠻⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀ ⣻⣿⣿⣿⣿⣿⠁\n";
		std::cout << "⢿⣿⣿⣿⣧⠀ ⠀   ⠀ ⣀⣀⣀⣀⣀⣀⣀⣀⠙⠛⠿⣿⣿⣿⣿⣧⠀⠀ ⢀⣴⣿⣿⣿⣿⣿⣿⣷⣄\n";
		std::cout << "⠘⣿⣿⣿⣿⣷⣄⣀⠀⢀⣀⣴⣿⣿⣿⣿⠏⣿⣿⣿⣿⡄⠀⠀⢸⣿⣿⣿⣿  ⣠⣿⣿⣿⣿⠋⠘⢿⣿⣿⣿⣦⡀\n";
		std::cout << "⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿\n";
		std::cout << "⠀⠀⠀⠈⠛⠿⢿⣿⣿⣿⣿⡿⠟⠋⠀⠀⠀⠿⠿⠿⠟⠿⣿⣿⣿⡿⠟⠋⠸⠿⠿⠿⠿⠿⠿⠿⠿⠸⠿⠿⠿⠿⠿⠿⠿\n\n";
	}
};