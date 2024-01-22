#include "test.hpp"
#include <iostream>

void elevator_system(int max_floor = 10, int min_floor = 0, int current_floor = 0)
{
    elevator::ascenseur ascenseur(max_floor, min_floor, current_floor);
    bool exit = false;
    std::string input;

    std::cout << "Max floor : " << ascenseur.get_max_floor() << std::endl;
    std::cout << "Min floor : " << ascenseur.get_min_floor() << std::endl;
    std::cout << "Actual floor : " << ascenseur.get_current_floor() << std::endl;

    while (exit == false) {
        std::cout << "Enter up or down to move the elevator : ";
        std::cin >> input;
        if (input.find("up") != std::string::npos)
            ascenseur.go_up();
        else if (input.find("down") != std::string::npos)
            ascenseur.go_down();
        else
            std::cout << "Invalid input" << std::endl;
        std::cout << "Actual floor : " << ascenseur.get_current_floor() << std::endl;
        std::cout << "Enter 'exit' to exit or anything else to continue : ";
        std::cin >> input;
        if (input.find("exit") != std::string::npos)
            exit = true;
    }
}

void elevator_system(int max_floor, int min_floor, int current_floor, int dynamic_elevator)
{
    elevator_system(max_floor, min_floor, current_floor);
    elevator::ascenseur ascenseur(max_floor, min_floor, current_floor);
    bool exit = false;
    std::string input;

    while (exit == false) {
        int floor_to_go = 0;

        std::cout << "Enter a floor to go : ";
        std::cin >> floor_to_go;
        std::cout << "go_to " << floor_to_go << std::endl;
        ascenseur.go_to(floor_to_go);
        std::cout << "go_to done, actual floor : " << ascenseur.get_current_floor() << std::endl;
        std::cout << "Enter 'exit' to exit or anything else to continue : ";
        std::cin >> input;
        if (input.find("exit") != std::string::npos)
            exit = true;
    }
}

void display_help(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./elevator [max_floor] [min_floor] [current_floor] [option_floor_buttons]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tmax_floor\tthe max floor of the building" << std::endl;
    std::cout << "\tmin_floor\tthe min floor of the building" << std::endl;
    std::cout << "\tcurrent_floor\tthe current floor of the elevator" << std::endl;
    std::cout << "\toption_floor_buttons\tthe floor buttons of the elevator" << std::endl;
}

int argument_parser(int ac, char **av)
{
    if (ac >= 4) {
        try {
            int max_floor = std::stoi(av[1]);
            int min_floor = std::stoi(av[2]);
            int current_floor = std::stoi(av[3]);

            if (max_floor < min_floor)
                throw std::invalid_argument("max_floor must be greater than min_floor");
            if (current_floor < min_floor || current_floor > max_floor)
                throw std::invalid_argument("current_floor must be between min_floor and max_floor");

            if (ac == 5) {
                int floor_to_go = std::stoi(av[4]);
                elevator_system(max_floor, min_floor, current_floor, floor_to_go);
            } else {
                elevator_system(max_floor, min_floor, current_floor);
            }

            return (0);
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return (84);
        }
    }
    if (ac == 2) {
        if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help") {
            display_help();
            return (0);
        } else {
            std::cerr << "Error: invalid argument" << std::endl;
            return (84);
        }
    } else {
        return (84);
    }

}

int main(int ac, char **av)
{
    try {
        return (argument_parser(ac, av));
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}