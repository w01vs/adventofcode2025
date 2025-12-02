#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
  int dial = 50;
  int rot0 = 0;
  int pw = 0;
  if (argc == 2) {
    std::string line;
    std::ifstream stream{argv[1]};
    while (std::getline(stream, line)) {
      bool pos = line.at(0) == 'R';
      line.erase(line.begin());
      int rot = std::stoi(line);
      long y = 0;
      int clicks = 0;
      if (!pos) {
        y = (long)dial - rot;
        clicks = (int)std::floor((dial - 1.0) / 100.0) -
                 (int)std::floor((y - 1.0) / 100.0);
      } else {
        y = (long)dial + rot;
        clicks = (int)(y / 100) - (dial / 100);
      }

      dial = (y % 100 + 100) % 100;
      pw += clicks;
    }
    stream.close();
    std::cout << pw << std::endl;
  }
  return 0;
}