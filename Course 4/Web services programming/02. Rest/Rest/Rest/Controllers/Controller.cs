using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using System.Collections.Generic;

namespace Rest.Controllers
{
    
    [Route("api/[controller]")]
    [ApiController]
    public class StackController : ControllerBase
    {
        private static Stack<int> _globalStack = new Stack<int>();
        private static int _result = 0;

        [HttpGet]
        public IActionResult Get()
        {
            var result = _globalStack.Count > 0 ? (_result + _globalStack.Peek()) : _result;
            return Ok(new { result });
        }

        [HttpPost]
        public IActionResult Post([FromQuery] int result)
        {
            _result = result;
            return Ok();
        }

        [HttpPut]
        public IActionResult Put([FromQuery] int add)
        {
            _globalStack.Push(add);
            return Ok();
        }

        [HttpDelete]
        public IActionResult Delete()
        {
            if (_globalStack.Count == 0)
            {
                return BadRequest("[ERROR] Stack is empty.");
            }

            _globalStack.Pop();
            return Ok();
        }
    }
}
