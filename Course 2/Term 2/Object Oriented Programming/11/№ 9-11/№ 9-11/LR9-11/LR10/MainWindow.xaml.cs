using LR9.models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace LR9
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region Data
        Player PlayerBuff;
        UnitOfWork UOW;
        #endregion

        public MainWindow()
        {
            InitializeComponent();
            UOW = new UnitOfWork();
        }
        #region Func
        //Под Unit of work и Repository переписанна толькоо функция TakeData()
        public void TakeData()
        {

                var Players = UOW.Players.GetAll();

                var Teams = UOW.Players.GetAll();

                foreach(var pl in Players)
                {
                    foreach(var Team in Teams)
                    {
                        if(pl.TeamId == Team.Id)
                        {
                            pl.Team = Team;
                        }
                    }
                }

                //Linq
                           
                var query = from Player in Players
                            join Team in Teams on Player.TeamId equals Team.Id
                            select new { PlayerId = Player.Id, Name = Player.Name, Position = Player.Position, Age = Player.Age, TeamId = Team.Id, TeamName = Team.Name};

                if(Radio1.IsChecked == true)
                    query = query.OrderByDescending(p => p.PlayerId);
                if (Radio2.IsChecked == true)
                    query = query.OrderByDescending(p => p.Age);

                DataGridName.ItemsSource = query.ToList();
            
        }
        public void TakeFilteredData()
        {
            using (SoccerContext db = new SoccerContext())
            {
                try
                {
                    int FTeamId = Convert.ToInt32(TB_TeamID.Text);
                    var Teams = db.Teams.ToList();
                    var Players = from p in db.Players
                                  where p.TeamId == FTeamId
                                  select p;

                    var query = from Player in Players
                                join Team in Teams on Player.TeamId equals Team.Id
                                select new { PlayerId = Player.Id, Name = Player.Name, Position = Player.Position, Age = Player.Age, TeamId = Team.Id, TeamName = Team.Name };


                    DataGridName.ItemsSource = query.ToList();
                }
                catch (Exception ex) { }
            }
        }
        public void ShowAllTeamdData()
        {
            using (SoccerContext db = new SoccerContext())
            {
                var Teams = db.Teams.ToList();
                DataGridName.ItemsSource = Teams.ToList();
            }
        }
        public void AddPlayer()
        {
            using (SoccerContext db = new SoccerContext())
            {
                try
                {
                    // создание и добавление моделей
                    int FTeamId = Convert.ToInt32(TB_TeamIdCreate.Text);
                    var Team = from p in db.Teams
                               where p.Id == FTeamId
                               select p;

                    Team tm = Team as Team;

                    Player pl1 = new Player
                    {
                        Name = TB_PlayerName.Text,
                        Age = Convert.ToInt32(TB_PlayerAge.Text),
                        Position = TB_PlayerPosition.Text,
                        TeamId = FTeamId,
                        Team = tm
                    };

                    db.Players.Add(pl1);
                    db.SaveChanges();
                }
                catch (Exception ex) { }
            }
        }
        public void AddTeam()
        {
            using (SoccerContext db = new SoccerContext())
            {
                // создание и добавление моделей
                Team t1 = new Team {Name = TB_TeamName.Text };
                db.Teams.Add(t1);
                db.SaveChanges();
            }
        }
        //async? null
        public void AddTeamAndPlayerTransaction()
        {
            using (SoccerContext db = new SoccerContext())
            {

                using (var transaction = db.Database.BeginTransaction())
                {
                    
                    try
                    {
                        Team t1 = new Team { Name = "Барселона" };
                        Team t2 = new Team { Name = "Реал Мадрид" };
                        db.Teams.Add(t1);
                        db.Teams.Add(t2);
                        db.SaveChanges();

                        Player pl1 = new Player { Name = "Роналду", Age = 31, Position = "Нападающий", Team = t2 };
                        Player pl2 = new Player { Name = "Месси", Age = 28, Position = "Нападающий", Team = t1 };
                        Player pl3 = new Player { Name = "Хави", Age = 34, Position = "Полузащитник", Team = t1 };
                        db.Players.AddRange(new List<Player> { pl1, pl2, pl3 });
                        db.SaveChanges();

                        // Подтверждение транзакции
                        transaction.Commit();
                    }
                    catch (Exception ex)
                    {
                        // Отмена транзакции в случае возникновения ошибки
                        transaction.Rollback();
                        throw;
                    }
                }
            }
        }
        public void DeletePlayer()
        {
            try
            {
                using (SoccerContext db = new SoccerContext())
                {
                    int TI = Convert.ToInt32(TB_PlayerIdDelete.Text);

                    List<Player> t1 = db.Players.ToList<Player>();
                    Player tm = null;
                    foreach (Player t in t1)
                    {
                        if (t.Id == TI)
                        {
                            tm = t; break;
                        }
                    }

                    if (tm != null)
                    {
                        db.Players.Remove(tm);
                        db.SaveChanges();
                    }
                }
            }
            catch (Exception ex) { }
        }
        public void DeleteTeam()
        {
            using (SoccerContext db = new SoccerContext())
            {
                int TI = Convert.ToInt32(TB_TeamdIdDelete.Text);

                List<Team> t1 = db.Teams.ToList<Team>();
                Team tm = null;
                foreach(Team t in t1)
                {
                    if(t.Id == TI)
                    {
                        tm = t; break;
                    }
                }

                if (tm != null)
                {
                    db.Teams.Remove(tm);
                    db.SaveChanges();
                }
            }
        }
        //сомнительная конструкция
        public void LoadPlayer()
        {
            try
            {
                using (SoccerContext db = new SoccerContext())
                {
                    int TI = Convert.ToInt32(TB_EditPlayerId.Text);

                    List<Player> t1 = db.Players.ToList<Player>();
                    foreach (Player t in t1)
                    {
                        if (t.Id == TI)
                        {
                            PlayerBuff = t; break;
                        }
                    }

                    if (PlayerBuff != null)
                    {
                        TB_EPA.Text = PlayerBuff.Age.ToString();
                        TB_EPN.Text = PlayerBuff.Name.ToString();
                        TB_EPP.Text = PlayerBuff.Position.ToString();
                    }
                }
            }
            catch (Exception ex) { }

        }
        public void EditPlayer()
        {
            try
            {
                using (SoccerContext db = new SoccerContext())
                {
                    List<Player> PL = db.Players.ToList<Player>();

                    Player p = null;                 

                    foreach (Player pf in PL)
                    {
                        if (pf.Id == PlayerBuff.Id)
                        {
                            p = pf; break;
                        }  
                    }

                    if(p != null)
                    {
                        PL.Remove(p);

                        p.Name = TB_EPN.Text;
                        p.Position = TB_EPP.Text;
                        p.Age = Convert.ToInt32(TB_EPA.Text);

                        PL.Add(p);

                        db.SaveChanges();
                    }

                }
            }
            catch (Exception ex) { }

        }
        #endregion
        #region Buttons
        private void BTN_FilteredFind_Click(object sender, RoutedEventArgs e) { TakeFilteredData(); }
        private void BTN_Find_Click(object sender, RoutedEventArgs e) { TakeData(); }
        //Create Team
        private void Button_Click(object sender, RoutedEventArgs e) { AddTeam(); }
        private void BTN_ShowAllTeams_Click(object sender, RoutedEventArgs e) { ShowAllTeamdData(); }
        private void BTN_CreatePlayer_Click(object sender, RoutedEventArgs e) { AddPlayer(); }
        //delete player
        private void Button_Click_1(object sender, RoutedEventArgs e) { DeletePlayer(); }
        //delete team
        private void Button_Click_2(object sender, RoutedEventArgs e) { DeleteTeam(); }
        private void TB_LoadPlayer_Click(object sender, RoutedEventArgs e) { LoadPlayer(); }
        private void BTN_SaveChanges_Click(object sender, RoutedEventArgs e) { EditPlayer(); }
        private void BTN_Transaction_Click(object sender, RoutedEventArgs e) { AddTeamAndPlayerTransaction(); }

        #endregion
    }
}
