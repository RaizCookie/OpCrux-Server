/*
   Dienstag, 10. November 202021:58:12
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
CREATE TABLE dbo.UnlockedEmotes
	(
	playerID bigint NOT NULL,
	emoteID int NOT NULL
	)  ON [PRIMARY]
GO
ALTER TABLE dbo.UnlockedEmotes SET (LOCK_ESCALATION = TABLE)
GO
COMMIT
select Has_Perms_By_Name(N'dbo.UnlockedEmotes', 'Object', 'ALTER') as ALT_Per, Has_Perms_By_Name(N'dbo.UnlockedEmotes', 'Object', 'VIEW DEFINITION') as View_def_Per, Has_Perms_By_Name(N'dbo.UnlockedEmotes', 'Object', 'CONTROL') as Contr_Per 