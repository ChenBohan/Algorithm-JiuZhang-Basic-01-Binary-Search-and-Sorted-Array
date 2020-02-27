# Leetcode-01-JiuZhang-Algorithm-Basic-Course
九章算法基础班

## Chapter 2

- 二分法
  - 实现方法
    - 递归
        - 工程上避免使用递归，可能出现stack overflow
    - while循环（推荐）
  - 适用问题
    - 是不是要找first position或者last position
    - 复杂度需要从O(n)降到O(logn)

- [First Position of Target](https://www.lintcode.com/problem/first-position-of-target/description)
  - 二分查找找左边界
  - Keypoints
    - while循环：`while (start + 1 < end)`
      - start + 1 >= end 时终止，即start与end相邻或相等
      - 最终退出时，无论start和end时相邻或相等，都当作相邻处理，各判断一次
      - 相邻就退出避免死循环
    - 取中间数：`mid = start + (end - start) / 2;`
      - 与`mid = (start + end) / 2`相比，不容易在数字过大时造成int溢出
    - 判断mid和target的关系：`A[mid] ? target`
      - 等于: `end = mid;`
      - 大于: `start = mid;`
      - 小于: `end = mid;`
    - 判断start、end与target的关系
      - A[start] == target: `return start;`
      - A[end] == target: `return end;`
            
- [Search for a Range](https://www.lintcode.com/problem/search-for-a-range/)
  - 二分查找找左右边界
  - Keypoints
    - 找左右边界的区别：当`nums[mid] == target`时，是往左边找还是往右边找
  
- [Search Insert Position](https://www.lintcode.com/problem/search-insert-position/description)
  - 可转换为用二分法查找第一个大于等于targer的元素位置，即first position of...
    - Keypoints
      - 若找不到第一个大于等于的元素，说明target大于数组中所有元素
  
- [search a 2d matrix ii](https://www.lintcode.com/problem/search-a-2d-matrix-ii/description)
  - 1. 二分法
    - 用二分法寻找对角线上第一个大于等于target的元素，以此元素为原点，可以先排除左上和右下矩阵，继续在左下和右上矩阵中搜索。
  - 2. 对角线走步法
    - 从左下角开始，往右上角逼近
      - 当左下角<target,可以忽略所在该列的所有值，位置向右+1，即从【X,Y】->【X,Y+1】
      - 当左下角>target,可以忽略所在该行的所有值，位置向上+1，即从【X,Y】->【X-1,Y】
      - 当左下角==target,计数器count+1，可以忽略所在该列和改行的所有值，位置向斜上方移动，即从【X,Y】->【X-1,Y+1】
 
- [first bad version](https://www.lintcode.com/problem/first-bad-version/description)

- [find peak element](https://www.lintcode.com/problem/find-peak-element/description)
  - 二分法
    - 每次取中间元素，如果大于左右，则这就是peek。
    - 否则取大的一边，两个都大，可以随便取一边。最终会找到peek。
