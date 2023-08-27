using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;

namespace LR9.models
{
    public class SoccerContext : DbContext
    {
        public SoccerContext() : base("SoccerContext")
        { }

        public DbSet<Player> Players { get; set; }
        public DbSet<Team> Teams { get; set; }
    }

    public class Player
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Position { get; set; }
        public int Age { get; set; }

        public int? TeamId { get; set; }
        public Team Team { get; set; }
    }
    public class Team
    {
        public int Id { get; set; }
        public string Name { get; set; } // название команды

        public ICollection<Player> Players { get; set; }
        public Team()
        {
            Players = new List<Player>();
        }

        public static implicit operator Team(Player v)
        {
            return v.Team;
        }
    }
}