# Описание

Программа вычисляет факториал числа с помощью потоков

# Установка

- `$ git clone git@github.com:Crocussys/Parallel_factorial.git`
- `$ cd Parallel_factorial/`
- `$ make`

# Запуск

- `$ ./Parallel_factorial [number] {count_threads}`

`number` - Факториал какого числа надо посчитать. ! Не больше 20 !
`count_threads` - Сколько потоков следует использовать. Если не указать, попробует найти оптимальное количество.

# Вывод

На экран выводит ответ и за какое количество наносекунд он найден.

# Возвращает

- `0` - Программа выполнена успешно
- `1` - Недостаточно аргументов командной строки (Не указано число)
- `2` - В аргументах не числа
- `3` - Количество потоков не указано и не удалось найти оптимальное значение
- `4` - Недопустимое значение аргумента
