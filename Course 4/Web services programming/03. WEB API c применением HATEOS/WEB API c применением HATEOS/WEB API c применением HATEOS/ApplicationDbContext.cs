using System.Collections.Generic;
using WEB_API_c_применением_HATEOS.Models;
using Microsoft.EntityFrameworkCore;

namespace WEB_API_c_применением_HATEOS
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }

        public DbSet<Student> Students { get; set; }
    }

}
