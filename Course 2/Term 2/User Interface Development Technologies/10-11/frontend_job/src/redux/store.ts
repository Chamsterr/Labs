// src/redux/store.ts
import { vacancyReducer } from "./reducers";
import { createStore, combineReducers } from "redux";

export const rootReducer = combineReducers({
    vacancy: vacancyReducer,
  });

export const store = createStore(vacancyReducer);
