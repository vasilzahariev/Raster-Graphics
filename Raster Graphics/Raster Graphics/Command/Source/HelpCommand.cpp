#include "../HelpCommand.h"

std::string HelpCommand::executor() {
	std::string output = "";

	output += "The following commands are supported:\n";
	output += "* open <file> -> opens <file> and creates a session\n";
	output += "* close -> closes the active session and closes all its files\n";
	output += "* save -> saves all the files in the active session\n";
	output += "* saveas <file> -> saves the first file in the active session in <file>\n";
	output += "* grayscale -> transforms every non-grayscale (excluding the monochrome) image (in the active session) into grayscale\n";
	output += "* monochrome -> transforms every non-monochrome image (in the active session) into monochrome\n";
	output += "* negative -> applies the negative transformation for every image in the active session\n";
	output += "* rotate <direction> -> rotates every image (in the active session) in a desired direction (90 degrees) - either left or right\n";
	output += "* undo -> undos the last command (doesn't affect save)\n";
	output += "* add <image> -> adds an image to the current session\n";
	output += "* session info -> prints information about the current session\n";
	output += "* switch <sessionId> -> switches to the session with <sessionId>\n";
	output += "* collage <direction> <image1> <image2> <outimage> -> creates a collage of <image1> and <image2> in <outimage>. <direction> is either horizontal or vertical\n";
	output += "* help -> prints information about every command\n";
	output += "* exit -> exits the program\n";

	return output;
}
