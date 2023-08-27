using System;
using System.Collections.Generic;
using System.ComponentModel;

namespace mvvm2;

public partial class Project
{
    public long Id { get; set; }

    public string Name { get; set; } = null!;

    public long? GroupId { get; set; }

    public virtual Group? Group { get; set; }

    public virtual ICollection<Task> Tasks { get; set; } = new List<Task>();
}
