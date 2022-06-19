#include "../Command.h"

std::string Command::execute() {
	std::string output = "";

	output = executor();

	//try {
	//	output = executor();
	//}
	//catch (CommandException err) {
	//	output = err.what();
	//}
	//catch (FileException err) {
	//	output = err.what();
	//}
	//catch (ImageException err) {
	//	output = err.what();
	//}
	//catch (NotAnException err) { // TODO: Add an easter egg =)
	//	output = err.what();
	//}
	//catch (OutOfBoundsException err) {
	//	output = err.what();
	//}
	//catch (SessionException err) {
	//	output = err.what();
	//}
	//catch (std::exception err) {
	//	output = err.what();
	//}

	return output;
}
