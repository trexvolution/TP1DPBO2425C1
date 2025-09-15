<?php
class Electroshop {
    private $id;
    private $nama;
    private $kategori;
    private $brand;
    private $harga;

    public function __construct($id, $nama, $kategori, $brand, $harga) {
        $this->id = $id;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->brand = $brand;
        $this->harga = $harga;
    }

    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getKategori() { return $this->kategori; }
    public function getBrand() { return $this->brand; }
    public function getHarga() { return $this->harga; }

    public function editData($nama, $kategori, $brand, $harga) {
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->brand = $brand;
        $this->harga = $harga;
    }
}
