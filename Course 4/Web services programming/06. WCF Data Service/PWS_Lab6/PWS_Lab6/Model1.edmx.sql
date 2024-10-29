
-- --------------------------------------------------
-- Entity Designer DDL Script for SQL Server 2005, 2008, 2012 and Azure
-- --------------------------------------------------
-- Date Created: 09/29/2024 12:24:49
-- Generated from EDMX file: D:\4k1s\WS\PWS_Labs_7sem-master\PWS_Lab6\PWS_Lab6\Model1.edmx
-- --------------------------------------------------

SET QUOTED_IDENTIFIER OFF;
GO
USE [Students];
GO
IF SCHEMA_ID(N'dbo') IS NULL EXECUTE(N'CREATE SCHEMA [dbo]');
GO

-- --------------------------------------------------
-- Dropping existing FOREIGN KEY constraints
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[FK__note__stud_id__38996AB5]', 'F') IS NOT NULL
    ALTER TABLE [dbo].[note] DROP CONSTRAINT [FK__note__stud_id__38996AB5];
GO

-- --------------------------------------------------
-- Dropping existing tables
-- --------------------------------------------------

IF OBJECT_ID(N'[dbo].[note]', 'U') IS NOT NULL
    DROP TABLE [dbo].[note];
GO
IF OBJECT_ID(N'[dbo].[student]', 'U') IS NOT NULL
    DROP TABLE [dbo].[student];
GO

-- --------------------------------------------------
-- Creating all tables
-- --------------------------------------------------

-- Creating table 'note'
CREATE TABLE [dbo].[note] (
    [id] int IDENTITY(1,1) NOT NULL,
    [stud_id] int  NULL,
    [subject] nvarchar(20)  NULL,
    [note1] int  NULL
);
GO

-- Creating table 'student'
CREATE TABLE [dbo].[student] (
    [id] int IDENTITY(1,1) NOT NULL,
    [name] nvarchar(50)  NULL
);
GO

-- --------------------------------------------------
-- Creating all PRIMARY KEY constraints
-- --------------------------------------------------

-- Creating primary key on [id] in table 'note'
ALTER TABLE [dbo].[note]
ADD CONSTRAINT [PK_note]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- Creating primary key on [id] in table 'student'
ALTER TABLE [dbo].[student]
ADD CONSTRAINT [PK_student]
    PRIMARY KEY CLUSTERED ([id] ASC);
GO

-- --------------------------------------------------
-- Creating all FOREIGN KEY constraints
-- --------------------------------------------------

-- Creating foreign key on [stud_id] in table 'note'
ALTER TABLE [dbo].[note]
ADD CONSTRAINT [FK__note__stud_id__38996AB5]
    FOREIGN KEY ([stud_id])
    REFERENCES [dbo].[student]
        ([id])
    ON DELETE NO ACTION ON UPDATE NO ACTION;
GO

-- Creating non-clustered index for FOREIGN KEY 'FK__note__stud_id__38996AB5'
CREATE INDEX [IX_FK__note__stud_id__38996AB5]
ON [dbo].[note]
    ([stud_id]);
GO

-- --------------------------------------------------
-- Script has ended
-- --------------------------------------------------