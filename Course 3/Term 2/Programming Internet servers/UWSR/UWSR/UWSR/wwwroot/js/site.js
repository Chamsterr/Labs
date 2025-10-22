document.addEventListener('keydown', function (event) {
    //console.log('before if: '+event.key);
    if (event.ctrlKey && event.key === '`') {
        window.location.href = 'http://localhost:6118/Auth?shortcut=ctrl+`';
        console.log('Сочетание клавиш Ctrl+` нажато');
    }
});