/**
 * 題目：182. Duplicate Emails (重複的電子郵件)
 * 難度：簡單 (Easy)
 * 描述：編寫一個 SQL 查詢，找出 Person 表中所有重複的電子郵件。
 * * 時間複雜度：O(N) - 掃描一次資料表。
 * 空間複雜度：O(N) - 用於分組的 Hash 表空間。
 * * 設計思路：
 * 1. 使用 `GROUP BY` 將相同的 Email 聚集在一起。
 * 2. 使用 `HAVING COUNT(Email) > 1` 篩選出出現次數超過一次的 Email。
 */

SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;
