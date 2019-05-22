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
    Player(char ID[12], char name[30], char age[2], char position[20], char country[20], char league[30], char club[50], char salary[30]) {
        this.ID = ID;
        this.name = name;
        this.age = age;
        this.position = position;
        this.country = country;
        this.league = league;
        this.club = club;
        this.salary = salary;
    }

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

    }
};

class Database {
    private:
    std::vector<Player> players;
    std::fstream fp;

    public:
    void addPlayer(Player player) {
        players.push_back(player);
    }

    void writePlayers() {
        int count;
        fp.open("Players.DAT", std::ios::out | std::ios::app);
        for (Player player : players) {
            fp.write((char*)&player, sizeof(Player));
        }
        fp.close();
    }
}