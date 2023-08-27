using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class GroupProvider
    {
        private readonly DbContext _dbContext;

        public GroupProvider(DbContext dbContext)
        {
            _dbContext = dbContext;
        }

        public List<Group> GetGroups()
        {
            return _dbContext.Set<Group>().ToList();
        }

        public void AddGroup(Group group)
        {
            _dbContext.Set<Group>().Add(group);
            _dbContext.SaveChanges();
        }

        public void DeleteGroup(Group group)
        {
            _dbContext.Set<Group>().Remove(group);
            _dbContext.SaveChanges();
        }

    }
}
