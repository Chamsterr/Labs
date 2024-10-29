using System;
using System.Collections.Generic;
using System.ServiceModel;
using System.ServiceModel.Syndication;
using System.ServiceModel.Web;
using StudentsModel;

namespace SyndicationServiceLibrary
{
    [ServiceContract]
    [ServiceKnownType(typeof(Atom10FeedFormatter))]
    [ServiceKnownType(typeof(Rss20FeedFormatter))]
    [ServiceKnownType(typeof(List<StudentsEntities11>))]
    public interface IFeed
    {

        [OperationContract]
        [WebInvoke(Method = "GET", BodyStyle = WebMessageBodyStyle.Bare, UriTemplate = "/{studentId}")]
        Object GetStudentNotes(string studentId);
    }
}
