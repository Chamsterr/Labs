// src/components/Main.tsx
import React from "react";
import { useSelector, useDispatch } from "react-redux";
import Vacancy from "./Vacancy";
import { IVacancy } from "../classes/Vacancy";
import VacancyInfo from "./VacancyInfo";
import Container from "@mui/material/Container";
import Grid from "@mui/material/Grid";
import SearchBar from "./SearchBar";
import { selectVacancy } from "../redux/actions";
import {Vacancys} from '../state'

const Main = () => {
  const selectedVacancy = useSelector((state: any) => state.selectedVacancy);
  const dispatch = useDispatch();

  const handleSelectVacancy = (vacancy: IVacancy) => {
    dispatch(selectVacancy(vacancy.id));
  };

  return (
    <div style={{ backgroundColor: "#FAFAFA", paddingTop: 15, width: "100%", height: "100%" }}>
      <Container maxWidth="lg">
        <div style={{ marginBottom: "20px" }}>
          <SearchBar />
        </div>

        <Grid container spacing={2}>
          <Grid item xs={4}>
            {Vacancys.map((vacancy) => (
              <Vacancy
                key={vacancy.id}
                companyName={vacancy.companyName}
                vacancyName={vacancy.vacancyName}
                location={vacancy.location}
                imageSrc={vacancy.image}
                date={vacancy.date}
                stack={vacancy.stack}
                id={vacancy.id}
                onSelect={handleSelectVacancy}
              />
            ))}
          </Grid>
          <Grid item xs={8}>
            <VacancyInfo vacancy={selectedVacancy} />
          </Grid>
        </Grid>
      </Container>
    </div>
  );
};

export default Main;
