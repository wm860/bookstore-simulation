Dane podawane programowi przez użytkownika, potrzebne do rozpoczęcia symulacji:
 - czas [unsigned short int - czas jednostkowy]
 - liczba sprzedawców [1-5]
 - liczba klientów [1-3] 
 - liczba ksiażek [5-20]

Dane wczytywane z pliku (nazwy plików też będą podawane jako argumenty) domyślnie:
- books.txt - tytuly ksiazek, ktore beda do dyspozycji przy tworzeniu ksiegarni

Lista książek (baza danych) wczytywana z pliku books_data_base.txt. Będą to książki, o które klienci będą mogli się pytać.

Do wczytywania danych z pliku utworzono odrębną klasę o nazwie file_operation. W niej znajdują się następujące metody:




Dodatkowe info:
- W .vscode w launchu w args masz podane domyślne argumenty wejściowe.
- niech losowość może polega na samym ustaleniu czynnosci danego klienta, a nie na wyborze liczby klientow; liczba klientow ustalana jako argument startowy programu przez uzytownika

To do:
 - Na końcu projektu nazwy ścieżki plików dodać jako argumenty wczytywania programu
 - Dodać losowość w programie - losowanie aktywności klienta, czyli niech generator zdecyduje, czy klient ma np. kupic ksiazke, zapytac sie o ksiazke, czy wyjsc z ksiegarni. Proponuję to zrobić tak:
    1) Każdemu klientowi generator na poczatku ustawia cel wizyty, np 1 to kup ksiazke, 2 to zapytaj o ksiazke itd. [genre class tu można użyć?]
    2) Do klienta przydzielany jest sprzedawca
    3) Do klienta losowana jest książka z listy książek którą utworzę
Czyli w każdym kroku symulacji ma powstać taka macierz gdzie wiersze określają klientów, a kolumny kolejno:
        - id klienta,
        - id sprzedawcy
        - wylosowana czynnosc
        - wylosowana ksiazka
gdy dana książka zostanie zakupiona to wówczas zmieni się atrybut state klasy książka.

Niech na początku wszystko odbywa się w czasie jednostkowym i np dla 1 sprzedawcy, potem się doda opcje, że dana czynność trwa więcej niż 1 pętle 
