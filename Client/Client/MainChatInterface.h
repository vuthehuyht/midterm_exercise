#pragma once
#include<string>
namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainChatInterface
	/// </summary>
	public ref class MainChatInterface : public System::Windows::Forms::Form
	{
	public:
		MainChatInterface(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void displayMessage(System::String^ message) {
			this->textBox2->AppendText(message + System::Environment::NewLine);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainChatInterface()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  messageEntered;
	protected:

	private: System::Windows::Forms::TextBox^  textBox2;
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
			this->messageEntered = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// messageEntered
			// 
			this->messageEntered->Location = System::Drawing::Point(24, 316);
			this->messageEntered->MaxLength = 10000;
			this->messageEntered->Name = L"messageEntered";
			this->messageEntered->Size = System::Drawing::Size(319, 20);
			this->messageEntered->TabIndex = 0;
			this->messageEntered->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainChatInterface::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(20, 15);
			this->textBox2->MaxLength = 10000000;
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBox2->Size = System::Drawing::Size(323, 286);
			this->textBox2->TabIndex = 1;
			// 
			// MainChatInterface
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(355, 363);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->messageEntered);
			this->Name = L"MainChatInterface";
			this->Text = L"Main Chat";
			this->ResumeLayout(false);
			this->PerformLayout();
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainChatInterface::ChatFormClosed);
		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter) {
			this->textBox2->AppendText("Me: " + messageEntered->Text + System::Environment::NewLine);
			messageEntered->Text = "";
		}
	}
	private: System::Void ChatFormClosed(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (MessageBox::Show("Do you want to exit?", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
		}
		else {
			e->Cancel = true;
		}
	}
	};
}
