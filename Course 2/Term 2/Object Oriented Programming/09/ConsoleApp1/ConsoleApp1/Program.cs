// See https://aka.ms/new-console-template for more information
using ConsoleApp1;

Console.WriteLine("Hello, World!");

// получаем объекты из бд и выводим на консоль
using (TaskifyDbContext db = new TaskifyDbContext())
{
    // получаем объекты из бд и выводим на консоль
    var groups = db.Groups.ToList();
    Console.WriteLine("Список объектов:");

    foreach (var g1 in groups)
    {
        Console.WriteLine($"{g1.Id}.{g1.Name}");
    }

    Console.WriteLine("------------------------------");

    GroupProvider gp = new GroupProvider(db);
    Group g = new Group();
    g.Name = "Life2";

    db.Groups.Add(g);
    db.SaveChanges();


    groups = db.Groups.ToList();
    foreach (var g2 in groups)
    {
        Console.WriteLine($"{g2.Id}.{g2.Name}");
    }

    var query = db.Projects
                  .Join(db.Groups,
                        project => project.GroupId,
                        group => group.Id,
                        (project, group) => new { ProjectName = project.Name, GroupName = group.Name });

    var query2 = from project in db.Projects
                join groupss in db.Groups
                on project.GroupId equals groupss.Id
                select new { ProjectName = project.Name, GroupName = groupss.Name };


    var result = query2.ToList();

    foreach (var g3 in result)
    {
        Console.WriteLine($"{g3.ProjectName}.{g3.GroupName}");
    }
}