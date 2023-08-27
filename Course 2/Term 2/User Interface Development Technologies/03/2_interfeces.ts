interface Rect {
    readonly id: string
    color?: string
    size: {
        width: number
        heihgt: number
    }
}

const rect1: Rect = {
    id: '123123',
    size: {
        width: 20,
        heihgt: 30
    },
    color: '#ccc'
}

rect1.color = 'black'
rect1.id = '3232'

const rect3 = {} as Rect
const rect4 = <Rect>{}
// =======

interface RectWithArea extends Rect{
    getArea: () => number; 
}

const rect5: RectWithArea = {
    id: '123',
    size: {
        width: 20,
        heihgt: 20
    },
    getArea(): number {
        return this.size.width * this.size.heihgt
    },
}
// =================

interface IClock{
    time: Date
    setTime(date: Date): void
}

class Clock implements IClock{
    time: Date = new Date()
    setTime(date: Date): void {
        this.time = date
    }
}

// ====================
interface Styles{
    [key: string]: string
}

const css = {
    border: "1px solid black",
    marginTop: '2px',
    borderRadius: '5px'
}