INSERT INTO people
  WITH RECURSIVE
    cte(id, name, city, country, birthday, email) AS (
        VALUES(6 , random(), random(), random(), random(), random()) UNION ALL 
        SELECT id+1,random(),random(), random(), random(), random() FROM cte WHERE ID<100
    )
SELECT * FROM cte;