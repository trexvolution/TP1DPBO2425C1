// Saya Nur Abdillah dengan NIM 2408515 mengerjakan Tugas Praktikum 1
// dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahan-Nya 
// maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan

#include <bits/stdc++.h>    // Meng-include semua library standar C++
#include "Electroshop.cpp"  // Meng-include file class Electroshop yang sudah dibuat

using namespace std;

int main(){

    list<Electroshop> ListBarang;   // Membuat list (linked list STL) untuk menyimpan objek Electroshop
    int choice = 0; // Variabel untuk menampung pilihan menu

    // Perulangan akan terus berjalan selama choice tidak bernilai 6 (Exit)
    while (choice != 6){

        cout << "+-------------------+" << endl;
        cout << "|   Menu Perintah   |" << endl;
        cout << "+-------------------+" << endl;
        cout << "| 1. Tambahkan Data |" << endl;
        cout << "| 2. Tampilkan Data |" << endl;
        cout << "| 3. Update Data    |" << endl;
        cout << "| 4. Hapus Data     |" << endl;
        cout << "| 5. Cari Data      |" << endl;
        cout << "| 6. Exit           |" << endl;
        cout << "+-------------------+" << endl;
        cout << "Perintah apa yang ingin anda lakukan : ";
        cin >> choice;  // Input pilihan dari user

        // Pilihan 1 untuk menambahkan data
        if(choice == 1){

            // Input data barang
            string id, nama, kategori, brand;
            int harga;
            cout << "Silahkan masukkan data berikut: " << endl;
            cout << "ID :";
            cin >> id;
            cout << "Nama :";
            cin >> nama;
            cout << "Kategori : ";
            cin >> kategori;
            cout << "Brand :";
            cin >> brand;
            cout << "Harga :";
            cin >> harga;

            // Membuat objek sementara dari class Electroshop
            Electroshop temp(id, nama, kategori, brand, harga);

            // Menyimpan data ke dalam list
            ListBarang.push_back(temp);

        // Pilihan 2 untuk menampilkan isi data
        }else if (choice == 2){

            if (ListBarang.empty()){     // Jika list kosong

                cout << "Data Masih Kosong" << endl;

            }else{
                
                // Menentukan panjang kolom tabel agar rapi
                int id_len = 2, name_len = 4, kate_len = 8, brand_len = 5, harga_len = 5;

                // Mencari panjang maksimum dari tiap atribut agar tabel tidak terpotong
                for (Electroshop electroshop : ListBarang){
                    if(electroshop.IdLength() > id_len){
                        id_len = electroshop.IdLength();
                    }
                    if(electroshop.namaLength() > name_len){
                        name_len = electroshop.namaLength();
                    }
                    if(electroshop.KategoriLength() > kate_len){
                        kate_len = electroshop.KategoriLength();
                    }
                    if(electroshop.brandLength() > brand_len){
                        brand_len = electroshop.brandLength();
                    }
                    if(electroshop.hargaLength() > harga_len){
                        harga_len = electroshop.hargaLength();
                    }
                }

                // Cetak header tabel
                cout << "+" << string (id_len, '-') 
                << "+" << string (name_len, '-') 
                << "+" << string (kate_len, '-') 
                << "+" << string (brand_len, '-') 
                << "+" << string (harga_len, '-') 
                << "+" << endl;

                cout << "|" << "ID" << string (id_len - 2, ' ')
                << "|" << "Name" << string (name_len - 4, ' ')
                << "|" << "Kategori" << string (kate_len - 8, ' ')
                << "|" << "Brand" << string (brand_len - 5, ' ')
                << "|" << "Harga" << string (harga_len - 5, ' ')
                << "|" << endl;

                cout << "+" << string (id_len, '-') 
                << "+" << string (name_len, '-') 
                << "+" << string (kate_len, '-') 
                << "+" << string (brand_len, '-') 
                << "+" << string (harga_len, '-') 
                << "+" << endl;

                // Cetak isi data barang satu per satu
                for (Electroshop electrochop : ListBarang){
                        cout << "|" << electrochop.getId() << string (id_len - electrochop.getId().length(), ' ')
                    << "|" << electrochop.getName() << string (name_len - electrochop.getName().length(), ' ')
                    << "|" << electrochop.getKategori() << string (kate_len - electrochop.getKategori().length(), ' ')
                    << "|" << electrochop.getBrand() << string (brand_len - electrochop.getBrand().length(), ' ')
                    << "|" << electrochop.getHarga() << string (harga_len - to_string(electrochop.getHarga()).length(), ' ')
                    << "|" << endl;
                }

                // Cetak footer tabel
                cout << "+" << string (id_len, '-') 
                << "+" << string (name_len, '-') 
                << "+" << string (kate_len, '-') 
                << "+" << string (brand_len, '-') 
                << "+" << string (harga_len, '-') 
                << "+" << endl;
            }

        // Pilihan 3 mengubah isi data
        }else if (choice == 3){

            string id;
            cout << "Masukkan ID yang ingin diupdate : ";
            cin >> id;

            // Mencari data dengan ID yang sesuai
            Electroshop* pointer_edit = NULL;
            auto it = ListBarang.begin();
            while (it != ListBarang.end() && pointer_edit == NULL){
                pointer_edit = it->searchId(id);    // cek apakah ID cocok
                it++;
            }

            if(pointer_edit != NULL){   // Jika data ditemukan

                cout << "Berikut data dengan ID tersebut" << endl;
                cout << "Nama :" << pointer_edit->getName() << endl;
                cout << "Kategori :" << pointer_edit->getKategori() << endl;
                cout << "Brand :" << pointer_edit->getBrand() << endl;
                cout << "Harga :" << pointer_edit->getHarga() << endl << endl;

                // Input data baru untuk update
                string nama, kategori, brand;
                int harga;
                cout << "Masukkan Nama :";
                cin >> nama;
                cout << "Masukkan Kategori :";
                cin >> kategori;
                cout << "Masukkan Brand :";
                cin >> brand;
                cout << "Masukkan Harga :";
                cin >> harga;

                // Edit data lama dengan data baru
                pointer_edit->editData(nama, kategori, brand, harga);

            }else{
                
                cout << "Data yang anda cari tidak ditemukan" << endl;
            }
        
        // Pilihan 4 menghapus data
        }else if (choice == 4){

            string id;
            cout << "Masukkan ID data yang ingin dihapus :";
            cin >> id;

            auto it = ListBarang.begin();
            int flag = 0;
            while (it != ListBarang.end() && flag == 0){

                if(it->getId() == id){

                    // Jika ID cocok, hapus data dari list
                    it = ListBarang.erase(it);
                    cout << "Data telah dihapus" << endl;
                    flag = 1;

                }else{

                    it++;
                }
                
                if(flag == 0){
                    cout << "Data tidak ditemukan" << endl;
                }
            }

        // Pilihan 5 untuk mencari data
        }else if (choice == 5){

            string id;
            cout << "Masukkan ID yang ingin dicari : ";
            cin >> id;
            Electroshop* pointer_edit = NULL;
            auto it = ListBarang.begin();
            while (it != ListBarang.end() && pointer_edit == NULL){
                pointer_edit = it->searchId(id);
                it++;
            }

            if(pointer_edit != NULL){
                cout << "Berikut data dengan ID " << id << " tersebut :" << endl;
                cout << "Nama :" << pointer_edit->getName() << endl;
                cout << "Kategori :" << pointer_edit->getKategori() << endl;
                cout << "Brand :" << pointer_edit->getBrand() << endl;
                cout << "Harga :" << pointer_edit->getHarga() << endl << endl;

            }else{
                
                cout << "Data yang anda cari tidak ditemukan" << endl;
            }
        }
    }
    
    return 0;
}