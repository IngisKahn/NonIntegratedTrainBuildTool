export module Railroad:CSXT;

import :Base;
using namespace std;

export class CSXT : public Railroad
{
public:
	virtual constexpr string Name() const override { return "CSX Transportation"; }
	virtual void DisplayLogo() const override
	{
		cout << R"(
⠀⠀⠀⢀⣤⣶⣾⣿⣿⣿⣷⣶⣤⣶⣶⣶⡆⠀⢀⣴⣾⣿⣿⣷⣦⣶⣶⣶⡆⢰⣶⣶⣶⣶⣶⣶⣶⢰⣶⣶⣶⣶⣶⣶⣶
⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢠⣿⣿⣿⣿⡿⠿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿
⢠⣿⣿⣿⣿⡿⠋⠉⠁⠉⠉⠻⣿⣿⣿⣿⡇⢸⣿⣿⣿⣯⠀⠀⠸⣿⣿⣿⡇⠀ ⠙⣿⣿⣿⣷⣄⢀⣾⣿⣿⣿⠟⠁
⣾⣿⣿⣿⡏⠀⠀⠀ ⠀⠀⠀ ⠀⠀⠀⠀⠘⢿⣿⣿⣿⣷⣦⣤⣀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⡿⠋
⣿⣿⣿⣿⡇⠀⠀  ⠀⠀⠀  ⠀⠀⠀⠀⠀⠘⠻⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀ ⣻⣿⣿⣿⣿⣿⠁
⢿⣿⣿⣿⣧⠀ ⠀   ⠀ ⣀⣀⣀⣀⣀⣀⣀⣀⠙⠛⠿⣿⣿⣿⣿⣧⠀⠀ ⢀⣴⣿⣿⣿⣿⣿⣿⣷⣄
⠘⣿⣿⣿⣿⣷⣄⣀⠀⢀⣀⣴⣿⣿⣿⣿⠏⣿⣿⣿⣿⡄⠀⠀⢸⣿⣿⣿⣿  ⣠⣿⣿⣿⣿⠋⠘⢿⣿⣿⣿⣦⡀
⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿
⠀⠀⠀⠈⠛⠿⢿⣿⣿⣿⣿⡿⠟⠋⠀⠀⠀⠿⠿⠿⠟⠿⣿⣿⣿⡿⠟⠋⠸⠿⠿⠿⠿⠿⠿⠿⠿⠸⠿⠿⠿⠿⠿⠿⠿

)";
	}
};