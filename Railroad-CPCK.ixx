export module Railroad:CPCK;

import :Base;
using namespace std;

export class CPCK : public Railroad
{
public:
	virtual constexpr string Name() const override { return "Canadian Pacific Kansas City"; }
	virtual void DisplayLogo() const override
	{
		cout << R"(
⢀⣤⣤⣤⣤⣤⣤⣤⣤⣤⡀⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⡀⣤⣤⣤⡄⠀⢀⣤⣤⣤⣤⡄⣠⣤⣤⣤⣤⣤⣤⣤⣤⣀
⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣇⣴⣿⣿⣿⣿⠟⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⠉⠉⠉⠿⠟⠛⠛⣿⣿⣿⣏⣉⣉⣉⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⢸⣿⣿⣿⠉⠉⠉⠹⠿⠛⠛
⣿⣿⣿⣿⣀⣀⣀⣶⣶⣤⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⢸⣿⣿⣿⣀⣀⣀⣰⣶⣦⣤
⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⡟⠛⠛⠛⠛⠛⠉⠀⣿⣿⣿⡿⠋⢿⣿⣿⣿⣷⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠈⠛⠛⠛⠛⠛⠛⠛⠛⠛⠁⠛⠛⠛⠃⠀⠀⠀⠀ ⠀⠀⠀⠛⠛⠛⠃⠀ ⠀⠙⠛⠛⠛⠛⠙⠛⠛⠛⠛⠛⠛⠛⠛⠉

)";
	}
};