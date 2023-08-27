export class Challenge {
    static solution(nums1: Array<number>, nums2: Array<number>): any {
        return (this.getMedian(nums1) + this.getMedian(nums2)) / 2
    }

    static getMedian(nums: Array<number>) {
        if (nums.length % 2 == 0) {
            return (nums[Math.floor(nums.length / 2)] + nums[Math.floor(nums.length / 2) - 1]) / 2
        }
        else {
            return nums[Math.floor(nums.length / 2)]
        }

    }
}

console.log(Challenge.solution([1, 3, 4, 7, 9], [2, 5, 6, 9, 11]))