#pragma once
#include "User.h"
namespace ProjectForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbAddress;
	private: System::Windows::Forms::Button^ btCreat;
	private: System::Windows::Forms::Label^ lbLogin;
	private: System::Windows::Forms::Button^ btExit;
	protected:






	private: System::Windows::Forms::TextBox^ tbPhone;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbAddress = (gcnew System::Windows::Forms::TextBox());
			this->btCreat = (gcnew System::Windows::Forms::Button());
			this->lbLogin = (gcnew System::Windows::Forms::Label());
			this->btExit = (gcnew System::Windows::Forms::Button());
			this->tbPhone = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// tbName
			// 
			this->tbName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->tbName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbName->Font = (gcnew System::Drawing::Font(L"Soft Core", 15));
			this->tbName->ForeColor = System::Drawing::Color::White;
			this->tbName->Location = System::Drawing::Point(758, 151);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(231, 21);
			this->tbName->TabIndex = 0;
			// 
			// tbEmail
			// 
			this->tbEmail->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->tbEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbEmail->Font = (gcnew System::Drawing::Font(L"Soft Core", 15));
			this->tbEmail->ForeColor = System::Drawing::Color::White;
			this->tbEmail->Location = System::Drawing::Point(758, 226);
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(231, 21);
			this->tbEmail->TabIndex = 0;
			// 
			// tbPassword
			// 
			this->tbPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->tbPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Soft Core", 15));
			this->tbPassword->ForeColor = System::Drawing::Color::White;
			this->tbPassword->Location = System::Drawing::Point(758, 306);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(231, 21);
			this->tbPassword->TabIndex = 0;
			// 
			// tbAddress
			// 
			this->tbAddress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->tbAddress->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbAddress->Font = (gcnew System::Drawing::Font(L"Soft Core", 15));
			this->tbAddress->ForeColor = System::Drawing::Color::White;
			this->tbAddress->Location = System::Drawing::Point(758, 453);
			this->tbAddress->Name = L"tbAddress";
			this->tbAddress->Size = System::Drawing::Size(231, 21);
			this->tbAddress->TabIndex = 0;
			// 
			// btCreat
			// 
			this->btCreat->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->btCreat->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btCreat.BackgroundImage")));
			this->btCreat->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btCreat->FlatAppearance->BorderSize = 0;
			this->btCreat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btCreat->Location = System::Drawing::Point(758, 493);
			this->btCreat->Name = L"btCreat";
			this->btCreat->Size = System::Drawing::Size(197, 50);
			this->btCreat->TabIndex = 1;
			this->btCreat->UseVisualStyleBackColor = false;
			this->btCreat->Click += gcnew System::EventHandler(this, &RegisterForm::btCreat_Click);
			// 
			// lbLogin
			// 
			this->lbLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lbLogin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lbLogin.Image")));
			this->lbLogin->Location = System::Drawing::Point(802, 567);
			this->lbLogin->Name = L"lbLogin";
			this->lbLogin->Size = System::Drawing::Size(100, 23);
			this->lbLogin->TabIndex = 2;
			this->lbLogin->Click += gcnew System::EventHandler(this, &RegisterForm::lbLogin_Click);
			// 
			// btExit
			// 
			this->btExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(72)));
			this->btExit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btExit.BackgroundImage")));
			this->btExit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btExit->FlatAppearance->BorderSize = 0;
			this->btExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btExit->Location = System::Drawing::Point(769, 598);
			this->btExit->Name = L"btExit";
			this->btExit->Size = System::Drawing::Size(133, 42);
			this->btExit->TabIndex = 1;
			this->btExit->UseVisualStyleBackColor = false;
			this->btExit->Click += gcnew System::EventHandler(this, &RegisterForm::btExit_Click);
			// 
			// tbPhone
			// 
			this->tbPhone->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->tbPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbPhone->Font = (gcnew System::Drawing::Font(L"Soft Core", 15));
			this->tbPhone->ForeColor = System::Drawing::Color::White;
			this->tbPhone->Location = System::Drawing::Point(758, 379);
			this->tbPhone->Name = L"tbPhone";
			this->tbPhone->Size = System::Drawing::Size(231, 21);
			this->tbPhone->TabIndex = 0;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1044, 646);
			this->Controls->Add(this->lbLogin);
			this->Controls->Add(this->btExit);
			this->Controls->Add(this->btCreat);
			this->Controls->Add(this->tbPhone);
			this->Controls->Add(this->tbAddress);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();

	}

		   public: bool switchToLogin = false;

private: System::Void lbLogin_Click(System::Object^ sender, System::EventArgs^ e) {
	this->switchToLogin = true;
	this->Close();


}
	   public: User^ user = nullptr;

private: System::Void btCreat_Click(System::Object^ sender, System::EventArgs^ e) {
	
	String^ name = tbName->Text;
	String^ email = tbEmail->Text;
	String^ phone = tbPhone->Text;
	String^ address = tbAddress->Text;
	String^ password = tbPassword->Text;
	
	if (name->Length==0|| email->Length == 0|| phone->Length == 0 ||
		address->Length == 0 || password->Length == 0 ) {
		MessageBox::Show("Please enter all fields", "one or more fields are empety "); 
		return;
	}

	try {
		String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=test1;Integrated Security=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();
		String^ sqlQuery = "INSERT INTO users " + "(name, email, phone,address,password)VALUES"
			+ "(@name, @email, @phone, @address, @password);";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@email", email);
		command.Parameters->AddWithValue("@phone", phone);
		command.Parameters->AddWithValue("@name", name);
		command.Parameters->AddWithValue("@address", address);
		command.Parameters->AddWithValue("@password", password);

		command.ExecuteNonQuery();
		user = gcnew User;
		user->name = name;
		user->email = email;
		user->address = address;
		user->phone = phone;
		user->password = password;
		this->Close();

	}
	catch (Exception^ ex) {
		MessageBox::Show("Faild to register new user", "Refister Failure", MessageBoxButtons::OK);

	
	
	}

}
};
}
