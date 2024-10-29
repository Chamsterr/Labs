    using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Web;
using System.Web.Mvc;
using System.Xml;

namespace wclient.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult GetFeed(string studentId, string format)
        {
            string content = string.Empty;

            if (!string.IsNullOrEmpty(studentId))
            {
                if (format.Equals("atom", StringComparison.OrdinalIgnoreCase))
                {
                    content = GetAtomFeed(studentId);
                }
                else if (format.Equals("rss", StringComparison.OrdinalIgnoreCase))
                {
                    content = GetRssFeed(studentId);
                }
            }
            else
            {
                return Json(new { error = "Заполните поле student id" });
            }

            return Json(new { content });
        }

        private string GetAtomFeed(string studentId)
        {
            StringBuilder atomContent = new StringBuilder();
            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load($"http://localhost:2003/SyndicationService/feed/{studentId}?format=atom");
            XmlElement root = xmlDoc.DocumentElement;

            XmlNamespaceManager nsmgr = new XmlNamespaceManager(xmlDoc.NameTable);
            nsmgr.AddNamespace("atom", "http://www.w3.org/2005/Atom");

            XmlNodeList entryNodes = root.SelectNodes("//atom:entry", nsmgr);
            atomContent.Append("ATOM\n\n");

            foreach (XmlNode atomEntry in entryNodes)
            {
                XmlNode titleNode = atomEntry.SelectSingleNode("atom:title", nsmgr);
                string title = titleNode != null ? titleNode.InnerText : "";

                XmlNode contentNode = atomEntry.SelectSingleNode("atom:content", nsmgr);
                string description = contentNode != null ? contentNode.InnerText : "";

                atomContent.Append($"Subject: {title}\nDescription: {description}\n\n");
            }

            return atomContent.ToString();
        }

        private string GetRssFeed(string studentId)
        {
            StringBuilder rssContent = new StringBuilder();
            XmlDocument rssXmlDoc = new XmlDocument();
            rssXmlDoc.Load($"http://localhost:2003/SyndicationService/feed/{studentId}?format=rss");
            XmlNodeList rssNodes = rssXmlDoc.SelectNodes("rss/channel/item");

            rssContent.Append("RSS\n");

            foreach (XmlNode rssNode in rssNodes)
            {
                XmlNode rssSubNode = rssNode.SelectSingleNode("title");
                string title = rssSubNode != null ? rssSubNode.InnerText : "";

                rssSubNode = rssNode.SelectSingleNode("link");
                string link = rssSubNode != null ? rssSubNode.InnerText : "";

                rssSubNode = rssNode.SelectSingleNode("description");
                string description = rssSubNode != null ? rssSubNode.InnerText : "";

                rssContent.Append($"Subject: {title}\nDescription: {description}\n\n");
            }

            return rssContent.ToString();
        }

    }
}