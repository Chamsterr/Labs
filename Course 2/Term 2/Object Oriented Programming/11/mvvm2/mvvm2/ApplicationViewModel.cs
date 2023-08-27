using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace mvvm2
{
    using System.ComponentModel;
    using System.Runtime.CompilerServices;
    using System.Collections.ObjectModel;
    using System.Text.RegularExpressions;

    namespace MVVM
    {
        public class ApplicationViewModel : INotifyPropertyChanged
        {
            private Project selectedPhone;

            public ObservableCollection<Phone> Phones { get; set; }
            public ObservableCollection<Project> Projects { get; set; }

            public Project SelectedProject
            {
                get { return selectedPhone; }
                set
                {
                    selectedPhone = value;
                    OnPropertyChanged("SelectedProject");
                }
            }

            public ApplicationViewModel()
            {
                Phones = new ObservableCollection<Phone>
                {
                    new Phone { Title="iPhone 7", Company="Apple", Price=56000 },
                    new Phone {Title="Galaxy S7 Edge", Company="Samsung", Price =60000 },
                    new Phone {Title="Elite x3", Company="HP", Price=56000 },
                    new Phone {Title="Mi5S", Company="Xiaomi", Price=35000 }
                };

                using (TaskifyDbContext db = new TaskifyDbContext())
                {
                    Projects = new ObservableCollection<Project>(db.Projects.ToList());
                }
            }

            public event PropertyChangedEventHandler PropertyChanged;
            public void OnPropertyChanged([CallerMemberName] string prop = "")
            {
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs(prop));
            }
        }
    }
}
