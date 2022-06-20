#pragma once

#include "Command.h"
#include <vector>
#include "../Session/Session.h"
#include "../Factories/ImageFactory.h"

class CollageCommand : public Command {
public:
	CollageCommand(Session* const session, const std::vector<std::string>& args);

	std::string execute() override;

	static size_t getNumberOfArgs();

private:
	Session* const m_session;
	std::vector<std::string> m_args;
	static const size_t nArgs = 4;

	Image* getImage(const std::string& fileName);
	Image* collage(Image* image1, Image* image2, std::string direction, std::string outImageLocation);
};
