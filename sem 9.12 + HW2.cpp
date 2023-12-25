// Задания 1 и 2 выполнили Егорова Екатерина и Нечипоренко Дарья (Группа 22БИ3) на паре. 
// Остальные задание делали втроем: Егорова Екатерина, Нечипоренко Дарья, Корнеев Никита (Группа 22БИ3)
#include <iostream>
#include <cstdlib> //Для 4 задания
#include <ctime> //Для 4 задания

/*Task 2*/
void array_Memory(double** array_2, int length) //выделяем память для массива
{
    *array_2 = new double[length];
}

void full_array(double* array_2, int length) //заполняем массив
{
    for (int i = 0; i < length; i++)
    {
        array_2[i] = (i + 1);
    }
}
void showArray(double* Array, int length) //показать массив на экране
{
    for (int i = 0; i < length; i++)
    {
        std::cout << Array[i] << "; ";
    }
}
void clearMemory(double* Array) //освободить память
{
    delete[] Array;
}

/*Task3*/
void ChangeChetNechet(int* array, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int n = array[i];
        array[i] = array[i + 1];
        array[i + 1] = n;
    }
}

/*Task 4*/

// Функция для заполнения двумерного массива случайными числами от 10 до 50
void FullTwoArray(int** array, int lines, int columns) {
    srand(time(0)); // Используем текущее время для инициализации генератора случайных чисел

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            array[i][j] = rand() % 41 + 10; // Генерация числа от 10 до 50
        }
    }
}

// Функция для вывода двумерного массива на экран
void ShowTwoArray(int** array, int lines, int columns) {
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << array[i][j] << " "; //Выводим массив
        }
        std::cout << std::endl;
    }
}

/*Task 5*/
// Функция для сложения
int sum(int a, int b) {
    return a + b;
}

// Функция для вычитания
int subtraction(int a, int b) {
    return a - b;
}

// Функция для умножения
int mult(int a, int b) {
    return a * b;
}

// Функция для деления
int division(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    else {
        std::cout << "Error: division on 0.\n";
        return 0;
    }
}

int main()
{
    /*Task1*/
    //1.1
    const float a = 3.2;
    const float* const fPtr = &a;

    //1.2
    typedef long int* longI_ptr;

    //1.3
    double c = 0;
    double* cPtr = &c;

    //1.4
    const short int d = 0;
    const short int* dPtr = &d;

    //1.5
    typedef const float* const float_ptr;
    const float_ptr e = 0;

    //1.6
    typedef const char* char_ptr;
    char_ptr f = "f";

    //1.7
    double g = 5.0;
    double* const ptr_g = &g;

    //1.8
    typedef unsigned int* const int_ptr;

    /*task 2*/
    double* array_ptr;
    int stopWord;

    do {
        std::cout << "Enter integer length (>=0): ";
        int length;
        std::cin >> length; //ввод длины массива с клавиатуры
        array_Memory(&array_ptr, length);  //вызов функции выделения памяти для массива
        full_array(array_ptr, length); //заполнение массива
        showArray(array_ptr, length); //вывод элементов массива на экран
        clearMemory(array_ptr); //очищение памяти
        std::cout << "\nIf you want to finish, write '999' without quotes. If you want to continue, any other number: ";
        std::cin >> stopWord; //считывание стоп-слова
    } while (stopWord != 999);
    std::cout << "\nYou finished" << std::endl;

    /*Task3*/

    const int sizeofArray = 12;
    int* array_ptr3 = new int[sizeofArray];

    // Заполняем массив значениями
    for (int i = 0; i < sizeofArray; ++i) {
        array_ptr3[i] = i + 1;
    }
    // Выводим исходный массив на экран
    std::cout << "Source array: ";
    for (int i = 0; i < sizeofArray; ++i) {
        std::cout << array_ptr3[i] << " ";
    }

    // Вызываем функции для обмена значениями четных и нечетных ячеек
    ChangeChetNechet(array_ptr3, sizeofArray);
    //Выводим массив после обмена
    std::cout << "\nArray after exchange: ";
    for (int i = 0; i < sizeofArray; ++i) {
        std::cout << array_ptr3[i] << " ";
    }
    std::cout << "\n";
    // Освобождение выделенной памяти
    delete[] array_ptr3;

    /*Task4*/

    int lines, columns;

    // Получение от пользователя количества строк и столбцов
    std::cout << "Enter number of lines: ";
    std::cin >> lines;

    std::cout << "Enter number of columns: ";
    std::cin >> columns;

    // Выделение памяти под двумерный динамический массив
    int** array4 = new int* [lines];
    for (int i = 0; i < lines; ++i) {
        array4[i] = new int[columns];
    }

    // Заполнение и вывод массива
    FullTwoArray(array4, lines, columns);

    std::cout << "Two-dimensional array of random numbers from 10 to 50:\n";
    ShowTwoArray(array4, lines, columns);

    // Освобождение выделенной памяти
    for (int i = 0; i < lines; ++i) {
        delete[] array4[i];
    }
    delete[] array4;

    /*Task5*/
    // Указатель на функцию с двумя параметрами типа int и возвращаемым значением типа int
    int (*ptrFunPointer)(int, int);

    char operation;
    int num1, num2;

    // Ввод данных от пользователя
    std::cout << "\nEnter two integers and the operation (+, -, *, /), separated by spaces: ";
    std::cin >> num1 >> num2 >> operation;

    // Пока не введен пробел в качестве знака операции, продолжаем выполнение
    while (operation != ' ') {
        // Выбор функции в зависимости от введенной операции
        switch (operation) {
        case '+':
            ptrFunPointer = sum;
            break;
        case '-':
            ptrFunPointer = subtraction;
            break;
        case '*':
            ptrFunPointer = mult;
            break;
        case '/':
            ptrFunPointer = division;
            break;
        default:
            std::cout << "Invalid operation. Please enter the correct operation (+, -, *, /).\n";
            // Пропустить текущую итерацию цикла
            continue;
        }

        // Вызов выбранной функции и вывод результата
        std::cout << "Result: " << ptrFunPointer(num1, num2) << std::endl;

        // Запрос новых данных
        std::cout << "Enter two integers and the operation (+, -, *, /), separated by spaces (or enter a space to complete): ";
        std::cin >> num1 >> num2 >> operation;
    }

    return 0;
}

/*Task 6_LeetCode
class Solution {
public:

    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Сортируем массив
        int mini = INT_MAX; // Присваиваем переменной "mini" максимальное интовое значение
        // Формируем группу из k элементов
        for(int i = 0; i < nums.size(); i++)
        {
            if(i + k - 1 < nums.size())
            {
                int diff = nums[i + k - 1] - nums[i]; //Считаем разницу
                mini = min(mini, diff); //Записываем разницу в переменную "mini"
            }
            else
            {
                break;
            }
        }
        return mini; //Выводим разницу
    }
};
*/

/*Task 7_LeetCode
class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end()); //сортируем вектор-массив по возрастанию значений с первого до последнего элемента
        int last = arr[arr.size() - 1], count = 0; //фиксируем последний элемент по его индексу для перебора пар чисел и инициируем переменную-счётчик для подсчета повторений числа
        for (int i = arr.size() - 1; i > -1; i--) //перебор каждого числа с конца массива
        {
            if (last != arr[i]) //проверка на несовпадение значений текущего и следующего элемента
            {
                if (count == last) //если счётчик совпадает со значением числа в на i-ом месте и следующее число отличается
                    return last; //вывод наибольшего счастливого числа
                count = 0; //обнуление счётчика, так как следующее число после фиксированного last отличается
            }
            count++; //прибавляем к счётчикау 1, так как первое условие не подошло и рассмотренное число совпадает с фиксированным
            last = arr[i]; //фиксирование нового "конечного элемента"
        }
        if (count == last) //проверка на счастливость последнего числа по условию
            return last; //вывод счастливого числа в случае успеха
        return -1; // если нет счастливых чисел в массиве
    }
};
*/

/* Task 8_LeetCode
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), fix_n = nums[0], count=0; //инициируем переменные для косичества элементов, фиксированного значения мажоритарного элемента и переменной-счётчика
        for(int i = 0; i < n; i++) //проходим по массиву
        {
            if(count == 0)  fix_n = nums[i]; //если счётчик = 0, то присваиваем фиксированное значение i-ого элемента
            if(nums[i] == fix_n)  count++; // //если значение элемента совпало с фиксированным значением, то счётчик увеличивается на 1
            else count--; //иначе уменьшается на 1
        }
        return fix_n;
    }
};
*/




