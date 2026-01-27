# systemy-wbudowane-zaliczenie-2
## Przygotowanie środowiska (SSH i klonowanie repozytorium)
1. Sklonuj repozytorium z kluczem i skonfiguruj SSH:

```
git clone https://github.com/Daniel880/systemy-wbudowane-key.git   # pobranie repo z kluczem
cd systemy-wbudowane-key                                            # wejście do katalogu

chmod 600 systemy-wbudowane-2                                       # ustawienie praw do klucza
eval "$(ssh-agent -s)"                                              # uruchomienie ssh-agenta
ssh-add systemy-wbudowane-2                                         # dodanie klucza do agenta
```

2. Skonfiguruj dane użytkownika (wstaw swoje dane):

```
git config --global user.name "Imie Nazwisko"                       # ustawienie nazwy użytkownika
git config --global user.email "imie@nazwisko.com"                  # ustawienie adresu email
```

3. Sklonuj główne repozytorium:

```
cd ..                                                               # wyjście poziom wyżej
git clone git@github.com:Daniel880/systemy-wbudowane-zaliczenie-2.git          # klon repo projektu przez SSH
cd systemy-wbudowane-zaliczenie-2
```

## Opis zadania
Repozytorium zawiera zaawansowany system diagnostyki systemowej w C++. Projekt wykorzystuje **bibliotekę statyczną** do obsługi danych systemowych. W projekcie **brakuje jednego pliku `.cpp`**, który należy dodać oraz uwzględnić w konfiguracji CMake.

Zadanie polega na:
1. Dodaniu jednego pliku `.cpp`.
2. Uzupełnieniu [CMakeLists.txt](CMakeLists.txt) o dodany plik (już przygotowany).
3. Dodaniu definicji funkcji `generate_diagnostics_report()`.
4. Implementacji funkcji, która wypisuje raport diagnostyczny, wykorzystując funkcje z [include/diagnostics.h](include/diagnostics.h).
5. Utworzeniu commita.
6. Utworzeniu brancha o odpowiedniej nazwie.
7. Wysłaniu kodu do repozytorium na GitHub.


## Wymagany format wyjścia
Program musi wypisać **dokładnie 5 linii** w następującym formacie (bez polskich znaków):

```
=== SYSTEM STATUS ===
Engineer: DanielWyrwal
Branch: Zaliczenie2-DanielWyrwal
Uptime: 5h 23m
Running Processes: 127
```

Wartości `Uptime` oraz `Running Processes` są zwracane przez przygotowane funkcje — należy je jedynie sformatować i wypisać.
Pole `Engineer` musi odpowiadać nazwie gałęzi bez prefiksu `Zaliczenie2-` (bez spacji).

## Wymagania implementacyjne
1. Utworzyć plik [src/student_output.cpp](src/student_output.cpp).
2. Dodać plik do listy źródeł w [CMakeLists.txt](CMakeLists.txt) (już przygotowany).
3. Zaimplementować funkcję `generate_diagnostics_report()` w pliku [src/student_output.cpp](src/student_output.cpp) zadeklarowaną w [include/student_output.h](include/student_output.h).
4. Skorzystać z funkcji z [include/diagnostics.h](include/diagnostics.h):
	- `get_branch_name()`
	- `get_system_uptime()`
	- `get_running_processes()`

## Przykładowa struktura pliku student_output.cpp
```cpp
#include "student_output.h"
#include "diagnostics.h"

#include <iostream>

void generate_diagnostics_report() {
	std::cout << "=== SYSTEM STATUS ===" << std::endl;
	std::cout << "Engineer: " << ImieNazwisko << std::endl;
	std::cout << "Branch: " << get_branch_name() << std::endl;
	std::cout << "Uptime: " << get_system_uptime() << std::endl;
	std::cout << "Running Processes: " << get_running_processes() << std::endl;
}
```

## Wymagania dotyczące gałęzi
Nazwa gałęzi musi mieć format: `Zaliczenie2-ImieNazwisko` (ASCII, bez polskich znaków i bez spacji).

## Wymagane pakiety (Alpine Linux)
Należy zainstalować: `cmake`, `make`, `g++`, `git`.
Przykład: `apk add cmake make g++ git`

## Budowanie lokalne
```
mkdir -p build
cd build
cmake ..
make
./zaliczenie2
```

## GitHub Actions
Workflow weryfikuje:
1. Generowanie CMake
2. Kompilację biblioteki i aplikacji
3. Uruchomienie programu bez błędu

## Architektura projektu
- **include/system_info.h** - Funkcje niskopoziomowe do odczytu informacji systemowych
- **include/diagnostics.h** - Interfejs publiczny do generowania raportu diagnostycznego
- **src/system_info.cpp** - Implementacja funkcji systemowych
- **src/diagnostics.cpp** - Logika diagnostyki (do uzupełnienia przez studenta)
- **src/student_output.cpp** - **Plik do uzupełnienia przez studenta**
- **src/main.cpp** - Punkt wejścia aplikacji