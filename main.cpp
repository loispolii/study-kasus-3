#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

class makanan {
  friend istream &operator>>(istream &, makanan &);

public:
  void delivery();
  void potongan();
  void jumlahharga();
  void output();

private:
  int jumlah, harga, diskon, beli, menu, porsi, total, banyakmenu, jarak, hgjrk,
      pilih, i, bayar, kembali;
};

void makanan::jumlahharga() {
  total = 0;
  cout << "==========================\n";
  cout << "|| DAFTAR HARGA         ||\n";
  cout << "==========================\n";
  cout << "|| 1. ayprek  : Rp.21000||\n";
  cout << "|| 2. aygor   : Rp.17000||\n";
  cout << "|| 3. cumgor  : Rp.20000||\n";
  cout << "|| 4. aybak   : Rp.25000||\n";
  cout << "==========================\n";

  cout << endl << "Berapa menu yang ingin dibeli  ";
  cin >> banyakmenu;
  for (i = 1; i <= banyakmenu; ++i) {
    cout << "\nMenu yang anda pilih : ";
    cin >> pilih;
    if (pilih == 1) {
      cout << "1. ayprek : Rp 21.000" << endl;
      cout << "Masukan banyak porsi : ";
      cin >> porsi;
      harga = 21000 * porsi;
      cout << "Total satuan : " << harga;
      total = total + harga;
    } else if (pilih == 2) {
      cout << "2. aygor : Rp 17.000" << endl;
      cout << "Masukan banyak porsi : ";
      cin >> porsi;
      harga = 17000 * porsi;
      cout << "Total satuan : " << harga;
      total = total + harga;
    } else if (pilih == 3) {
      cout << "3. cumgor : Rp 20.000" << endl;
      cout << "Masukan banyak porsi : ";
      cin >> porsi;
      harga = 20000 * porsi;
      cout << "Total satuan : " << harga;
      total = total + harga;
    } else if (pilih == 4) {
      cout << "4. aybak : Rp 25.000" << endl;
      cout << "Masukan banyak porsi : ";
      cin >> porsi;
      harga = 25000 * porsi;
      cout << "Total satuan : " << harga;
      total = total + harga;
    }
  }
}

void makanan::delivery() {
  cout << "\nPilih jarak rumah kamu dari RM ";
  cin >> jarak;
  if (jarak <= 3) {
    cout << "\nBiaya ongkir sebesar Rp.15000\n";
    hgjrk = 15000;
    if ((total >= 25000) && (total < 50000)) {
      cout << "Anda mendapatkan potongan ongkir   Rp.3000\n";
      hgjrk = 12000;
    } else if ((total >= 50000) && (total < 150000)) {
      cout << "Anda mendapatkan potongan ongkir Rp.5000\n";
      hgjrk = 10000;
    } else if (total > 150000) {
      cout << "Anda mendapatkan potongan ongkir Rp.8000\n";
      hgjrk = 7000;
    }
  }

  if (jarak > 3) {
    cout << "Biaya ongkir sebesar Rp.25000\n";
    hgjrk = 25000;
    if ((total >= 25000) && (total < 50000)) {
      cout << "Anda mendapatkan potongan ongkir Rp.3000\n";
      hgjrk = 22000;
    } else if ((total >= 50000) && (total < 150000)) {
      cout << "Anda mendapatkan potongan ongkir Rp.5000\n";
      hgjrk = 20000;
    } else if (total > 150000) {
      cout << "Anda mendapatkan potongan ongkir Rp.8000\n";
      hgjrk = 17000;
    }
  }
}

void makanan::potongan() {
  if ((total >= 50000) && (total < 150000)) {
    diskon = total * 15 / 100;
    cout << "Anda mendapatkan diskon 15% dengan total diskon Rp." << diskon;
  } else if (total >= 150000) {
    diskon = total * 35 / 100;
    cout << "Anda mendapatkan diskon 35% dengan total diskon Rp." << diskon;
  }
  jumlah = total + hgjrk - diskon;
}

void makanan::output() {
  cout << "\nTotal harga yang dipesan : " << total;
  cout << "\nBiaya delivery  " << hgjrk;
  cout << "\nDiskon sebesar  " << diskon;
  cout << "\nJumlah total yang harus di bayar  " << jumlah;
  cout << "\nMasukan Uang anda  ";
  cin >> bayar;
  kembali = bayar - jumlah;
  cout << "\nJumlah yang harus dikembalikan  " << kembali;

  ofstream hsl;
  hsl.open("struk.txt", ios::out);
  hsl << "        MAKANAN           " << endl;
  hsl << "==========================" << endl;
  hsl << " Menu Makanan dan Harga   " << endl;
  hsl << "1. Ayprek    : Rp21.000 " << endl;
  hsl << "2. Aygor     : Rp17.000 " << endl;
  hsl << "3. cumgor    : Rp20.000 " << endl;
  hsl << "4. Aybak     : Rp25.000 " << endl;
  hsl << "\n=========================\n";

  hsl << "\nTotal harga yang dipesan : " << total;
  hsl << "\nBiaya delivery : " << hgjrk;
  hsl << "\nTotal diskon : " << diskon;
  hsl << "\nJumlah total yang harus di bayar : " << jumlah;
  hsl << "\nUang anda : " << bayar;
  hsl << "\nKembalian : " << kembali;
}

int main() {
  makanan x;
  x.jumlahharga();
  x.delivery();
  x.potongan();
  x.output();

  return 0;
}