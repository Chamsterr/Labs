using System.Collections;
using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using lab3b.Models;
using lab7.StaticData;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Identity;
using Microsoft.DotNet.Scaffolding.Shared.CodeModifier.CodeChange;

namespace lab3b.Controllers
{

    public class AdminController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly UserManager<IdentityUser> _userManager;
        private readonly RoleManager<IdentityRole> _roleManager;
        private readonly SignInManager<IdentityUser> _signInManager;
        public AdminController(ILogger<HomeController> logger,
            UserManager<IdentityUser> userManager,
            RoleManager<IdentityRole> roleManager, SignInManager<IdentityUser> signInManager)
        {
            _logger = logger;
            _roleManager = roleManager;
            _userManager = userManager;
            _signInManager = signInManager;
        }

        [Authorize(Roles = "Administrator")]
        public IActionResult Index()
        {
            return View();
        }

        [HttpGet]
        [HttpPost]
        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> AddNewUser(string? email, string? password) //введеные данные 
        {
            var userModel = new UserViewModel(); //соз объекта пользователя
            userModel.userList = _userManager.Users.ToList();
            if (HttpContext.Request.Method == HttpMethods.Get) //ввод данных
            {
                return View(userModel);
            }
            if (email == null || password == null) //обязательные поля
            {
                userModel.errorMessage = "One of the fields is not filled in";
                return View(userModel);
            }
            if (_userManager.FindByEmailAsync(email).Result != null)
            {
                userModel.errorMessage = "One of the fields is not filled in";
                return View(userModel);
            }

            var newUser = new IdentityUser() { Email = email, UserName = email };//если прошел валидацию
            await _userManager.CreateAsync(newUser, password);
            userModel.isActionSuccess = true;
            userModel.userList = _userManager.Users.ToList();//Если операция успешна, устанавливается флаг isActionSuccess в true и
            //обновляется список пользователей в объекте userModel
            return View(userModel);
        }

        [HttpGet]
        [HttpPost]
        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> DeleteUser(string userId)
        {
            var userModel = new UserViewModel();
            userModel.userList = _userManager.Users.ToList();
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View(userModel);
            }
            if (await _userManager.FindByIdAsync(userId) == null)
            {
                userModel.errorMessage = "User is not found";
                return View(userModel);
            }
            if (_userManager.FindByIdAsync(userId).Result.Email == "Admin@admin.admin1")
            {
                userModel.errorMessage = "The administrator user cannot be deleted";
                return View(userModel);
            }
            await _userManager.DeleteAsync(await _userManager.FindByIdAsync(userId));
            userModel.isActionSuccess = true;
            userModel.userList = _userManager.Users.ToList();
            return View(userModel);
        }

        [HttpGet]
        [HttpPost]
        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> AddNewRole(string? roleName)
        {
            var roleModel = new RoleViewModel();
            roleModel.roleList = _roleManager.Roles.ToList();
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View(roleModel);
            }
            if (roleName == null)
            {
                roleModel.errorMessage = "Role field is empty";
                return View(roleModel);
            }
            if (await _roleManager.RoleExistsAsync(roleName))
            {
                roleModel.errorMessage = "This role already exists";
                return View(roleModel);
            }
            await _roleManager.CreateAsync(new IdentityRole(roleName));
            roleModel.isActionSuccess = true;
            roleModel.roleList = _roleManager.Roles.ToList();
            return View(roleModel);
        }


        [HttpGet]
        [HttpPost]
        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> DeleteRole(string roleId)
        {
            var roleModel = new RoleViewModel();
            roleModel.roleList = _roleManager.Roles.ToList();
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View(roleModel);
            }
            var role = await _roleManager.FindByIdAsync(roleId);
            if (role == null)
            {
                roleModel.errorMessage = "Role not found";
                return View(roleModel);
            }

            if (role.Name == "Administrator")
            {
                roleModel.errorMessage = "The administrator role cannot be deleted";
                return View(roleModel);
            }
            var usersInRole = await _userManager.GetUsersInRoleAsync(role.Name);
            foreach (var user in usersInRole)
            {
                await _userManager.RemoveFromRoleAsync(user, role.Name);
            }
            await _roleManager.DeleteAsync(role);
            roleModel.isActionSuccess = true;
            roleModel.roleList = _roleManager.Roles.ToList();
            return View(roleModel);
        }

        [HttpGet]
        [HttpPost]
        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> AssignRolesToUser(string? roleName, string? userEmail)//назначаем роль пользователя 
        {
            var userRolesModel = new UserRolesViewModel();
            userRolesModel.userList = _userManager.Users.ToList();
            userRolesModel.rolesList = _roleManager.Roles.ToList();
            userRolesModel.userRoles = new List<UserRole>();
            foreach (var user in userRolesModel.userList)
            {
                userRolesModel.userRoles.Add(new UserRole() { user = user, rolesList = _userManager.GetRolesAsync(user).Result.ToList() });
            }
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View(userRolesModel);
            }

            if (roleName == null || userEmail == null)
            {
                userRolesModel.errorMessage = "One of the options is not selected";
            }
            await _userManager.AddToRoleAsync(await _userManager.FindByEmailAsync(userEmail), roleName);
            userRolesModel.userRoles = new List<UserRole>();
            foreach (var user in userRolesModel.userList)
            {
                userRolesModel.userRoles.Add(new UserRole() { user = user, rolesList = _userManager.GetRolesAsync(user).Result.ToList() });
            }
            userRolesModel.userList = _userManager.Users.ToList();
            userRolesModel.rolesList = _roleManager.Roles.ToList();
            userRolesModel.isActionSuccess = true;
            return View(userRolesModel);
        }


        [HttpGet]
        [HttpPost]
        [Authorize(Roles = "Administrator")]
        public async Task<IActionResult> RemoveRolesFromUser(string? roleName, string? userEmail)
        {
            var userRolesModel = new UserRolesViewModel();
            userRolesModel.userList = _userManager.Users.ToList();
            userRolesModel.rolesList = _roleManager.Roles.ToList();
            userRolesModel.userRoles = new List<UserRole>();
            foreach (var user in userRolesModel.userList)
            {
                userRolesModel.userRoles.Add(new UserRole() { user = user, rolesList = _userManager.GetRolesAsync(user).Result.ToList() });
            }
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View(userRolesModel);
            }
            if (roleName == null || userEmail == null)
            {
                userRolesModel.errorMessage = "One of the options is not selected";
            }
            await _userManager.RemoveFromRoleAsync(await _userManager.FindByEmailAsync(userEmail), roleName);
            userRolesModel.userRoles = new List<UserRole>();
            foreach (var user in userRolesModel.userList)
            {
                userRolesModel.userRoles.Add(new UserRole() { user = user, rolesList = _userManager.GetRolesAsync(user).Result.ToList() });
            }
            userRolesModel.userList = _userManager.Users.ToList();
            userRolesModel.rolesList = _roleManager.Roles.ToList();
            userRolesModel.isActionSuccess = true;
            return View(userRolesModel);
        }

        [AllowAnonymous]
        [HttpGet]
        [HttpPost]
        public async Task<IActionResult> Register(string username, string password)
        {
            if (HttpContext.User.Identity.IsAuthenticated)
            {
                return RedirectToAction(nameof(Error), new { message = "You are already registered" });
            }
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View();
            }
            var user = new IdentityUser();
            user.Email = username;
            user.UserName = username;
            user.EmailConfirmed = true;

            var result = await _userManager.CreateAsync(user, password);
            if (result.Succeeded)
            {
                await _signInManager.SignInAsync(user, isPersistent: false);
                return RedirectToAction("Index", "Home");
            }
            else
            {
                return RedirectToAction(nameof(Error), new { message = "Registration failed" });
            }
        }

        [AllowAnonymous]
        [HttpPost]
        [HttpGet]
        public async Task<IActionResult> SignIn(string username, string password, bool rememberMe)
        {
            if (HttpContext.User.Identity.IsAuthenticated)
            {
                return RedirectToAction(nameof(Error), new { message = "You are already logged in" });
            }
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View();
            }
            var result = await _signInManager.PasswordSignInAsync(username, password, rememberMe, lockoutOnFailure: false);
            if (result.Succeeded)
            {
                return RedirectToAction("Index", "Home");
            }
            else
            {
                return RedirectToAction(nameof(Error), new { message = "Failed login" });
            }
        }

        [Authorize]
        [HttpGet]
        [HttpPost]
        public async Task<IActionResult> SignOut()
        {
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View();
            }
            await _signInManager.SignOutAsync();
            return RedirectToAction("Index", "Home");
        }

        [Authorize]
        [HttpGet]
        [HttpPost]
        public async Task<IActionResult> ChangePassword(string currentPassword, string newPassword)
        {
            if (HttpContext.Request.Method == HttpMethods.Get)
            {
                return View();
            }
            var user = await _userManager.GetUserAsync(User);
            if (user == null)
            {
                return RedirectToAction(nameof(Error), new { message = "User not found" });
            }

            var changePasswordResult = await _userManager.ChangePasswordAsync(user, currentPassword, newPassword);
            if (!changePasswordResult.Succeeded)
            {
                return RedirectToAction(nameof(Error), new { message = "Error with change password" });
            }

            await _signInManager.RefreshSignInAsync(user);
            return RedirectToAction("Index", "Home");
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]//не должна кэшироваться нигде.
        public IActionResult Error(string? message)
        {
            var model = new ErrorViewModel
            {
                Message = message
            };
            return View("Error", model);
        }
    }

}
