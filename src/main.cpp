#include "controller.hpp"

int main() {
  Controller *controller = new Controller;
  controller->run();
  delete controller;
  return 0;
}
