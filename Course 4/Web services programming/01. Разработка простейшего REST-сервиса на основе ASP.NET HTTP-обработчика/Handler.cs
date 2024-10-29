using System;
using System.Collections.Generic;
using System.Web;
using System.Web.SessionState;

public class Handler : IHttpHandler, IRequiresSessionState
{
    private int _result;

    public bool IsReusable => true;

    public void ProcessRequest(HttpContext context)
    {
        var req = context.Request;
        var res = context.Response;
        var session = HttpContext.Current.Session;
        var stack = session["Stack"] as Stack<int>;

        if (stack is null)
        {
            session["Stack"] = new Stack<int>();
            stack = session["Stack"] as Stack<int>;
        }

        switch (req.HttpMethod)
        {
            case "GET":
                HandleGetRequest(res, stack);
                break;

            case "POST":
                HandlePostRequest(req, res);
                break;

            case "PUT":
                HandlePutRequest(req, res, stack);
                break;

            case "DELETE":
                HandleDeleteRequest(res, stack);
                break;

            default:
                SendResponse(res, 405, "[ERROR] Method Not Allowed.");
                break;
        }
    }

    private void HandleGetRequest(HttpResponse res, Stack<int> stack)
    {
        var result = (stack.Count > 0) ? (_result + stack.Peek()) : _result;
        res.ContentType = "application/json";
        res.Write("{\"result\": " + result + "}");
    }

    private void HandlePostRequest(HttpRequest req, HttpResponse res)
    {
        if (!int.TryParse(req.QueryString["result"], out int resultParameter))
        {
            SendResponse(res, 400, "[ERROR] Enter integer parameter.");
            return;
        }
        _result = resultParameter;
    }

    private void HandlePutRequest(HttpRequest req, HttpResponse res, Stack<int> stack)
    {
        if (!int.TryParse(req.QueryString["add"], out int addParameter))
        {
            SendResponse(res, 400, "[ERROR] Enter integer parameter.");
            return;
        }
        stack.Push(addParameter);
    }

    private void HandleDeleteRequest(HttpResponse res, Stack<int> stack)
    {
        if (stack.Count <= 0)
        {
            SendResponse(res, 400, "[ERROR] Stack is empty.");
            return;
        }
        stack.Pop();
    }

    private void SendResponse(HttpResponse res, int code, string message)
    {
        res.StatusCode = code;
        res.Write(message);
    }
}