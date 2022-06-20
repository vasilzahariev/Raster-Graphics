#pragma once

#include <vector>

#include "Session.h"
#include "../Exceptions/SessionException.h"

class SessionMaster {
public:
	SessionMaster();

	Session* getActiveSession() const;

	void switchSession(const int id);

	void addSession(const Session& session);

	void closeActiveSession();

	bool checkIfFileAlreadyExists(std::string_view fileLocation) const;

	bool areThereUnsavedChanges() const;

private:
	Session* m_activeSession;
	std::vector<Session> m_sessions;

	size_t getSessionIndex(const Session* const session) const;
};
