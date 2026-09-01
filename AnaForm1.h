#pragma once
#include "RandevuDugum.h"
#using <System.Data.dll>
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;


namespace medtrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// AnaForm1 için özet
	/// </summary>
	public ref class AnaForm1 : public System::Windows::Forms::Form
	{
	private:
	private: System::Void veritabanindanRandevulariYukle()
	{

		SqlConnection^ baglanti =
			gcnew SqlConnection(
				connectionString
			);
		try {

			baglanti->Open();


			String^ sorgu =
				"SELECT "
				"randevu_no, hasta_adi, doktor_adi, "
				"bolum, tarih, saat, durum "
				"FROM dbo.cpp_randevular "
				"ORDER BY "
				"tarih ASC, "
				"TRY_CONVERT(time(0), REPLACE(saat, '.', ':')) ASC, "
				"id ASC";


			SqlCommand^ komut =
				gcnew SqlCommand(
					sorgu,
					baglanti
				);


			SqlDataReader^ okuyucu =
				komut->ExecuteReader();


			// ÖNCE LINKED LIST'Ý TEMÝZLE
			bas =
				nullptr;


			while (okuyucu->Read()) {

				DateTime tarih =
					safe_cast<DateTime>(
						okuyucu["tarih"]
						);


				RandevuDugum^ yeniRandevu =
					gcnew RandevuDugum(
						okuyucu["randevu_no"]->ToString(),
						okuyucu["hasta_adi"]->ToString(),
						okuyucu["doktor_adi"]->ToString(),
						okuyucu["bolum"]->ToString(),
						tarih.ToString("dd.MM.yyyy"),
						okuyucu["saat"]->ToString()
					);


				yeniRandevu->durum =
					okuyucu["durum"]->ToString();


				randevuSonaEkle(
					yeniRandevu
				);
			}


			okuyucu->Close();

			baglanti->Close();


			// LINKED LIST'TEKÝ KAYITLARI TABLOYA YANSIT
			tabloyuYenile();
		}
		catch (SqlException^ ex) {

			if (
				baglanti->State ==
				ConnectionState::Open
				) {

				baglanti->Close();
			}


			MessageBox::Show(
				String::Concat(
					L"Randevular yüklenirken veritabaný hatasý oluþtu:\n",
					ex->Message
				),
				L"Hata",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}
		String^ connectionString =
			"Data Source=(localdb)\\MSSQLLocalDB;"
			"Initial Catalog=MedTrackDB;"
			"Integrated Security=True;"
			"TrustServerCertificate=True;";
		RandevuDugum^ bas = nullptr;
	public:
		AnaForm1(void)
		{
			InitializeComponent();

			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~AnaForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblBaslik;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ lblAciklama;
	private: System::Windows::Forms::Panel^ pnlRandevuFormu;
	private: System::Windows::Forms::Label^ lblFormBaslik;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label;

	private: System::Windows::Forms::TextBox^ txtHastaAdi;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtRandevuNo;
	private: System::Windows::Forms::TextBox^ txtDoktorAdi;
	private: System::Windows::Forms::ComboBox^ cmbBolum;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ dtpTarih;

	private: System::Windows::Forms::TextBox^ txtSaat;
	private: System::Windows::Forms::DataGridView^ dgvRandevular;
	private: System::Windows::Forms::Button^ btnRandevuAra;
	private: System::Windows::Forms::Button^ btnSiradakiHasta;
	private: System::Windows::Forms::Button^ btnRandevuEkle;

	private: System::Windows::Forms::Button^ btnRandevuIptal;
	private: System::Windows::Forms::Button^ btnRandevuSil;
	private: System::Windows::Forms::Label^ label6;



	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblBaslik = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnRandevuSil = (gcnew System::Windows::Forms::Button());
			this->txtSaat = (gcnew System::Windows::Forms::TextBox());
			this->btnRandevuIptal = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnRandevuEkle = (gcnew System::Windows::Forms::Button());
			this->dtpTarih = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnSiradakiHasta = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnRandevuAra = (gcnew System::Windows::Forms::Button());
			this->cmbBolum = (gcnew System::Windows::Forms::ComboBox());
			this->dgvRandevular = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtDoktorAdi = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtRandevuNo = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->txtHastaAdi = (gcnew System::Windows::Forms::TextBox());
			this->pnlRandevuFormu = (gcnew System::Windows::Forms::Panel());
			this->lblFormBaslik = (gcnew System::Windows::Forms::Label());
			this->lblAciklama = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRandevular))->BeginInit();
			this->pnlRandevuFormu->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblBaslik
			// 
			this->lblBaslik->AutoSize = true;
			this->lblBaslik->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->lblBaslik->Location = System::Drawing::Point(379, 9);
			this->lblBaslik->Name = L"lblBaslik";
			this->lblBaslik->Size = System::Drawing::Size(551, 41);
			this->lblBaslik->TabIndex = 0;
			this->lblBaslik->Text = L"MEDTRACK RANDEVU TAKÝP SÝSTEMÝ";
			// 
			// panel1
			// 
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->BackColor = System::Drawing::Color::AliceBlue;
			this->panel1->Controls->Add(this->btnRandevuSil);
			this->panel1->Controls->Add(this->txtSaat);
			this->panel1->Controls->Add(this->btnRandevuIptal);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->btnRandevuEkle);
			this->panel1->Controls->Add(this->dtpTarih);
			this->panel1->Controls->Add(this->btnSiradakiHasta);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->btnRandevuAra);
			this->panel1->Controls->Add(this->cmbBolum);
			this->panel1->Controls->Add(this->dgvRandevular);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->txtDoktorAdi);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->txtRandevuNo);
			this->panel1->Controls->Add(this->label);
			this->panel1->Controls->Add(this->txtHastaAdi);
			this->panel1->Controls->Add(this->pnlRandevuFormu);
			this->panel1->Controls->Add(this->lblAciklama);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(-18, 53);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1313, 678);
			this->panel1->TabIndex = 1;
			// 
			// btnRandevuSil
			// 
			this->btnRandevuSil->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->btnRandevuSil->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnRandevuSil->ForeColor = System::Drawing::Color::Indigo;
			this->btnRandevuSil->Location = System::Drawing::Point(875, 169);
			this->btnRandevuSil->Name = L"btnRandevuSil";
			this->btnRandevuSil->Size = System::Drawing::Size(322, 35);
			this->btnRandevuSil->TabIndex = 17;
			this->btnRandevuSil->Text = L"Randevuyu Sil";
			this->btnRandevuSil->UseVisualStyleBackColor = false;
			this->btnRandevuSil->Click += gcnew System::EventHandler(this, &AnaForm1::btnRandevuSil_Click);
			// 
			// txtSaat
			// 
			this->txtSaat->Location = System::Drawing::Point(308, 340);
			this->txtSaat->Name = L"txtSaat";
			this->txtSaat->Size = System::Drawing::Size(133, 22);
			this->txtSaat->TabIndex = 11;
			this->txtSaat->Text = L"09.00";
			// 
			// btnRandevuIptal
			// 
			this->btnRandevuIptal->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->btnRandevuIptal->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnRandevuIptal->ForeColor = System::Drawing::Color::Indigo;
			this->btnRandevuIptal->Location = System::Drawing::Point(875, 218);
			this->btnRandevuIptal->Name = L"btnRandevuIptal";
			this->btnRandevuIptal->Size = System::Drawing::Size(322, 43);
			this->btnRandevuIptal->TabIndex = 16;
			this->btnRandevuIptal->Text = L"Randevuyu Ýptal Et";
			this->btnRandevuIptal->UseVisualStyleBackColor = false;
			this->btnRandevuIptal->Click += gcnew System::EventHandler(this, &AnaForm1::btnRandevuIptal_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(121, 333);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(159, 29);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Randevu Saati:";
			// 
			// btnRandevuEkle
			// 
			this->btnRandevuEkle->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->btnRandevuEkle->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnRandevuEkle->ForeColor = System::Drawing::Color::Indigo;
			this->btnRandevuEkle->Location = System::Drawing::Point(875, 69);
			this->btnRandevuEkle->Name = L"btnRandevuEkle";
			this->btnRandevuEkle->Size = System::Drawing::Size(322, 40);
			this->btnRandevuEkle->TabIndex = 15;
			this->btnRandevuEkle->Text = L"Randevu Ekle";
			this->btnRandevuEkle->UseVisualStyleBackColor = false;
			this->btnRandevuEkle->Click += gcnew System::EventHandler(this, &AnaForm1::btnRandevuEkle_Click);
			// 
			// dtpTarih
			// 
			this->dtpTarih->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpTarih->Location = System::Drawing::Point(308, 301);
			this->dtpTarih->Name = L"dtpTarih";
			this->dtpTarih->Size = System::Drawing::Size(200, 22);
			this->dtpTarih->TabIndex = 2;
			this->dtpTarih->ValueChanged += gcnew System::EventHandler(this, &AnaForm1::dtpTarih_ValueChanged);
			// 
			// btnSiradakiHasta
			// 
			this->btnSiradakiHasta->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->btnSiradakiHasta->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnSiradakiHasta->ForeColor = System::Drawing::Color::Indigo;
			this->btnSiradakiHasta->Location = System::Drawing::Point(875, 267);
			this->btnSiradakiHasta->Name = L"btnSiradakiHasta";
			this->btnSiradakiHasta->Size = System::Drawing::Size(322, 40);
			this->btnSiradakiHasta->TabIndex = 14;
			this->btnSiradakiHasta->Text = L"Sýradaki Hastayý Çaðýr";
			this->btnSiradakiHasta->UseVisualStyleBackColor = false;
			this->btnSiradakiHasta->Click += gcnew System::EventHandler(this, &AnaForm1::btnSiradakiHasta_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(121, 296);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(167, 29);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Randevu Tarihi:";
			// 
			// btnRandevuAra
			// 
			this->btnRandevuAra->BackColor = System::Drawing::Color::BlanchedAlmond;
			this->btnRandevuAra->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->btnRandevuAra->ForeColor = System::Drawing::Color::Indigo;
			this->btnRandevuAra->Location = System::Drawing::Point(875, 115);
			this->btnRandevuAra->Name = L"btnRandevuAra";
			this->btnRandevuAra->Size = System::Drawing::Size(322, 40);
			this->btnRandevuAra->TabIndex = 13;
			this->btnRandevuAra->Text = L"Randevu Ara";
			this->btnRandevuAra->UseVisualStyleBackColor = false;
			this->btnRandevuAra->Click += gcnew System::EventHandler(this, &AnaForm1::btnRandevuAra_Click);
			// 
			// cmbBolum
			// 
			this->cmbBolum->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBolum->FormattingEnabled = true;
			this->cmbBolum->Location = System::Drawing::Point(338, 266);
			this->cmbBolum->Name = L"cmbBolum";
			this->cmbBolum->Size = System::Drawing::Size(121, 24);
			this->cmbBolum->TabIndex = 9;
			// 
			// dgvRandevular
			// 
			this->dgvRandevular->AllowUserToAddRows = false;
			this->dgvRandevular->AllowUserToDeleteRows = false;
			this->dgvRandevular->BackgroundColor = System::Drawing::Color::AliceBlue;
			this->dgvRandevular->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvRandevular->Location = System::Drawing::Point(126, 383);
			this->dgvRandevular->MultiSelect = false;
			this->dgvRandevular->Name = L"dgvRandevular";
			this->dgvRandevular->ReadOnly = true;
			this->dgvRandevular->RowHeadersWidth = 51;
			this->dgvRandevular->RowTemplate->Height = 24;
			this->dgvRandevular->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRandevular->Size = System::Drawing::Size(1071, 228);
			this->dgvRandevular->TabIndex = 2;
			this->dgvRandevular->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AnaForm1::dgvRandevular_CellClick);
			this->dgvRandevular->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AnaForm1::dgvRandevular_CellContentClick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(121, 261);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(173, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Hastane  Bölümü";
			// 
			// txtDoktorAdi
			// 
			this->txtDoktorAdi->Location = System::Drawing::Point(352, 231);
			this->txtDoktorAdi->Name = L"txtDoktorAdi";
			this->txtDoktorAdi->Size = System::Drawing::Size(133, 22);
			this->txtDoktorAdi->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(121, 224);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(204, 29);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Doktor Adý Soyadý:";
			// 
			// txtRandevuNo
			// 
			this->txtRandevuNo->Location = System::Drawing::Point(352, 186);
			this->txtRandevuNo->Name = L"txtRandevuNo";
			this->txtRandevuNo->Size = System::Drawing::Size(133, 22);
			this->txtRandevuNo->TabIndex = 7;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label->Location = System::Drawing::Point(121, 186);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(198, 29);
			this->label->TabIndex = 5;
			this->label->Text = L"Randevu Numarasý:";
			// 
			// txtHastaAdi
			// 
			this->txtHastaAdi->Location = System::Drawing::Point(352, 152);
			this->txtHastaAdi->Name = L"txtHastaAdi";
			this->txtHastaAdi->Size = System::Drawing::Size(133, 22);
			this->txtHastaAdi->TabIndex = 6;
			this->txtHastaAdi->TextChanged += gcnew System::EventHandler(this, &AnaForm1::txtHastaAdi_TextChanged);
			// 
			// pnlRandevuFormu
			// 
			this->pnlRandevuFormu->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->pnlRandevuFormu->Controls->Add(this->lblFormBaslik);
			this->pnlRandevuFormu->Location = System::Drawing::Point(126, 55);
			this->pnlRandevuFormu->Name = L"pnlRandevuFormu";
			this->pnlRandevuFormu->Size = System::Drawing::Size(359, 54);
			this->pnlRandevuFormu->TabIndex = 2;
			// 
			// lblFormBaslik
			// 
			this->lblFormBaslik->AutoSize = true;
			this->lblFormBaslik->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblFormBaslik->ForeColor = System::Drawing::SystemColors::MenuText;
			this->lblFormBaslik->Location = System::Drawing::Point(65, 15);
			this->lblFormBaslik->Name = L"lblFormBaslik";
			this->lblFormBaslik->Size = System::Drawing::Size(224, 25);
			this->lblFormBaslik->TabIndex = 3;
			this->lblFormBaslik->Text = L"Yeni Randevu Oluþtur";
			// 
			// lblAciklama
			// 
			this->lblAciklama->AutoSize = true;
			this->lblAciklama->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAciklama->ForeColor = System::Drawing::SystemColors::InfoText;
			this->lblAciklama->Location = System::Drawing::Point(429, 10);
			this->lblAciklama->Name = L"lblAciklama";
			this->lblAciklama->Size = System::Drawing::Size(433, 25);
			this->lblAciklama->TabIndex = 1;
			this->lblAciklama->Text = L"Hasta randevularýný görüntüleyin ve yönetin.";
			this->lblAciklama->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(121, 145);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(224, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Hasta Adý ve Soyadý:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1326, 82);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 16);
			this->label6->TabIndex = 18;
			this->label6->Click += gcnew System::EventHandler(this, &AnaForm1::label6_Click);
			// 
			// AnaForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1384, 764);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->lblBaslik);
			this->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->Name = L"AnaForm1";
			this->Text = L"MEDTRACK-PANEL";
			this->Load += gcnew System::EventHandler(this, &AnaForm1::AnaForm1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRandevular))->EndInit();
			this->pnlRandevuFormu->ResumeLayout(false);
			this->pnlRandevuFormu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txtHastaAdi_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void AnaForm1_Load(
	System::Object^ sender,
	System::EventArgs^ e
) {

	cmbBolum->Items->Add(L"Dahiliye");
	cmbBolum->Items->Add(L"Kardiyoloji");
	cmbBolum->Items->Add(L"Ortopedi");
	cmbBolum->Items->Add(L"Göz Hastalýklarý");
	cmbBolum->Items->Add(L"KBB");
	cmbBolum->Items->Add(L"Çocuk Hastalýklarý");


	dgvRandevular->Columns->Add(
		L"RandevuNo",
		L"Randevu No"
	);

	dgvRandevular->Columns->Add(
		L"HastaAdi",
		L"Hasta Adý"
	);

	dgvRandevular->Columns->Add(
		L"DoktorAdi",
		L"Doktor"
	);

	dgvRandevular->Columns->Add(
		L"Bolum",
		L"Bölüm"
	);

	dgvRandevular->Columns->Add(
		L"Tarih",
		L"Tarih"
	);

	dgvRandevular->Columns->Add(
		L"Saat",
		L"Saat"
	);

	dgvRandevular->Columns->Add(
		L"Durum",
		L"Durum"
	);


	// SÜTUNLAR OLUÞTUKTAN SONRA
	// VERÝTABANINDAKÝ RANDEVULARI YÜKLE
	veritabanindanRandevulariYukle();
}
private: System::Void btnRandevuEkle_Click(
	System::Object^ sender,
	System::EventArgs^ e
) {

	// BOÞ ALAN KONTROLÜ
	if (
		txtHastaAdi->Text->Trim() == "" ||
		txtRandevuNo->Text->Trim() == "" ||
		txtDoktorAdi->Text->Trim() == "" ||
		cmbBolum->SelectedIndex == -1 ||
		txtSaat->Text->Trim() == ""
		) {

		MessageBox::Show(
			L"Lütfen tüm alanlarý doldurunuz.",
			L"Uyarý",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		return;
	}


	// LINKED LIST ÝÇÝNDE AYNI RANDEVU NO VAR MI?
	RandevuDugum^ mevcut = bas;

	while (mevcut != nullptr) {

		if (
			mevcut->randevuNo ==
			txtRandevuNo->Text->Trim()
			) {

			MessageBox::Show(
				L"Bu randevu numarasý zaten kullanýlýyor.",
				L"Uyarý",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			return;
		}

		mevcut = mevcut->sonraki;
	}


	// SQL SERVER BAÐLANTISI
	SqlConnection^ baglanti =
		gcnew SqlConnection(
			connectionString
		);


	String^ sorgu =
		"INSERT INTO dbo.cpp_randevular "
		"(randevu_no, hasta_adi, doktor_adi, "
		"bolum, tarih, saat, durum) "
		"VALUES "
		"(@randevu_no, @hasta_adi, @doktor_adi, "
		"@bolum, @tarih, @saat, @durum)";


	SqlCommand^ komut =
		gcnew SqlCommand(
			sorgu,
			baglanti
		);


	komut->Parameters->Add(
		"@randevu_no",
		SqlDbType::NVarChar,
		20
	)->Value =
		txtRandevuNo->Text->Trim();


	komut->Parameters->Add(
		"@hasta_adi",
		SqlDbType::NVarChar,
		100
	)->Value =
		txtHastaAdi->Text->Trim();


	komut->Parameters->Add(
		"@doktor_adi",
		SqlDbType::NVarChar,
		100
	)->Value =
		txtDoktorAdi->Text->Trim();


	komut->Parameters->Add(
		"@bolum",
		SqlDbType::NVarChar,
		100
	)->Value =
		cmbBolum->SelectedItem->ToString();


	komut->Parameters->Add(
		"@tarih",
		SqlDbType::Date
	)->Value =
		dtpTarih->Value.Date;


	komut->Parameters->Add(
		"@saat",
		SqlDbType::NVarChar,
		10
	)->Value =
		txtSaat->Text->Trim();


	komut->Parameters->Add(
		"@durum",
		SqlDbType::NVarChar,
		30
	)->Value =
		L"Aktif";


	try {

		baglanti->Open();

		komut->ExecuteNonQuery();

	}
	catch (SqlException^ ex) {

		// 2601 ve 2627: Ayný randevu numarasý
		if (
			ex->Number == 2601 ||
			ex->Number == 2627
			) {

			MessageBox::Show(
				L"Bu randevu numarasý veritabanýnda zaten bulunuyor.",
				L"Uyarý",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

		}
		else {

			MessageBox::Show(
				L"Veritabaný hatasý:\n" +
				ex->Message,
				L"Hata",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}

		return;
	}
	finally {

		if (
			baglanti->State ==
			ConnectionState::Open
			) {

			baglanti->Close();
		}
	}


	// LINKED LIST'E EKLE
	RandevuDugum^ yeniRandevu =
		gcnew RandevuDugum(
			txtRandevuNo->Text->Trim(),
			txtHastaAdi->Text->Trim(),
			txtDoktorAdi->Text->Trim(),
			cmbBolum->SelectedItem->ToString(),
			dtpTarih->Value.ToShortDateString(),
			txtSaat->Text->Trim()
		);


	randevuSonaEkle(
		yeniRandevu
	);


	tabloyuYenile();


	MessageBox::Show(
		L"Randevu veritabanýna baþarýyla kaydedildi.",
		L"Bilgi",
		MessageBoxButtons::OK,
		MessageBoxIcon::Information
	);


	// FORMU TEMÝZLE
	txtHastaAdi->Clear();
	txtRandevuNo->Clear();
	txtDoktorAdi->Clear();

	cmbBolum->SelectedIndex = -1;

	dtpTarih->Value =
		DateTime::Today;

	txtSaat->Clear();

	txtRandevuNo->Focus();
}
private: System::Void btnRandevuAra_Click(
	System::Object^ sender,
	System::EventArgs^ e
) {

	String^ randevuNo =
		txtRandevuNo->Text->Trim();


	if (randevuNo == "") {

		MessageBox::Show(
			L"Lütfen aranacak randevu numarasýný yazýnýz.",
			L"Uyarý",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		txtRandevuNo->Focus();

		return;
	}


	SqlConnection^ baglanti =
		gcnew SqlConnection(
			connectionString
		);


	String^ sorgu =
		"SELECT "
		"randevu_no, hasta_adi, doktor_adi, "
		"bolum, tarih, saat, durum "
		"FROM dbo.cpp_randevular "
		"WHERE randevu_no = @randevu_no";


	SqlCommand^ komut =
		gcnew SqlCommand(
			sorgu,
			baglanti
		);


	komut->Parameters->Add(
		"@randevu_no",
		SqlDbType::NVarChar,
		20
	)->Value =
		randevuNo;


	try {

		baglanti->Open();

		SqlDataReader^ okuyucu =
			komut->ExecuteReader();


		if (okuyucu->Read()) {

			txtHastaAdi->Text =
				okuyucu["hasta_adi"]->ToString();

			txtDoktorAdi->Text =
				okuyucu["doktor_adi"]->ToString();


			String^ bolum =
				okuyucu["bolum"]->ToString();

			int bolumIndex =
				cmbBolum->FindStringExact(
					bolum
				);

			if (bolumIndex >= 0) {

				cmbBolum->SelectedIndex =
					bolumIndex;
			}


			dtpTarih->Value =
				safe_cast<DateTime>(
					okuyucu["tarih"]
				);


			txtSaat->Text =
				okuyucu["saat"]->ToString();


			MessageBox::Show(
				L"Randevu veritabanýnda bulundu.",
				L"Bilgi",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

		}
		else {

			MessageBox::Show(
				L"Bu numaraya ait randevu veritabanýnda bulunamadý.",
				L"Bilgi",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}


		okuyucu->Close();

		baglanti->Close();
	}
	catch (SqlException^ ex) {

		if (
			baglanti->State ==
			ConnectionState::Open
			) {

			baglanti->Close();
		}


		MessageBox::Show(
			String::Concat(
				L"Veritabaný hatasý:\n",
				ex->Message
			),
			L"Hata",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
private: System::Void btnRandevuSil_Click(
	System::Object^ sender,
	System::EventArgs^ e
) {

	String^ randevuNo =
		txtRandevuNo->Text->Trim();


	if (randevuNo == "") {

		MessageBox::Show(
			L"Lütfen silinecek randevu numarasýný yazýnýz.",
			L"Uyarý",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		txtRandevuNo->Focus();

		return;
	}


	System::Windows::Forms::DialogResult cevap =
		MessageBox::Show(
			L"Bu randevuyu silmek istediðinize emin misiniz?",
			L"Silme Onayý",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);


	if (
		cevap !=
		System::Windows::Forms::DialogResult::Yes
		) {

		return;
	}


	SqlConnection^ baglanti =
		gcnew SqlConnection(
			connectionString
		);


	String^ sorgu =
		"DELETE FROM dbo.cpp_randevular "
		"WHERE randevu_no = @randevu_no";


	SqlCommand^ komut =
		gcnew SqlCommand(
			sorgu,
			baglanti
		);


	komut->Parameters->Add(
		"@randevu_no",
		SqlDbType::NVarChar,
		20
	)->Value =
		randevuNo;


	try {

		baglanti->Open();

		int silinenSatir =
			komut->ExecuteNonQuery();

		baglanti->Close();


		if (silinenSatir == 0) {

			MessageBox::Show(
				L"Bu numaraya ait randevu veritabanýnda bulunamadý.",
				L"Bilgi",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			return;
		}


		// LINKED LIST'TEN DE SÝL
		RandevuDugum^ mevcut =
			bas;

		RandevuDugum^ onceki =
			nullptr;

		while (mevcut != nullptr) {

			if (
				mevcut->randevuNo ==
				randevuNo
				) {

				if (onceki == nullptr) {

					bas =
						mevcut->sonraki;

				}
				else {

					onceki->sonraki =
						mevcut->sonraki;}
				break;}
			onceki =
				mevcut;

			mevcut =
				mevcut->sonraki;}
		tabloyuYenile();

		MessageBox::Show(
			L"Randevu veritabanýndan baþarýyla silindi.",
			L"Bilgi",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);


		// FORM ALANLARINI TEMÝZLE
		txtHastaAdi->Clear();
		txtRandevuNo->Clear();
		txtDoktorAdi->Clear();

		cmbBolum->SelectedIndex = -1;

		dtpTarih->Value =
			DateTime::Today;

		txtSaat->Clear();

		txtRandevuNo->Focus();
	}
	catch (SqlException^ ex) {

		if (
			baglanti->State ==
			ConnectionState::Open
			) {

			baglanti->Close();
		}


		MessageBox::Show(
			String::Concat(
				L"Veritabaný hatasý:\n",
				ex->Message
			),
			L"Hata",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
private: System::Void btnRandevuIptal_Click(
	System::Object^ sender,
	System::EventArgs^ e
) {

	String^ iptalNo =
		txtRandevuNo->Text->Trim();


	if (iptalNo == "") {

		MessageBox::Show(
			L"Lütfen iptal edilecek randevu numarasýný giriniz.",
			L"Uyarý",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		txtRandevuNo->Focus();

		return;
	}


	SqlConnection^ baglanti =
		gcnew SqlConnection(
			connectionString
		);


	try {

		baglanti->Open();


		// RANDEVU VERÝTABANINDA VAR MI?
		String^ kontrolSorgusu =
			"SELECT durum "
			"FROM dbo.cpp_randevular "
			"WHERE randevu_no = @randevu_no";


		SqlCommand^ kontrolKomutu =
			gcnew SqlCommand(
				kontrolSorgusu,
				baglanti
			);


		kontrolKomutu->Parameters->Add(
			"@randevu_no",
			SqlDbType::NVarChar,
			20
		)->Value =
			iptalNo;


		Object^ sonuc =
			kontrolKomutu->ExecuteScalar();


		if (
			sonuc == nullptr ||
			sonuc == DBNull::Value
			) {

			baglanti->Close();

			MessageBox::Show(
				L"Bu numaraya ait randevu veritabanýnda bulunamadý.",
				L"Bilgi",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			return;
		}


		String^ mevcutDurum =
			sonuc->ToString();


		if (
			mevcutDurum ==
			L"Ýptal Edildi"
			) {

			baglanti->Close();

			MessageBox::Show(
				L"Bu randevu zaten iptal edilmiþ.",
				L"Bilgi",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			return;
		}


		auto cevap =
			MessageBox::Show(
				L"Bu randevuyu iptal etmek istediðinize emin misiniz?",
				L"Randevu Ýptal",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);


		if (
			cevap !=
			System::Windows::Forms::DialogResult::Yes
			) {

			baglanti->Close();

			return;
		}


		// VERÝTABANINDA DURUMU GÜNCELLE
		String^ guncellemeSorgusu =
			"UPDATE dbo.cpp_randevular "
			"SET durum = @durum "
			"WHERE randevu_no = @randevu_no";


		SqlCommand^ guncellemeKomutu =
			gcnew SqlCommand(
				guncellemeSorgusu,
				baglanti
			);


		guncellemeKomutu->Parameters->Add(
			"@durum",
			SqlDbType::NVarChar,
			30
		)->Value =
			L"Ýptal Edildi";


		guncellemeKomutu->Parameters->Add(
			"@randevu_no",
			SqlDbType::NVarChar,
			20
		)->Value =
			iptalNo;


		guncellemeKomutu->ExecuteNonQuery();

		baglanti->Close();


		// LINKED LIST'TEKÝ DURUMU DA GÜNCELLE
		RandevuDugum^ mevcut =
			bas;


		while (mevcut != nullptr) {

			if (
				mevcut->randevuNo ==
				iptalNo
				) {

				mevcut->durum =
					L"Ýptal Edildi";

				break;
			}


			mevcut =
				mevcut->sonraki;
		}


		tabloyuYenile();


		MessageBox::Show(
			L"Randevu veritabaný üzerinden iptal edildi.",
			L"Bilgi",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	}
	catch (SqlException^ ex) {

		if (
			baglanti->State ==
			ConnectionState::Open
			) {

			baglanti->Close();
		}


		MessageBox::Show(
			String::Concat(
				L"Veritabaný hatasý:\n",
				ex->Message
			),
			L"Hata",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
private: System::Void btnSiradakiHasta_Click(
	System::Object^ sender,
	System::EventArgs^ e
) {

	SqlConnection^ baglanti =
		gcnew SqlConnection(
			connectionString
		);


	try {

		baglanti->Open();


		// TARÝH VE SAATE GÖRE ÝLK AKTÝF RANDEVUYU BUL
		String^ sorgu =
			"SELECT TOP 1 "
			"randevu_no, hasta_adi, doktor_adi, "
			"bolum, tarih, saat "
			"FROM dbo.cpp_randevular "
			"WHERE durum = @durum "
			"ORDER BY "
			"tarih ASC, "
			"TRY_CONVERT(time(0), REPLACE(saat, '.', ':')) ASC, "
			"id ASC";


		SqlCommand^ komut =
			gcnew SqlCommand(
				sorgu,
				baglanti
			);


		komut->Parameters->Add(
			"@durum",
			SqlDbType::NVarChar,
			30
		)->Value =
			L"Aktif";


		SqlDataReader^ okuyucu =
			komut->ExecuteReader();


		if (!okuyucu->Read()) {

			okuyucu->Close();
			baglanti->Close();

			MessageBox::Show(
				L"Bekleyen aktif randevu bulunmamaktadýr.",
				L"Bilgi",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			return;
		}


		// VERÝTABANINDAN GELEN BÝLGÝLER
		String^ randevuNo =
			okuyucu["randevu_no"]->ToString();

		String^ hastaAdi =
			okuyucu["hasta_adi"]->ToString();

		String^ doktorAdi =
			okuyucu["doktor_adi"]->ToString();

		String^ bolum =
			okuyucu["bolum"]->ToString();

		DateTime tarih =
			safe_cast<DateTime>(
				okuyucu["tarih"]
				);

		String^ saat =
			okuyucu["saat"]->ToString();


		okuyucu->Close();


		// VERÝTABANINDA DURUMU ÇAÐRILDI YAP
		String^ guncellemeSorgusu =
			"UPDATE dbo.cpp_randevular "
			"SET durum = @yeni_durum "
			"WHERE randevu_no = @randevu_no";


		SqlCommand^ guncellemeKomutu =
			gcnew SqlCommand(
				guncellemeSorgusu,
				baglanti
			);


		guncellemeKomutu->Parameters->Add(
			"@yeni_durum",
			SqlDbType::NVarChar,
			30
		)->Value =
			L"Çaðrýldý";


		guncellemeKomutu->Parameters->Add(
			"@randevu_no",
			SqlDbType::NVarChar,
			20
		)->Value =
			randevuNo;


		guncellemeKomutu->ExecuteNonQuery();

		baglanti->Close();


		// LINKED LIST'TEKÝ KAYDI DA GÜNCELLE
		RandevuDugum^ mevcut =
			bas;


		while (mevcut != nullptr) {

			if (
				mevcut->randevuNo ==
				randevuNo
				) {

				mevcut->durum =
					L"Çaðrýldý";

				break;
			}


			mevcut =
				mevcut->sonraki;
		}


		// HASTA BÝLGÝLERÝNÝ FORMA GETÝR
		txtRandevuNo->Text =
			randevuNo;

		txtHastaAdi->Text =
			hastaAdi;

		txtDoktorAdi->Text =
			doktorAdi;


		int bolumIndex =
			cmbBolum->FindStringExact(
				bolum
			);

		if (bolumIndex >= 0) {

			cmbBolum->SelectedIndex =
				bolumIndex;
		}


		dtpTarih->Value =
			tarih;

		txtSaat->Text =
			saat;


		tabloyuYenile();


		// TABLODA ÇAÐRILAN HASTAYI SEÇ
		for (
			int i = 0;
			i < dgvRandevular->Rows->Count;
			i++
			) {

			if (
				dgvRandevular
				->Rows[i]
				->Cells["RandevuNo"]
				->Value != nullptr
				&&
				dgvRandevular
				->Rows[i]
				->Cells["RandevuNo"]
				->Value
				->ToString() ==
				randevuNo
				) {

				dgvRandevular
					->Rows[i]
					->Selected =
					true;

				dgvRandevular
					->CurrentCell =
					dgvRandevular
					->Rows[i]
					->Cells["RandevuNo"];

				break;
			}
		}


		MessageBox::Show(
			L"Sýradaki hasta: " +
			hastaAdi +
			L"\nDurum: Çaðrýldý",
			L"Hasta Çaðýr",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	}
	catch (SqlException^ ex) {

		if (
			baglanti->State ==
			ConnectionState::Open
			) {

			baglanti->Close();
		}


		MessageBox::Show(
			String::Concat(
				L"Veritabaný hatasý:\n",
				ex->Message
			),
			L"Hata",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
	   private: void randevuSonaEkle(
		   RandevuDugum^ yeniDugum
	   ) {

		   // Liste boþsa
		   if (bas == nullptr) {

			   bas = yeniDugum;
			   return;
		   }
		   // Listenin baþýndan baþla
		   RandevuDugum^ mevcut = bas;
		   // Son düðümü bul
		   while (mevcut->sonraki != nullptr) {

			   mevcut = mevcut->sonraki;
		   }
		   // Yeni düðümü sona baðla
		   mevcut->sonraki = yeniDugum;
	   }
			  private: void tabloyuYenile()
			  {

				  dgvRandevular->Rows->Clear();


				  RandevuDugum^ mevcut = bas;


				  while (mevcut != nullptr) {

					  dgvRandevular->Rows->Add(
						  mevcut->randevuNo,
						  mevcut->hastaAdi,
						  mevcut->doktorAdi,
						  mevcut->bolum,
						  mevcut->tarih,
						  mevcut->saat,
						  mevcut->durum
					  );


					  mevcut = mevcut->sonraki;
				  }


				  dgvRandevular->ClearSelection();
			  }
private: System::Void dgvRandevular_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (e->RowIndex < 0)
		return;

	DataGridViewRow^ satir =
		dgvRandevular->Rows[e->RowIndex];


	if (satir->Cells["RandevuNo"]->Value == nullptr)
		return;


	txtRandevuNo->Text =
		satir->Cells["RandevuNo"]->Value->ToString();

	txtHastaAdi->Text =
		satir->Cells["HastaAdi"]->Value->ToString();

	txtDoktorAdi->Text =
		satir->Cells["DoktorAdi"]->Value->ToString();

	cmbBolum->SelectedItem =
		satir->Cells["Bolum"]->Value->ToString();

	txtSaat->Text =
		satir->Cells["Saat"]->Value->ToString();


	DateTime tarih;

	if (
		DateTime::TryParse(
			satir->Cells["Tarih"]->Value->ToString(),
			tarih
		)
		) {

		dtpTarih->Value = tarih;
	}
}
private: System::Void dgvRandevular_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dtpTarih_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
};

}
