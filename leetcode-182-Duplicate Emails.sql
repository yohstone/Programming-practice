// Write a SQL query to find all duplicate emails in a table named Person.

select Email from Person Group by Email having count(Email) > 1