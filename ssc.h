#pragma once
#include <string>
#include<Windows.h>
#include<lmaccess.h>
#include<atlstr.h>
#pragma comment(lib, "Netapi32.lib")
using namespace std;

#define VERSION "0.2"


#ifdef _WIN64
#define NORES (18446744073709551615)
#else
#ifdef WIN32
#define NORES (4294967295)
#endif
#endif

class SecureSettingsController {
private:
	string cmd;
public:
	SecureSettingsController();
	~SecureSettingsController();


	void readCommand();
	string getCommand();
	void execCommand();


	int printUserGroupList();
	int addUserGroup(bool ifUser);
	int deleteUserGroup(bool ifUser);
	int changeUserGroup(bool ifUser);


	int setPriv();
	int changePrivStatus();
	int delPriv();



	void printError(string err);
};