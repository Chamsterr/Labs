// src/redux/reducers.ts
import { VacancyActionTypes, SELECT_VACANCY } from "./types";

interface VacancyState {
  selectedVacancy: number | null;
}

const initialState: VacancyState = {
  selectedVacancy: null,
};

export function vacancyReducer(
  state = initialState,
  action: VacancyActionTypes
): VacancyState {
  switch (action.type) {
    case SELECT_VACANCY:
      return {
        ...state,
        selectedVacancy: action.payload,
      };
    default:
      return state;
  }
}
