#include <iostream>
#include <string>

using namespace std;

class ECM
{
protected:
	string CPUmodel;
	int RAMsizeGB;
	int storageSizeGB;
public:
	ECM(string cpu = "Unknown", int ram = 0, int storage = 0) : CPUmodel(cpu), RAMsizeGB(ram), storageSizeGB(storage) {}

	virtual void showInfo()
	{
		cout << "CPU: " << CPUmodel << endl;
		cout << "RAM: " << RAMsizeGB << endl;
		cout << "Storage: " << storageSizeGB << endl;
	}
};

class server : public ECM
{
private:
	int rackUnitHeight;
	int maxClient;
	bool hasRedundantPSU;
	string remoteIP;
public:
	server(string cpu = "Unknown", int ram = 0, int storage = 0, int height = 0, int maxCl = 0, bool psu = false, string ip = "0.0.0.0")
		: ECM(cpu, ram, storage), rackUnitHeight(height), maxClient(maxCl), hasRedundantPSU(psu), remoteIP(ip) {
	}

	void showInfo()
	{
		cout << "--- Server Info ---" << endl;
		ECM::showInfo();
		cout << "Rack Height: " << rackUnitHeight << endl;
		cout << "Max Clients: " << maxClient << endl;
		cout << "Redundant PSU: " << hasRedundantPSU << endl;
		cout << "Remote IP: " << remoteIP << endl;
		cout << "-------------------------";
	}
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
	laptop(string cpu = "Unknown", int ram = 0, int storage = 0, string mdl = "NoName", double batteryCap = 0.0, int batteryHP = 0, double weight = 0, double screen = 0)
		: ECM(cpu, ram, storage), model(mdl), batteryCapacityWh(batteryCap), batteryHealth(batteryHP), weightKg(weight), screenSizeInches(screen) {
	}

	void showInfo()
	{
		cout << "--- Laptop Info ---" << endl;
		ECM::showInfo();
		cout << "Model: " << model;
		cout << "Battery Capacity(wh): " << batteryCapacityWh << endl;
		cout << "Battery Health: " << batteryHealth << "%" << endl;
		cout << "Weight: " << weightKg << endl;
		cout << "Screen Size: " << screenSizeInches << endl;
		cout << "-------------------------";
	}
};

int main()
{
	ECM newMachine("INTEL", 1024, 1024);
	server newServer("Intel Xeon", 64, 4000, 2, 500, true, "192.168.1.10");
	laptop newLaptop("Intel Core i7", 16, 1000, "MacBook Pro", 99.6, 95, 2.1, 16.2);


	newMachine.showInfo();
	cout << endl;
	newServer.showInfo();
	cout << endl;
	newLaptop.showInfo();
}