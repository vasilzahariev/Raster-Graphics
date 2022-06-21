# FMI-OOP-Raster-Graphics
Проектът представлява конзолен редактор на растерни изображения, който поддържа работа с 3 вида файлови формата (небинарните версии на PBM, PGM и PPM), работа с множество потребителски сесии и прилагане на различни трансформации върху изображенията.

Повече информация за поддържаните типове: https://en.wikipedia.org/wiki/Netpbm

Проектът е изграден на чист C++.

## Съдържание
1. [Конфигуриране на приложението](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#конфигуриране-на-приложението)
2. [Функционалности](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#функционалности)
3. [Структура на проекта](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#структура-на-проекта)
    1. [Main.cpp](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#maincpp)
    2. [Engine](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#engine)
    3. [Command](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#command)
    4. [Image](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#image)
    5. [Session](https://github.com/vasilzahariev/FMI-OOP-Raster-Graphics/#session)

## Конфигуриране на приложението

## Функционалности

| Команда | Описание | Брой аргументи | Аргументи |
| ------ | ------ | ------ | ------ |
| *open \<fileLocation>* | Отваря файл, прочита информацията му, създава сесия и добавя прочетената информация в нея. | 1 | ***\<fileLocation>*** -> локация на файла |
| *add \<fileLocation>* | Отваря файл, прочита информацията му и добавя прочетената информация в активната сесия. | 1 | ***\<fileLocation>*** -> локация на файла |
| *undo* | Отменя последната незапазена операция (няма ефект върху **add** и **open**). | 0 | - |
| *save* | Запазва промените на всяка снимка от активната сесия обратно в съответните им файлове. | 0 | - |
| *saveas \<fileLocation>* | Запазва промените на първата снимка в активната сесия на определена локация. | 1 | ***\<fileLocation>*** -> локация на файла |
| *close* | Затваря активната сесия като изтрива незапазените промени. | 0 | - |
| *grayscale* | Преобразува всички цветни изображения в активната сесия в такива използващи нюанси на сивото. | 0 | - |
| *monochrome* | Преобразува всички цветни и сиви изображения в активната сесия в черно-бели. | 0 | - |
| *negative* | Прилага трансофрмация негатив върху всички изображения в активната сесия. | 0 | - |
| *rotate \<direction>* | Завърта всички изобравения в активната сесия на +90 или -90 градуса. | 1 | ***\<direction>*** -> посока на завъртане (**right** или **left**) |
| *collage \<direction> \<image1> \<image2> \<outImage>* | Създава вертикален или хоризонтален колаж на две изображения от един и същ тип. Колажа се записва в \<outImage> и се добавя към активната сесия | 4 | ***\<direction\>*** -> ориентация на колажа (**horizontal** или **vertical**)<br /><br />***\<image1>*** -> локация на файла съдърщаш първата снимка<br /><br />***\<image2>*** -> локация на файла съдържащ втората снимка<br /><br />***\<outImage>*** -> локация на файла, в който ще бъде записан колажа |
| *session info* | Връща информация за активната сесия (идентификатор на сесията, отворени снимки, незапазени операции). | 0 | - |
| *switch \<session>* | Сменя активната сесия на определена сесия. | 1 | ***\<session>*** -> идентификатор на определената сесия |
| *help* | Връща информация за всяка от поддържаните команди. | 0 | - |
| *exit* | Излиза от програмата като преди това проверява дали има незапазени промени в активната сесия и ако има пита потребителя дали иска да ги запази или не. | 0 | - |

## Структура на проекта

### Main.cpp
Съдържа *int main()* функцията, която служи за стартова точка на програмата.

### Egnine
Класът **Engine** представлява Singleton клас, който отговаря за входовете и изходите. Той се грижи за поемането и обработването на грешки.

| Видимост | Метод | Описание | Параметри |
| ------ | ------ | ------ | ------ |
| public | *static Engine& getInstance()* | Връща референция към единствената възможна инстанция на **Engine** класа. | - |
| public | *void run(std::istream& in = std::cin, std::ostream& out = std::cout)* | Пуска основната функционалност на програмата. | ***std::istream& in*** -> входният поток (по подозиране е std::cin)<br /><br />***std::ostream& out*** -> изходният поток (по подозиране е std::cout) |

### Command
Програмата трябва да поддържа, валидира и работи с 15 разлчни команди. За реализацията на работата с команди беше използван Command Design Pattern-а. Това се усъщесвява като се създават следните 3 главни класа:

#### **CommandParser**
Клас обработващ входните данни към такива, които могат да бъдат използва от CommandFactory за създаване на нужната команда.

| Видимост | Метод | Описание | Параметри |
| ------ | ------ | ------ | ------ |
| public | *static Command\* parseCommandLine(std::string line, SessionMaster\* sessionMaster)* | Статичен метод, преобразуващ входен ред в STL вектор от аргументи, като преди това премахва ненужните празни места и проверява дали броят на къвичките е правялен. | ***std::string line*** -> входен ред<br /><br /> ***SessionMaster* sessionMaster*** -> Пойнтър към обект от тип **SessionMaster**, който се подава за използване от **CommandFactory** |

#### **CommandFactory**
Клас, който използва разделени в STL вектор аргументи, за да създаде обект от нужният тип команда. Реализиран е чрез употребата на Factory Design Pattern.

| Видимост | Метод | Описание | Параметри |
| ------ | ------ | ------ | ------ |
| public | static Command* createCommand(std::vector\<std::string> args, SessionMaster* sessionMaster) | Създава и връща команда според нуждният вид, както и валидира дали такъв вид команда съществува и дали аргументите са коректни. | ***std::vector\<std::string> args*** -> аргументите от командият ред<br/><br/> ***SessionMaster* sessionMaster*** -> Обект от тип **SessionMaster**, използван за подаване на нужните данни към определени команди |

#### **Command**
Абстрактен клас, който служи за базов на всяка команда.(За после: Повечете наследници изискват нужните за тях обекти за изпълнението на определената команда)

| Видимост | Метод | Описание | Параметри |
| ------ | ------ | ------ | ------ |
| public | virtual std::string execute() = 0 | Виртуален метод, който е оставен да бъде реализиран в наследниците на **Command**. Връща ***std::string***, който служи като съобщение за успешното изпълнение на командата. | - |
| public | static size_t getNumberOfArgs() | Връща нужният брой аргументи, изскван от командният ред | - |

Всяка команда реализира нуджните методи за Command, като някои наследници може да изискват определени обекти да им бъдат подадени, за коректното им изпълнение. Пример: **RotateCommand** е класът отговорен за екзекуцията на командата *rotate*, но за да бъде изпълнена тя, класът се нуджае от пойнтър към активната сесия, за да е възможно прилагането на командата върху всички снимки в нея. Също така класът се нуждае и от посоката на завъртане.

### Image

### Session
