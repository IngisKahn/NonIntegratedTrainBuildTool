export module Railroad:Base;

import std;
using namespace std;

export class Railroad 
{
public:
	virtual constexpr string Name() const = 0;
	virtual void DisplayLogo() const = 0;
	virtual bool ValidateTrainSymbol(string_view symbol) { return true; }
};