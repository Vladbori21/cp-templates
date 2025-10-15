# Prefix Sum (Префиксные суммы)

## Что это
Массив, где pref[i] = сумма всех элементов до i (не включая i).
Или переменная pref, когда для задачи нужна не сумма, а остатки от деления(leetcode 974)

## Зачем нужно
- Быстро считать сумму на отрезке [l, r] O(n)
- Применяется в задачах:
  - Leetcode 560 — Subarray Sum Equals K
  - Leetcode 974 — Subarrays Divisible by K
  - Leetcode 523 — Continuous Subarray Sum

## Формула
sum(l, r) = pref[r+1] - pref[l]
subarray[i,...,j] is multiple of k: pref[i] mod k = pref[j] mod k


-Leetcode 560:
  -Example 1:
    -Input: nums = [1,1,1], k = 2 <- pref[0,1,2,3]
    -Output: 2
  -Example 2:
    -Input: nums = [1,2,3], k = 3
    -Output: 2



-Leetcode 974: <- тут нужны остатки, т.к. сумма делится на k, если остатки первого и посленего элемента подмассива равны, то подммасив кратен k
  -Example 1:
    -Input: nums = [4,5,0,-2,-3,1], k = 5 <- pref[0,4,9,9,7,4,5] modulo[0,4,4,4,2,4,0]
    -Output: 7
    -Explanation: There are 7 subarrays with a sum divisible by k = 5:
    -[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
  -Example 2:
    -Input: nums = [5], k = 9
    -Output: 0



-Leetcode 523:
  -Example 1:
    -Input: nums = [23,2,4,6,7], k = 6
    -Output: true
    -Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
  -Example 2:
    -Input: nums = [23,2,6,4,7], k = 6
    -Output: true
    -Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
    -42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.






