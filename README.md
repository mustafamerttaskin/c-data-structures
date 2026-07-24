<div align="center">

# 🔗 c-data-structures

**Sıfırdan C: bağlı liste ve yığın, birim testleriyle birlikte**

![C](https://img.shields.io/badge/C-C11-00599C?logo=c&logoColor=white)
![Build](https://img.shields.io/badge/Build-Makefile-informational)
![Tests](https://img.shields.io/badge/Tests-assert%20tabanlı-4c9a2a)
![License](https://img.shields.io/badge/Bağımlılık-Yok-lightgrey)

</div>

---

## Ne var

Harici bağımlılığı olmayan, sıfırdan yazılmış iki klasik veri yapısı:
**tek yönlü bağlı liste (singly linked list)** ve **dizi tabanlı yığın
(array-based stack)** — her ikisi için de birim test paketiyle birlikte.

| Dosya | İçerik |
|---|---|
| `src/linked_list.c` | `push_front` / `push_back`, değere göre silme, `contains`, `reverse`, hata ayıklama için `list_to_string` |
| `src/stack.c` | Sabit kapasiteli dizi tabanlı yığın — `push`, `pop`, `peek`, dolu/boş kontrolleri |
| `src/main.c` | Her iki yapıyı senaryolu bir dizi işlemden geçiren demo |
| `tests/` | Normal durumlar ve uç durumları (boş liste, dolu yığın, boş yığından pop) kapsayan assert tabanlı testler |

## Neden

Ders dışında C'de elle bellek yönetimi, pointer manipülasyonu ve API
tasarımını pratik etmek için. Her satırın kolayca açıklanabilmesi için
bilinçli olarak küçük tutuldu.

## Derleme ve çalıştırma

```bash
make demo && ./demo   # walkthrough demosunu çalıştır
make test             # tüm birim testlerini derle ve çalıştır
make clean             # derleme çıktılarını temizle
```

### Örnek çıktı

```
=== Linked List demo ===
After pushes: [5, 10, 20, 30] (size=4)
After removing 20: [5, 10, 30] (size=3)
Contains 30? yes
Contains 99? no
After reverse: [30, 10, 5]

=== Stack demo ===
Top after pushing 1,2,3: 3
Popped: 3
Popped: 2
Popped: 1
Stack empty now? yes
```

## Proje yapısı

```
c-data-structures/
├── include/
│   ├── linked_list.h
│   └── stack.h
├── src/
│   ├── linked_list.c
│   ├── stack.c
│   └── main.c
├── tests/
│   ├── test_linked_list.c
│   └── test_stack.c
└── Makefile
```
