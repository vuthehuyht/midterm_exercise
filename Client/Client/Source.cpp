
#include "LoginForm.h"
using namespace Client;

int main() {
	Application::EnableVisualStyles();
	Client::LoginForm form;
	Application::Run(%form);
	return 0;
}