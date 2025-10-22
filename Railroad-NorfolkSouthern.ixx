export module Railroad:NorfolkSouthern;

import :Base;

using namespace std;

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