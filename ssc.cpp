#include "ssc.h"
#include <iostream>

SecureSettingsController::SecureSettingsController()
{
	cmd.clear();
	cout << "Security Settings Controller. Version " << VERSION << endl;
	return;
}

SecureSettingsController::~SecureSettingsController()
{
	cmd.clear();
	cout << "Thanks for using." << endl;
}
void SecureSettingsController::readCommand()
{
	getline(cin, cmd);
	execCommand();
	return;
}
string SecureSettingsController::getCommand()
{
	return this -> cmd;
}

void SecureSettingsController::execCommand()
{
	if (cmd.find("exit") != NORES) return;
	else if (cmd.find("add") != NORES) {
		if (cmd.find("user") != NORES) addUserGroup(1);
		else if (cmd.find("group") != NORES) addUserGroup(0);
		else if (cmd.find("priv") != NORES) setPriv();
		else printError("syntax: add <user|group|priv>");
	}
	else if (cmd.find("delete") != NORES) {
		if (cmd.find("user") != NORES) deleteUserGroup(1);
		else if (cmd.find("group") != NORES) deleteUserGroup(0);
		else if (cmd.find("priv") != NORES) delPriv();
		else printError("syntax: delete <user|group|priv>");
	}
	else if (cmd.find("change") != NORES) {
		if (cmd.find("user") != NORES) changeUserGroup(1);
		else if (cmd.find("group") != NORES) changeUserGroup(0);
		else if (cmd.find("priv") != NORES) changePrivStatus();
		else printError("syntax: change <user|group|priv>");
	}
	else if (cmd.find("info") != NORES) {
		printUserGroupList();
	}
 	return;
}

int SecureSettingsController::printUserGroupList()
{
	cout << "Printing users/groups list..." << endl;
	USER_INFO_0* userBuf;
	DWORD entires;
	DWORD total_entires;
	DWORD resume_handle = 0;
	NET_API_STATUS userList = NetUserEnum(
		NULL,
		0, 0,
		(BYTE**)&userBuf,
		4096,
		&entires,
		&total_entires,
		&resume_handle
	);
	for (unsigned i = 0; i < entires; i++)
	{
		string username = string(CW2A(userBuf[i].usri0_name));
		cout << username << endl;
	}
	
	return 0;
}

int SecureSettingsController::addUserGroup(bool ifUser)
{
	if (ifUser) {
		cout << "Adding user..." << endl;
	}
	else {
		cout << "Adding group..." << endl;
	}
	return 0;
}

int SecureSettingsController::deleteUserGroup(bool ifUser)
{
	if (ifUser) {
		cout << "Deleting user..." << endl;
	}
	else {
		cout << "Deleting group..." << endl;
	}
	return 0;
}

int SecureSettingsController::changeUserGroup(bool ifUser)
{
	if (ifUser) {
		cout << "Changing user..." << endl;
	}
	else {
		cout << "Changing group..." << endl;
	}
	return 0;
}

int SecureSettingsController::setPriv()
{
	cout << "Setting privilege..." << endl;
	return 0;
}

int SecureSettingsController::changePrivStatus()
{
	cout << "Changing privilege..." << endl;
	return 0;
}

int SecureSettingsController::delPriv()
{
	cout << "Deleting privilege..." << endl;
	return 0;
}

void SecureSettingsController::printError(string err)
{
	cout << "Error: " << err << endl;
	return;
}
