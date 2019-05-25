#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

class Player{
    private:
    char ID[12];
    char name[50];
    char age[2];
    char position[20];
    char country[20];
    char league[30];
    char club[50];
    char salary[30];

    public:

    void getPlayer() {
        std::cout << "\nEnter ID: ";
        std::cin.getline(ID, 12);
        std::cout << "Enter Name: ";
        std::cin.getline(name, 50);
        std::cout << "Enter Age: ";
        std::cin.getline(age, 2);
        std::cout << "Enter Position: ";
        std::cin.getline(position, 20);
        std::cout << "Enter Country: ";
        std::cin.getline(country, 20);
        std::cout << "Enter League: ";
        std::cin.getline(league, 30);
        std::cout << "Enter Club: ";
        std::cin.getline(club, 50);
        std::cout << "Enter Salary: ";
        std::cin.getline(salary, 30);
    }

    char *getID() {
        return ID;
    }

    void showPlayer() {
        std::cout << "ID: " << ID << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Position: " << position << "\n";
        std::cout << "Country: " << country << "\n";
        std::cout << "League: " << league << "\n";
        std::cout << "Club: " << club << "\n";
        std::cout << "Salary: " << salary << "\n";
    }

    void modifyPlayer() {
        std::cout << "ID: ";
        std::cin.getline()
    }
};

class Database {
    private:
    Player player;
    std::fstream fp;

    public:

    void writePlayers() {
        int next;
        fp.open("Players.DAT", std::ios::out | std::ios::app);
        do
        {
            player.getPlayer();
            fp.write((char*)&player, sizeof(player));
            std::cout << "1 for next player, 0 to stop: " << std::endl;
            std::cin >> next;
        } while (next == 1);
        fp.close();
    }

    void modifyPlayer() {
        int found = 0;
        char n[20];

        std::cout << "Enter ID: ";
        std::cin >> n;

        fp.open("Players.DAT", std::ios::in | std::ios::out);

        while (fp.read((char*)&player, sizeof(player)))
        {
            if(player->getID().compare(n) == 0) {

            }
        }
        
    }
};