#include "../HelpCommand.h"

void HelpCommand::execute() {
	std::cout << "The following commands are supported:" << std::endl;
	std::cout << "open <file>											opens <file>" << std::endl;
	std::cout << "close													closes currently opened file" << std::endl;
	std::cout << "save													saves the currently opened file" << std::endl;
	std::cout << "saveas <file>											saves the currently opened file in <file>" << std::endl;
	std::cout << "grayscale												transforms every non-grayscale (excluding the monochrome) images into grayscale" << std::endl;
	std::cout << "monochrome											transforms every non-monochrome images into monochrome" << std::endl;
	std::cout << "negative												applies the negative transformation" << std::endl;
	std::cout << "rotate <direction>									rotates an image in a desired direction (90 degrees) - either left or right" << std::endl;
	std::cout << "undo													undos the last command (doesn't affect save)" << std::endl;
	std::cout << "add <image>											adds an image to the current session" << std::endl;
	std::cout << "session info											prints information about the current session" << std::endl;
	std::cout << "switch <session>										switches to the session with ID <session>" << std::endl;
	std::cout << "collage <direction> <image1> <image2> <outimage>		creates a collage of <image1> and <image2> in <outimage>. <direction> is either horizontal or vertical" << std::endl;
	std::cout << "help													prints information about every command" << std::endl;
	std::cout << "exit													exits the program" << std::endl;
}

HelpCommand* HelpCommand::clone() {
	return new HelpCommand();
}
