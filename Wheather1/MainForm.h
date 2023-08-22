#pragma once
#include <iostream>
#include <curl/curl.h>
#include <msclr/marshal_cppstd.h>
#include <json/json.h>
#using <System.dll>
#using <System.Windows.Forms.dll>
#include <windows.h>


namespace Wheather1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
		size_t totalSize = size * nmemb;
		response->append((char*)contents, totalSize);
		return totalSize;
	}



	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();       
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::ListBox^ Favorite;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;




	private: System::ComponentModel::IContainer^ components;

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Favorite = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 50, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Location = System::Drawing::Point(61, 134);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label2->Size = System::Drawing::Size(402, 97);
			this->label2->TabIndex = 1;
			this->label2->Text = L"000";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(3, 231);
			this->label4->Name = L"label4";
			this->label4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label4->Size = System::Drawing::Size(0, 13);
			this->label4->TabIndex = 3;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(61, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(402, 42);
			this->textBox1->TabIndex = 4;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS PGothic", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Fuchsia;
			this->button1->Location = System::Drawing::Point(469, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(52, 42);
			this->button1->TabIndex = 5;
			this->button1->Text = L"🔎";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Fuchsia;
			this->button2->Location = System::Drawing::Point(3, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(52, 42);
			this->button2->TabIndex = 7;
			this->button2->Text = L"📍";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 300000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(682, 490);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(86, 64);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(585, 490);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(91, 64);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// Favorite
			// 
			this->Favorite->BackColor = System::Drawing::Color::White;
			this->Favorite->FormattingEnabled = true;
			this->Favorite->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Tokyo", L"London" });
			this->Favorite->Location = System::Drawing::Point(424, 12);
			this->Favorite->Name = L"Favorite";
			this->Favorite->Size = System::Drawing::Size(120, 95);
			this->Favorite->TabIndex = 10;
			this->Favorite->Visible = false;
			this->Favorite->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::Favorite_SelectedIndexChanged);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				70)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10)));
			this->tableLayoutPanel1->Controls->Add(this->button3, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->button2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button1, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label2, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::AddColumns;
			this->tableLayoutPanel1->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.4031F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.22222F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 15)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(584, 387);
			this->tableLayoutPanel1->TabIndex = 12;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::tableLayoutPanel1_Paint);
			// 
			// button3
			// 
			this->button3->AutoSize = true;
			this->button3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button3->Font = (gcnew System::Drawing::Font(L"Goudy Stout", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Fuchsia;
			this->button3->Location = System::Drawing::Point(527, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(54, 42);
			this->button3->TabIndex = 12;
			this->button3->Text = L"💗";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(68, 231);
			this->label3->Margin = System::Windows::Forms::Padding(10, 0, 3, 0);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(395, 97);
			this->label3->TabIndex = 2;
			this->label3->Text = L"First Name";
			this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 50, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(61, 48);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(402, 86);
			this->label1->TabIndex = 0;
			this->label1->Text = L"abcd";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(584, 387);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->Favorite);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"Weather on C++ ";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: float AdjustFontSize() {
		// Задайте начальный размер шрифта и начальную высоту окна
		int initialFontSize = 50; // Размер шрифта при стандартном размере окна
		int initialFormHeight = 400; // Высота окна при стандартном размере

		// Получите текущую высоту окна
		int currentFormHeight = this->ClientSize.Height;

		// Рассчитайте новый размер шрифта с использованием линейного соотношения
		float scaleFactor = static_cast<float>(currentFormHeight) / initialFormHeight;
		float newFontSize = initialFontSize * scaleFactor;

		return newFontSize;
	}

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		CURL* curl = curl_easy_init();


		std::string response;
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.seeip.org/jsonip?");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		CURLcode res = curl_easy_perform(curl);
		long responseCode;
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
		Json::Value root;
		Json::CharReaderBuilder reader;
		std::istringstream responseStream(response);
		std::string errs;
		Json::parseFromStream(reader, responseStream, &root, &errs);

		std::string str;
		str = "http://api.weatherapi.com/v1/current.json?key=8a33ca87160848debb2194051232706&q=" + root["ip"].asString();

		if (curl) {
			std::string response;
			curl_easy_setopt(curl, CURLOPT_URL, str.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
			CURLcode res = curl_easy_perform(curl);
			if (res == CURLE_OK) {
				long responseCode;
				curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
				Json::Value root;
				Json::CharReaderBuilder reader;
				std::istringstream responseStream(response);
				std::string errs;
				Json::parseFromStream(reader, responseStream, &root, &errs);
				//int temp = root["current"]["temp_c"].asInt();;
				//std::cout << "\nTemp: " << temp;
				std::string time = root["location"]["name"].asString();
				Label^ label1 = this->label1; // Replace "label1" with the actual name of your label control

				System::String^ newLabelText = gcnew System::String(time.c_str());

				label1->Text = newLabelText;

				int temp = root["current"]["temp_c"].asInt();

				Label^ label2 = this->label2; // Replace "label1" with the actual name of your label control

				System::String^ newLabelText2	 = gcnew System::String(temp.ToString()+"C°");

				label2->Text = newLabelText2;

				std::string lastUp = root["location"]["localtime"].asString();;

				Label^ label3 = this->label3; // Replace "label1" with the actual name of your label control

				System::String^ newLabelText3 = gcnew System::String(lastUp.c_str());

				label3->Text = newLabelText3;

				bool isDay =  root["current"]["is_day"].asBool();
				if (isDay) {
					this->BackgroundImage = pictureBox1->Image;

					label2->ForeColor = System::Drawing::Color::Black;
					label1->ForeColor = System::Drawing::Color::Black;
					label3->ForeColor = System::Drawing::Color::Black;
					label4->ForeColor = System::Drawing::Color::Black;

									
				}
				else
				{
					this->BackgroundImage = pictureBox2->Image;
					label1->ForeColor = System::Drawing::Color::White;
					label2->ForeColor = System::Drawing::Color::White;
					label3->ForeColor = System::Drawing::Color::White;
					label4->ForeColor = System::Drawing::Color::White;
					
				}


			}
			else {
				std::cout << "Request failed with error: " << curl_easy_strerror(res) << std::endl;
			}
			curl_easy_cleanup(curl);
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


			CURL* curl = curl_easy_init();


		
			TextBox^ textBox = this->textBox1; 

			
			std::string str = msclr::interop::marshal_as< std::string >(textBox->Text);
			str = "http://api.weatherapi.com/v1/current.json?key=8a33ca87160848debb2194051232706&q=" + str;

			if (curl) {
				std::string response;
				curl_easy_setopt(curl, CURLOPT_URL, str.c_str());
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
				CURLcode res = curl_easy_perform(curl);
				if (res == CURLE_OK) {
					long responseCode;
					curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
					Json::Value root;
					Json::CharReaderBuilder reader;
					std::istringstream responseStream(response);
					std::string errs;
					Json::parseFromStream(reader, responseStream, &root, &errs);
					std::string time = root["location"]["name"].asString();
					Label^ label1 = this->label1; // Replace "label1" with the actual name of your label control

					System::String^ newLabelText = gcnew System::String(time.c_str());

					label1->Text = newLabelText;

					int temp = root["current"]["temp_c"].asInt();

					Label^ label2 = this->label2; // Replace "label1" with the actual name of your label control

					System::String^ newLabelText2 = gcnew System::String(temp.ToString() + "C°");

					label2->Text = newLabelText2;

					std::string lastUp = root["current"]["last_updated"].asString();

					Label^ label3 = this->label3; // Replace "label1" with the actual name of your label control

					System::String^ newLabelText3 = gcnew System::String(lastUp.c_str());

					label3->Text = newLabelText3;

					bool isDay = root["current"]["is_day"].asBool();
					if (isDay) {
						this->BackgroundImage = pictureBox1->Image;

						label2->ForeColor = System::Drawing::Color::Black;
						label1->ForeColor = System::Drawing::Color::Black;
						label3->ForeColor = System::Drawing::Color::Black;
						label4->ForeColor = System::Drawing::Color::Black;


					}
					else
					{
						this->BackgroundImage = pictureBox2->Image;
						label1->ForeColor = System::Drawing::Color::White;
						label2->ForeColor = System::Drawing::Color::White;
						label3->ForeColor = System::Drawing::Color::White;
						label4->ForeColor = System::Drawing::Color::White;
					}


				}
				else {
					std::cout << "Request failed with error: " << curl_easy_strerror(res) << std::endl;
				}
				curl_easy_cleanup(curl);
			}

		
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MainForm_Load(sender, e);
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	MainForm_Load(sender, e);
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}




private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == (char)Keys::Enter) {
		// Perform the button's action here
		e->Handled = true;
		button1_Click(sender, e);

	}
}
private: System::Void Favorite_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e) {

	System::Drawing::Font^ currentFont = label1->Font;

	float fontSize = AdjustFontSize(); 
	System::Drawing::Font^ newFont = gcnew System::Drawing::Font(currentFont->FontFamily, fontSize, currentFont->Style);

	// Установим новый шрифт для метки.
	label1->Font = newFont;
	label2->Font = newFont;
	fontSize = AdjustFontSize()/4; 
	System::Drawing::Font^ newFont1 = gcnew System::Drawing::Font(currentFont->FontFamily, fontSize, currentFont->Style);

	label3->Font = newFont1;
}
};
}
