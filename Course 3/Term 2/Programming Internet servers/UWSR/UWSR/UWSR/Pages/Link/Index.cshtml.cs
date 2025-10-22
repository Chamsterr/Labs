using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using UWSR.Data;
using UWSR.Models;

namespace UWSR.Pages.Link
{
    public class IndexModel : PageModel
    {
        private readonly UWSR.Data.AppDbContext _context;

        public IndexModel(UWSR.Data.AppDbContext context)
        {
            _context = context;
        }

        public IList<Links> Link { get;set; } = default!;

        public async Task OnGetAsync()
        {
            if (_context.Links != null)
            {
                Link = await _context.Links.ToListAsync();
            }
        }

        public IActionResult OnPostClearCookies()
        {
            HttpContext.Session.Remove("isAdmin");


            return RedirectToPage();
        }
    }
}
