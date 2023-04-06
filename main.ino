#include <MD_MAX72xx.h>
#include <SPI.h>
#include "snake.h"
#include "food.h"

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW

#define MAX_DEVICES 4
#define CLK_PIN 13   // or SCK
#define DATA_PIN 11  // or MOSI
#define CS_PIN 10    // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);  // SPI hardware interface

// int x = 1;
// int y = 1;

const int X_AXIS_MAPPING[8] = { 8, 7, 6, 5, 4, 3, 2, 1 };

const int Y_AXIS_MAPPING[32] = { 25, 26, 27, 28, 29, 30, 31, 32, 17, 18, 19, 20, 21, 22, 23, 24, 9, 10, 11, 12, 13, 14, 15, 16, 1, 2, 3, 4, 5, 6, 7, 8 };

enum keyType {
  UP,     // 0
  RIGHT,  // 1
  DOWN,   // 2
  LEFT,   // 3
  PUSH,   // 4
  NONE    // 5
};

// Arduino pin numbers
const int SW_pin = 2;  // digital pin connected to switch output
const int X_pin = 0;   // analog pin connected to X output
const int Y_pin = 1;   // analog pin connected to Y output

int snakeLength = 3;

int x[256];
int y[256];

// Snake snake(3, 3);
Food food(1, 15);

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
  mx.begin();
  resetDisplay();

  for (int z = 0; z < snakeLength; z++) {
    x[z] = 3 + z;
    y[z] = 3;
  }
}

void loop() {
  delay(120);

  handleKeyInput();
  logic();
  draw();
}

void draw() {
  mx.clear();
  // led(snake.getX(), snake.getY());
  for (int z = 0; z < snakeLength; z++) {
    if (z == 0) {
      // led(snake.getX(), snake.getY());
      led(x[z], y[z]);
    } else {
      led(x[z], y[z]);
    }
  }
  led(food.getX(), food.getY());
}
void logic() {

  // snake.update();

  // food collision
  if ((x[0] == food.getX()) && (y[0] == food.getY())) {

    snakeLength++;
    food.generate();
  }
  //if (food.getX() == snake.getX() && food.getY() == snake.getY()) {
  // snake.eat();
  //food.generate();
  //}
}

void resetDisplay(void) {
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 2);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  mx.clear();
}

void led(int x, int y) {
  mx.setPoint(X_AXIS_MAPPING[x - 1] - 1, Y_AXIS_MAPPING[y - 1] - 1, 1);
}

void handleKeyInput() {
  if (digitalRead(SW_pin) == 0) {

    // return PUSH;
  }
  for (int z = snakeLength; z > 0; z--) {
    x[z] = x[(z - 1)];
    y[z] = y[(z - 1)];
      Serial.println(x[z]);

  }

  // right
  if (analogRead(X_pin) > 1000) {
    x[0] += 1;
    //snake.setDirection(1, 0);
  }
  // left
  if (analogRead(X_pin) < 100) {
    x[0] -= 1;  // snake.setDirection(-1, 0);
  }
  // down
  if (analogRead(Y_pin) > 1000) {
    y[0] += 1;
    // snake.setDirection(0, 1);
  }
  // up
  if (analogRead(Y_pin) < 100) {
    y[0] -= 1;
    // snake.setDirection(0, -1);
  }
}
