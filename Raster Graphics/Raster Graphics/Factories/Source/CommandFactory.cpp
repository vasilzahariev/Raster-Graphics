#include "../CommandFactory.h"

Command* CommandFactory::createCommand(std::vector<std::string> args, SessionMaster* sessionMaster) {
    std::string commandType = args[0];

    RasterGraphicsUtility::toLowerString(commandType);

    if (commandType == "open") {
        if (args.size() == 1)
            throw CommandException("Invalid number of arguments");

        return new OpenCommand(sessionMaster, args[1]);
    }
    else if (commandType == "rotate") {
        if (args.size() == 1)
            throw CommandException("Invalid number of arguments");

        return new RotateCommand(sessionMaster->getActiveSession(), args[1]);
    }
    else if (commandType == "grayscale")
        return new GrayscaleCommand(sessionMaster->getActiveSession());
    else if (commandType == "monochrome")
        return new MonochromeCommand(sessionMaster->getActiveSession());
    else if (commandType == "negative")
        return new NegativeCommand(sessionMaster->getActiveSession());
    else if (commandType == "add") {
        if (args.size() == 1)
            throw CommandException("Invalid number of arguments");

        return new AddCommand(sessionMaster->getActiveSession(), args[1]);
    }
    else if (commandType == "save")
        return new SaveCommand(sessionMaster->getActiveSession());
    else if (commandType == "saveas") {
        if (args.size() == 1)
            throw CommandException("Invalid number of arguments");

        return new SaveAsCommand(sessionMaster->getActiveSession(), args[1]);
    }
    else if (commandType == "close")
        return new CloseCommand(sessionMaster->getActiveSession());
    else if (commandType == "undo")
        return new UndoCommand(sessionMaster->getActiveSession());
    else if (commandType == "help")
        return new HelpCommand();

    throw CommandException("Invalid command");
}
