#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include <string>
#include <utility>

namespace robot_simulator {

/**
 * @enum Bearing
 * @brief Represents the four possible directions in which a robot can face.
 */
enum class Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

/**
 * @class Robot
 * @brief Simulates a robot moving on an infinite two-dimensional grid.
 *
 * The robot can turn right, turn left, and advance one position
 * in the direction it is currently facing.
 */
class Robot {
public:

    /**
     * @brief Constructs a robot at the origin facing north.
     */
    Robot();

    /**
     * @brief Constructs a robot at a specified position and bearing.
     *
     * @param position Initial position of the robot.
     * @param bearing Initial direction of the robot.
     */
    Robot(std::pair<int, int> position, Bearing bearing);

    /**
     * @brief Turns the robot 90 degrees clockwise.
     */
    void turn_right();

    /**
     * @brief Turns the robot 90 degrees counter-clockwise.
     */
    void turn_left();

    /**
     * @brief Advances the robot one unit in its current direction.
     */
    void advance();

    /**
     * @brief Executes a sequence of robot instructions.
     *
     * @param instructions String containing R, L and A instructions.
     */
    void execute_sequence(const std::string& instructions);

    /**
     * @brief Gets the current position of the robot.
     *
     * @return Current position as an x,y pair.
     */
    std::pair<int, int> get_position() const;

    /**
     * @brief Gets the current bearing of the robot.
     *
     * @return Current bearing.
     */
    Bearing get_bearing() const;

private:
    std::pair<int, int> position_;
    Bearing bearing_;
};

} // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H
