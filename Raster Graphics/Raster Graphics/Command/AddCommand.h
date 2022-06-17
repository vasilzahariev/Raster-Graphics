#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H

#include <fstream>

#include "Command.h"
#include "../Session/Session.h"
#include "../Image/ImageFactory.h"
#include "../Exceptions/FileException.h"

class AddCommand : public Command {
public:
	AddCommand(Session* const session, std::string_view fileLocation);

	std::string execute() override;

private:
	Session* const m_session;
	mutable std::string m_fileLocation;
};

#endif // !ADDCOMMAND_H
