USE [Univer2]
GO
/****** Object:  StoredProcedure [dbo].[PSUBJECT]    Script Date: 6/4/2023 2:26:54 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[PSUBJECT] @p varchar(20) = NULL, @K int output
	AS
	BEGIN
		SET @K = (SELECT COUNT(*) 
		FROM SUBJECT
		WHERE SUBJECT.PULPIT = @p)
		SELECT * 
		FROM SUBJECT
		WHERE SUBJECT.PULPIT = @p;
	END