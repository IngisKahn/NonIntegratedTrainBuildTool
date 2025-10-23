export module Railroad:NorfolkSouthern;

import :Base;

using namespace std;


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

export class NorfolkSouthern : public Railroad
{
	bool isIntermodal { false };

	public:
	virtual constexpr string Name() const override {	return "Norfolk Southern"; }
	virtual void DisplayLogo() const override
	{
		cout << R"(
⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⢀⣀⡀⢀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⠀⠀⢀⣀⣀⣀⣀⣀⣀⣀⣀⣀
⠀⠀⠀⠀⠀⠀⠀⠿⠻⠟⠿⠻⠟⠿⠻⠟⠿⠻⠟⠿⠻⠟⠿⠻⠟⠿⠻⠟⠋⠉⠉⠈⠉⠉⠀⠀⠀⠀⠀⠰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣧⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶
 ⠀⠀⠀⠀⠀⢀⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⡶⠶⠦⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠛⠛⠛⣿⣿⣿⣿⣿⣿
 ⠀⠀⠀⠀⠀⣀⣀⣁⣈⣀⣁⣈⣀⣁⣈⣀⣁⣈⣀⣁⣈⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣤⣤⣌⣉⠉⠉
 ⠀⠀⠀⠀⠐⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠻⠛⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⠋⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡄
 ⠀⠀⠀⢀⣾⣷⣿⣾⣷⣿⣾⣷⣿⣾⣷⣿⣾⣷⣿⠾⠓⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣀⡀⠀⠀⠀⠀⠀⠈⢿⣿⡏⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣤⣤⣤⣬⠉⠉⠉⠉⢙⣿⣿⣿⣿⣿⣿⡇
 ⠀⠀⠀⣠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣷⣦⣄⡀⠀⠀⣰⡟⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣿⣿⣿⣿⣿⣿⡿ 
⠀⠀⠐⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠚⠛⠛⠛⠛⠛⠛⠓⠒⠚⠛⠃⠀⠀⠀⠀⠈⠛⠛⠛⠛⠛⠛⠃⠀⠙⠻⠿⠿⠿⠿⣿⣿⣿⣿⡿⠿⠿⠿⠛⠉⠀⠀
 ⠀⠀⡀⠀⠀⠀ ⠀⠀⣀⡀⠀⠀⢀⠀⡀⠀⠀⢀⠀⡀⠀  ⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀ ⠀⢀⠀⠀⠀⠀ ⠀⢀⣀⡀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
 ⠀⣿⢿⡆⣼⡇⣴⠏⠉⢹⡇⣸⣏⣉⡿⠇⣼⣏⣉⢉⣾⠋⠉⣿⡇⣾⠃⠀⢠⣿⣤⡞⠉⠀⠀⠀⠀⣾⣯⣍⣛⠃⣴⠋⠉⣻⡇⣼⠇⠀⣸⠇⠉⣻⠏⠉⣼⣇⣀⣸⠇⣸⣏⣉⠉⣸⣏⣉⡿⠃⣾⢿⣇⣸⡏⠀
 ⠼⠇⠘⠿⠿⠐⢿⣤⡤⠟⠡⠿⠁⠸⠟⠰⠏⠀⠀⠸⢷⣤⠴⠛⠰⠿⠤⠄⠾⠃⠹⠷⠀⠀⠀⠀⠰⣦⣤⡽⠟⠘⢿⣤⡴⠟⠁⠿⣤⡴⠏⠀⢠⡟⠀⢰⡟⠀⢠⡿⢠⣿⣥⡤⢠⡿⠉⢹⡇⢸⠇⠘⣿⡿⠀⠀⠀⠀


)";
	}

	virtual bool ValidateTrainSymbol(string_view symbol) override
	{
		if (symbol.empty() || !isdigit(symbol[0]))
			return false;
		isIntermodal = symbol[0] == '2';
		return true;
	}

	virtual constexpr string SymbolHelp() const override
	{
		return "Should start with a digit (intermodal starts with '2')";
	}
};