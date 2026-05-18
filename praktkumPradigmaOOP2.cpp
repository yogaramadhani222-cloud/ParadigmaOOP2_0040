#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
 
using namespace std;

class RekeningBank {
protected:
    string nomorRekening;
    string namaNasabah;
    double saldo;
 
public:
    RekeningBank(string nomor, string nama, double saldoAwal)
        : nomorRekening(nomor), namaNasabah(nama), saldo(saldoAwal) {}
 
    virtual void potongAdmin() = 0;

    virtual ~RekeningBank() {}
 
    string getNomorRekening() const { return nomorRekening; }
    string getNamaNasabah()   const { return namaNasabah; }
    double getSaldo()         const { return saldo; }
 
    virtual string getJenisRekening() const = 0;
 
    void tampilInfo() const {
        cout << "  No. Rekening : " << nomorRekening << "\n";
        cout << "  Nama Nasabah : " << namaNasabah << "\n";
        cout << "  Jenis        : " << getJenisRekening() << "\n";
        cout << "  Saldo        : Rp " << fixed << setprecision(0) << saldo << "\n";
    }
};

class RekeningySyariah : public RekeningBank {
public:
    RekeningySyariah(string nomor, string nama, double saldoAwal)
        : RekeningBank(nomor, nama, saldoAwal) {}
 
    void potongAdmin() override {
        cout << "  [INFO] Rekening Syariah — tidak ada potongan admin.\n";
    }
 
    string getJenisRekening() const override {
        return "Rekening Syariah";
    }
};

class RekeningKonvensional : public RekeningBank {
private:
    const double BIAYA_ADMIN = 15000.0;
 
public:
    RekeningKonvensional(string nomor, string nama, double saldoAwal)
        : RekeningBank(nomor, nama, saldoAwal) {}
 
    void potongAdmin() override {
        if (saldo >= BIAYA_ADMIN) {
            saldo -= BIAYA_ADMIN;
            cout << "  [POTONG] Biaya admin Rp 15.000 berhasil dipotong.\n";
        } else {
            cout << "  [GAGAL] Saldo tidak mencukupi untuk potongan admin!\n";
        }
    }
 
    string getJenisRekening() const override {
        return "Rekening Konvensional";
    }
};

class RekeningPremium : public RekeningBank {
private:
    const double BATAS_BEBAS_ADMIN  = 10000000.0;  // Rp 10.000.000
    const double BIAYA_ADMIN_PREMIUM = 50000.0;     // Rp 50.000
 
public:
    RekeningPremium(string nomor, string nama, double saldoAwal)
        : RekeningBank(nomor, nama, saldoAwal) {}
 
    void potongAdmin() override {
        if (saldo > BATAS_BEBAS_ADMIN) {
            cout << "  [BEBAS] Saldo di atas Rp 10.000.000 — bebas biaya admin.\n";
        } else {
            if (saldo >= BIAYA_ADMIN_PREMIUM) {
                saldo -= BIAYA_ADMIN_PREMIUM;
                cout << "  [POTONG] Biaya admin Rp 50.000 berhasil dipotong.\n";
            } else {
                cout << "  [GAGAL] Saldo tidak mencukupi untuk potongan admin premium!\n";
            }
        }
    }
 
    string getJenisRekening() const override {
        return "Rekening Premium";
    }
};

void prosesAkhirBulan(vector<RekeningBank*>& daftarRekening) {
    cout << "\n";
    cout << "============================================================\n";
    cout << "       PROSES OTOMATISASI AKHIR BULAN - BANK GIBRAN JAYA    \n";
    cout << "============================================================\n";
 
    for (size_t i = 0; i < daftarRekening.size(); i++) {
        cout << "\n[Rekening " << (i + 1) << "]\n";
        cout << "  >> Sebelum proses:\n";
        daftarRekening[i]->tampilInfo();
 
        daftarRekening[i]->potongAdmin();
 
        cout << "  >> Saldo akhir: Rp "
             << fixed << setprecision(0)
             << daftarRekening[i]->getSaldo() << "\n";
        cout << "------------------------------------------------------------\n";
    }
}

int main() {
    cout << "============================================================\n";
    cout << "          SISTEM PERBANKAN - BANK GIBRAN JAYA               \n";
    cout << "============================================================\n";
 
    vector<RekeningBank*> daftarRekening = {
        new RekeningySyariah     ("SYR-001", "Joko",       5000000),
        new RekeningKonvensional ("KON-001", "Budi",       500000),
        new RekeningKonvensional ("KON-002", "Citra",          10000),
        new RekeningPremium      ("PRM-001", "Lia",     15000000), 
        new RekeningPremium      ("PRM-002", "Eko",      8000000),
        new RekeningPremium      ("PRM-003", "Fitri",        30000),
    };
    prosesAkhirBulan(daftarRekening);

    cout << "\n============================================================\n";
    cout << "                    RINGKASAN SALDO AKHIR                   \n";
    cout << "============================================================\n";
    cout << left << setw(12) << "No. Rek"
         << setw(22) << "Nama Nasabah"
         << setw(22) << "Jenis"
         << "Saldo Akhir\n";
    cout << "------------------------------------------------------------\n";
    for (auto* rek : daftarRekening) {
        cout << left << setw(12) << rek->getNomorRekening()
             << setw(22) << rek->getNamaNasabah()
             << setw(22) << rek->getJenisRekening()
             << "Rp " << fixed << setprecision(0) << rek->getSaldo() << "\n";
    }
    cout << "============================================================\n";

    for (auto* rek : daftarRekening) {
        delete rek;
    }
    return 0;
}