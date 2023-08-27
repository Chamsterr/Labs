using LR9.models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace LR9
{
    public class PlayerRepository : IRepository<Player>
    {
        private SoccerContext db;

        public PlayerRepository(SoccerContext context)
        {
            this.db = context;
        }

        public IEnumerable<Player> GetAll()
        {
            return db.Players;
        }

        public Player Get(int id)
        {
            return db.Players.Find(id);
        }

        public void Create(Player book)
        {
            db.Players.Add(book);
        }

        public void Update(Player book)
        {
            db.Entry(book).State = EntityState.Modified;
        }

        public void Delete(int id)
        {
            Player book = db.Players.Find(id);
            if (book != null)
                db.Players.Remove(book);
        }
    }

    public class TeamRepository : IRepository<Team>
    {
        private SoccerContext db;

        public TeamRepository(SoccerContext context)
        {
            this.db = context;
        }

        public IEnumerable<Team> GetAll()
        {
            return db.Teams.Include(o => o.Players);
        }

        public Team Get(int id)
        {
            return db.Teams.Find(id);
        }

        public void Create(Team order)
        {
            db.Teams.Add(order);
        }

        public void Update(Team order)
        {
            db.Entry(order).State = EntityState.Modified;
        }

        public void Delete(int id)
        {
            Team order = db.Teams.Find(id);
            if (order != null)
                db.Teams.Remove(order);
        }
    }
}
