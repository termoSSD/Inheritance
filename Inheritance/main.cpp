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
    ECM(string cpu = "Unknown", int ram = 0, int storage = 0)
        : CPUmodel(cpu), RAMsizeGB(ram), storageSizeGB(storage) {
    }

    // Метод 1: Виведення інформації
    virtual void showInfo()
    {
        cout << "[ECM Info] CPU: " << CPUmodel
            << " | RAM: " << RAMsizeGB << "GB"
            << " | Storage: " << storageSizeGB << "GB" << endl;
    }

    // Метод 2: Апгрейд оперативної пам'яті
    void upgradeRAM(int additionalRAM)
    {
        RAMsizeGB += additionalRAM;
        cout << "RAM upgraded by " << additionalRAM << "GB. Total: " << RAMsizeGB << "GB." << endl;
    }

    // Метод 3: Заміна накопичувача
    void replaceStorage(int newSize)
    {
        storageSizeGB = newSize;
        cout << "New size: " << storageSizeGB << "GB." << endl;
    }

    // Метод 4: Симуляція запуску
    void powerOn()
    {
        cout << CPUmodel << " is starting up..." << " OK." << endl;
    }
};

// --- ПОХІДНИЙ КЛАС ---
class Laptop : public ECM
{
private:
    double batteryLevel;
    double weightKg;

public:
    Laptop(string cpu, int ram, int storage, double battery, double weight)
        : ECM(cpu, ram, storage), batteryLevel(battery), weightKg(weight) {
    }

    // Перевизначений метод (для красивого виводу, не рахується як "новий")
    void showInfo() override
    {
        cout << "--- Laptop Details ---" << endl;
        ECM::showInfo(); // Виклик методу батька
        cout << "[Portable Info] Battery: " << batteryLevel << "% | Weight: " << weightKg << "kg" << endl;
        cout << "----------------------" << endl;
    }

    // Новий Метод 1: Зарядка
    void chargeBattery(double amount)
    {
        batteryLevel += amount;
        if (batteryLevel > 100) batteryLevel = 100;
        cout << "> Laptop: Charging... Battery level is now " << batteryLevel << "%." << endl;
    }

    // Новий Метод 2: Перевірка мобільності
    void checkPortability()
    {
        if (weightKg < 2.0)
            cout << "> Laptop: This is a lightweight ultrabook (easy to carry)." << endl;
        else
            cout << "> Laptop: This is a heavy workstation." << endl;
    }
};

int main()
{
    cout << "=== DEMONSTRATION OF BASE CLASS (ECM) ===" << endl;
    // Створення об'єкта базового класу
    ECM myDesktop("Intel Core i5", 8, 512);

    // Демонстрація 4 методів базового класу
    myDesktop.powerOn();              // 1. Запуск
    myDesktop.showInfo();             // 2. Інфо
    myDesktop.upgradeRAM(8);          // 3. Апгрейд RAM
    myDesktop.replaceStorage(1024);   // 4. Заміна диска
    myDesktop.showInfo();             // Перевірка змін

    cout << endl << "=== DEMONSTRATION OF DERIVED CLASS (Laptop) ===" << endl;
    // Створення об'єкта похідного класу
    Laptop myLaptop("Apple M2", 16, 512, 45.5, 1.24);

    // Демонстрація успадкованих методів
    myLaptop.powerOn();

    // Демонстрація перевизначеного showInfo
    myLaptop.showInfo();

    // Демонстрація 2 нових методів похідного класу:
    myLaptop.checkPortability();      // 1. Перевірка ваги
    myLaptop.chargeBattery(30.0);     // 2. Зарядка

    return 0;
}