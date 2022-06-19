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
        return new CloseCommand(sessionMaster);
    else if (commandType == "undo")
        return new UndoCommand(sessionMaster->getActiveSession());
    else if (commandType == "help")
        return new HelpCommand();
    else if (commandType == "session") {
        if (args.size() == 1)
            throw CommandException("Invalid number of arguments");
        else if (args[1] != "info")
            throw CommandException("Invalid command");

        return new SessionInfoCommand(sessionMaster->getActiveSession());
    }
    else if (commandType == "switch") {
        if (args.size() == 1)
            throw CommandException("Invalid number of arguments");

        try {
            return new SwitchCommand(sessionMaster, std::stoi(args[1]));
        }
        catch (std::invalid_argument err) {
            throw CommandException("Invalid argument: <session> should be an INTEGER");
        }
    }
    else if (commandType == "exit")
        return new ExitCommand();

    throw CommandException("Invalid command");
}
