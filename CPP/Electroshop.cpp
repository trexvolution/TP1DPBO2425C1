// Saya Nur Abdillah dengan NIM 2408515 mengerjakan Tugas Praktikum 1
// dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahan-Nya 
// maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan

// Header untuk meng-include semua library standar C++
#include <bits/stdc++.h>

// Membuat class bernama Electroshop
using namespace std;

class Electroshop{

    private:

        // Properti/atribut barang elektronik
        string id;
        string nama;
        string kategori;
        string brand;
        int harga;
        
    public:

    // Constructor default (tanpa parameter)
    Electroshop(){
    }

    // Constructor dengan parameter untuk langsung mengisi data barang
    Electroshop(string id, string nama, string kategori, string brand, int harga){
        this->id = id;
        this->nama = nama;
        this->kategori = kategori;
        this->brand = brand;
        this->harga = harga;
    }

    // Setter dan Getter untuk setiap atribut
    void setId(string id){
        this->id = id;
    }

    string getId(){
        return this->id;
    }

    void setNama(string nama){
        this->nama = nama;
    }

    string getName(){
        return this->nama;
    }

    void setKategori(string kategori){
        this->kategori = kategori;
    }

    string getKategori(){
        return this->kategori;
    }

    void setBrand(string brand){
        this->brand = brand;
    }

    string getBrand(){
        return this->brand;
    }

    void setHarga(int harga){
        this->harga = harga;
    }

    int getHarga(){ 
        return this->harga;
    }

    // Fungsi tambahan untuk menghitung panjang string dari tiap atribut
    int IdLength(){
        return id.length();
    }

    int namaLength(){
        return nama.length();
    }

    int KategoriLength(){
        return kategori.length();
    }

    int brandLength(){
        return brand.length();
    }

    int hargaLength(){
        // Mengubah harga ke string lalu menghitung panjang digitnya
        return to_string(harga).length();
    }

    // Fungsi untuk mengedit data barang (nama, kategori, brand, harga)
    void editData(string nama, string kategori, string brand, int harga){
        this->nama = nama;
        this->kategori = kategori;
        this->brand = brand;
        this->harga = harga;
    }

    // Fungsi pencarian berdasarkan ID barang
    Electroshop* searchId(string id){
        if(this->id == id){
            return this;    // jika cocok, kembalikan objek ini
        }else{
            return NULL;    // jika tidak cocok, kembalikan NULL
        }
    }
    
    // Destructor
    ~Electroshop(){
    }
};