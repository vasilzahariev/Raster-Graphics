#pragma once

#include <string>
#include <string_view>

#include "Command.h"
#include "../Image/Image.h"
#include "../Exceptions/FileException.h"
#include "../Session/SessionMaster.h"
#include "../Image/ImageFactory.h"
#include "../Exceptions/ImageException.h"

class OpenCommand : public Command {
public:
	OpenCommand(SessionMaster* const sessionMaster, std::string_view fileLocation);

	std::string execute() override;

private:
	std::string m_fileLocation;
	SessionMaster* const m_sessionMaster;
};
