#include <bits/stdc++.h>

using namespace std;

class Electroshop{

    private:

        string id;
        string nama;
        string kategori;
        string brand;
        int harga;
        
    public:

    Electroshop(){
    }

    Electroshop(string id, string nama, string kategori, string brand, int harga){
        this->id = id;
        this->nama = nama;
        this->kategori = kategori;
        this->brand = brand;
        this->harga = harga;
    }

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
        return to_string(harga).length();
    }

    void editData(string nama, string kategori, string brand, int harga){
        this->nama = nama;
        this->kategori = kategori;
        this->brand = brand;
        this->harga = harga;
    }

    Electroshop* searchId(string id){
        if(this->id == id){
            return this;
        }else{
            return NULL;
        }
    }
    
    ~Electroshop(){
    }
};