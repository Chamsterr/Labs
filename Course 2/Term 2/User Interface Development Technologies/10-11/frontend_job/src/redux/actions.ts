// src/redux/actions.ts
import { SELECT_VACANCY, VacancyActionTypes } from "./types";

export function selectVacancy(newVacancy: number | null): VacancyActionTypes {
  return {
    type: SELECT_VACANCY,
    payload: newVacancy,
  };
}
