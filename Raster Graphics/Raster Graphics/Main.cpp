#include <fstream>

#include "Engine/Engine.h"

int main() {
	//std::ifstream input("input.txt");
	//std::ofstream output("output.txt");

	//Engine::getInstance().run(input, output);

	Engine::getInstance().run();

	return 0;
}