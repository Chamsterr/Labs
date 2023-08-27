using System;
using System.Collections.Generic;

namespace mvvm2;

public partial class Task
{
    public long Id { get; set; }

    public string Name { get; set; } = null!;

    public long? Description { get; set; }

    public long Status { get; set; }

    public long? ProjectId { get; set; }

    public string? CompletionDate { get; set; }

    public byte[]? Image { get; set; }

    public virtual Project? Project { get; set; }
}
