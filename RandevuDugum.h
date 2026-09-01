#pragma once
using namespace System;
namespace medtrack {
    public ref class RandevuDugum
    {
    public:
        String^ randevuNo;
        String^ hastaAdi;
        String^ doktorAdi;
        String^ bolum;
        String^ tarih;
        String^ saat;
        String^ durum;

        RandevuDugum^ sonraki;
        RandevuDugum(
            String^ no,
            String^ hasta,
            String^ doktor,
            String^ bolumAdi,
            String^ tarihBilgisi,
            String^ saatBilgisi
        )
        {
            randevuNo = no;
            hastaAdi = hasta;
            doktorAdi = doktor;
            bolum = bolumAdi;
            tarih = tarihBilgisi;
            saat = saatBilgisi;
            durum = L"Aktif";
            sonraki = nullptr;
        }
    };

}