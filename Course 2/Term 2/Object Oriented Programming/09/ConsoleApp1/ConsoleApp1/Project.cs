using System;
using System.Collections.Generic;

namespace ConsoleApp1;

public partial class Project
{
    public long Id { get; set; }

    public string Name { get; set; } = null!;

    public long GroupId { get; set; }

    public virtual ICollection<Task> Tasks { get; set; } = new List<Task>();
}
