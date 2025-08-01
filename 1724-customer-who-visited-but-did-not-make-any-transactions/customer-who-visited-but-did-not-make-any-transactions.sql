# Write your MySQL query statement below
SELECT v.customer_id, count(*) as count_no_trans FROM Visits as v LEFT JOIN 
Transactions as T ON v.visit_id = t.visit_id
WHERE t.visit_id is NULL GROUP BY v.customer_id;