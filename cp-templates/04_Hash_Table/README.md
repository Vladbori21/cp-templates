
# Hash Table (Хеш-таблица)

## Что это
Hash Table (хеш-таблица) — структура данных, которая хранит пары **ключ–значение** и обеспечивает доступ к элементам за **O(1)** в среднем.
В C++ чаще всего реализуется через:
- `unordered_map<Key, Value>` — неупорядоченная таблица (хеширование);
- `map<Key, Value>` — сбалансированное дерево (упорядоченное хранение, O(log n)).
  
## Зачем нужно
- быстро искать, добавлять и удалять элементы
- считать частоты появления элементов
- проверять наличие дубликатов
- сопоставлять объекты (ключ → значение)

## Методы C++

```cpp
unordered_map<string, int> mp;

mp["apple"] = 3;       // добавить или изменить
mp.insert({"banana", 5}); 
mp["apple"]++;         // увеличить значение
mp.erase("banana");    // удалить ключ
mp.count("apple");     // проверить наличие (0 или 1)
mp.clear();            // очистить таблицу

for (auto& [key, value] : mp) {
    cout << key << " -> " << value << endl;
}
```

## Ошибки

- Использовать `mp[key]` только для чтения — оно создаёт элемент с `0`, даже если его не было.
Вместо этого используй `mp.count(key)` или `mp.find(key)`.
- Не забывать, что порядок обхода в `unordered_map` не определён.

## Примеры использования
- Подсчёт количества элементов в массиве
- Проверка, можно ли составить строку из другой (`anagram`)
- Запоминание уже посещённых состояний или индексов

## Примеры реализации

📄 [Решение →](./Examples.cpp)

### Leetcode 383. Ransom Note

- Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
- **Идея:** считаем буквы в **magazine**, потом в **ransomNote**
- **Примеры:**
  ```
  Example 1:
  Input: ransomNote = "a", magazine = "b"
  Output: false
  
  Example 2:
  Input: ransomNote = "aa", magazine = "ab"
  Output: false
  
  Example 3:
  Input: ransomNote = "aa", magazine = "aab"
  Output: true
  ```

### Leetcode 3005. Count Elements With Maximum Frequency

- You are given an array nums consisting of positive integers. Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
- **Идея:** считаем частоту элементов
- **Примеры:**
```
Example 1:
Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.

Example 2:
Input: nums = [1,2,3,4,5]
Output: 5
Explanation: All elements of the array have a frequency of 1 which is the maximum.
So the number of elements in the array with maximum frequency is 5.
```

### Leetcode 242. Valid Anagram

- Given two strings s and t, return true if t is an anagram of s, and false otherwise.
- **Идея:** считаем буквы в **s**, потом в **t**
- **Примеры:**
```
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
```
