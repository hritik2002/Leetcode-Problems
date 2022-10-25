# Write your MySQL query statement below
select FirstName, LastName, City, State from Address Right join Person on Address.PersonId = Person.PersonId;