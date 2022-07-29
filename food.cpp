#include <Arduino.h>
#include "constants.h"
#include "food.h"

void Food::generate()
{
  this->x = random(1, MAX_COLS);
  this->y = random(1, MAX_ROWS);
}
