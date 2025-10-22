export module Railroad:CanadianNational;

import :Base;
using namespace std;

export class CanadianNational : public Railroad
{
	public:
	virtual constexpr string Name() const override { return "Canadian National Railway"; }
	virtual void DisplayLogo() const override
	{
		cout << R"(
⠀⠀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀ ⠀⣠⣴⣶⣿⣷⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⢸⣿⣿⣿
⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀ ⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⢸⣿⣿⣿
⣿⣿⣿⣿⠏⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁  ⢰⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣶⡄⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⢸⣿⣿⣿
⣿⣿⣿⣿                   ⢸⣿⣿⣿⡇⠀⠀⠀⠹⢿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀ ⠀⢸⣿⣿⣿
⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀ ⢸⣿⣿⣿⡇⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀ ⠀⢸⣿⣿⣿
⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀ ⢸⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣷⣄⠀⠀⠀⠀ ⠀⢸⣿⣿⣿
⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀        ⢸⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣷⣄⠀⠀ ⠀⢸⣿⣿⣿
⣿⣿⣿⣿⣄⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣼⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠙⢿⣿⣿⣿⣦⣀⣀⣾⣿⣿⡏
⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠻⣿⣿⣿⣿⣿⣿⣿⡿⠀
⠀⠙⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠙⠿⣿⣿⡿⠋⠀⠀

)";
	}
};