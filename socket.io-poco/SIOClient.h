#pragma once

#include "SIOClientImpl.h"

#include "Poco/URI.h"

using Poco::URI;

class SIOClient
{
private:
	~SIOClient();

	SIOClientImpl *_socket;
	
	std::string _uri;
	std::string _endpoint;
	//URI _uri;

	NotificationCenter* _nCenter;

	SIOEventRegistry *_registry;
	SIONotificationHandler *_sioHandler; 

public:
	SIOClient(std::string uri, std::string endpoint, SIOClientImpl *impl);

	bool init();

	static SIOClient* connect(std::string uri);
	void send(std::string s);
	void emit(std::string eventname, std::string args);
	std::string getUri();
	NotificationCenter* getNCenter();

	typedef void (SIOEventTarget::*callback)(const void*, Object::Ptr&);

	void on(const char *name, SIOEventTarget *target, callback c);

	void fireEvent(const char * name, Object::Ptr args);
};