#include "../HelpCommand.h"

std::string HelpCommand::execute() {
	std::string output = "";

	output += "The following commands are supported:" + '\n';
	output += "open <file>											opens <file>" + '\n';
	output += "close													closes currently opened file" + '\n';
	output += "save													saves the currently opened file" + '\n';
	output += "saveas <file>											saves the currently opened file in <file>" + '\n';
	output += "grayscale												transforms every non-grayscale (excluding the monochrome) images into grayscale" + '\n';
	output += "monochrome											transforms every non-monochrome images into monochrome" + '\n';
	output += "negative												applies the negative transformation" + '\n';
	output += "rotate <direction>									rotates an image in a desired direction (90 degrees) - either left or right" + '\n';
	output += "undo													undos the last command (doesn't affect save)" + '\n';
	output += "add <image>											adds an image to the current session" + '\n';
	output += "session info											prints information about the current session" + '\n';
	output += "switch <session>										switches to the session with ID <session>" + '\n';
	output += "collage <direction> <image1> <image2> <outimage>		creates a collage of <image1> and <image2> in <outimage>. <direction> is either horizontal or vertical" + '\n';
	output += "help													prints information about every command" + '\n';
	output += "exit													exits the program" + '\n';

	return output;
}
