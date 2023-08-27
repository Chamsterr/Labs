"use strict";
exports.__esModule = true;
exports.Challenge = void 0;
var Challenge = /** @class */ (function () {
    function Challenge() {
    }
    Challenge.solution = function (nums1, nums2) {
        return (this.getMedian(nums1) + this.getMedian(nums2)) / 2;
    };
    Challenge.getMedian = function (nums) {
        if (nums.length % 2 == 0) {
            return (nums[Math.floor(nums.length / 2)] + nums[Math.floor(nums.length / 2) - 1]) / 2;
        }
        else {
            return nums[Math.floor(nums.length / 2)];
        }
    };
    return Challenge;
}());
exports.Challenge = Challenge;
console.log(Challenge.solution([1, 3, 4, 7, 9], [2, 5, 6, 9, 11]));
