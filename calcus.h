#ifndef CALCUS_H
#define CALCUS_H
#include <QString>

class calcus
{
private:
    QString isParam(char *str);              // функция для проверки, присваивается ли выражение к переменной
    void eatspaces(char *str);            // функция для удаления пробелов
    double expr(char *str);               // функция, вычисляющая выражение
    double term(char *str, int &index);   // функция для анализа элемента
    double trigon(char *str, int &index); // функция для вычисления тригонометрических значений
    double power(char *str, int &index);  // функция для извлечения степени
    double number(char *str, int &index); // функция, распознающая число
public:
    QString calculate(QString strr);
};



#endif // CALCUS_H
