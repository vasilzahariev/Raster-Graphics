#pragma once

#include <fstream>

#include "Command.h"
#include "../Session/Session.h"
#include "../Factories/ImageFactory.h"
#include "../Exceptions/FileException.h"
#include "../Session/SessionMaster.h"

class AddCommand : public Command {
public:
	AddCommand(SessionMaster* const sessionMaster, Session* const session, std::string_view fileLocation);

	static size_t getNumberOfArgs();

	std::string execute() override;

private:
	SessionMaster* const m_sessionMaster;
	Session* const m_session;
	mutable std::string m_fileLocation;

	static const size_t nArgs = 1;
};
