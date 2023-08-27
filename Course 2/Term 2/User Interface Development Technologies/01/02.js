"use strict";
exports.__esModule = true;
exports.Challenge = void 0;
var Challenge = /** @class */ (function () {
    function Challenge() {
    }
    Challenge.solution = function (number) {
        var numbers = new Set();
        var answer;
        for (var i = 5; i < number; i += 5) {
            numbers.add(i);
        }
        for (var i = 3; i < number; i += 3) {
            numbers.add(i);
        }
        numbers.forEach(function (element) {
            answer += number;
        });
    };
    return Challenge;
}());
exports.Challenge = Challenge;
Challenge.solution(3);
