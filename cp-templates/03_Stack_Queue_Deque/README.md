# Stack, Queue & Deque (Стек, Очередь и Дек)

## Что это

- **Stack (Стек)** — структура данных LIFO (Last In First Out), последний добавленный элемент извлекается первым.  
- **Queue (Очередь)** — структура данных FIFO (First In First Out), первый добавленный элемент извлекается первым.  
- **Deque (Двусторонняя очередь)** — можно добавлять/удалять элементы с **обоих концов**.

---

## Зачем нужно

- **Стек**
  - Проверка корректности скобок
  - Undo/Redo операции
  - Рекурсивные обходы графа через стек вместо рекурсии
  - Next Greater/Smaller Element (монотонный стек)
  
- **Очередь**
  - BFS (поиск в ширину)
  - Сортировка топологическая
  - Задачи на «первый пришёл — первый ушёл»
  
- **Дек**
  - Sliding window максимумы/минимумы
  - Очередь с ограничением размера
  - Задачи на двухсторонние очереди и «первые/последние k элементов»

---

## Методы C++

### Stack
```cpp
stack<int> st;
st.push(10);    // добавить
st.pop();       // удалить верхний
st.top();       // посмотреть верхний
st.empty();     // проверить пустоту
```
### queue<int> q;
```cpp
q.push(10);     // добавить в конец
q.pop();        // удалить с начала
q.front();      // первый элемент
q.back();       // последний элемент
q.empty();      // проверка на пустоту
```
### deque<int> d;
```cpp
d.push_back(1);   // добавить в конец
d.push_front(2);  // добавить в начало
d.pop_back();     // удалить с конца
d.pop_front();    // удалить с начала
d.front();        // первый элемент
d.back();         // последний элемент
d.empty();        // проверка на пустоту
```
## Ошибки

- Стек: забыть проверять пустоту перед top() или pop().
- Очередь: удалять элемент не проверив пустоту.
- Дек: перепутать push_back и push_front или индексы в sliding window.
- Монотонные структуры: забыть удалить устаревшие элементы.

## Примеры реализации
📄 [Решение →](./Examples.cpp)

### Leetcode 20. Valid Parentheses

  - Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  - **Идея: ** Используем стек, чтобы проверять правильность вложенности скобок.
  - **Примеры:**
  ```
  Example 1:
  Input: s = "()"
  Output: true

  Example 2:
  Input: s = "()[]{}"
  Output: true

  Example 3:
  Input: s = "(]"
  Output: false

  Example 4:
  Input: s = "([])"
  Output: true

  Example 5:
  Input: s = "([)]"
  Output: false
```
### Leetcode 387. First Unique Character in a String

  - Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
  - **Идея:** Считаем частоты букв и ищем первую с count = 1.
  - **Примеры:**
  ```
  Example 1:
  Input: s = "leetcode"
  Output: 0
  Explanation:
  The character 'l' at index 0 is the first character that does not occur at any other index.

  Example 2:
  Input: s = "loveleetcode"
  Output: 2

  Example 3:
  Input: s = "aabb"
  Output: -1
  ```
  


































