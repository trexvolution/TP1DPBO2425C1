<?php
class Electroshop {
    private $id;
    private $nama;
    private $kategori;
    private $brand;
    private $harga;
    private $gambar; // tambahan untuk gambar

    public function __construct($id, $nama, $kategori, $brand, $harga, $gambar = null) {
        $this->id = $id;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->brand = $brand;
        $this->harga = $harga;
        $this->gambar = $gambar;
    }

    public function getId() { return $this->id; }
    public function getNama() { return $this->nama; }
    public function getKategori() { return $this->kategori; }
    public function getBrand() { return $this->brand; }
    public function getHarga() { return $this->harga; }
    public function getGambar() { return $this->gambar; }

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
?>
