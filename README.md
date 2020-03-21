# Penjelasan dan Penyelesaian Soal Shift 1 Sistem Operasi
disusun oleh: M. Mikail Dwi Khusnanda (028) & Ghifari Akbar R (040)



# Soal Nomer 1a

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

# Soal Nomor 1b
<h2>1. Penjelasan</h2>
pada poin b, menampilkan 2 negara bagian (state) yang memiliki keuntungan (profit) paling sedikit berdasarkan hasil poin a dimana sudah diketahui poin a hasilnya adalah central, lalu kita harus mencari, disini, karena saya belum mendalami, saya menggunakan cara manual biasa, dengan menginputkan negara bagian yang memiliki region central. dan menghitung seperti poin a.

<h2>2. Penyelesaian</h2>
<img src="dokumentasi/dokum3.png">
pertama, sama seperti poin a, dimana begin saya gunakan untuk deklarasi variable, lalu pada main nya, saya isi dengan matching value tiap negara bagian, lalu penambahan yang sama dengan poin a, dan pada end, dilakukan perkondisian dimana jika kurang dari "satu" dimana satu adalah nilai terkecil, dan dua adalah nilai terkecil kedua, dan nsatu adalah nama nilai terkecil, dan ndua adalah nama nilai terkecil kedua.
pada if jika nilai lebih kecil dari nilai yang sudah ada pada satu, maka dua = satu dan satu = nilainya, dan sama pula untuk nama tiap variable nya.
lalu prinf pertama untuk saya mengecek, prinf kedua untuk nilai pasti terkecilnya
<img src="dokumentasi/dokum4.png">
hasilnya:

```
terkecil pertama adalah Texas berjumlah -24798
kedua adalah Illinois berjumlah -11559
```
<h2>Kesulitan</h2>
dari script saya sendiri paham bahwa script saya tidak efektif, tidak responsif dan rawan error.

<hr></hr>
<h4>*Update</h4>
<img src="dokumentasi/dokum5.png">
Ternyata saya bisa menemukan solusi lain setelah mencari cari, menggunakan array, untuk begin sama, untuk deklarasi var, lalu pada main nya, saya isi memasukkan kolom 11 yang kolom 13 nya adalah central, lalu menghitung menggunakan += profitnya, yaitu kolom 21.
lalu pada end, menggunakan for 2 kali untuk mengetahui yang paling sedikit pertama dan kedua, yang pertama di loop dulu, setelah ketemu, yang kedua di loop, loopnya menggunakan jika nilai pertama lebih kecil dari profit var itu, maka masukkan nilai dan nama var itu ke "pertama" atau discript bernama "satu" untuk nilai dan "nsatu" untuk nama var nya, yang kedua sama namun kondisinya ditambah "dan lebih besar dari (satu)"
<img src="dokumentasi/dokum6.png">

<h2>Source</h2>
https://unix.stackexchange.com/questions/242946/using-awk-to-sum-the-values-of-a-column-based-on-the-values-of-another-column

# Soal Nomor 1c
<h2>1. Penjelasan</h2>
dalam soal 1c, menampilkan 10 produk (product name) yang memiliki keuntungan (profit) paling sedikit berdasarkan 2 negara bagian (state) hasil poin b, dimana hasil poin b adalah Texas dan Ilinois, menggunakan cara yang lebih sederhana namun lebih kompleks hehe~, dengan menggunakan array, sort dan head untuk membatasi output, tanpa mendeklarasikan variable.

<h2>2. Penyelesaian</h2>
<img src="dokumentasi/dokum7.png">
dalam script diatas, menggunakan if yang sama seperti nomor 1b, dengan kondisi "atau", dan di END, menggunakan for untuk print angka dulu baru nama, lalu kita pipe dengan sort lalu pipe lagi dengan head, sort -g adalah sorting bilangan, jika tidak ada, maka minus dan tidak menjadi satu (1,-1,-1,2,3,-3...) yang harusnya (-3,-1,-1,1,2,3..) dan "head -n" n disini adalah line nya, berapa jumlah line dari head yang akan ditampilkan, karena dibutuhkan 10, maka head -n 10

<img src="dokumentasi/dokum8.png">

<h2>Kesulitan</h2>
-
<h2>Source</h2>
https://superuser.com/questions/264442/how-do-i-limit-the-number-of-displayed-lines-through-ls


# Soal Nomor 2a dan b
<h2>1. Penjelasan</h2>
membuat sebuah script bash yang dapat menghasilkan password secara acak sebanyak 28 karakter yang terdapat huruf besar, huruf kecil, dan angka. (b) Password acak tersebut disimpan pada file berekstensi .txt dengan nama berdasarkan argumen yang diinputkan dan HANYA berupa alphabet.
pertama, diharapkan pembaca memahami sed, pipe, dan bash dasar.
didalam kodingan, saya menggunakan for i in $* yang berarti tiap argumen yang ditulis, jalankan program, lalu echo $i sebagai inputan dari sed nya, pada sed nya, digunakan alphabet yang di invers, yang berarti selain alphabet di replace dengan tidak ada atau /(kosong)/ lalu inputan itu dimasukkan kedalam pipe lagi yang mana dimasukkan dalam var nama, lalu menggunakan password generator apg, dengan SNCL dimana harus memiliki satu special char yang sudah ditentukan, minimal 28 kata max 28 kata, dan output cuma 1 dan dimasukkan ke file txt yang bernama "nama" dari yang sudah di inputkan

<h2>Penyelesaian</h2>
<img src="dokumentasi/dokum9.png">
<img src="dokumentasi/dokum10.png">
cukup jelas dari pembahasan di Penjelasan

<h2>Kesulitan</h2>
untuk mencari penggunaan sed cukup menguras waktu, tapi bisa

# Soal Nomor 2c
<h2>1. Penjelasan</h2>
menenkripsi dengan menggunakan konversi huruf (string manipulation) yang disesuaikan
dengan jam(0-23), disini saya menggunakan cara semi manual/WET, pertama yang harus dikuasai adalah: bash umum, pipe, tr, date, apg. pengenkripsian data menggunakan chipertext, dengan menambahkan jam didalam string nama, contoh: pembuatan file yang bernama a pada jam 01:12 menjadi b.txt

<h2>Penyelesaian</h2>
<img src="dokumentasi/dokum11.png">
didalam script ini, saya menggunakan element yang sama seperti 2b, yaitu sed, dan apg, adapula yang baru dipelajari bernama tr, tr hampir sama dengan sed namun karena beberapa masalah yang dapat dilihat pada seksi kesulitan dibawah, akhirnya kami menggunakan tr. didalam script memiliki var A dimana untuk mendeklarasikan jam sekarang, lalu iter yang sama seperti poin 2b, dan didalam pipe kedua, kami tambahkan if dan elif untuk jika waktu sama dengan jam 0,1,2,3.. dan seterusnya, jika jam 1 (contoh), maka terdapat 

```
tr'[A-Za-z]' '[B-ZAb-za]'
```
yang mana artinya tolong ubah dari A-Z atau a-z menjadi B-Z dan A atau menjadi b-z dan a, jika ada alphabet Z maka akan menjadi A.

dan hasilnya di pipe lagi dan memasukkan fungsi apg sebagai password generator ke dalam file bernama hasil tadi . txt
<img src="dokumentasi/dokum12.png">
<h2>Kesulitan</h2>
didalam fitur sed, entah saya yang memang kurang mendalami atau gimana, separator kedua sed tidak bisa memberikan expresi, contoh:

```
sed s/[A-Z]/[B-ZA]/g
fungsi diatas bermakna tolong ganti setiap A sampai Z menjadi [B-ZA], jika kita input ABCD maka akan menjadi 
[B-ZA][B-ZA][B-ZA][B-ZA] karena separator kedua atau inputan tidak bisa berupa ekspresi.
```

# Soal Nomor 2d
<h2>1. Penjelasan</h2>
de encrypt dari nomer 2c hampir sama, menggunakan cara yang sama namun dibalik.

<h2>penyelesaian</h2>
<img src="dokumentasi/dokum13.png">
hanya membalik dari

```
tr '[A-Za-z]' '[C-ZA-Bc-za-b]'
menjadi
tr '[C-ZA-Bc-za-b]' '[A-Za-z]'
dan seterusnya
```
hasil:
<img src="dokumentasi/dokum14.png">

# Soal Nomor 3a
<h2>1. Penjelasan</h2>
membuat script untuk mendownload 28 gambar dari
"https://loremflickr.com/320/240/cat" menggunakan command wget dan menyimpan file
dengan nama "pdkt_kusuma_NO" (contoh: pdkt_kusuma_1, pdkt_kusuma_2,
pdkt_kusuma_3) serta jangan lupa untuk menyimpan log messages wget kedalam
sebuah file "wget.log".

<h2>penyelesaian</h2>
<img src="dokumentasi/dokum15.png">
Menggunakan bash script yang bernama hello-world mendownload 28 gambar dari situs loremflickr.com/320/240/cat dinamai dengan pdkt_kusuma_nomor. Langkah pertama dilakukan for loop sebanyak 28 kali, di dalam loop tersebut mengambil gambar dengan fungsi wget dan menyimpan dalam wget.log. Mengubah nama dengan ekstensi -O dan -nd untuk mengekslusikan direktori dari download. -r untuk download rekursif atau berulang. beserta url download yaitu dari situs di atas
<img src="dokumentasi/dokum16.png">

# Soal Nomor 3b
<h2>1. Penjelasan</h2>
membuat script no 3a yang berjalan setiap 8 jam dimulai dari jam 6.05 setiap hari kecuali hari Sabtu

<h2>penyelesaian</h2>
embuat crontab dengan fungsi crontab -e lalu mengisinya dengan format 5 6,14,22 * * 0,1,2,3,4,5 /home/ghifari/hello-world dengan 5 menit 6,14,22 setiap 8 jam dimulai dari jam 6 lalu hari dimulai dari hari 0 yaitu minggu yaitu sampai jumat yaitu 5 

```
5 6,14,22 * * 0,1,2,3,4,5 /home/peacefulhack/hello-world
```

# Soal Nomor 3c
<h2>1. Penjelasan</h2>
Untuk menemukan gambar yang identik dan memindahkan gambar tersebut ke dalam folder khusus diperlukan algoritma sorting untuk membandingkan gambar satu per satu. Dalam membuat script untuk mengidentifikasi gambar harus mencari gambar yang identik dan memisahkan gambar tersebut ke dalam folder bernama duplicate. Sedangkan gambar yang tidak identik akan ditaruh pada folder kenangan. Lalu dilakukan log menjadi log.bak.


<h2>penyelesaian</h2>
<img src="3c.png">
<img src="3c_.png">
<img src="3c1.png">
<img src="3c2.png">
<img src="3c3.png">
Untuk mengidentifikasi gambar yang identik langkah awal yaitu membuat variabel b untuk mencari semua gambar pdkt_kusuma, lalu mensorting semua gambar tersebut. Lalu dilakukan grep untuk menccari lokasi gambar tersebut dan memasukannya ke dalam location.log. Setelah itu, dilakukan looping untuk mencari gambar mana yang identik dengan menandai gambar mana yang identik. Gambar yang identik akan ditaruh pada array c=() dan pada folder duplicate sedangkan yang tidak identik akan ditaruh pada kenangan dan melakukan wget log.

<h2>Kesulitan</h2>
Memindahkan semua gambar identik, gambar yang terpindahkan merupakan gambar identik tetapi tidak semua yang identik dipindahkan. Mencari cara untuk membandingkan semua gambar.
