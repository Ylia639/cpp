#include <iostream>
#include <cctype>
void f1()
{
    std::cout << "Задание 1.\n";
    std::cout << "Введите строку:";
    char str[51];
    std::cin.getline(str, 51);

    for (int i = 0; i < 51; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            std::cout << str[i];
    }
    std::cout << std::endl;
}
void f2()
{
    std::cout << "Задание 2\n";
    std::cout << "Введите строку:";
    char str[51];
    std::cin.getline(str, 51);
    int len = std::strlen(str);
    if (std::isalpha(str[0]))
        std::cout << str[0];
    for (int i = 1; i < len - 1; i++)
    {
        if (std::isalpha(str[i]) && !std::isalpha(str[i - 1]))
        {
            std::cout << str[i];
        }
        if (std::isalpha(str[i]) && !std::isalpha(str[i + 1]))
        {
            std::cout << str[i] << ' ';
        }
    }
    std::cout << std::endl;
}
void f3()
{
    std::cout << "Задание 3.\n";
    std::cout << "Ведите строку: ";
    char str[51];
    std::cin.getline(str, 51);
    int len = std::strlen(str);
    char a;
    int b;
    b = 0;
    std::cout << "Введите букву: ";
    std::cin >> a;
    for (int i = 1; i < len - 1; i++)
    {
        if (str[i] == a)
        {
            b += 1;
            
        }
    }
    std::cout << "Количество повторений в строке: " << b;
}
    void f4()
    {
        
        std::cout << " \nЗадание 4." << std::endl;
        std::cout << "Введите строку ";
        char str[51];
        char str2[51];
        std::cin.getline(str, 51);
        std::cin.getline(str2, 51);

        int len1 = 0, len2 = 0;
        for (int i = 0; str[i]; i++) {
            if (isalnum(str[i]) ||str[i] == ' '||  ispunct(str[i])) {
                len1++;
            }
        }
        for (int i = 0; str2[i]; i++) {
            if (isalnum(str2[i]) || str2 [i] == ' ' || ispunct(str2[i])) {
                len2++;
            }
        }

        int index = -1;
        for (int i = 0; i <= len1 - len2; i++) {
            int match = 1;
            for (int j = 0; j < len2; j++) {
                if (tolower(str[i + j]) != tolower(str2[j])) {
                    match = 0;
                    break;
                }
            }
            if (match == 1) {
                index = i;
                break;
            }
        }


        std::cout << index << std::endl;


    }
    void f5()
    {
        std::cout << "Задание 5. " << std::endl;
        std::cout << "Введите строку ";
        char str1[51];
        char str2[51];
        std::cin.getline(str1, 51);
        std::cin.getline(str2, 51);

        int a = 0;
        int i = 0, j = 0;
        do {
            j = 0;
            do {
                if (str1[i + j] != str2[j]) {
                    break;
                }
                j++;
            } while (str2[j] != '\0' && str1[i + j] != '\0');
            if (str2[j] == '\0') {
                a++;
            }
            i++;
        } while (str1[i] != '\0');

        std::cout << "Номер элемента: " << a << std::endl;
    }

int main() {
    setlocale(LC_ALL, "rus");
   f1();
    f2();
    f3();
    f4();
    f5();
}
