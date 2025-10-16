
# Sliding Window & Two Pointers (Скользящее окно и два указателя)

## Что это
Техника оптимизации перебора, где мы используем **два указателя (left, right)**, чтобы динамически выбирать подмассив или подстроку, удовлетворяющую условию.  
Вместо проверки всех возможных подотрезков (O(n²)), мы двигаем указатели умно, добиваясь **O(n)**.

---

## Виды
- **Two Pointers** — обычно используется для **отсортированных массивов** или задач типа *"сойтись из концов"*.
- **Sliding Window** — для подмассивов/подстрок, где мы ищем **наибольший/наименьший диапазон**, удовлетворяющий условию.

---

## Зачем нужно
- Поиск подмассива с нужным свойством (сумма, количество, уникальность и т.д.)
- Нахождение максимальной/минимальной длины подмассива
- Проверка подстрок и подмассивов без дубликатов, с ограничением и т.д.

---

## Типовые шаблоны

### 🔹 Two Pointers (на отсортированном массиве)
```cpp
int i = 0, j = nums.size() - 1;

while (i < j) {

    int sum = nums[i] + nums[j];

    if (sum == target) return {i, j};
    else if (sum < target) i++;
    else j--;

}
```
### 🔹 Sliding Window (переменное окно)
```cpp
int l = 0;
for (int r = 0; r < nums.size(); r++) {
    // добавить nums[r] в окно
    
    while (условие нарушено) {
        // убрать nums[l] из окна
        l++;
    }
    
    // обновить ответ
}
```

## Ошибки

- Забыть обновить `l` при нарушении условия окна.
- Неправильно обновлять ответ (внутри или снаружи цикла).
- Считать окно по `r - l`, а не `r - l + 1`.
- Не различать фиксированное окно (фикс. размер) и переменное (по условию).

## Примеры реализации

📄 [Решение →](./Examples.cpp)

### Leetcode 167. Two Sum II - Input Array Is Sorted (Two Pointers)

- Given a array of integers numbers that is already sorted in non-decreasing order, find two numbers such that their sum target number. Return the positions of the two numbers
- **Идея:** Уменьшаем правый указатель, если сумма больше `target`, иначе двигаем левый указатель
- **Примеры:**
  ```
  Example 1:
  Input: numbers = [2,7,11,15], target = 9
  Output: [1,2]
  Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

  Example 2:
  Input: numbers = [2,3,4], target = 6
  Output: [1,3]
  Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
  ```

### Leetcode 3. Longest Substring Without Repeating Characters (Sliding Window)

- Given a string s, find the length of the longest substring without duplicate characters.
- **Идея:** расширяем окно, пока буквы не дублируются, сужаем окно, пока дубль не уйдет
- **Примеры:**
  ```
  Example 1:
  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

  Example 2:
  Input: s = "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.
  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
  ```

### Leetcode 1004. Max Consecutive Ones III (Sliding Window)

- Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
- **Идея:** расширяем окно пока `k>0`, сужаем окно пока условие не будет выполняться
- **Примеры:**
  ```
  Example 1:
  Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
  Output: 6
  Explanation: [1,1,1,0,0,1,1,1,1,1,1]

  Example 2:
  Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
  Output: 10
  Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
  ```
















