using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace WinFormsApp2
{
    internal class Flights
    {
        private List<Plane> flights = new List<Plane>() { };
        string filePath = "plane.json";

        public Flights()
        {
            flights = new List<Plane>() { };
            if (File.Exists(filePath))
            {
                // Чтение содержимого файла
                string json = File.ReadAllText(filePath);
                if (!(json == "" || json == null))
                {

                    // Десериализация объекта
                    flights = JsonConvert.DeserializeObject<List<Plane>>(json);
                }
            }
        }
        public void AddFlight(Plane plane)
        {
            flights.Add(plane);
        }
        public List<Plane> GetFlights()
        {
            return flights;
        }
        public void Delete()
        {
            flights.Clear();
            File.Delete(filePath);
        }

        public static void JsonSerelization<T>(T planes, string filePath = "plane")
        {
            filePath = filePath.Replace("/", "-").Replace(":", "_").Replace(" ", "-") + ".json";
            string json = JsonConvert.SerializeObject(planes, Formatting.Indented);
            byte[] bytes = Encoding.UTF8.GetBytes(json);
            using (FileStream stream = new FileStream(filePath, FileMode.OpenOrCreate))
            {
                stream.Write(bytes, 0, bytes.Length);
            }
        }

        public IEnumerable<Plane> GetStringForPrintByFilters(TextBox model, TextBox type, TextBox numberOfPlaces, TextBox Carryng)
        {
            string modelSearch = model.Text == ""? "\\S": model.Text;
            string typeSearch = type.Text == "" ? "\\S" : type.Text;
            var numberOfPlacesSearch = numberOfPlaces.Text == "" ? $"\\S+" : $"^{numberOfPlaces.Text}$";
            string carryngSearch = Carryng.Text == "" ? $"\\S+" : $"^{Carryng.Text}$";
            IEnumerable<Plane> matchingPlanes = new List<Plane>() { };
            if (flights != null) {
                matchingPlanes = from plane in flights
                                     where Regex.IsMatch(plane.Model, $"{modelSearch}+", RegexOptions.IgnoreCase) 
                                     && Regex.IsMatch(plane.Type, $"{typeSearch}+", RegexOptions.IgnoreCase)
                                     && Regex.Match(plane.NumberOfPlace.ToString(), numberOfPlacesSearch).Success
                                     && Regex.Match(plane.Carrying.ToString(), carryngSearch).Success
                                     select plane;
            }

            return matchingPlanes;
        }
    }
}
