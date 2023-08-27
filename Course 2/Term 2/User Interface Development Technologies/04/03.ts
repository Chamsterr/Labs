// =============================
interface CarsType {
    manufacturer: string;
    model: string;
}

interface ArrayCarsType {
    cars: Array<CarsType>
}
// =============================


const car1: CarsType = {
    manufacturer: "manufacturer1",
    model: 'model1'
};

const car2: CarsType = {
    manufacturer: "manufacturer2",
    model: 'model2'
};

const arrayCars: ArrayCarsType = {
    cars: [car1, car2]
};

console.log(arrayCars.cars[1].model)