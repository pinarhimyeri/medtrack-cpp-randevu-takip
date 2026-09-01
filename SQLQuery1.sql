CREATE TABLE dbo.cpp_randevular
(
    id INT IDENTITY(1,1) NOT NULL
        PRIMARY KEY,

    randevu_no NVARCHAR(20) NOT NULL
        UNIQUE,

    hasta_adi NVARCHAR(100) NOT NULL,

    doktor_adi NVARCHAR(100) NOT NULL,

    bolum NVARCHAR(100) NOT NULL,

    tarih DATE NOT NULL,

    saat NVARCHAR(10) NOT NULL,

    durum NVARCHAR(30) NOT NULL
        CONSTRAINT DF_cpp_randevular_durum
        DEFAULT N'Aktif'
);