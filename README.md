Dane wczytywane potrzebne do rozpoczęcia symulacji:
 - czas [unsigned short int]
 - liczba sprzedawców [1-5]
 - liczba klientów [1-3] 
 - liczba ksiażek [5-20]
 Dane te wczytywane z pliku simulation_start.txt lub podawane podczas wywołania funkcji.

Lista książek (baza danych) wczytywana z pliku books_data_base.txt. Będą to książki, o które klienci będą mogli się pytać.

Do wczytywania danych z pliku utworzono odrębną klasę o nazwie file_operation. W niej znajdują się następujące metody:
1) 