# MEDTRACK C++ Randevu Takip Sistemi

MEDTRACK; hasta randevularını oluşturmak, görüntülemek ve yönetmek amacıyla geliştirilmiş masaüstü randevu takip uygulamasıdır.

Proje, **C++/CLI Windows Forms** ile geliştirilmiş ve randevu bilgilerinin kalıcı olarak saklanması için **SQL Server** veritabanı kullanılmıştır.

## Projenin Amacı

Bu projenin amacı, sağlık kurumlarında gerçekleştirilen temel randevu işlemlerini tek bir masaüstü uygulaması üzerinden yönetmektir.

Uygulama sayesinde hasta ve randevu bilgileri kaydedilebilir, mevcut randevular aranabilir, iptal edilebilir ve sıradaki hasta çağrılabilir.

## Özellikler

* Yeni hasta randevusu oluşturma
* Randevu numarasıyla kayıt arama
* Hasta ve doktor bilgilerini görüntüleme
* Hastane bölümü seçme
* Randevu tarihi ve saati belirleme
* Mevcut randevuyu silme
* Randevu durumunu iptal edildi olarak güncelleme
* Sıradaki hastayı çağırma
* Randevuları tarih ve saate göre listeleme
* Randevu bilgilerinin SQL Server veritabanında saklanması
* Bağlı liste veri yapısıyla randevu kayıtlarının yönetilmesi
* Kullanıcı dostu Windows Forms arayüzü

## Kullanılan Teknolojiler

* C++
* C++/CLI
* Windows Forms
* .NET Framework
* SQL Server
* SQL Server LocalDB
* Visual Studio 2022
* Git ve GitHub

## Proje Yapısı

```text
medtrack-cpp-randevu-takip/
├── AnaForm1.cpp
├── AnaForm1.h
├── AnaForm1.resx
├── MyForm.cpp
├── MyForm.h
├── RandevuDugum.h
├── main.cpp
├── medtrack.slnx
├── medtrack.vcxproj
├── medtrack.vcxproj.filters
├── SQLQuery1.sql
├── README.md
├── LICENSE
└── .gitignore
```

### Temel Dosyalar

* `main.cpp`: Uygulamanın başlangıç noktasıdır.
* `AnaForm1.h`: Ana randevu yönetim ekranını ve olay fonksiyonlarını içerir.
* `AnaForm1.cpp`: Ana formun C++ kaynak kodlarını içerir.
* `AnaForm1.resx`: Windows Forms arayüz kaynaklarını saklar.
* `RandevuDugum.h`: Randevular için kullanılan bağlı liste düğüm yapısını içerir.
* `MyForm.h` ve `MyForm.cpp`: Uygulamadaki yardımcı form yapılarını içerir.
* `SQLQuery1.sql`: Gerekli SQL Server veritabanı ve tablo sorgularını içerir.
* `medtrack.slnx`: Visual Studio çözüm dosyasıdır.
* `medtrack.vcxproj`: C++ projesinin Visual Studio yapılandırmasını içerir.

## Veritabanı Yapısı

Randevu kayıtları SQL Server üzerinde bulunan `cpp_randevular` tablosunda saklanır.

Temel randevu bilgileri:

* Randevu numarası
* Hasta adı ve soyadı
* Doktor adı ve soyadı
* Hastane bölümü
* Randevu tarihi
* Randevu saati
* Randevu durumu

Veritabanını oluşturmak için projede bulunan `SQLQuery1.sql` dosyası SQL Server Management Studio veya Visual Studio SQL araçları üzerinden çalıştırılmalıdır.

## Kurulum

### Gereksinimler

Projeyi çalıştırabilmek için aşağıdaki araçların kurulu olması gerekir:

* Windows 10 veya Windows 11
* Visual Studio 2022
* Desktop development with C++ iş yükü
* C++/CLI desteği
* .NET Framework
* SQL Server veya SQL Server LocalDB

### Çalıştırma Adımları

1. Depoyu bilgisayarınıza indirin:

```bash
git clone https://github.com/pinarhimyeri/medtrack-cpp-randevu-takip.git
```

2. Proje klasörünü açın.

3. `medtrack.slnx` dosyasını Visual Studio ile çalıştırın.

4. `SQLQuery1.sql` dosyasını SQL Server üzerinde çalıştırarak gerekli veritabanını ve tabloyu oluşturun.

5. Projedeki SQL Server bağlantı metnini kendi bilgisayarınızdaki sunucu adına göre kontrol edin.

6. Visual Studio üzerinden hedef platformu `x64` olarak seçin.

7. Projeyi derleyip çalıştırın.

## Uygulama Kullanımı

1. Hasta adı ve soyadı girilir.
2. Benzersiz bir randevu numarası belirlenir.
3. Doktor bilgisi ve hastane bölümü seçilir.
4. Randevu tarihi ve saati girilir.
5. **Randevu Ekle** butonuyla kayıt oluşturulur.
6. Oluşturulan kayıtlar uygulamanın liste alanında görüntülenir.
7. Randevu numarası kullanılarak kayıt aranabilir.
8. Gerekli durumlarda randevu iptal edilebilir veya silinebilir.
9. **Sıradaki Hastayı Çağır** butonuyla sıradaki randevu işleme alınabilir.

## Veri Yapısı

Projede randevuların bellekte yönetilmesi için bağlı liste yaklaşımı kullanılmıştır.

`RandevuDugum.h` dosyasında her randevunun bilgilerini ve sonraki randevunun bağlantısını tutan düğüm yapısı bulunmaktadır. Bu yapı, randevu kayıtlarının sıralı biçimde işlenmesini ve sıradaki hastanın çağrılmasını destekler.

## Ekran Görüntüsü

> MEDTRACK ana ekran görüntüsü bu bölüme eklenecektir.

## Gelecekte Eklenebilecek Özellikler

* Doktor ve hasta giriş sistemi
* Kullanıcı yetkilendirme
* Randevu hatırlatma bildirimleri
* Gelişmiş hasta arama ve filtreleme
* Randevu geçmişi ve raporlama
* Çoklu hastane ve poliklinik desteği
* Web tabanlı MEDTRACK sistemiyle entegrasyon

## Geliştirici

**Pınar Himyeri**
Bilgisayar Mühendisliği

## Lisans

Bu proje MIT Lisansı ile lisanslanmıştır. Ayrıntılar için `LICENSE` dosyasını inceleyebilirsiniz.
