#pragma once
#include <stddef.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} IntVector;

IntVector *int_vector_new(size_t initial_capacity);
//Создает массив нулевого размера.

IntVector *int_vector_copy(const IntVector *v);

void int_vector_free(IntVector *v);
//Освобождает память, выделенную для вектора v.

int int_vector_get_item(const IntVector *v, size_t index);

void int_vector_set_item(IntVector *v, size_t index, int value);
//Присваивает элементу под номером index значение item. В случае выхода за
//границы массива поведение не определено.

size_t int_vector_get_size(const IntVector *v);

size_t int_vector_get_capacity(const IntVector *v);

int int_vector_push_back(IntVector *v, int item);
//Добавляет элемент в конец массива. При необходимости увеличивает емкость
//массива. Для простоты в качестве коэффициента роста можно использовать 2.

void int_vector_pop_back(IntVector *v);
//Удаляет последний элемент из массива. Нет эффекта, если размер массива равен
// 0.

int int_vector_shrink_to_fit(IntVector *v);
//Уменьшает емкость массива до его размера.

void int_vector_resize(IntVector *v, size_t new_size);
//Изменяет размер массива.
//Если новый размер массива больше исходного, то добавленные элементы
//заполняются нулями.

//Если новый размер массива меньше исходного, то перевыделение памяти не
//происходит. Для уменьшения емкости массива в этом случае следует использовать
//функцию int_vector_shrink_to_fit.

int int_vector_reserve(IntVector *v, size_t capacity);
//Изменить емкость массива.
//Нет эффекта, если новая емкость меньше либо равна исходной.