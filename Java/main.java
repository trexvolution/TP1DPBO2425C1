import java.util.*;

public class main {
    public static void main(String[] args) {
        List<Electroshop> listBarang = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);
        int choice = 0;

        while (choice != 6) {
            System.out.println("+-------------------+");
            System.out.println("|   Menu Perintah   |");
            System.out.println("+-------------------+");
            System.out.println("| 1. Tambahkan Data |");
            System.out.println("| 2. Tampilkan Data |");
            System.out.println("| 3. Update Data    |");
            System.out.println("| 4. Hapus Data     |");
            System.out.println("| 5. Cari Data      |");
            System.out.println("| 6. Exit           |");
            System.out.println("+-------------------+");
            System.out.print("Perintah apa yang ingin anda lakukan : ");
            choice = scanner.nextInt();
            scanner.nextLine(); // consume newline

            if (choice == 1) {
                System.out.println("Silahkan masukkan data berikut:");
                System.out.print("ID: ");
                String id = scanner.nextLine();
                System.out.print("Nama: ");
                String nama = scanner.nextLine();
                System.out.print("Kategori: ");
                String kategori = scanner.nextLine();
                System.out.print("Brand: ");
                String brand = scanner.nextLine();
                System.out.print("Harga: ");
                int harga = scanner.nextInt();
                scanner.nextLine();

                Electroshop temp = new Electroshop(id, nama, kategori, brand, harga);
                listBarang.add(temp);

            } else if (choice == 2) {
                if (listBarang.isEmpty()) {
                    System.out.println("Data Masih Kosong");
                } else {
                    int idLen = 2, nameLen = 4, kateLen = 8, brandLen = 5, hargaLen = 5;
                    for (Electroshop e : listBarang) {
                        idLen = Math.max(idLen, e.idLength());
                        nameLen = Math.max(nameLen, e.namaLength());
                        kateLen = Math.max(kateLen, e.kategoriLength());
                        brandLen = Math.max(brandLen, e.brandLength());
                        hargaLen = Math.max(hargaLen, e.hargaLength());
                    }

                    String border = "+" + "-".repeat(idLen) +
                                    "+" + "-".repeat(nameLen) +
                                    "+" + "-".repeat(kateLen) +
                                    "+" + "-".repeat(brandLen) +
                                    "+" + "-".repeat(hargaLen) + "+";

                    System.out.println(border);
                    System.out.printf("|%-" + idLen + "s|%-" + nameLen + "s|%-" + kateLen + "s|%-" + brandLen + "s|%-" + hargaLen + "s|\n",
                                      "ID", "Name", "Kategori", "Brand", "Harga");
                    System.out.println(border);

                    for (Electroshop e : listBarang) {
                        System.out.printf("|%-" + idLen + "s|%-" + nameLen + "s|%-" + kateLen + "s|%-" + brandLen + "s|%-" + hargaLen + "d|\n",
                                          e.getId(), e.getNama(), e.getKategori(), e.getBrand(), e.getHarga());
                    }

                    System.out.println(border);
                }

            } else if (choice == 3) {
                System.out.print("Masukkan ID yang ingin diupdate: ");
                String id = scanner.nextLine();
                Electroshop pointerEdit = null;
                for (Electroshop e : listBarang) {
                    pointerEdit = e.searchId(id);
                    if (pointerEdit != null) break;
                }

                if (pointerEdit != null) {
                    System.out.println("Berikut data dengan ID tersebut:");
                    System.out.println("Nama: " + pointerEdit.getNama());
                    System.out.println("Kategori: " + pointerEdit.getKategori());
                    System.out.println("Brand: " + pointerEdit.getBrand());
                    System.out.println("Harga: " + pointerEdit.getHarga());

                    System.out.print("Masukkan Nama: ");
                    String nama = scanner.nextLine();
                    System.out.print("Masukkan Kategori: ");
                    String kategori = scanner.nextLine();
                    System.out.print("Masukkan Brand: ");
                    String brand = scanner.nextLine();
                    System.out.print("Masukkan Harga: ");
                    int harga = scanner.nextInt();
                    scanner.nextLine();

                    pointerEdit.editData(nama, kategori, brand, harga);
                } else {
                    System.out.println("Data yang anda cari tidak ditemukan");
                }

            } else if (choice == 4) {
                System.out.print("Masukkan ID data yang ingin dihapus: ");
                String id = scanner.nextLine();
                boolean removed = false;

                Iterator<Electroshop> it = listBarang.iterator();
                while (it.hasNext()) {
                    Electroshop e = it.next();
                    if (e.getId().equals(id)) {
                        it.remove();
                        System.out.println("Data telah dihapus");
                        removed = true;
                        break;
                    }
                }

                if (!removed) {
                    System.out.println("Data tidak ditemukan");
                }

            } else if (choice == 5) {
                System.out.print("Masukkan ID yang ingin dicari: ");
                String id = scanner.nextLine();
                Electroshop pointerEdit = null;
                for (Electroshop e : listBarang) {
                    pointerEdit = e.searchId(id);
                    if (pointerEdit != null) break;
                }

                if (pointerEdit != null) {
                    System.out.println("Berikut data dengan ID " + id + " tersebut:");
                    System.out.println("Nama: " + pointerEdit.getNama());
                    System.out.println("Kategori: " + pointerEdit.getKategori());
                    System.out.println("Brand: " + pointerEdit.getBrand());
                    System.out.println("Harga: " + pointerEdit.getHarga());
                } else {
                    System.out.println("Data yang anda cari tidak ditemukan");
                }
            }
        }

        scanner.close();
    }
}
