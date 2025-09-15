#include <bits/stdc++.h>
#include "Electroshop.cpp"

using namespace std;

int main(){

    list<Electroshop> ListBarang;
    int choice = 0;
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
        cin >> choice;

        if(choice == 1){

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
            Electroshop temp(id, nama, kategori, brand, harga);
            ListBarang.push_back(temp);

        }else if (choice == 2){

            if (ListBarang.empty()){

                cout << "Data Masih Kosong" << endl;

            }else{
                
                int id_len = 2, name_len = 4, kate_len = 8, brand_len = 5, harga_len = 5;
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

                for (Electroshop electrochop : ListBarang){
                        cout << "|" << electrochop.getId() << string (id_len - electrochop.getId().length(), ' ')
                    << "|" << electrochop.getName() << string (name_len - electrochop.getName().length(), ' ')
                    << "|" << electrochop.getKategori() << string (kate_len - electrochop.getKategori().length(), ' ')
                    << "|" << electrochop.getBrand() << string (brand_len - electrochop.getBrand().length(), ' ')
                    << "|" << electrochop.getHarga() << string (harga_len - to_string(electrochop.getHarga()).length(), ' ')
                    << "|" << endl;
                }

                cout << "+" << string (id_len, '-') 
                << "+" << string (name_len, '-') 
                << "+" << string (kate_len, '-') 
                << "+" << string (brand_len, '-') 
                << "+" << string (harga_len, '-') 
                << "+" << endl;
            }

            
        }else if (choice == 3){

            string id;
            cout << "Masukkan ID yang ingin diupdate : ";
            cin >> id;
            Electroshop* pointer_edit = NULL;
            auto it = ListBarang.begin();
            while (it != ListBarang.end() && pointer_edit == NULL){
                pointer_edit = it->searchId(id);
                it++;
            }

            if(pointer_edit != NULL){

                cout << "Berikut data dengan ID tersebut" << endl;
                cout << "Nama :" << pointer_edit->getName() << endl;
                cout << "Kategori :" << pointer_edit->getKategori() << endl;
                cout << "Brand :" << pointer_edit->getBrand() << endl;
                cout << "Harga :" << pointer_edit->getHarga() << endl << endl;

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
                pointer_edit->editData(nama, kategori, brand, harga);

            }else{
                
                cout << "Data yang anda cari tidak ditemukan" << endl;
            }
            
            
        }else if (choice == 4){

            string id;
            cout << "Masukkan ID data yang ingin dihapus :";
            cin >> id;

            auto it = ListBarang.begin();
            int flag = 0;
            while (it != ListBarang.end() && flag == 0){
                if(it->getId() == id){

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