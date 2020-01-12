/*
   Freitag, 10. Januar 202001:14:04
   Benutzer: 
   Server: localhost
   Datenbank: OPCRUX_GD
   Anwendung: 
*/

/* Überprüfen Sie das Skript gründlich, bevor Sie es außerhalb des Datenbank-Designer-Kontexts ausführen, um potenzielle Datenverluste zu vermeiden.*/
BEGIN TRANSACTION
SET QUOTED_IDENTIFIER ON
SET ARITHABORT ON
SET NUMERIC_ROUNDABORT OFF
SET CONCAT_NULL_YIELDS_NULL ON
SET ANSI_NULLS ON
SET ANSI_PADDING ON
SET ANSI_WARNINGS ON
COMMIT
BEGIN TRANSACTION
GO
CREATE TABLE dbo.Inventory
	(
	objectID bigint NOT NULL,
	ownerID bigint NOT NULL,
	tab int NOT NULL,
	slot int NOT NULL,
	template int NOT NULL,
	count int NOT NULL,
	attributes tinyint NULL,
	metadata text NULL
	)  ON [PRIMARY]
	 TEXTIMAGE_ON [PRIMARY]
GO
ALTER TABLE dbo.Inventory SET (LOCK_ESCALATION = TABLE)
GO
COMMIT
select Has_Perms_By_Name(N'dbo.Inventory', 'Object', 'ALTER') as ALT_Per, Has_Perms_By_Name(N'dbo.Inventory', 'Object', 'VIEW DEFINITION') as View_def_Per, Has_Perms_By_Name(N'dbo.Inventory', 'Object', 'CONTROL') as Contr_Per 