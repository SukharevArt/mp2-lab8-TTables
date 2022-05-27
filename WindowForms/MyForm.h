#pragma once
#include "../TTable.h"
#include "../TArrayHash.h"
#include "../TSortTable.h"
#include "../TBalTable.h"
#include "../TListHash.h"
#include "../TScanTable.h"
#include "../TTreeTable.h"
#include<fstream>

namespace WindowForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	protected:
		TTable* tbl;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			initt();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Label_Size;
	protected:

	private: System::Windows::Forms::Label^ Label_CountKeys;

	private: System::Windows::Forms::Label^ Label_TmpKey;
	private: System::Windows::Forms::Label^ Label_Result;
	private: System::Windows::Forms::TextBox^ Size;
	private: System::Windows::Forms::TextBox^ CountKeys;
	private: System::Windows::Forms::TextBox^ TmpKey;
	private: System::Windows::Forms::CheckBox^ scntbl;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ blnctr;

	private: System::Windows::Forms::CheckBox^ smpltr;


	private: System::Windows::Forms::CheckBox^ lsthsh;

	private: System::Windows::Forms::CheckBox^ arrhsh;

	private: System::Windows::Forms::CheckBox^ srttbl;

	private: System::Windows::Forms::ListView^ ListOfTable;

	private: System::Windows::Forms::ColumnHeader^ Keys;
	private: System::Windows::Forms::ColumnHeader^ Values;
	private: System::Windows::Forms::Label^ Label_Eff;
	private: System::Windows::Forms::Label^ Result;
	private: System::Windows::Forms::Label^ Eff;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Label_Size = (gcnew System::Windows::Forms::Label());
			this->Label_CountKeys = (gcnew System::Windows::Forms::Label());
			this->Label_TmpKey = (gcnew System::Windows::Forms::Label());
			this->Label_Result = (gcnew System::Windows::Forms::Label());
			this->Size = (gcnew System::Windows::Forms::TextBox());
			this->CountKeys = (gcnew System::Windows::Forms::TextBox());
			this->TmpKey = (gcnew System::Windows::Forms::TextBox());
			this->scntbl = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->blnctr = (gcnew System::Windows::Forms::CheckBox());
			this->smpltr = (gcnew System::Windows::Forms::CheckBox());
			this->lsthsh = (gcnew System::Windows::Forms::CheckBox());
			this->arrhsh = (gcnew System::Windows::Forms::CheckBox());
			this->srttbl = (gcnew System::Windows::Forms::CheckBox());
			this->ListOfTable = (gcnew System::Windows::Forms::ListView());
			this->Keys = (gcnew System::Windows::Forms::ColumnHeader());
			this->Values = (gcnew System::Windows::Forms::ColumnHeader());
			this->Label_Eff = (gcnew System::Windows::Forms::Label());
			this->Result = (gcnew System::Windows::Forms::Label());
			this->Eff = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Label_Size
			// 
			this->Label_Size->AutoSize = true;
			this->Label_Size->BackColor = System::Drawing::SystemColors::Window;
			this->Label_Size->Cursor = System::Windows::Forms::Cursors::Default;
			this->Label_Size->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Label_Size->Location = System::Drawing::Point(531, 73);
			this->Label_Size->Name = L"Label_Size";
			this->Label_Size->Size = System::Drawing::Size(234, 40);
			this->Label_Size->TabIndex = 0;
			this->Label_Size->Text = L"Число записей";
			// 
			// Label_CountKeys
			// 
			this->Label_CountKeys->AutoSize = true;
			this->Label_CountKeys->BackColor = System::Drawing::SystemColors::Window;
			this->Label_CountKeys->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Label_CountKeys->Location = System::Drawing::Point(516, 136);
			this->Label_CountKeys->Name = L"Label_CountKeys";
			this->Label_CountKeys->Size = System::Drawing::Size(282, 40);
			this->Label_CountKeys->TabIndex = 1;
			this->Label_CountKeys->Text = L"Диапозон ключей";
			// 
			// Label_TmpKey
			// 
			this->Label_TmpKey->AutoSize = true;
			this->Label_TmpKey->BackColor = System::Drawing::SystemColors::Window;
			this->Label_TmpKey->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Label_TmpKey->Location = System::Drawing::Point(564, 208);
			this->Label_TmpKey->Name = L"Label_TmpKey";
			this->Label_TmpKey->Size = System::Drawing::Size(100, 40);
			this->Label_TmpKey->TabIndex = 2;
			this->Label_TmpKey->Text = L"Ключ";
			// 
			// Label_Result
			// 
			this->Label_Result->AutoSize = true;
			this->Label_Result->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Label_Result->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Label_Result->Location = System::Drawing::Point(580, 332);
			this->Label_Result->Name = L"Label_Result";
			this->Label_Result->Size = System::Drawing::Size(176, 46);
			this->Label_Result->TabIndex = 3;
			this->Label_Result->Text = L"Результат";
			// 
			// Size
			// 
			this->Size->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Size->Location = System::Drawing::Point(666, 70);
			this->Size->Name = L"Size";
			this->Size->Size = System::Drawing::Size(131, 48);
			this->Size->TabIndex = 4;
			// 
			// CountKeys
			// 
			this->CountKeys->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CountKeys->Location = System::Drawing::Point(666, 133);
			this->CountKeys->Name = L"CountKeys";
			this->CountKeys->Size = System::Drawing::Size(131, 48);
			this->CountKeys->TabIndex = 5;
			// 
			// TmpKey
			// 
			this->TmpKey->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TmpKey->Location = System::Drawing::Point(666, 205);
			this->TmpKey->Name = L"TmpKey";
			this->TmpKey->Size = System::Drawing::Size(131, 48);
			this->TmpKey->TabIndex = 6;
			// 
			// scntbl
			// 
			this->scntbl->AutoSize = true;
			this->scntbl->Checked = true;
			this->scntbl->CheckState = System::Windows::Forms::CheckState::Checked;
			this->scntbl->Location = System::Drawing::Point(17, 38);
			this->scntbl->Name = L"scntbl";
			this->scntbl->Size = System::Drawing::Size(312, 44);
			this->scntbl->TabIndex = 8;
			this->scntbl->Text = L"Неупорядоченная";
			this->scntbl->UseVisualStyleBackColor = true;
			this->scntbl->CheckedChanged += gcnew System::EventHandler(this, &MyForm::scntbl_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->blnctr);
			this->groupBox1->Controls->Add(this->smpltr);
			this->groupBox1->Controls->Add(this->lsthsh);
			this->groupBox1->Controls->Add(this->arrhsh);
			this->groupBox1->Controls->Add(this->srttbl);
			this->groupBox1->Controls->Add(this->scntbl);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(253, 49);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(257, 306);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Виды таблиц";
			// 
			// blnctr
			// 
			this->blnctr->AutoSize = true;
			this->blnctr->Location = System::Drawing::Point(17, 255);
			this->blnctr->Name = L"blnctr";
			this->blnctr->Size = System::Drawing::Size(439, 44);
			this->blnctr->TabIndex = 13;
			this->blnctr->Text = L"Сбалансированное дерево";
			this->blnctr->UseVisualStyleBackColor = true;
			this->blnctr->CheckedChanged += gcnew System::EventHandler(this, &MyForm::blnctr_CheckedChanged);
			// 
			// smpltr
			// 
			this->smpltr->AutoSize = true;
			this->smpltr->Location = System::Drawing::Point(17, 205);
			this->smpltr->Name = L"smpltr";
			this->smpltr->Size = System::Drawing::Size(316, 44);
			this->smpltr->TabIndex = 12;
			this->smpltr->Text = L"Дерево (обычное)";
			this->smpltr->UseVisualStyleBackColor = true;
			this->smpltr->CheckedChanged += gcnew System::EventHandler(this, &MyForm::smpltr_CheckedChanged);
			// 
			// lsthsh
			// 
			this->lsthsh->AutoSize = true;
			this->lsthsh->Location = System::Drawing::Point(17, 159);
			this->lsthsh->Name = L"lsthsh";
			this->lsthsh->Size = System::Drawing::Size(372, 44);
			this->lsthsh->TabIndex = 11;
			this->lsthsh->Text = L"Хеш-таблица(список)";
			this->lsthsh->UseVisualStyleBackColor = true;
			this->lsthsh->CheckedChanged += gcnew System::EventHandler(this, &MyForm::lsthsh_CheckedChanged);
			// 
			// arrhsh
			// 
			this->arrhsh->AutoSize = true;
			this->arrhsh->Location = System::Drawing::Point(17, 110);
			this->arrhsh->Name = L"arrhsh";
			this->arrhsh->Size = System::Drawing::Size(374, 44);
			this->arrhsh->TabIndex = 10;
			this->arrhsh->Text = L"Хэш-таблица(массив)";
			this->arrhsh->UseVisualStyleBackColor = true;
			this->arrhsh->CheckedChanged += gcnew System::EventHandler(this, &MyForm::arrhsh_CheckedChanged);
			// 
			// srttbl
			// 
			this->srttbl->AutoSize = true;
			this->srttbl->Location = System::Drawing::Point(17, 74);
			this->srttbl->Name = L"srttbl";
			this->srttbl->Size = System::Drawing::Size(278, 44);
			this->srttbl->TabIndex = 9;
			this->srttbl->Text = L"Упорядоченная";
			this->srttbl->UseVisualStyleBackColor = true;
			this->srttbl->CheckedChanged += gcnew System::EventHandler(this, &MyForm::srttbl_CheckedChanged);
			// 
			// ListOfTable
			// 
			this->ListOfTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->Keys, this->Values });
			this->ListOfTable->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ListOfTable->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->ListOfTable->HideSelection = false;
			this->ListOfTable->Location = System::Drawing::Point(15, 38);
			this->ListOfTable->MultiSelect = false;
			this->ListOfTable->Name = L"ListOfTable";
			this->ListOfTable->Size = System::Drawing::Size(229, 478);
			this->ListOfTable->TabIndex = 10;
			this->ListOfTable->UseCompatibleStateImageBehavior = false;
			this->ListOfTable->View = System::Windows::Forms::View::Details;
			// 
			// Keys
			// 
			this->Keys->Text = L"Ключ";
			this->Keys->Width = 80;
			// 
			// Values
			// 
			this->Values->Text = L"Значение";
			this->Values->Width = 125;
			// 
			// Label_Eff
			// 
			this->Label_Eff->AutoSize = true;
			this->Label_Eff->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Label_Eff->Location = System::Drawing::Point(279, 375);
			this->Label_Eff->Name = L"Label_Eff";
			this->Label_Eff->Size = System::Drawing::Size(283, 46);
			this->Label_Eff->TabIndex = 11;
			this->Label_Eff->Text = L"Эффективность";
			// 
			// Result
			// 
			this->Result->AutoSize = true;
			this->Result->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Result->Location = System::Drawing::Point(613, 388);
			this->Result->Name = L"Result";
			this->Result->Size = System::Drawing::Size(40, 46);
			this->Result->TabIndex = 12;
			this->Result->Text = L"0";
			// 
			// Eff
			// 
			this->Eff->AutoSize = true;
			this->Eff->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Eff->ForeColor = System::Drawing::Color::Red;
			this->Eff->Location = System::Drawing::Point(343, 428);
			this->Eff->Name = L"Eff";
			this->Eff->Size = System::Drawing::Size(40, 46);
			this->Eff->TabIndex = 13;
			this->Eff->Text = L"0";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(835, 75);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 42);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Заполнить таблицу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(835, 159);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(194, 42);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Вставить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(835, 236);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(194, 42);
			this->button3->TabIndex = 16;
			this->button3->Text = L"Удалить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(835, 336);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(194, 42);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Вывести таблицу";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1043, 651);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Eff);
			this->Controls->Add(this->Result);
			this->Controls->Add(this->Label_Eff);
			this->Controls->Add(this->ListOfTable);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->TmpKey);
			this->Controls->Add(this->CountKeys);
			this->Controls->Add(this->Size);
			this->Controls->Add(this->Label_Result);
			this->Controls->Add(this->Label_TmpKey);
			this->Controls->Add(this->Label_CountKeys);
			this->Controls->Add(this->Label_Size);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LabTables";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	

	private: Void initt() {
		Result->Text = "";
		Eff->Text = "";
	}
	private: System::Void Printtbl() {
		ListOfTable->Items->Clear();
		for (tbl->Reset(); !tbl->IsEnd(); tbl->GoNext()) {
			ListViewItem ^ tt = gcnew ListViewItem(gcnew String(std::to_string(tbl->GetKey()).c_str()), 0);
			tt->SubItems->Add(gcnew String(tbl->GetValue().c_str()));
			ListOfTable->Items->Add(tt);
		}
	}
	
	private: System::Void scntbl_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		if (this->scntbl->Checked == true) {
			this->scntbl->Checked = true;
			this->srttbl->Checked = false;
			this->blnctr->Checked = false;
			this->smpltr->Checked = false;
			this->arrhsh->Checked = false;
			this->lsthsh->Checked = false;
		}
	}
	private: System::Void srttbl_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		if (this->srttbl->Checked == true) {
			this->scntbl->Checked = false;
			this->srttbl->Checked = true;
			this->blnctr->Checked = false;
			this->smpltr->Checked = false;
			this->arrhsh->Checked = false;
			this->lsthsh->Checked = false;
		}
	}
	private: System::Void arrhsh_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		if (this->arrhsh->Checked == true) {
			this->scntbl->Checked = false;
			this->srttbl->Checked = false;
			this->blnctr->Checked = false;
			this->smpltr->Checked = false;
			this->arrhsh->Checked = true;
			this->lsthsh->Checked = false;
		}
	}
	private: System::Void lsthsh_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		if (this->lsthsh->Checked == true) {
			this->scntbl->Checked = false;
			this->srttbl->Checked = false;
			this->blnctr->Checked = false;
			this->smpltr->Checked = false;
			this->arrhsh->Checked = false;
			this->lsthsh->Checked = true;
		}
	}
	private: System::Void smpltr_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		if (this->smpltr->Checked == true) {
			this->scntbl->Checked = false;
			this->srttbl->Checked = false;
			this->blnctr->Checked = false;
			this->smpltr->Checked = true;
			this->arrhsh->Checked = false;
			this->lsthsh->Checked = false;
		}
	}
	private: System::Void blnctr_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		if (this->blnctr->Checked == true) {
			this->scntbl->Checked = false;
			this->srttbl->Checked = false;
			this->blnctr->Checked = true;
			this->smpltr->Checked = false;
			this->arrhsh->Checked = false;
			this->lsthsh->Checked = false;
		}
	}

	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		Eff->Text = "";
		if (this->CountKeys->Text == "") {
			Result->Text = "Задайте корректный диапозон ключей";
			return;
		}
		if (this->Size->Text == "") {
			Result->Text = "Задайте корректный размер";
			return;
		}
		delete tbl;
		int SizeMx = Convert::ToInt32(CountKeys->Text);
		
		if (this->scntbl->Checked)
			tbl = new TScanTable(SizeMx);
		else if (this->srttbl->Checked) {
			tbl = new TSortTable(SizeMx);
		}else if (this->arrhsh->Checked) {
			tbl = new TArrayHash(SizeMx), SizeMx *= 1000;
		}else if (this->lsthsh->Checked) {
			tbl = new TListHash(SizeMx), SizeMx *= 1000;
		}else if (this->smpltr->Checked) {
			tbl = new TTreeTable;
		}else if (this->blnctr->Checked) {
			tbl = new TBalTable;
		}else{
			this->scntbl->Checked = true;
			tbl = new TScanTable(SizeMx);
		}
		Int32 sz = Int32::Parse(this->Size->Text);
		Random rnd;
		int w;

		tbl->ClearEff();
		for (Int32 i = 0; i < sz; i++){
			w = rnd.Next();
			w %= SizeMx;
			if (!tbl->Insert(TRecord(w, "val" + std::to_string(w))))
				i--;
		}
		Eff->Text = gcnew String(std::to_string(tbl->GetEff()).c_str());
		Printtbl();
	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		Eff->Text = "";
		if (TmpKey->Text == "") {
			Result->Text = ("ВВедите ключ для вставки");
			return;
		}
		tbl->ClearEff();
		int num = Convert::ToInt32(TmpKey->Text);
		if (tbl->Insert(TRecord(num, "val" + std::to_string(num)))) {
			Result->Text = "Запись успешно добавлена";
			Eff->Text = gcnew String(std::to_string(tbl->GetEff()).c_str());
			Printtbl();
		}
		else {
			Result->Text = "Запись с таким ключом уже существует";
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		Eff->Text = "";
		if (TmpKey->Text == "") {
			Result->Text = ("ВВедите ключ для удаления");
			return;
		}
		tbl->ClearEff();
		int num = Convert::ToInt32(TmpKey->Text);
		if (tbl->Delete(num)) {
			Result->Text = "Запись успешно удалена";
			Eff->Text = gcnew String(std::to_string(tbl->GetEff()).c_str());
			Printtbl();
		}
		else {
			Result->Text = "Запись с таким ключом не существует";
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Result->Text = "";
		Eff->Text = ""; 
		std::ofstream fout("output.txt");
		tbl->PrintTbl(fout);
		fout.close();
	}
};
}
