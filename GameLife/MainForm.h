#pragma once
#include "GameField.h"
#include"GameModel.h"

namespace WindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			fld = gcnew GameField(
				panel1->Width,
				panel1->Height,
				panel1->CreateGraphics()
			);
			openFileDialog1->Filter = "Text files(*.txt)|*.txt";
			saveFileDialog1->Filter = "Text files(*.txt)|*.txt";

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnNextStep;
	private: System::Windows::Forms::Button^  btnStop;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::Button^  btnColor;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label3;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnColor = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnNextStep = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(17, 16);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(831, 438);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel1_MouseClick);
			this->panel1->Resize += gcnew System::EventHandler(this, &MainForm::panel1_Resize);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->btnColor);
			this->groupBox1->Controls->Add(this->btnLoad);
			this->groupBox1->Controls->Add(this->btnSave);
			this->groupBox1->Controls->Add(this->btnNextStep);
			this->groupBox1->Controls->Add(this->btnStop);
			this->groupBox1->Controls->Add(this->btnStart);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Location = System::Drawing::Point(17, 462);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(831, 124);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление";
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(109, 74);
			this->trackBar1->Maximum = 2000;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(184, 56);
			this->trackBar1->TabIndex = 11;
			this->trackBar1->Value = 500;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &MainForm::trackBar1_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 17);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Скорость";
			// 
			// btnColor
			// 
			this->btnColor->Location = System::Drawing::Point(680, 21);
			this->btnColor->Name = L"btnColor";
			this->btnColor->Size = System::Drawing::Size(129, 67);
			this->btnColor->TabIndex = 9;
			this->btnColor->Text = L"Выбрать цвет";
			this->btnColor->UseVisualStyleBackColor = true;
			this->btnColor->Click += gcnew System::EventHandler(this, &MainForm::btnColor_Click);
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(301, 60);
			this->btnLoad->Margin = System::Windows::Forms::Padding(4);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(181, 28);
			this->btnLoad->TabIndex = 8;
			this->btnLoad->Text = L"Загрузить...";
			this->btnLoad->UseVisualStyleBackColor = true;
			this->btnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnLoad_Click_1);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(492, 60);
			this->btnSave->Margin = System::Windows::Forms::Padding(4);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(181, 28);
			this->btnSave->TabIndex = 7;
			this->btnSave->Text = L"Сохранить...";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click_1);
			// 
			// btnNextStep
			// 
			this->btnNextStep->Location = System::Drawing::Point(531, 21);
			this->btnNextStep->Margin = System::Windows::Forms::Padding(4);
			this->btnNextStep->Name = L"btnNextStep";
			this->btnNextStep->Size = System::Drawing::Size(141, 28);
			this->btnNextStep->TabIndex = 6;
			this->btnNextStep->Text = L"Следующий шаг";
			this->btnNextStep->UseVisualStyleBackColor = true;
			this->btnNextStep->Click += gcnew System::EventHandler(this, &MainForm::btnNextStep_Click);
			// 
			// btnStop
			// 
			this->btnStop->Enabled = false;
			this->btnStop->Location = System::Drawing::Point(416, 21);
			this->btnStop->Margin = System::Windows::Forms::Padding(4);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(100, 28);
			this->btnStop->TabIndex = 5;
			this->btnStop->Text = L"Стоп";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MainForm::btnStop_Click);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(301, 21);
			this->btnStart->Margin = System::Windows::Forms::Padding(4);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(100, 28);
			this->btnStart->TabIndex = 4;
			this->btnStart->Text = L"Старт";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainForm::btnStart_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 54);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Размер поля по вертикали";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 25);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(200, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Размер поля по горизонтали";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(221, 23);
			this->numericUpDown2->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(65, 22);
			this->numericUpDown2->TabIndex = 1;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown2_ValueChanged);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(221, 52);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(65, 22);
			this->numericUpDown1->TabIndex = 0;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MainForm::numericUpDown1_ValueChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(865, 585);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Игра \"Жизнь\"";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	GameField^ fld;
	Color c=Color::Red;
	String^ StringNumber(int a) 
	{
		if (a >= 100&&a<256) {

			return a.ToString();
		}
		else if (a >= 10 && a < 100) {
			return "0" + a.ToString();
		}
		else {
			return "00" + a.ToString();
		}
	}
	void SaveColor(Color ^c, String^ mas) 
	{
		
	    mas += StringNumber(c->A);
		mas += StringNumber(c->R);
		mas += StringNumber(c->G);
		mas += StringNumber(c->B);
		

	}
	

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		fld->Paint();
		fld->speed = (2000 - trackBar1->Value);
	}
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	int x = e->X;
	int y = e->Y;
 	fld->ChangeState(x, y,c);
}
private: System::Void btnNextStep_Click(System::Object^  sender, System::EventArgs^  e) {
	fld->NextGeneration();
}
private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
	numericUpDown1->Enabled = false;
	numericUpDown2->Enabled = false;
	btnLoad->Enabled = false;
	btnSave->Enabled = false;
	btnNextStep->Enabled = false;
	btnStop->Enabled = true;
	btnStart->Enabled = false;
	fld->StartLife();
}
private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) {
	numericUpDown1->Enabled =true;
	numericUpDown2->Enabled = true;
	btnLoad->Enabled = true;
	btnSave->Enabled = true;
	btnNextStep->Enabled = true;
	btnStop->Enabled = false;
	btnStart->Enabled = true;
	fld->StopLife();
}
private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	fld->StopLife();
}
private: System::Void panel1_Resize(System::Object^  sender, System::EventArgs^  e) {
	fld->Update(panel1->Width,panel1->Height,panel1->CreateGraphics());
}

private: System::Void btnLoad_Click_1(System::Object^  sender, System::EventArgs^  e) {
	try {
		openFileDialog1->ShowDialog();
		String^ fileText = System::IO::File::ReadAllText(openFileDialog1->FileName);
		int numA;
		int numR;
		int numG;
		int numB;
		int x = fileText->IndexOf('x');
		int y= fileText->LastIndexOf('x');
		int c= Int32::Parse(fileText->Substring(0, x));
		int r = Int32::Parse(fileText->Substring(x+1, y-x-1));
		fld->Cols = c;
		fld->Rows = r;
		numericUpDown1->Value = c;
		numericUpDown2->Value = r;
		int k = y+1;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				numA=Int32::Parse(fileText->Substring(k, 3));
				numR= Int32::Parse(fileText->Substring(k+3,3));
				numG = Int32::Parse(fileText->Substring(k + 6, 3));
				numB = Int32::Parse(fileText->Substring(k + 9, 3));
				fld->Field[i,j]= Color::FromArgb(numA, numR, numG, numB);//цвет образуется от трех параметров зеленый красныйй синий ,значения от 0-255 это интенс
				
				k = k + 12;
			}

		}
		fld->Paint();
	}
	catch (...) {
		MessageBox::Show("Не удалось считать");
	}
}
private: System::Void btnSave_Click_1(System::Object^  sender, System::EventArgs^  e) {
	try {
		saveFileDialog1->ShowDialog();
		String^ mas = "";
		mas = fld->Cols.ToString() +"x"+ fld->Rows.ToString()+"x";
		for (int i = 0; i < fld->Rows; i++)
		{
			for (int j = 0; j < fld->Cols; j++)
			{
				mas += StringNumber(fld->Field[i, j].A);
				mas += StringNumber(fld->Field[i, j].R);
				mas += StringNumber(fld->Field[i, j].G);
				mas += StringNumber(fld->Field[i, j].B);

				//SaveColor(fld->Field[i,j],mas);
			}

		}
		
		System::IO::File::WriteAllText(saveFileDialog1->FileName, mas);
		MessageBox::Show("Файл сохранен");
	}
	catch (...) {
		MessageBox::Show("Не удалось сохранить");
	}
}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	
	fld->StopLife();

	fld = gcnew GameField(Int32(numericUpDown1->Value), Int32(numericUpDown2->Value), panel1->Width, panel1->Height, panel1->CreateGraphics());
	fld->Paint();
	fld->speed = (2000 - trackBar1->Value);
}
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	
	fld->StopLife();

	fld = gcnew GameField(Int32(numericUpDown1->Value), Int32(numericUpDown2->Value), panel1->Width, panel1->Height, panel1->CreateGraphics());
	fld->Paint();
	fld->speed = (2000 - trackBar1->Value);
}
private: System::Void btnColor_Click(System::Object^  sender, System::EventArgs^  e) {
	colorDialog1->ShowDialog();
	c = colorDialog1->Color;
	

}
private: System::Void trackBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	fld->speed = (2000 - trackBar1->Value);
}
};
}
