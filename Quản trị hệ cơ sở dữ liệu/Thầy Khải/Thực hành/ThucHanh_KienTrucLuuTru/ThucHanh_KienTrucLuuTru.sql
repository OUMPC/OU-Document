USE Master;
CREATE DATABASE SmallWorks ON  PRIMARY
( NAME = 'SmallWorksPrimary'
, FILENAME = 'C:\SmallWorks.mdf'
, SIZE = 10MB
, FILEGROWTH = 20%
, MAXSIZE = 50MB)
, FILEGROUP FileGroup1
( NAME = 'SmallWorksData1'
, FILENAME = 'C:\SmallWorksData1.ndf'
, SIZE = 10MB
, FILEGROWTH = 20%
, MAXSIZE = 50MB)
, FILEGROUP FileGroup2
( NAME = 'SmallWorksData2'
, FILENAME = 'C:\SmallWorksData2.ndf'
, SIZE = 10MB
, FILEGROWTH = 20%
, MAXSIZE = 50MB)
 LOG ON
( NAME = 'SmallWorks_log'
, FILENAME = 'C:\SmallWorks_log.ldf'
, SIZE = 10MB
, FILEGROWTH = 10%
, MAXSIZE = 20MB);
GO
USE SmallWorks;
GO
ALTER DATABASE SmallWorks
MODIFY FILEGROUP FileGroup1 DEFAULT;
GO

CREATE TABLE dbo.Contact(
  ContactID int NOT NULL
, FirstName varchar(75) NOT NULL
, LastName varchar(75) NOT NULL
, EmailAddress varchar(255) NULL
, Phone varchar(25) NULL
) ON FileGroup1;

CREATE TABLE dbo.Product(
  ProductID int NOT NULL
, ProductName varchar(75) NOT NULL
, ProductNumber nvarchar(25) NOT NULL
, StandardCost money NOT NULL
, ListPrice money NOT NULL
) ON FileGroup2;

INSERT dbo.Contact
(ContactID, FirstName, LastName, EmailAddress, Phone)
SELECT ContactID, FirstName, LastName, EmailAddress, Phone
FROM AdventureWorks.Person.Contact
WHERE ContactID < 5000;

INSERT dbo.Product
(ProductID, ProductName, ProductNumber, StandardCost, ListPrice)
SELECT ProductID, Name, ProductNumber, StandardCost, ListPrice
FROM AdventureWorks.Production.Product;

ALTER DATABASE SmallWorks MODIFY FILEGROUP FileGroup2 READONLY; --READWRITE 

USE SmallWorks
DELETE FROM dbo.Contact WHERE ContactID<500;

ALTER DATABASE SmallWorks MODIFY FILEGROUP FileGroup2 READWRITE;
USE SmallWorks
DELETE FROM dbo.Product WHERE ProductID<500;
