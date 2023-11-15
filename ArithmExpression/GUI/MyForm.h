#pragma once
#include"MyArithmExpress.h"
#include <msclr/marshal_cppstd.h>


namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Button^ btnCalculate;

	private: System::Windows::Forms::TextBox^ txtInfixExpression;
	private: System::Windows::Forms::Label^ lblInfix;
	private: System::Windows::Forms::Label^ lblPostfix;
	private: System::Windows::Forms::Label^ lblCalculated;




	public:
		MyForm(void)
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
		~MyForm()
		{
			/*if (components)
			{
				delete components;
			}*/
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnCalculate = (gcnew System::Windows::Forms::Button());
			this->txtInfixExpression = (gcnew System::Windows::Forms::TextBox());
			this->lblInfix = (gcnew System::Windows::Forms::Label());
			this->lblPostfix = (gcnew System::Windows::Forms::Label());
			this->lblCalculated = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnCalculate
			// 
			this->btnCalculate->Location = System::Drawing::Point(313, 27);
			this->btnCalculate->Name = L"btnCalculate";
			this->btnCalculate->Size = System::Drawing::Size(109, 40);
			this->btnCalculate->TabIndex = 0;
			this->btnCalculate->Text = L"Enter expression";
			this->btnCalculate->UseVisualStyleBackColor = true;
			this->btnCalculate->Click += gcnew System::EventHandler(this, &MyForm::btnCalculate_Click);
			// 
			// txtInfixExpression
			// 
			this->txtInfixExpression->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->txtInfixExpression->Location = System::Drawing::Point(32, 29);
			this->txtInfixExpression->Name = L"txtInfixExpression";
			this->txtInfixExpression->Size = System::Drawing::Size(260, 34);
			this->txtInfixExpression->TabIndex = 1;
			// 
			// lblInfix
			// 
			this->lblInfix->AutoSize = true;
			this->lblInfix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblInfix->Location = System::Drawing::Point(29, 84);
			this->lblInfix->Name = L"lblInfix";
			this->lblInfix->Size = System::Drawing::Size(53, 25);
			this->lblInfix->TabIndex = 2;
			this->lblInfix->Text = L"Infix:";
			// 
			// lblPostfix
			// 
			this->lblPostfix->AutoSize = true;
			this->lblPostfix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblPostfix->Location = System::Drawing::Point(29, 116);
			this->lblPostfix->Name = L"lblPostfix";
			this->lblPostfix->Size = System::Drawing::Size(76, 25);
			this->lblPostfix->TabIndex = 3;
			this->lblPostfix->Text = L"Postfix:";
			// 
			// lblCalculated
			// 
			this->lblCalculated->AutoSize = true;
			this->lblCalculated->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblCalculated->Location = System::Drawing::Point(29, 145);
			this->lblCalculated->Name = L"lblCalculated";
			this->lblCalculated->Size = System::Drawing::Size(111, 25);
			this->lblCalculated->TabIndex = 4;
			this->lblCalculated->Text = L"Calculated:";
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(638, 302);
			this->Controls->Add(this->lblCalculated);
			this->Controls->Add(this->lblPostfix);
			this->Controls->Add(this->lblInfix);
			this->Controls->Add(this->txtInfixExpression);
			this->Controls->Add(this->btnCalculate);
			this->Name = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		private: System::Void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
			try {

				String^ infix = txtInfixExpression->Text;

				TArithmeticExpression expression(msclr::interop::marshal_as<std::string>(infix));
				std::string postfix = expression.GetPostfix();
				double result = expression.Calculate();
				lblInfix->Text = "Infix: " + infix;
				lblPostfix->Text = "Postfix: " + gcnew String(postfix.c_str());
				lblCalculated->Text = "Calculated: " + result.ToString("F2");
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
};
}

#pragma endregion
