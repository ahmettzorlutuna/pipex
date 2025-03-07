# pipex
My école 42 pipex project

Pipex

📌 Proje Açıklaması

Pipex, UNIX boru hattı (pipeline) işlemlerini taklit eden bir programdır. Bu proje, shell komutlarının nasıl çalıştığını ve giriş/çıkış yönlendirmelerini anlamaya yönelik bir çalışmadır. pipex, iki veya daha fazla komutu bir pipe (|) ile bağlayarak, her komutun çıktısını bir sonrakine giriş olarak yönlendirir.

🚀 Kullanım

Standart Kullanım

./pipex infile "cmd1" "cmd2" ... "cmdN" outfile

infile: İlk komutun (cmd1) girdi olarak kullanacağı dosya.

cmd1 ... cmdN: Çalıştırılacak komutlar. Her komut bir öncekinin çıktısını giriş olarak kullanır.

outfile: Son komutun çıktısının yazılacağı dosya.

Here_doc Modu (Bonus)

./pipex here_doc LIMITER "cmd1" "cmd2" ... "cmdN" outfile

here_doc: Standart girişten (stdin) okuma modu.

LIMITER: Girişin sonlandığını belirten kelime.

cmd1 ... cmdN: Çalıştırılacak komutlar.

outfile: Sonuçların yazılacağı dosya.

Örnek Kullanımlar

Standart Kullanım

./pipex input.txt "cat" "grep hello" "wc -l" output.txt

Bu komut şu işlemi gerçekleştirir:

< input.txt cat | grep hello | wc -l > output.txt

input.txt içeriği cat ile okunur, grep hello ile filtrelenir, wc -l ile satır sayısı hesaplanır ve sonuç output.txt dosyasına yazılır.

Here_doc Kullanımı

./pipex here_doc END "cat" "grep hello" "wc -l" output.txt

Bu komut şu işlemi gerçekleştirir:

<< END cat | grep hello | wc -l >> output.txt

Kullanıcıdan giriş alır, END girildiğinde giriş kesilir ve komutlar çalıştırılır.

🛠 Kurulum ve Derleme

1️⃣ Projeyi Klonlayın

git clone https://github.com/kullanici_adi/pipex.git && cd pipex

2️⃣ Derleme

make

make komutu, gerekli dosyaları derleyerek pipex adlı çalıştırılabilir dosyayı oluşturacaktır.

Bonus özellikleri de derlemek için:

make bonus

3️⃣ Çalıştırma

./pipex infile "cmd1" "cmd2" ... "cmdN" outfile
./pipex here_doc LIMITER "cmd1" "cmd2" ... "cmdN" outfile

🔧 Teknik Detaylar

fork(), execve(), pipe(), dup2(), close() gibi sistem çağrıları kullanılmıştır.

Komut yolları, PATH ortam değişkeni üzerinden dinamik olarak bulunur.

here_doc modu için STDIN yönlendirmesi eklenmiştir.

Birden fazla komut desteği sağlanmıştır.

Standart hata kontrolleri eklenmiştir.
