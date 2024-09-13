-- =========================
-- Drop Database Template
-- =========================
USE master
GO

IF  EXISTS (
	SELECT name 
		FROM sys.databases 
		WHERE name = N'ABC'
)
DROP DATABASE ABC
GO