#ifndef ELEVATOR_HPP_
#define ELEVATOR_HPP_

namespace elevator
{
    class ascenseur {
        public:
            /**
             * @brief Construct a new ascenseur object
             * @param max_floor the max floor of the building
             * @param min_floor the min floor of the building
             * @param current_floor the current floor of the elevator
            */
            ascenseur(int max_floor, int min_floor, int current_floor = 0);
            ~ascenseur() = default;

            /**
             * @brief Get the current floor of the elevator
             * @return int the current floor of the elevator
            */
            int get_current_floor() const;
            /**
             * @brief Get the max floor of the building
             * @return int the max floor of the building
            */
            int get_max_floor() const;
            /**
             * @brief Get the min floor of the building
             * @return int the min floor of the building
            */
            int get_min_floor() const;
            /**
             * @brief Set the current floor of the elevator
             * @param floor the floor to set
            */
            void set_current_floor(int floor);
            /**
             * @brief Go up of one floor
            */
            void go_up();
            /**
             * @brief Go down of one floor
            */
            void go_down();
            /**
             * @brief Go to a specific floor
             * @param floor the floor to go
            */
            void go_to(int floor);

        private:
            /**
             * @brief the current floor of the elevator
            */
            int _current_floor;
            /**
             * @brief the max floor of the building
            */
            int _max_floor;
            /**
             * @brief the min floor of the building
            */
            int _min_floor;
    };
}

#endif /* !ELEVATOR_HPP_ */