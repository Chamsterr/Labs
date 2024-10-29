using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Http;
using System.Collections.Generic;
using Newtonsoft.Json.Linq;

public class JsonRpcRequest
{
    public string Jsonrpc { get; set; }
    public string Method { get; set; }
    public JToken Params { get; set; }
    public int? Id { get; set; }
}

public class ExitErrorException : Exception
{
    public object JsonRpcError { get; }

    public ExitErrorException(object jsonRpcError)
    {
        JsonRpcError = jsonRpcError;
    }
}

[ApiController]
[Route("api/[controller]")]
public class JRServiceController : ControllerBase
{
    [HttpPost]
    public IActionResult HandleJsonRpcRequests([FromBody] object requests)
    {
        if (requests is JArray requestArray)
        {
            var responses = new List<object>();
            foreach (var item in requestArray)
            {
                try
                {
                    var request = item.ToObject<JsonRpcRequest>();
                    responses.Add(ProcessRequest(request));
                }
                catch (ExitErrorException ex)
                {
                    responses.Add(ex.JsonRpcError);
                    return Ok(responses);
                }
                catch (Exception)
                {
                    var errorResponse = CreateErrorResponse(1, "Ошибка в парсинге JSON-RPC.", -32700);
                    responses.Add(errorResponse);
                }
            }
            return Ok(responses);
        }

        if (requests is JObject singleRequest)
        {
            try
            {
                var request = singleRequest.ToObject<JsonRpcRequest>();
                return Ok(ProcessRequest(request));
            }
            catch (ExitErrorException ex)
            {
                return BadRequest(ex.JsonRpcError);
            }
            catch (Exception)
            {
                var errorResponse = CreateErrorResponse(1, "Ошибка в парсинге JSON-RPC.", -32700);
                return BadRequest(errorResponse);
            }
        }

        return BadRequest(CreateErrorResponse(null, "Неверный синтаксис JSON-RPC.", -32700));
    }

    private object ProcessRequest(JsonRpcRequest request)
    {
        if (request == null)
        {
            return CreateErrorResponse(null, "Неверный формат запроса.", -32600);
        }

        switch (request.Method)
        {
            case "SetM": return HandleSetM(request);
            case "GetM": return HandleGetM(request);
            case "AddM": return HandleAddM(request);
            case "SubM": return HandleSubM(request);
            case "MulM": return HandleMulM(request);
            case "DivM": return HandleDivM(request);
            case "ErrorExit": return HandleErrorExit(request);
            default: return CreateErrorResponse(request.Id, "Метод не найден.", -32601);
        }
    }

    private object HandleSetM(JsonRpcRequest request)
    {
        var (k, x) = ParseParams(request.Params);

        if (k == null || x == null)
        {
            return CreateErrorResponse(request.Id, "Параметры 'k' и 'x' обязательны для метода SetM.", -32602);
        }

        int result = x.Value;
        HttpContext.Session.SetInt32(k, result);
        return CreateSuccessResponse(request.Id, result);
    }

    private object HandleGetM(JsonRpcRequest request)
    {
        string k = null;

        if (request.Params.Type == JTokenType.String)
        {
            k = request.Params.ToString();
        }
        else if (request.Params is JArray posParams && posParams.Count == 1)
        {
            k = posParams[0].ToString();
        }
        else if (request.Params is JObject)
        {

            k = ParseParams(request.Params).k;
        }

        if (k == null)
        {
            return CreateErrorResponse(request.Id, "Параметр 'k' обязателен для метода GetM.", -32602);
        }

        int? getValue = HttpContext.Session.GetInt32(k);
        if (getValue == null)
        {
            return CreateErrorResponse(request.Id, "Значение по заданному ключу не найдено.", -32603);
        }

        return CreateSuccessResponse(request.Id, getValue);
    }



    private object HandleAddM(JsonRpcRequest request)
    {
        var (k, x) = ParseParams(request.Params);

        if (k == null || x == null)
        {
            return CreateErrorResponse(request.Id, "Параметры 'k' и 'x' обязательны для метода AddM.", -32602);
        }

        int? addValue = HttpContext.Session.GetInt32(k);
        if (addValue == null)
        {
            return CreateErrorResponse(request.Id, "Значение по заданному ключу не найдено.", -32603);
        }

        int result = addValue.Value + x.Value;
        HttpContext.Session.SetInt32(k, result);
        return CreateSuccessResponse(request.Id, result);
    }

    private object HandleSubM(JsonRpcRequest request)
    {
        var (k, x) = ParseParams(request.Params);

        if (k == null || x == null)
        {
            return CreateErrorResponse(request.Id, "Параметры 'k' и 'x' обязательны для метода SubM.", -32602);
        }

        int? subValue = HttpContext.Session.GetInt32(k);
        if (subValue == null)
        {
            return CreateErrorResponse(request.Id, "Значение по заданному ключу не найдено.", -32603);
        }

        int result = subValue.Value - x.Value;
        HttpContext.Session.SetInt32(k, result);
        return CreateSuccessResponse(request.Id, result);
    }

    private object HandleMulM(JsonRpcRequest request)
    {
        var (k, x) = ParseParams(request.Params);

        if (k == null || x == null)
        {
            return CreateErrorResponse(request.Id, "Параметры 'k' и 'x' обязательны для метода MulM.", -32602);
        }

        int? mulValue = HttpContext.Session.GetInt32(k);
        if (mulValue == null)
        {
            return CreateErrorResponse(request.Id, "Значение по заданному ключу не найдено.", -32603);
        }

        int result = mulValue.Value * x.Value;
        HttpContext.Session.SetInt32(k, result);
        return CreateSuccessResponse(request.Id, result);
    }

    private object HandleDivM(JsonRpcRequest request)
    {
        var (k, x) = ParseParams(request.Params);

        if (k == null || x == null)
        {
            return CreateErrorResponse(request.Id, "Параметры 'k' и 'x' обязательны для метода DivM.", -32602);
        }

        if (x == 0)
        {
            return CreateErrorResponse(request.Id, "Деление на ноль невозможно.", -32603);
        }

        int? divValue = HttpContext.Session.GetInt32(k);
        if (divValue == null)
        {
            return CreateErrorResponse(request.Id, "Значение по заданному ключу не найдено.", -32603);
        }

        int result = divValue.Value / x.Value;
        HttpContext.Session.SetInt32(k, result);
        return CreateSuccessResponse(request.Id, result);
    }

    private object HandleErrorExit(JsonRpcRequest request)
    {
        HttpContext.Session.Clear();
        var exitError = CreateErrorResponse(request.Id, "ExitError", -32001);
        throw new ExitErrorException(exitError);
    }

    private (string k, int? x) ParseParams(JToken parameters)
    {
        if (parameters is JArray posParams && posParams.Count >= 2)
        {
            return (posParams[0].ToString(), posParams[1].ToObject<int>());
        }
        else if (parameters is JObject namedParams)
        {
            var k = namedParams["k"]?.ToString();
            var x = namedParams["x"]?.ToObject<int>();
            return (k, x);
        }
        return (null, null);
    }

    private object CreateSuccessResponse(int? id, object result)
    {
        return new
        {
            jsonrpc = "2.0",
            id,
            result
        };
    }

    private object CreateErrorResponse(int? id, string errorMessage, int code)
    {
        return new
        {
            jsonrpc = "2.0",
            id,
            error = new
            {
                code,
                message = errorMessage
            }
        };
    }
}
