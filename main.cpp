#include "ssc.h"
#include <clocale>


int main() {
	setlocale(LC_ALL, "Russian");
	SecureSettingsController Con1;
	while (true) {
		Con1.readCommand();
		if (Con1.getCommand() == " exit") break;
	}
	return 0;
}