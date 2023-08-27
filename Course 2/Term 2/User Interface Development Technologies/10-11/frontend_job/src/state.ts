import { IVacancy } from './classes/Vacancy'


export const Vacancys: IVacancy[] = [
    {
        id: 1,
        companyName: 'Pixel Perfect Solutions',
        location: 'Сан-Франциско, США',
        vacancyName: 'Frontend Developer',
        date: '2023-06-12',
        image: "/images/WhiteSnake.PNG",
        stack: ['React', 'Redux', 'TypeScript', 'SASS'],
        info: 'Мы ищем опытного разработчика, способного создавать великолепные пользовательские интерфейсы.'
    },
    {
        id: 2,
        companyName: 'VueMasters LLC',
        location: 'Берлин, Германия',
        vacancyName: 'Senior Frontend Developer',
        date: '2023-06-10',
        image: "/images/WhiteSnake.PNG",
        stack: ['Vue.js', 'Vuex', 'JavaScript', 'CSS3'],
        info: 'Наша команда в поисках опытного разработчика Vue.js для создания и поддержки сложных веб-приложений.'
    },
    {
        id: 3,
        companyName: 'Angular Innovations',
        location: 'Лондон, Великобритания',
        vacancyName: 'Frontend Engineer',
        date: '2023-06-08',
        image: "/images/WhiteSnake.PNG",
        stack: ['Angular', 'RxJS', 'TypeScript', 'LESS'],
        info: 'Если вы любите Angular и хотите работать над интересными проектами, мы ждем вас!'
    },
    {
        id: 4,
        companyName: 'Responsive Design Experts',
        location: 'Париж, Франция',
        vacancyName: 'Junior Frontend Developer',
        date: '2023-06-05',
        image: "/images/WhiteSnake.PNG",
        stack: ['HTML5', 'CSS3', 'JavaScript', 'Bootstrap'],
        info: 'Мы предлагаем уникальные возможности для развития для начинающих разработчиков, стремящихся к мастерству в области адаптивного дизайна.'
    }
];
