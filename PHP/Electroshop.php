<?php
// Saya Nur Abdillah dengan NIM 2408515 mengerjakan Tugas Praktikum 1
// dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahan-Nya 
// maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan

// Definisi class Electroshop untuk merepresentasikan data produk/barang
class Electroshop {
    // Properti private hanya bisa diakses lewat method (getter/setter)
    private $id, $nama, $kategori, $brand, $harga, $gambar;

    // Konstruktor: dijalankan otomatis saat objek dibuat
    // Parameter: id, nama, kategori, brand, harga, dan opsional gambar
    public function __construct($id, $nama, $kategori, $brand, $harga, $gambar = null) {
        $this->id = $id;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->brand = $brand;
        $this->harga = $harga;
        $this->gambar = $gambar;
    }

    // Getter: mengembalikan nilai dari masing-masing properti
    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getKategori() { return $this->kategori; }
    public function getBrand() { return $this->brand; }
    public function getHarga() { return $this->harga; }
    public function getGambar() { return $this->gambar; }

    // Method untuk mengedit/mengubah data produk
    // Gambar bersifat opsional → hanya diupdate jika parameter gambar diisi
    public function editData($nama, $kategori, $brand, $harga, $gambar = null) {
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->brand = $brand;
        $this->harga = $harga;
        if ($gambar) {
            $this->gambar = $gambar;
        }
    }
}
