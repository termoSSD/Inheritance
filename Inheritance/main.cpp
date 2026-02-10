#include <iostream>
#include <string>

using namespace std;

class ECM
{
private:
	string CPUmodel;
	int RAMsizeGB;
	int storageSizeGB;
public:

};

class server : public ECM
{
private:
	int rackUnitHeight;
	int maxClient;
	bool hasRedundantPSU;
	string remoteIP;
public:
};

class laptop : public ECM
{
private:
	string model;
	double batteryCapacityWh;
	int batteryHealth;
	double weightKg;
	double screenSizeInches;
public:
};

int main()
{
}