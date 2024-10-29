using System;

namespace web_forms_proxy
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        private Simplex _client;

        protected void Page_Load(object sender, EventArgs e)
        {
            _client = new Simplex();
        }

        protected void SumClick(object sender, EventArgs e)
        {
            int first;
            int second;
            if (int.TryParse(x.Text.ToString(), out first) &&
               int.TryParse(y.Text.ToString(), out second))
            {
                var req = new
                {
                    x = first,
                    y= second
                };

                dynamic res = _client.AddS(Newtonsoft.Json.JsonConvert.SerializeObject(req));
                dynamic resJSON = Newtonsoft.Json.JsonConvert.DeserializeObject(res);

                result.Text = resJSON.sumres;
            }
        }
    }
}