#ifndef MESA_CRITTERS_DIRECTION_H
#define MESA_CRITTERS_DIRECTION_H

#include <array>
#include <iosfwd>
#include <map>

/**
 * @class direction
 * Defines the direction that a moving critter is allowed to travel.
 *
 * - Increasing south moves a critter down
 * - Increasing west moves a critter right
 */
enum class direction {
  CENTER,                 /*!< No movement. */
  NORTH,                  /*!< Move one cell up. */
  NORTH_EAST,             /*!< Move one cell up and to the right. */
  EAST,                   /*!< Move one cell right. */
  SOUTH_EAST,             /*!< Move one cell down and to the right. */
  SOUTH,                  /*!< Move one cell down. */
  SOUTH_WEST,             /*!< Move one cell down and to the left. */
  WEST,                   /*!< Move one cell left. */
  NORTH_WEST,             /*!< Move one cell up and to the left. */
};


/**
 * Send text representation of a Direction to an output stream.
 *
 * @param os reference to an output stream
 * @param rhs reference to the Direction
 * @return the modified output stream
 */
std::ostream& operator<<(std::ostream& os, const direction& rhs);


/**
 * Allows the Direction class members to be used in a range for loop
 * Example:
 *    map<Direction, shared_ptr<Critter>> neighbors;
 *    for (const auto& d: directions) {
 *      // do something with neighbors[d] . . . 
 *    }
 * @see Simulator::get_neighbors
 */
const std::array<direction,8> directions = 
{
  {
    direction::NORTH,
    direction::NORTH_EAST,
    direction::EAST,     
    direction::SOUTH_EAST,
    direction::SOUTH,    
    direction::SOUTH_WEST,
    direction::WEST,     
    direction::NORTH_WEST
  }
};

#endif
