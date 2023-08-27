enum Membership {
    Simple,
    Standard,
    Premium
}

const memvership = Membership.Standard
const memvershipReverse = Membership[2]
console.log(memvership)
console.log(memvershipReverse)

enum SocialMedia {
    VK = "VK",
    FACEBOOK = 'FACEBOOK',
    INSTAGRAM = 'INSTAGRAM'
}

const social = SocialMedia.INSTAGRAM
console.log(social)