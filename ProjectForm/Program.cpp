#include "LoginForm.h"
#include "AdminForm.h"
#include "RegisterForm.h"
#include "UserForm.h"
using namespace System;
using namespace System::Windows::Forms;


void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	

	Admins^ admin = nullptr;
	User^ user = nullptr;
	while (true)
	{
		ProjectForm::LoginForm loginForm;
		loginForm.ShowDialog();
		if (loginForm.swithtoregister) {
		
			ProjectForm::RegisterForm registerForm;
			registerForm.ShowDialog();
			if (registerForm.switchToLogin) {
			
				continue;
			}
			else
			{
				user = registerForm.user;
				break;



			}
				
		}
		else {
			user = loginForm.user;
			break;

		
		
		}





	}


	if (user != nullptr) {
		ProjectForm::AdminForm adminForm(user);
		Application::Run(% adminForm);

		
	}
	if (admin != nullptr) {
		ProjectForm::UserForm userform(admin);
		Application::Run(% userform);


	}
	







}