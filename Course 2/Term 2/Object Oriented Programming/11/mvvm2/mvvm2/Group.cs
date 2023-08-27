using System;
using System.Collections.Generic;

namespace mvvm2;

public partial class Group
{
    public long Id { get; set; }

    public string Name { get; set; } = null!;

    public virtual ICollection<Project> Projects { get; set; } = new List<Project>();
}
