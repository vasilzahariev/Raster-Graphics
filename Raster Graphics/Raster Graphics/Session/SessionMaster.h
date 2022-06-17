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

private:
	Session* m_activeSession;
	std::vector<Session> m_sessions;
};
