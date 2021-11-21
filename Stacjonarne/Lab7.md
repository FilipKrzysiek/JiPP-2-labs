# Laboratorium 7 (22/23.11.2021)

Celem tego laboratorium jest zapoznanie się z tematyką dziedziczenia i polimorfizmem.

## Dziedziczenie

Dziedziczenie, jak mówi słownik języka polskiego, dziedziczyć, to otrzymywać coś w spadku. W programowaniu też ma to zastosowanie, ponieważ klasę bazową może odziedziczyć inna klasa i otrzyma od niej wszystkie pola i metody, które były w przestrzeni `protected` i `public`. Można określić to inaczej, dziedziczenie, to rozszerzanie, ale nie tylko. Przeanalizujmy poniższe klasy. Przeanalizujmy poniższy przykład.

```c++
class Student {
protected:
    string firstName, lastName;
    string idNumber;
    vector<unsigned short> grades; //*10
    
public:
    void printPerson();
    
    void printGrades();
    
    void printIdNumber();
};

class Worker {
protected:
    string firstName, lastName;
    unsigned salary;
    string emplacement;
    
public:
    void printPerson();
    
    void printSalary();
    
    void printEmplacement();
};

class Teacher {
protected:
    string firstName, lastName;
    unsigned salary;
    string emplacement;
    vector<string> subjets;
    
public:
    void printPerson();
    
    void printSalary();
    
    void printEmplacement();
    
    void printSubjects();
    
    void printAllData();
};
```

Przeanalizuj te klasy. Dostrzegłeś coś? Mają one części wspólne. Pierwszą częścią, która się powtarza wszędzie jest `string firstName, lastName;` i `void printPerson();`. Stwórzmy z tego osobną klasę, która będzie takim ogólnikiem i będzie przechowywać podstawowe informacje o osobie, będzie się ona nazywać `Person`.

`Student` zawiera tylko pola z klasy `Person` i jakieś swoje, które są charakterystyczne dla tej klasy. Spójrz teraz na klasę `Worker` i `Teacher`. Mają one znowu te same pola. Zróbmy ot samo co wcześniej, czyli wyłączmy z klasy `Teacher` i `Worker` część wspólną tych klas. Wyszło na to, że to będzie cała klasa `Worker`, niech tak zostanie. Czyli `Teacher` będzie specjalizował klasę `Worker`.

Podsumujmy stworzyliśmy klasę bazową `Person`, po której dziedziczą klasy `Student` i `Worker`. Następnie Stworzyliśmy dziedziczenie `Teachera` z `Workera`. Zobacz poniżej, jak będzie to wyglądać.

```c++
class Person {
protected:
    string firstName, lastName;
    
public:
    void printPerson();
};

class Student : public Person {
protected:
    string idNumber;
    vector<unsigned short> grades; //*10
    
public:
    void printGrades();
    void printIdNumber();
};

class Worker : public Person {
protected:
    unsigned salary;
    string emplacement;
    
public:
    void printSalary();
    void printEmplacement();
};

class Teacher: public Worker {
protected:
    vector<string> subjets;
    
public:
    void printSubjects();
    
    void printAllData();
};
```


Wiesz już, jakie jest podstawowe zadanie dziedziczenia. Wyciąganie części wspólnej, czyli mówiąc inaczej, wyłączanie przed nawias. Co nam to daje? Po pierwsze upraszcza struktórę i kod (nie mamy tego samego w 10 miejscach), upraszcza tworzenie modyfikacji, ponieważ nie musimy robić zmian w 10 miejscach, wystarczy, że zrobimy w jednym. Może jednak to też mieć drugą stronę medale, ale nie ma niczego, co ma same plusy.

## Zadanie

1. Stwórz klasę figura, która będzie przechowywać nazwę i kolor.
2. Stwórz klasę dla konkretnych figur, które będą dziedziczyć po `Figure`.
3. Stwórz metody służące do obliczania pola i obwodu.


&nbsp;

&nbsp;

# Polimorfizm

Polimorfizm (wielopostaciowość) jest to cecha programowania obiektowego, umożliwiająca różne zachowanie tych samych metod wirtualnych (funkcji wirtualnych) w czasie wykonywania programu.

Najprościej rzecz ujmując możemy przechowywać w obiekcie typu klasy bazowej, obiekt typu klasy dziedziczącej. Czyli takie troszkę oszukiwanie.

```c++
Figure *fig = new Circle();
```

Polimorfizm działa tylko i wyłącznie ze wskaźnikami i referencją

```c++
Rectangle rect = new Rectangle();
Figure& fig1 = rect
```

Klasa Figure jest klasą bazową i posiada przepis na naszą klasę, część metod pokrywa się z klasą Circle.
Przykładem niech będzie `Figure`.

1. Stwórz klasę `Figure`.
2. Zadeklaruj metodę virtualną `double getArea()`.
```c++
virtual double getArea() = 0; //Przypisujemy 0, aby nie było ciała metody
```
3. Stwórz klasę `Circle` z konstruktorem, który przyjmuje promień.
4. Odziedzicz klasę `Figure`, zaimplementuj `getArea`.
5. Stwórz klasę `Rectangle` z konstruktorem, który przyjmuje długości boków.
6. Odziedzicz klasę `Rectangle`, zaimplementuj `getArea`.
7. Użyj następującego pliku main
```c++
int main() {
    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);
    
    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
}
```
