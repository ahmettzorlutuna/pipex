# Pipex

## 📌 Proje Açıklaması
**Pipex**, UNIX boru hattı (pipeline) işlemlerini taklit eden bir programdır. Bu proje, shell komutlarının nasıl çalıştığını ve giriş/çıkış yönlendirmelerini anlamaya yönelik bir çalışmadır. `pipex`, iki veya daha fazla komutu bir pipe (`|`) ile bağlayarak, her komutun çıktısını bir sonrakine giriş olarak yönlendirir.

## 🚀 Kullanım
### Standart Kullanım
```sh
./pipex infile "cmd1" "cmd2" ... "cmdN" outfile
```
- `infile`: İlk komutun (cmd1) girdi olarak kullanacağı dosya.
- `cmd1 ... cmdN`: Çalıştırılacak komutlar. Her komut bir öncekinin çıktısını giriş olarak kullanır.
- `outfile`: Son komutun çıktısının yazılacağı dosya.

### Here_doc Modu (Bonus)
```sh
./pipex here_doc LIMITER "cmd1" "cmd2" ... "cmdN" outfile
```
- `here_doc`: Standart girişten (`stdin`) okuma modu.
- `LIMITER`: Girişin sonlandığını belirten kelime.
- `cmd1 ... cmdN`: Çalıştırılacak komutlar.
- `outfile`: Sonuçların yazılacağı dosya.

### Örnek Kullanımlar
#### Standart Kullanım
```sh
./pipex input.txt "cat" "grep hello" "wc -l" output.txt
```
Bu komut şu işlemi gerçekleştirir:
```sh
< input.txt cat | grep hello | wc -l > output.txt
```
`input.txt` içeriği `cat` ile okunur, `grep hello` ile filtrelenir, `wc -l` ile satır sayısı hesaplanır ve sonuç `output.txt` dosyasına yazılır.

#### Here_doc Kullanımı
```sh
./pipex here_doc END "cat" "grep hello" "wc -l" output.txt
```
Bu komut şu işlemi gerçekleştirir:
```sh
<< END cat | grep hello | wc -l >> output.txt
```
Kullanıcıdan giriş alır, `END` girildiğinde giriş kesilir ve komutlar çalıştırılır.

## 🛠 Kurulum ve Derleme
### 1️⃣ Projeyi Klonlayın
```sh
git clone https://github.com/kullanici_adi/pipex.git && cd pipex
```
### 2️⃣ Derleme
```sh
make
```
`make` komutu, gerekli dosyaları derleyerek `pipex` adlı çalıştırılabilir dosyayı oluşturacaktır.

Bonus özellikleri de derlemek için:
```sh
make bonus
```

### 3️⃣ Çalıştırma
```sh
./pipex infile "cmd1" "cmd2" ... "cmdN" outfile
./pipex here_doc LIMITER "cmd1" "cmd2" ... "cmdN" outfile
```

## 🔧 Teknik Detaylar
- `fork()`, `execve()`, `pipe()`, `dup2()`, `close()` gibi sistem çağrıları kullanılmıştır.
- Komut yolları, `PATH` ortam değişkeni üzerinden dinamik olarak bulunur.
- `here_doc` modu için `STDIN` yönlendirmesi eklenmiştir.
- Birden fazla komut desteği sağlanmıştır.
- Standart hata kontrolleri eklenmiştir.

## 📜 Lisans
Bu proje **42 School** kapsamında yapılmıştır ve eğitim amaçlıdır.

---
📌 *Daha fazla bilgi için: [42 Pipex Projesi](https://github.com/kullanici_adi/pipex)*


