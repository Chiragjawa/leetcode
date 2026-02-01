# Write your MySQL query statement below
SELECT 
    t.trans_date as month,
    t.country as country,
    COUNT(trans_date) as trans_count,
    SUM(IF(t.state = 'approved',1,0)) as approved_count,
    SUM(t.amount) as trans_total_amount,
    SUM(IF(state = 'approved',t.amount,0)) as approved_total_amount
FROM (
    SELECT
    DATE_FORMAT(trans_date, '%Y-%m' ) as trans_date,
    id,
    country,
    state,
    amount
FROM Transactions
) as t
GROUP BY t.trans_date, t.country