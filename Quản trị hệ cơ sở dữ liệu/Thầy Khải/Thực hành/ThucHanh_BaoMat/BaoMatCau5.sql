
USE AdventureWorks
go

-- Các hành động có quyền: XEM và THÊM
SELECT [DepartmentID]
      ,[Name]
      ,[GroupName]
      ,[ModifiedDate]
 FROM [AdventureWorks].[HumanResources].[Department]


INSERT INTO [HumanResources].[Department](Name, GroupName)
VALUES ('SSS', 'H H FH FH')

-- Các hành động không có quyền:XÓA và SỬA

DELETE FROM [AdventureWorks].[HumanResources].[Department]
WHERE Name='SSS'

UPDATE [AdventureWorks].[HumanResources].[Department]
SET Name= 'NewSSS'