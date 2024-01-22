#include "test.hpp"
#include <iostream>

namespace elevator
{
    ascenseur::ascenseur(int max_floor, int min_floor, int current_floor)
    {
        if (max_floor < min_floor)
            throw std::invalid_argument("max_floor must be greater than min_floor");
        if (current_floor < min_floor || current_floor > max_floor)
            throw std::invalid_argument("current_floor must be between min_floor and max_floor");
        _max_floor = max_floor;
        _min_floor = min_floor;
        _current_floor = current_floor;
    }

    int ascenseur::get_current_floor() const
    {
        return _current_floor;
    }

    int ascenseur::get_max_floor() const
    {
        return _max_floor;
    }

    int ascenseur::get_min_floor() const
    {
        return _min_floor;
    }

    void ascenseur::set_current_floor(int floor)
    {
        _current_floor = floor;
    }

    void ascenseur::go_up()
    {
        if (_current_floor < _max_floor)
            _current_floor++;
    }

    void ascenseur::go_down()
    {
        if (_current_floor > _min_floor)
            _current_floor--;
    }

    void ascenseur::go_to(int floor)
    {
        if (floor > _max_floor || floor < _min_floor)
            throw std::invalid_argument("floor must be between min_floor and max_floor");
        if (floor > _current_floor) {
            while (_current_floor != floor) {
                go_up();
                std::cout << "Actual floor : " << _current_floor << std::endl;
            }
        } else if (floor < _current_floor) {
            while (_current_floor != floor) {
                go_down();
                std::cout << "Actual floor : " << _current_floor << std::endl;
            }
        }
    }
}
