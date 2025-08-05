-- Step 1: Self Join with all values
-- SELECT * 
-- FROM 
-- Weather w1 JOIN Weather w2;

-- Step 2: Calculate the Date difference for previous day
-- SELECT * FROM 
-- Weather w1 JOIN Weather w2 WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1;

-- Step 3: Now we have a data of Previous and Current date so, we have to just calculate now the previous day temp > curr day temp then return it 

-- SELECT * FROM 
-- Weather w1 JOIN Weather w2 WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 and w1.temperature > w2.temperature;

-- Step 4: Now we have all data, and we need only id, so print ID only 

SELECT w1.id FROM 
Weather w1 JOIN Weather w2 WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 and w1.temperature > w2.temperature;


-- SELECT w1.id 
-- FROM Weather w1 JOIN Weather w2 WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 and w1.temperature > w2.temperature;