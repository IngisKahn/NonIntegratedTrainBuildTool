export module Railroad:Base;

import std;
using namespace std;

export class Region
{	
public:
	
};

export struct TrainData
{
	string Symbol;
	uint32_t LengthFeet{ 0 };
	uint32_t WeightTons{ 0 };
	bool IsIntermodal{ false };
	bool IsDistriputedPower{ false };
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