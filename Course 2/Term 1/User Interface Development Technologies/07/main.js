const zone1 = document.querySelector('.zone1');
const zone2 = document.querySelector('.zone2');

const dart1 = document.querySelector('#dart1');
const dart2 = document.querySelector('#dart2');

zone1.ondragover = allowDrop;

function allowDrop(event) {
    event.preventDefault();
}

dart1.ondragstart = drag;
dart2.ondragstart = drag;

function drag(event) {
    event.dataTransfer.setData("id", event.target.id);
}

zone1.ondrop = drop;

function drop(event) {
    let itemId = event.dataTransfer.getData("id");
    let item = document.getElementById(itemId);
    item.style.top = event.clientY + 'px';

    let varLeft = event.clientX;
    item.style.left = event.clientX + 'px';


    test(item, varLeft);


}

function animate(options) {

    var start = performance.now();

    requestAnimationFrame(function animate(time) {
        // timeFraction от 0 до 1
        var timeFraction = (time - start) / options.duration;
        if (timeFraction > 1) timeFraction = 1;

        // текущее состояние анимации
        var progress = options.timing(timeFraction)

        options.draw(progress);

        if (timeFraction < 1) {
            requestAnimationFrame(animate);
        }

    });
}
document.getElementById("dart1").addEventListener("dragstart", function (e) {
    this.style.rotate = "90deg";
}, false);

document.getElementById("dart2").addEventListener("dragstart", function (e) {
    this.style.rotate = "90deg";
}, false);

function test(item, varLeft) {
    animate({
        duration: 1000,
        timing: function back(x, timeFraction) {
            return Math.pow(timeFraction, 2) * ((x + 1) * timeFraction - x)
        }.bind(null, 1.5),
        draw: function (progress) {
            console.log(varLeft - progress * 500 + 'px');
            item.style.left = varLeft - progress * 500 + 'px';
        }
    });
};