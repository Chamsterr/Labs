using System;
using static System.Net.Mime.MediaTypeNames;
using System.IO;
using System.Text;
using System.Reflection;
using System.Collections.Specialized;
using System.IO.Compression;
using System.Data.SqlTypes;

namespace OOP12
{
    public static class KNVLog
    {
        static string logfile = "KNVlogfile.txt";
        public static void Write(string method, string filename = null)
        {
            string textFromLogFile = Read();
            textFromLogFile += $"Date - {DateTime.Now}" + (filename != null? $"\nFile - {filename} \n": "\n") + $"Method - {method}\n";

            using (StreamWriter writer = new StreamWriter(logfile, false))
            {
                writer.WriteLine(textFromLogFile);
            }
        }

        public static string Read()
        {
            using (StreamReader reader = new StreamReader(logfile))
            {
                string text = reader.ReadToEnd();
                return text;
            }
        }
        public static bool Find(string str)
        {
            string text = Read();
            if (text.IndexOf(text) != -1)
            {
                return true;
            }
            return false;
        }

    }
    public static class KNVDiskInfo
    {
        public static void FreeDiskSpace()
        {
            DriveInfo[] allDrives = DriveInfo.GetDrives();
            string info = "Свободное место: \n";
            foreach (DriveInfo drive in allDrives)
            {
                info += $"{drive.Name} - {drive.AvailableFreeSpace / 1_000_000_000} \n";
            }
            Console.WriteLine(info);
            KNVLog.Write("FreeDiskSpace");
        }
    }
    public static class KNVFileInfo
    {
        public static string AbsolutePath(string filename)
        {
            string path = Path.GetFullPath(filename);
            Console.WriteLine(path);
            KNVLog.Write("AbsolutePath", filename);
            return path;
        }

        public static void GetFileInfo(string filename)
        {
            FileInfo fileInfo = new FileInfo(filename);
            Console.WriteLine("\nПолный путь:   " + KNVFileInfo.AbsolutePath(filename) +
                              "\nИмя файла:     " + fileInfo.Name +
                              "\nРазмер файла:  " + fileInfo.Length +
                              "\nРасширение:    " + fileInfo.Extension +
                              "\nДата изменения:" + fileInfo.LastWriteTime);
            KNVLog.Write("GetFileInfo", filename);
        }
    }
    public class KNVDirInfo
    {
        public static void GetDirInfo(string dirName)
        {
            DirectoryInfo dirInfo = new DirectoryInfo(dirName);
            Console.WriteLine("\nИмя директории:           " + dirInfo.Name +
                            "\nКоличество файлов:        " + dirInfo.GetFiles().Length +
                            "\nВремя создания:           " + dirInfo.LastWriteTime +
                            "\nКол-во поддиректорий:     " + dirInfo.GetDirectories().Length +
                            "\nРодительский директорий:  " + dirInfo.Parent.Name);
            KNVLog.Write("GetFileInfo", dirName);
        }
    }
    public class KNVFileManager
    {
        public static void GetAllFilesAndDir(string path)
        {
            string FilesAndDir = "";
            DriveInfo[] drives = DriveInfo.GetDrives();
            string[] dirs = System.IO.Directory.GetDirectories(path);
            string[] files = System.IO.Directory.GetFiles(path);

            FilesAndDir = "\nПапки:\n";
            foreach (string dir in dirs)
            {
                FilesAndDir += dir + "\n";
            }

            FilesAndDir += "Файлы:\n";
            foreach (string file in files)
            {
                FilesAndDir += file + "\n";
            }
            Console.WriteLine(FilesAndDir);
            KNVLog.Write("GetAllFilesAndDir");
        }
        public static void CreateDir(string path)
        {
            try
            {
                Directory.CreateDirectory(path);
            }
            catch
            {
                Console.WriteLine("Ошибка создания директория");
            }
            KNVLog.Write("CreateDir");
        }
        public static void CreateFile(string path)
        {
            FileInfo fileInfo = new FileInfo(path);
            using (StreamWriter sw = fileInfo.CreateText())
            {
                sw.WriteLine("");
                sw.Close();
            }
            KNVLog.Write("CreateDir");
        }
        public static void CopyFile(string path, string path2)
        {
            try
            {
                File.Copy(path, path2);       
            }
            catch
            {
               Console.WriteLine("Ошибка копирования файла");
            }
            FileInfo delete = new FileInfo(path);
            try
            {
                delete.Delete();
            }
            catch
            {
                Console.WriteLine("Отказано в доступе");
            }
            KNVLog.Write("CopyFile");
        }
        public static void CopyFiles(string extension, string path, string path2, string path3)
        {
            try
            {
                Directory.CreateDirectory(path2);

                string[] files = Directory.GetFiles(path, extension);
                foreach (string file in files)
                {
                    string fileName = Path.GetFileName(file);
                    string destFile = Path.Combine(path2, fileName);
                    File.Copy(file, destFile, true);
                }
            }
            catch
            {
                Console.WriteLine("Ошибка копирования файлов:");
            }

            try
            {
                string path4 = path3 + @"\KNVFiles";


                DirectoryInfo destDir = new DirectoryInfo(path4);
                if (destDir.Exists)
                    destDir.Delete(true);
                Directory.Move(path2, path4);
            }
            catch
            {
                Console.WriteLine("Ошибка перемещения файлов: ");
            }
            KNVLog.Write("CopyFiles");
        }
        public static void ZipFiles(string path, string path2, string path3)
        {
            try
            {
                ZipFile.CreateFromDirectory(path, path2);
            }
            catch
            {
                Console.WriteLine("Ошибка создания архива:");
            }
            //Разархивируйте его в другой директорий.
            try
            {
                ZipFile.ExtractToDirectory(path2, path3);
                Console.WriteLine("Архив разархивирован");
            }
            catch
            {
                Console.WriteLine("Ошибка разархивирования архива:");
            }
            KNVLog.Write("ZipFiles");
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            KNVDiskInfo.FreeDiskSpace();
            KNVFileInfo.AbsolutePath("OOP12.exe");
            KNVFileInfo.GetFileInfo("OOP12.exe");
            KNVDirInfo.GetDirInfo("Test");
            KNVFileManager.GetAllFilesAndDir("D:\\Labs\\Course 2\\Term 1\\Object Oriented Programming\\12. Working with stream classes and the file system\\OOP12\\OOP12\\bin\\Debug");
            KNVFileManager.CreateDir("KNVInspect");
            KNVFileManager.CreateDir("KNVFiles");
            KNVFileManager.CreateFile("test.txt");
            KNVFileManager.CopyFile("D:\\Labs\\Course 2\\Term 1\\Object Oriented Programming\\12. Working with stream classes and the file system\\OOP12\\OOP12\\bin\\Debug\\test.txt", "D:\\Labs\\Course 2\\Term 1\\Object Oriented Programming\\12. Working with stream classes and the file system\\OOP12\\OOP12\\bin\\Debug\\Test\\test.txt");
            KNVFileManager.ZipFiles("D:\\Labs\\Course 2\\Term 1\\Object Oriented Programming\\12. Working with stream classes and the file system\\OOP12\\OOP12\\bin\\Debug\\Test", "D:\\\\Labs\\\\Course 2\\\\Term 1\\\\Object Oriented Programming\\\\12. Working with stream classes and the file system\\\\OOP12\\\\OOP12\\\\bin\\\\Debug\\\\zip.zip", "D:\\Labs\\Course 2\\Term 1\\Object Oriented Programming\\12. Working with stream classes and the file system\\OOP12\\OOP12\\bin\\Debug\\Norm");
            Console.ReadLine();
        }
    }
}
