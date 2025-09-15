<?php
session_start();
require_once "Electroshop.php";

// --- Inisialisasi data di session ---
if (!isset($_SESSION['listBarang'])) {
    $_SESSION['listBarang'] = [];
}

// --- Tambah Data ---
if (isset($_POST['tambah'])) {
    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $kategori = $_POST['kategori'];
    $brand = $_POST['brand'];
    $harga = $_POST['harga'];

    // Upload gambar
    $gambar = null;
    if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] == 0) {
        $targetDir = "uploads/";
        if (!is_dir($targetDir)) mkdir($targetDir);
        $fileName = time() . "_" . basename($_FILES['gambar']['name']);
        $targetFile = $targetDir . $fileName;
        move_uploaded_file($_FILES['gambar']['tmp_name'], $targetFile);
        $gambar = $targetFile;
    }

    $barang = new Electroshop($id, $nama, $kategori, $brand, $harga, $gambar);
    $_SESSION['listBarang'][] = serialize($barang);
}

// --- Update Data ---
if (isset($_POST['update'])) {
    $id = $_POST['id'];
    foreach ($_SESSION['listBarang'] as $key => $val) {
        $barang = unserialize($val);
        if ($barang->getId() == $id) {
            $gambar = null;
            if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] == 0) {
                $targetDir = "uploads/";
                if (!is_dir($targetDir)) mkdir($targetDir);
                $fileName = time() . "_" . basename($_FILES['gambar']['name']);
                $targetFile = $targetDir . $fileName;
                move_uploaded_file($_FILES['gambar']['tmp_name'], $targetFile);
                $gambar = $targetFile;
            }
            $barang->editData($_POST['nama'], $_POST['kategori'], $_POST['brand'], $_POST['harga'], $gambar);
            $_SESSION['listBarang'][$key] = serialize($barang);
        }
    }
}

// --- Hapus Data ---
if (isset($_GET['hapus'])) {
    $id = $_GET['hapus'];
    foreach ($_SESSION['listBarang'] as $key => $val) {
        $barang = unserialize($val);
        if ($barang->getId() == $id) {
            unset($_SESSION['listBarang'][$key]);
        }
    }
}

// --- Cari Data ---
$cariHasil = null;
if (isset($_POST['cari'])) {
    $idCari = $_POST['idCari'];
    foreach ($_SESSION['listBarang'] as $val) {
        $barang = unserialize($val);
        if ($barang->getId() == $idCari) {
            $cariHasil = $barang;
            break;
        }
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Electroshop</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 20px; }
        th, td { border: 1px solid #333; padding: 8px; text-align: center; }
        th { background-color: #eee; }
        .form-container { margin-bottom: 20px; padding: 10px; border: 1px solid #ccc; }
        input, button { padding: 6px; margin: 4px; }
    </style>
</head>
<body>

<h1>Electroshop</h1>

<div class="form-container">
    <h2>Tambah Data</h2>
    <form method="POST" enctype="multipart/form-data">
        ID: <input type="text" name="id" required>
        Nama: <input type="text" name="nama" required>
        Kategori: <input type="text" name="kategori" required>
        Brand: <input type="text" name="brand" required>
        Harga: <input type="number" name="harga" required>
        Gambar: <input type="file" name="gambar" accept="image/*">
        <button type="submit" name="tambah">Tambah</button>
    </form>
</div>

<div class="form-container">
    <h2>Cari Data</h2>
    <form method="POST">
        ID: <input type="text" name="idCari" required>
        <button type="submit" name="cari">Cari</button>
    </form>
    <?php if ($cariHasil): ?>
        <p><strong>Hasil Pencarian:</strong></p>
        <p>ID: <?= $cariHasil->getId() ?></p>
        <p>Nama: <?= $cariHasil->getNama() ?></p>
        <p>Kategori: <?= $cariHasil->getKategori() ?></p>
        <p>Brand: <?= $cariHasil->getBrand() ?></p>
        <p>Harga: <?= $cariHasil->getHarga() ?></p>
        <?php if ($cariHasil->getGambar()): ?>
            <p><img src="<?= $cariHasil->getGambar() ?>" width="120"></p>
        <?php endif; ?>
    <?php elseif (isset($_POST['cari'])): ?>
        <p>Data tidak ditemukan.</p>
    <?php endif; ?>
</div>

<h2>Daftar Barang</h2>
<table>
    <tr>
        <th>ID</th>
        <th>Nama</th>
        <th>Kategori</th>
        <th>Brand</th>
        <th>Harga</th>
        <th>Gambar</th>
        <th>Aksi</th>
    </tr>
    <?php foreach ($_SESSION['listBarang'] as $val): 
        $barang = unserialize($val); ?>
        <tr>
            <td><?= $barang->getId() ?></td>
            <td><?= $barang->getNama() ?></td>
            <td><?= $barang->getKategori() ?></td>
            <td><?= $barang->getBrand() ?></td>
            <td><?= $barang->getHarga() ?></td>
            <td>
                <?php if ($barang->getGambar()): ?>
                    <img src="<?= $barang->getGambar() ?>" width="80">
                <?php else: ?>
                    Tidak ada gambar
                <?php endif; ?>
            </td>
            <td>
                <form method="POST" enctype="multipart/form-data" style="display:inline;">
                    <input type="hidden" name="id" value="<?= $barang->getId() ?>">
                    <input type="text" name="nama" placeholder="Nama baru">
                    <input type="text" name="kategori" placeholder="Kategori baru">
                    <input type="text" name="brand" placeholder="Brand baru">
                    <input type="number" name="harga" placeholder="Harga baru">
                    <input type="file" name="gambar" accept="image/*">
                    <button type="submit" name="update">Update</button>
                </form>
                <a href="?hapus=<?= $barang->getId() ?>" onclick="return confirm('Yakin hapus?')">Hapus</a>
            </td>
        </tr>
    <?php endforeach; ?>
</table>

</body>
</html>
