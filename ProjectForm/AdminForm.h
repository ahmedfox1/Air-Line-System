#pragma once
#include"User.h"

namespace ProjectForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminForm
	/// </summary>
	public ref class AdminForm : public System::Windows::Forms::Form
	{
	public:
		AdminForm(User^user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			LbUserInfo->Text = "User Id : " + user->id + "\nUser Name : " + user->name +
				"\nUser Email : " + user->email + "\nUser Address :  " + user->address;


		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LbUserInfo;
	private: System::Windows::Forms::Button^ btexit;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AdminForm::typeid));
			this->LbUserInfo = (gcnew System::Windows::Forms::Label());
			this->btexit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LbUserInfo
			// 
			this->LbUserInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LbUserInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbUserInfo->Location = System::Drawing::Point(306, 84);
			this->LbUserInfo->Name = L"LbUserInfo";
			this->LbUserInfo->Size = System::Drawing::Size(498, 197);
			this->LbUserInfo->TabIndex = 0;
			this->LbUserInfo->Text = L"label1";
			this->LbUserInfo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btexit
			// 
			this->btexit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btexit->Location = System::Drawing::Point(493, 410);
			this->btexit->Name = L"btexit";
			this->btexit->Size = System::Drawing::Size(140, 52);
			this->btexit->TabIndex = 1;
			this->btexit->Text = L"exit";
			this->btexit->UseVisualStyleBackColor = true;
			this->btexit->Click += gcnew System::EventHandler(this, &AdminForm::btexit_Click);
			// 
			// AdminForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1028, 749);
			this->Controls->Add(this->btexit);
			this->Controls->Add(this->LbUserInfo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AdminForm";
			this->Text = L"AdminForm";
			this->Load += gcnew System::EventHandler(this, &AdminForm::AdminForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AdminForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btexit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
