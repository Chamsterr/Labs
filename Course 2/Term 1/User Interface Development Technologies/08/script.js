$(document).ready(function () {

    // <!-- Табы на JS -->
    // $(".dws-form").on("click", ".tab", function () {
    //    Удаляем классы active
    //     $(".dws-form").find(".active").removeClass("active");

    //    Добавляем класс active
    //     $(this).addClass("active");
    //     $(".tab-form").eq($(this).index()).addClass("active");
    // });
});



function validation() {
    const EMAIL_REGEXP = /^([a-z0-9_-]+\.)*[a-z0-9_-]+@[a-z0-9_-]+(\.[a-z0-9_-]+)*\.[a-z]{2,6}$/;
    const PASSWORD_REGEXP = /(?=.*[0-9])(?=.*[!@#$%^&*])(?=.*[a-z])(?=.*[A-Z])[0-9a-zA-Z!@#$%^&*]{6,}/g
    //(?=.*[0-9]) - строка содержит хотя бы одно число;
    //(?=.*[!@#$%^&*]) - строка содержит хотя бы один спецсимвол;
    //(?=.*[a-z]) - строка содержит хотя бы одну латинскую букву в нижнем регистре;
    //(?=.*[A-Z]) - строка содержит хотя бы одну латинскую букву в верхнем регистре;
    //[0-9a-zA-Z!@#$%^&*]{6,} - строка состоит не менее, чем из 6 вышеупомянутых символов.

    const NAME_LASTNAME_REGEXP = /^[a-zA-Zа-яА-ЯёЁ]+$/;


    let email = document.getElementById("regEmail");
    let name = document.getElementById("regName");
    let lastname = document.getElementById("regLastName");
    let password = document.getElementById("regPassword");
    let date = document.getElementById("regDate");
    let termOfUse = document.getElementById("ckbox");

    let validation = true;
    if (!isValid(email.value, EMAIL_REGEXP)) {
        email.style.border = "1px solid red";
        alert("Неверный формат email");
        validation = false;
    }
    if (!isValid(password.value, PASSWORD_REGEXP)) {
        password.style.border = "1px solid red";
        alert(`Неверный формат пароля
                Пароль должен содержать:
                - минимум 6 символов
                - минимум 1 цифру
                - минимум 1 заглавную букву
                - минимум 1 спецсимвол (!@#$%^&*)`);
        validation = false;
    }
    if (!isValid(name.value, NAME_LASTNAME_REGEXP)) {
        name.style.border = "1px solid red";
        alert("Неверный формат имени");
        validation = false;
    }
    if (!isValid(lastname.value, NAME_LASTNAME_REGEXP)) {
        lastname.style.border = "1px solid red";
        alert("Неверный формат фамилии");
        validation = false;
    }

    if (Date.now() < Date.parse(date.value) || date.value == "") {
        date.style.border = "1px solid red";
        alert("Неверный формат даты");
        validation = false;
    }
    if (termOfUse.checked == false) {
        alert("Ознакомтесь с условиями использования");
        validation = false;
    }
    if (validation) {
        email.style.border = "1px solid green";
        password.style.border = "1px solid green";
        name.style.border = "1px solid green";
        lastname.style.border = "1px solid green";
        date.style.border = "1px solid green";
        alert("Регистрация прошла успешно!");
    }
}

function isValid(value, EMAIL_REGEXP) {
    return EMAIL_REGEXP.test(value);
}