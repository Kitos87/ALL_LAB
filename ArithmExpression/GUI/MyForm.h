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
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		TextBox^ txtInfixExpression;
		Label^ lblInfix;
		Label^ lblPostfix;
		Label^ lblCalculated;
		Button^ btnCalculate;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(600, 250); 
			this->Text = L"Expression Calculator";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

			this->txtInfixExpression = gcnew TextBox();
			this->txtInfixExpression->Location = System::Drawing::Point(20, 20); 
			this->txtInfixExpression->Size = System::Drawing::Size(400, 30); 
			this->txtInfixExpression->Font = gcnew System::Drawing::Font(L"Segoe UI", 10); 

			this->btnCalculate = gcnew Button();
			this->btnCalculate->Location = System::Drawing::Point(430, 20); 
			this->btnCalculate->Size = System::Drawing::Size(140, 35); 
			this->btnCalculate->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);
			this->btnCalculate->Text = L"Enter expression";
			this->btnCalculate->Click += gcnew System::EventHandler(this, &MyForm::btnCalculate_Click);

			this->lblInfix = gcnew Label();
			this->lblInfix->Location = System::Drawing::Point(20, 60); 
			this->lblInfix->Size = System::Drawing::Size(560, 30); 
			this->lblInfix->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);

			this->lblPostfix = gcnew Label();
			this->lblPostfix->Location = System::Drawing::Point(20, 100); 
			this->lblPostfix->Size = System::Drawing::Size(560, 30); 
			this->lblPostfix->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);

			this->lblCalculated = gcnew Label();
			this->lblCalculated->Location = System::Drawing::Point(20, 140); 
			this->lblCalculated->Size = System::Drawing::Size(560, 30); 
			this->lblCalculated->Font = gcnew System::Drawing::Font(L"Segoe UI", 10);

			this->Controls->Add(this->txtInfixExpression);
			this->Controls->Add(this->btnCalculate);
			this->Controls->Add(this->lblInfix);
			this->Controls->Add(this->lblPostfix);
			this->Controls->Add(this->lblCalculated);
		}


		void btnCalculate_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				// —читываем инфиксное выражение из TextBox
				String^ infix = txtInfixExpression->Text;
				// —оздаем экземпл€р класса дл€ работы с выражени€ми
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
