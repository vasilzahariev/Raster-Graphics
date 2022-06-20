#include "../CommandFactory.h"

Command* CommandFactory::createCommand(std::vector<std::string> args, SessionMaster* sessionMaster) {
	std::string commandType = args[0];

	RasterGraphicsUtility::toLowerString(commandType);

	if (commandType == "open") {
		argsValidator(args, OpenCommand::getNumberOfArgs() + 1);

		return new OpenCommand(sessionMaster, args[1]); // TODO: Look into
	}
	else if (commandType == "rotate") {
		argsValidator(args, RotateCommand::getNumberOfArgs() + 1);

		return new RotateCommand(sessionMaster->getActiveSession(), args[1]);
	}
	else if (commandType == "grayscale") {
		argsValidator(args, GrayscaleCommand::getNumberOfArgs() + 1);

		return new GrayscaleCommand(sessionMaster->getActiveSession());
	}
	else if (commandType == "monochrome") {
		argsValidator(args, MonochromeCommand::getNumberOfArgs() + 1);

		return new MonochromeCommand(sessionMaster->getActiveSession());
	}
	else if (commandType == "negative") {
		argsValidator(args, NegativeCommand::getNumberOfArgs() + 1);

		return new NegativeCommand(sessionMaster->getActiveSession());
	}
	else if (commandType == "add") {
		argsValidator(args, AddCommand::getNumberOfArgs() + 1); // TODO: Look into

		return new AddCommand(sessionMaster, sessionMaster->getActiveSession(), args[1]);
	}
	else if (commandType == "save") {
		argsValidator(args, SaveCommand::getNumberOfArgs() + 1);

		return new SaveCommand(sessionMaster->getActiveSession());
	}
	else if (commandType == "saveas") {
		argsValidator(args, SaveAsCommand::getNumberOfArgs() + 1);

		return new SaveAsCommand(sessionMaster->getActiveSession(), args[1]);
	}
	else if (commandType == "close") {
		argsValidator(args, CloseCommand::getNumberOfArgs() + 1);

		return new CloseCommand(sessionMaster);
	}
	else if (commandType == "undo") {
		argsValidator(args, UndoCommand::getNumberOfArgs() + 1);

		return new UndoCommand(sessionMaster->getActiveSession());
	}
	else if (commandType == "help") {
		argsValidator(args, HelpCommand::getNumberOfArgs() + 1);

		return new HelpCommand();
	}
	else if (commandType == "session") {
		argsValidator(args, SessionInfoCommand::getNumberOfArgs() + 1, [](const std::vector<std::string>& args) { return args[1] == "info"; });

		return new SessionInfoCommand(sessionMaster->getActiveSession());
	}
	else if (commandType == "switch") {
		argsValidator(args, SwitchCommand::getNumberOfArgs() + 1, [](const std::vector<std::string>& args) {
			try { int a = std::stoi(args[1]); }
			catch (std::invalid_argument err) { throw CommandException("Invalid argument: <session> should be an INTEGER"); }
			return true;
			});

		return new SwitchCommand(sessionMaster, std::stoi(args[1]));
	}
	else if (commandType == "collage") {
		argsValidator(args, CollageCommand::getNumberOfArgs() + 1);

		return new CollageCommand(sessionMaster->getActiveSession(), args);
	}
	else if (commandType == "exit") {
		argsValidator(args, ExitCommand::getNumberOfArgs() + 1);

		return new ExitCommand();
	}

	throw CommandException("Invalid command");
}

void CommandFactory::argsValidator(const std::vector<std::string> args, const size_t numberOfArgs, bool(*validator)(const std::vector<std::string>& str)) {
	if (args.size() != numberOfArgs)
		throw CommandException("Invalid number of arguments");

	if (validator != nullptr && !validator(args))
		throw CommandException("Invalid arguments");
}
