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
			textBox2->AppendText(message + "\r\n");
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
	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(24, 316);
			this->textBox1->MaxLength = 10000;
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(319, 32);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(20, 15);
			this->textBox2->MaxLength = 10000000;
			this->textBox2->Multiline = true;
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
			this->Controls->Add(this->textBox1);
			this->Name = L"MainChatInterface";
			this->Text = L"Chat Interface";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
