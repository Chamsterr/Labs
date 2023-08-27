// src/redux/types.ts
export const SELECT_VACANCY = "SELECT_VACANCY";

interface SelectVacancyAction {
  type: typeof SELECT_VACANCY;
  payload: number;
}
export interface RootState {
  selectedVacancy: number | null;
  // Добавьте другие поля состояния вашего приложения здесь
}
export type VacancyActionTypes = SelectVacancyAction;
