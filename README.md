# Penjelasan dan Penyelesaian Soal Shift 1 Sistem Operasi
disusun oleh: M. Mikail Dwi Khusnanda (028) & Ghifari Akbar R (040)



# Soal Nomer 1

<h2>1. Penjelasan</h2>
<p>Dalam memuat program yang menyerupai crontab tetapi berupa script bash diperlukan berbagai metode. saat ini akan dilakukan metode daemon yaitu background process yang berjalan menggunakan script bash.

<h2>2. Penyelesaian</h2>
<img src="Soal1/Screen Shot 2020-03-21 at 10.10.24.png">
<p>pertama diperlukan time_t dan struct localtime untuk mengambil waktu yang dibutuhkan saat ini. Lalu menggunakan template daemon dilakukan fork pada child process dan dibandingkan argumen yang diberi untuk menentukan apakah format detik, menit, atau jam salah.
dengan cara menjumlahkan profit dari region yang sama, lalu membandingkan sampai dapat region dengan keuntungan paling sedikit.
</p>

<img src="Soal1/Screen Shot 2020-03-21 at 10.10.37.png">

<img src="Soal1/Screen Shot 2020-03-21 at 10.10.46.png">

<h2>Kesulitan</h2>
Kesulitan paling terlihat pada membuat algoritma untuk membandingkan format detik, menit, dan jam. Menentukan mana yang salah dan mana yang sesuai. Karena template daemon sudah tersedia maka membuat daemon tidak terlalu menyulitkan.

# Soal Nomor 2
<h2>1. Penjelasan</h2>
Program soal nomer 2 diharuskan untuk membuat folder khusus dan membuat folder baru setiap 30 detik dengan nama timestamp. Lalu setiap folder yang baru dibuat setiap 30 detik itu mendownload sebanyak 20 gambar dari url https://picsum.photos setiap 5 detik dengan ukuran tertentu. Setelah semua didownload maka folder akan dizip. Lalu dibuat program untuk menterminasi semua proses tersebut, setelah menterminasi program tersebut akan mendelte dirinya sendiri.

<h2>2. Penyelesaian</h2>
<img src="Soal2/ss 2020-03-21 at 10.31.02.png">
fungsi sighanldr untuk menerima sinyal handler lalu, dibuat sebanyak 7 pid_t untuk menjalankan proses yang berbeda beda. lalu dibuat time_t untuk mendapatkan waktu saat ini, dan char tanggal untuk menyimpan waktu saat ini.
<img src="Soal2/ss 2020-03-21 at 10.31.09.png">
Lalu dijalankan command chdir untuk mengubah working directory menjadi /home/peacefulhack/Documents/Sistem Operasi/modul 2/SoalShiftSISOP20_modul2_T18/Soal2/

<img src="Soal2/ss 2020-03-21 at 10.31.31.png">
Lalu dibuat proses killer untuk mematikan proses menggunakan SIGKILL sehingga menterminasi semua proses.

<img src="Soal2/ss 2020-03-21 at 10.31.39.png">
<img src="Soal2/ss 2020-03-21 at 10.31.48.png">

<p>Lalu menggunakan curl didownload gambar dari url https://picsum.photos setiap 5 detik. pertama mengambil waktu saat ini menggunakan strftime dan menyimpan waktu tersebut dalam struct info dan char tanggal. Lalu dibuatkan folder dengan bernama tanggal saat itu melalui fork.</p>

<img src="Soal2/ss 2020-03-21 at 10.31.59.png">

<p>Pada bagian ini dilakukan curl untuk mendwonlaod gambar dari website. Lalu nama gambar yang didownnload disambungkan dengan strcat dengan nama folder yang dibuat yaitu tanggal.</p>

<img src="Soal2/ss 2020-03-21 at 10.32.14.png">

<p>Lalu saat semua proses dijalankan dilakukan zip dan setelah menzip folder tersebut dilakukan remove directory folder tanggal tersebut sehingga hanya tersisa hasil zip saja.</p>

<h2>Kesulitan</h2>
Kesulitan menentukan bagaimana melakukan fork pada berbagai proses yang banyak dan menentukan argumen yang tepat untuk command tertentu. Terkadang juga terdapat proses yang tidak berjalan tetapi setelah diperbaiki semua proses berjalan dengan normal.

# Soal Nomor 3
<h2>1. Penjelasan</h2>
Dalam soal nomor 3 diperlukan program yang berjalan secara bersamaan atau disebut multiprocessing. Membuat dua direktori, lalu setelah direktori pertama selesai dan lima detik kemudian dibuat direktori kedua. Lalu dalam zip mengeskrak file .jpg. dan semua esktrakan harus dipindahkan ke folder satu. Dan direktori ke folder direktori yang lain. Lalu setiap direktori yang dipindahkan dibuat dua folder teks kosong dengan ekstensi .txt.

<h2>2. Penyelesaian</h2>
<img src="Soal2/Screen Shot 2020-03-21 at 11.05.54.png">
<p>cekfolder di atas digunakan untuk menentukan apakah direktori yang dibuat sudah sesuai atau benar. Lalu dibuat tiga proses dengan fork(). Pada proses ch_a dilakukan unzip atau ekstrak jpg dari file zip yang ada. Pada proses ch_b dibuat direktori baru bernama indomi. Lalu jika kedua proses tersebut selesai maka dibuat direktori sedap. </p>

<img src="Soal3/Screen Shot 2020-03-21 at 11.06.06.png">
<img src="Soal3/Screen Shot 2020-03-21 at 11.06.11.png">
<p> Lalu membuat .txt dari kedua direktori tersebut. dan mengakhiri program</p>

<h2>Kesulitan</h2>
Menentukan command yang sesuai untuk membuat file txt dan mengekstrak file. 

