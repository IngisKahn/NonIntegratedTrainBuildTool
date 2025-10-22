export module Railroad:Base;

import std;
using namespace std;

export class Region
{
	
public:
};

export class Railroad 
{
public:
	virtual constexpr string Name() const = 0;
	virtual void DisplayLogo() const = 0;
	virtual bool ValidateTrainSymbol(string_view symbol) { return true; }
	virtual constexpr string SymbolHelp() const { return ""; }
	virtual vector<Region> Regions() const { return {}; }
};