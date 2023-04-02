#pragma once
#include "User.h";

namespace ProjectForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btexit;
	private: System::Windows::Forms::Button^ btlogin;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ tbemail;
	private: System::Windows::Forms::TextBox^ tbpassword;
	private: System::Windows::Forms::Button^ llregister;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->btexit = (gcnew System::Windows::Forms::Button());
			this->btlogin = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tbemail = (gcnew System::Windows::Forms::TextBox());
			this->tbpassword = (gcnew System::Windows::Forms::TextBox());
			this->llregister = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btexit
			// 
			this->btexit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(72)));
			this->btexit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btexit.BackgroundImage")));
			this->btexit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btexit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btexit->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(72)));
			this->btexit->FlatAppearance->BorderSize = 0;
			this->btexit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(72)));
			this->btexit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(11)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(72)));
			this->btexit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btexit->Location = System::Drawing::Point(772, 533);
			this->btexit->Name = L"btexit";
			this->btexit->Size = System::Drawing::Size(140, 49);
			this->btexit->TabIndex = 0;
			this->btexit->UseVisualStyleBackColor = false;
			this->btexit->Click += gcnew System::EventHandler(this, &LoginForm::btexit_Click);
			// 
			// btlogin
			// 
			this->btlogin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btlogin.BackgroundImage")));
			this->btlogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btlogin->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->btlogin->FlatAppearance->BorderSize = 0;
			this->btlogin->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->btlogin->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->btlogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btlogin->Location = System::Drawing::Point(772, 374);
			this->btlogin->Name = L"btlogin";
			this->btlogin->Size = System::Drawing::Size(168, 53);
			this->btlogin->TabIndex = 1;
			this->btlogin->UseVisualStyleBackColor = true;
			this->btlogin->Click += gcnew System::EventHandler(this, &LoginForm::btlogin_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(-15, -15);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// tbemail
			// 
			this->tbemail->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->tbemail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbemail->Font = (gcnew System::Drawing::Font(L"Soft Core", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbemail->ForeColor = System::Drawing::Color::White;
			this->tbemail->Location = System::Drawing::Point(759, 239);
			this->tbemail->Name = L"tbemail";
			this->tbemail->Size = System::Drawing::Size(228, 21);
			this->tbemail->TabIndex = 3;
			// 
			// tbpassword
			// 
			this->tbpassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->tbpassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbpassword->Font = (gcnew System::Drawing::Font(L"Viga", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbpassword->ForeColor = System::Drawing::Color::White;
			this->tbpassword->Location = System::Drawing::Point(758, 326);
			this->tbpassword->Name = L"tbpassword";
			this->tbpassword->PasswordChar = '*';
			this->tbpassword->Size = System::Drawing::Size(228, 22);
			this->tbpassword->TabIndex = 3;
			// 
			// llregister
			// 
			this->llregister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->llregister->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"llregister.BackgroundImage")));
			this->llregister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->llregister->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->llregister->Location = System::Drawing::Point(772, 463);
			this->llregister->Name = L"llregister";
			this->llregister->Size = System::Drawing::Size(147, 46);
			this->llregister->TabIndex = 5;
			this->llregister->UseVisualStyleBackColor = false;
			this->llregister->Click += gcnew System::EventHandler(this, &LoginForm::llregister_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1028, 647);
			this->Controls->Add(this->llregister);
			this->Controls->Add(this->tbpassword);
			this->Controls->Add(this->tbemail);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btlogin);
			this->Controls->Add(this->btexit);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(10)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"LoginForm";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btexit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();

	}
		   public: User^ user=nullptr;


	private: System::Void btlogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = this->tbemail->Text;
		String^ password = this->tbpassword->Text;
		if (email->Length == 0 || password->Length == 0) {
			MessageBox::Show("Please enter email and password");
			return;
		}
		try {
			String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=test1;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQUERY = "SELECT * FROM Users WHERE email=@email AND password=@pwd;";
			SqlCommand command(sqlQUERY, % sqlConn);
			command.Parameters->AddWithValue("@email", email);
			command.Parameters->AddWithValue("@pwd", password);

			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {

				user = gcnew User;
				user->id =reader->GetInt32(0);
				user->name = reader->GetString(1);
				user->email = reader->GetString(2);
				user->phone = reader->GetString(3);
				user->address = reader->GetString(4);
				user->password = reader->GetString(5);




				this->Close();



			}
			else {
				MessageBox::Show("Email or password is incorrect ",
					"Email or Password Error", MessageBoxButtons::OK);

			
			}


		}
		catch (Exception^ e) {
			MessageBox::Show("Try again");

		
		}


	}
		   public: bool swithtoregister=false;


private: System::Void llregister_Click(System::Object^ sender, System::EventArgs^ e) {
	this->swithtoregister = true;
	this->Close();
}
};
}


