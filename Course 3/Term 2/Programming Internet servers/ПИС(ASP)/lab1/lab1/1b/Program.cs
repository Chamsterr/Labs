using System.Net.WebSockets;
using System.Net;
using System.Text;

internal class Program
{
    static void Main(string[] args)
    {
        var builder = WebApplication.CreateBuilder(args);
        var app = builder.Build();

        app.UseWebSockets();

        app.MapGet("/websocket", async (HttpContext context) =>
        {
            if (context.WebSockets.IsWebSocketRequest)
            {
                using var webSocket = await context.WebSockets.AcceptWebSocketAsync();
                await OnConnected(webSocket);
            }
            else context.Response.StatusCode = (int)HttpStatusCode.BadRequest;
        });

        async Task OnConnected(WebSocket webSocket)
        {
            try
            {
                while (webSocket.State == WebSocketState.Open)
                {
                    var buffer = new ArraySegment<byte>(Encoding.UTF8.GetBytes(DateTime.Now.ToString("HH:mm:ss")));
                    await webSocket.SendAsync(buffer, WebSocketMessageType.Text, true, CancellationToken.None);
                    await Task.Delay(2000);
                }
            }
            catch (Exception ex)
            {
                var buffer = new ArraySegment<byte>(Encoding.UTF8.GetBytes(ex.Message));
                await webSocket.SendAsync(buffer, WebSocketMessageType.Text, true, CancellationToken.None);

            }
        }

        app.UseDefaultFiles();
        app.UseStaticFiles();

        app.Run();
    }
}
